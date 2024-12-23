#ifndef WAVPASSTHROUGH_H
#define WAVPASSTHROUGH_H

#include <string>
#include <vector>

class wavPassThrough 
{
    public:
    wavPassThrough();
    ~wavPassThrough();

    bool loadWavFile(const std::string& filePath);

    bool saveWavFile(const std::string& filePath);

    const std::vector<int16_t>& getAudioData() const;
    int getSampleRate() const;
    int getNumChannels() const;

    private:

    struct WavHeader {
        char riff[4];
        int32_t overallSize;
        char wave[4];
        char fmt[4];
        int32_t fmtSize;
        int16_t audioFormat;
        int16_t numChannels;
        int32_t sampleRate;
        int32_t bitRate;
        int16_t blockAlign;
        int16_t bitsPerSample;
        char data[4];
        int32_t dataSize; 
    };

    WavHeader header;
    std::vector<int16_t> audioData;
};

#endif

