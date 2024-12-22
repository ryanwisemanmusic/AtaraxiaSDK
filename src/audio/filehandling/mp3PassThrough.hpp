#ifndef MP3PASSTHROUGH_HPP
#define MP3PASSTHROUGH_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

#endif

class MP3Decoder 
{
    public:
    MP3Decoder(const std::string& filePath);
    ~MP3Decoder();
    void decode();

    private:
    std::ifstream inputFile;
    std::vector<uint8_t> currentFrame;
    bool readNextFrame();
    bool isFrameValid(const std::vector<uint8_t>& frame);
    void decompressFrame(const std::vector<uint8_t>& frame);

};