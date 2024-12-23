#ifndef AUDIO_PROCESSING_HPP
#define AUDIO_PROCESSING_HPP

#include <string>

class AudioProcessing {
    public:
    void loadAudioFile(const std::string& path);
    void playAudio();
};

#endif