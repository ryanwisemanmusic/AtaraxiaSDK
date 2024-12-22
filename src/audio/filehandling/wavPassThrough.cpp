#include "wavPassThrough.hpp"
#include <fstream>
#include <iostream>

wavPassThrough::wavPassThrough() {
    // Initialize with default values
}

wavPassThrough::~wavPassThrough() {
    // Destructor (no special cleanup needed in this case)
}

bool wavPassThrough::loadWavFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open WAV file: " << filePath << std::endl;
        return false;
    }

    // Read WAV header
    file.read(reinterpret_cast<char*>(&header), sizeof(header));

    // Validate the header
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        std::cerr << "Invalid WAV file format." << std::endl;
        return false;
    }

    // Read audio data
    audioData.resize(header.dataSize / sizeof(int16_t));
    file.read(reinterpret_cast<char*>(audioData.data()), header.dataSize);
    
    file.close();
    return true;
}

bool wavPassThrough::saveWavFile(const std::string& filePath) {
    std::ofstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
        return false;
    }

    // Set the header information
    header.dataSize = audioData.size() * sizeof(int16_t);
    header.overallSize = header.dataSize + sizeof(WavHeader) - 8;

    // Write the WAV header
    file.write(reinterpret_cast<char*>(&header), sizeof(header));

    // Write the audio data
    file.write(reinterpret_cast<char*>(audioData.data()), header.dataSize);
    
    file.close();
    return true;
}

const std::vector<int16_t>& wavPassThrough::getAudioData() const {
    return audioData;
}

int wavPassThrough::getSampleRate() const {
    return header.sampleRate;
}

int wavPassThrough::getNumChannels() const {
    return header.numChannels;
}
