#include "m4aPassThrough.hpp"

M4ADecoder::M4ADecoder(const std::string &filePath)
{
    inputFile.open(filePath, std::ios::binary);
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Failed to open M4A file.");
    }
}

M4ADecoder::~M4ADecoder()
{
    if (inputFile.is_open())
    {
        inputFile.close();
    }
    
}

void M4ADecoder::decode()
{
    while (readNextAtom())
    {
        if (isAtmonValid(currentAtom))
        {
            processAtom(currentAtom);
        }
        else
        {
            std::cerr << "Invalid atom detected. Skipping..." << std::endl;
        }
        
    }
    
}

bool M4ADecoder::readNextAtom()
{
    constexpr size_t atomSize = 8;
    currentAtom.resize(atomSize);

    inputFile.read(reinterpret_cast<char*>(currentAtom.data()), atomSize);
    return inputFile.gcount() == atomSize;
}

bool M4ADecoder::isAtmonValid(const std::vector<uint8_t> &atom)
{
    return atom.size() >= 4 &&
    (atom[4] == 'f' && atom[5] == 't' && atom[6] == 'y' && atom[7] == 'p');
}

void M4ADecoder::processAtom(const std::vector<uint8_t> &atom)
{
    std::cout << "Processing M4A atom..." << std::endl;
}
