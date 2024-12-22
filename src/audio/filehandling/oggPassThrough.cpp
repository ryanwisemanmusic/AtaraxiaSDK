#include "oggPassThrough.hpp"

OGGDecoder::OGGDecoder(const std::string &filePath)
{
    inputFile.open(filePath, std::ios::binary);
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Failed to open OGG file.");
    }
    
}

OGGDecoder::~OGGDecoder()
{
    if (inputFile.is_open())
    {
        inputFile.close();
    }
    
}

void OGGDecoder::decode()
{
    while (readNextPage())
    {
        if (isPageValid(currentPage))
        {
            processPage(currentPage);
        }
        else
        {
            std::cerr << "Invalid page detected. Skipping..." << std::endl;
        }
        
    }
    
}

bool OGGDecoder::readNextPage()
{
    constexpr size_t pageSize = 512;
    currentPage.resize(pageSize);

    inputFile.read(reinterpret_cast<char*>(currentPage.data()), pageSize);
    return inputFile.gcount() > 0;
}

bool OGGDecoder::isPageValid(const std::vector<uint8_t> &page)
{
    return page.size() >= 4 &&
           page[0] == 'O' && page[1] == 'g' &&
           page[2] == 'g' && page[3] == 'S';
}

void OGGDecoder::processPage(const std::vector<uint8_t> &page)
{
    std::cout << "Processing OGG page..." << std::endl;
}
