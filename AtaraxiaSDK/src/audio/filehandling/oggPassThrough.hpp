#ifndef OGGPASSTHROUGH_HPP
#define OGGPASSTHROUGH_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <string>

class OGGDecoder 
{
    public:
    OGGDecoder(const std::string& filePath);
    ~OGGDecoder();

    void decode();

    private:
    std::ifstream inputFile;
    std::vector<uint8_t> currentPage;

    bool readNextPage();
    bool isPageValid(const std::vector<uint8_t>& page);
    void processPage(const std::vector<uint8_t>& page);

};
#endif