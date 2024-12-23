#ifndef M4APASSTHROUGH_HPP
#define M4APASSTHROUGH_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

class M4ADecoder 
{
    public:
    M4ADecoder(const std::string& filePath);
    ~M4ADecoder();

    void decode();

    private:
    std::ifstream inputFile;
    std::vector<uint8_t> currentAtom;

    bool readNextAtom();
    bool isAtmonValid(const std::vector<uint8_t>& atom);
    void processAtom(const std::vector<uint8_t>& atom);
};