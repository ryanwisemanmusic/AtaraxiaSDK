#include "AudioProcessing.objc.hpp"
#include <iostream>

void AudioProcessing::loadAudioFile(const std::string& path) {
    std::cout << "Loading audio file: " << path << std::endl;
}

void AudioProcessing::playAudio() {
    std::cout << "Playing audio..." << std::endl;
}

