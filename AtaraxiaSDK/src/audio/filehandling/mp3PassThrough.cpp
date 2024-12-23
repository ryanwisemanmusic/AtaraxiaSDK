#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include "mp3PassThrough.hpp"

MP3Decoder::MP3Decoder(const std::string &filePath)
{
    inputFile.open(filePath, std::ios::binary);
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Failed to open MP3 file.");
    }
    
}

MP3Decoder::~MP3Decoder()
{
    if (inputFile.is_open())
    {
        inputFile.close();
    }
}

void MP3Decoder::decode()
{
    while (readNextFrame())
    {
        if (isFrameValid(currentFrame))
        {
            decompressFrame(currentFrame);
        }
        else
        {
            std::cerr << "Invalid frame detected. Skipping..." << std::endl;
        }
        
    }
    
}

bool MP3Decoder::readNextFrame()
{
    constexpr size_t frameSize = 144;
    currentFrame.resize(frameSize);

    inputFile.read(reinterpret_cast<char*>(currentFrame.data()), frameSize);
    return inputFile.gcount() == frameSize;
}

bool MP3Decoder::isFrameValid(const std::vector<uint8_t> &frame)
{
    return frame.size() >=4 &&
    (frame[0] == 0xFF) && ((frame[1] & 0xE0) == 0xE0);
}

void MP3Decoder::decompressFrame(const std::vector<uint8_t> &frame)
{
    std::cout << "Decoding frame..." << std::endl;
}
