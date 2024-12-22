#include "midiPassThrough.hpp"

MIDIDecoder::MIDIDecoder(const std::string &filePath)
{
    inputFile.open(filePath, std::ios::binary);
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Failed to open MIDI file.");
    }
}

MIDIDecoder::~MIDIDecoder()
{
    if (inputFile.is_open())
    {
        inputFile.close();
    }
}

void MIDIDecoder::decode()
{
    while (readNextChunk())
    {
        if (isChunkValid(currentChunk))
        {
            processChunk(currentChunk);
        }
        else
        {
            std::cerr << "Invalid chunk detected. Skipping..." << std::endl;
        }
        
    }
    
}

bool MIDIDecoder::readNextChunk()
{
    constexpr size_t chunkSize = 14;
    currentChunk.resize(chunkSize);

    inputFile.read(reinterpret_cast<char*>(currentChunk.data()), chunkSize);
    return inputFile.gcount() == chunkSize;
}

bool MIDIDecoder::isChunkValid(const std::vector<uint8_t> &chunk)
{
    return chunk.size() >= 4 &&
    chunk[0] == 'M' && chunk[1] == 'T' && chunk[2] == 'h' && chunk[3] == 'd';
}

void MIDIDecoder::processChunk(const std::vector<u_int8_t> &chunk)
{
    std::cout << "Processing MIDI chunk..." << std::endl;
}
