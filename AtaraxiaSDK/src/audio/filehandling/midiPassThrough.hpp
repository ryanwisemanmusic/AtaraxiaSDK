#ifndef MIDIPASSTHROUGH_HPP
#define MIDIPASSTHROUGH_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <string>

class MIDIDecoder 
{
    public:
    MIDIDecoder(const std::string& filePath);
    ~MIDIDecoder();

    void decode();

    private:
    std::ifstream inputFile;
    std::vector<uint8_t> currentChunk;

    bool readNextChunk();
    bool isChunkValid(const std::vector<uint8_t>& chunk);
    void processChunk(const std::vector<u_int8_t>& chunk);
};

#endif