#include "AudioProcessing.hpp"
#import <Foundation/Foundation.h>

void processAudioInObjCPlusPlus()
{
    NSLog(@"Processing audio with Objective-C++ logic...");

    std::string audioFilePath = "resources/audio/mp3audio/Model (14edo)"
    AudioProcessing AudioProcessor;
    audioProcessor.loadAudioFile(audioFilePath);
    audioProcessor.playAudio();
}