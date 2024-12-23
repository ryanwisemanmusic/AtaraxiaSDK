#import <Foundation/Foundation.h>
#include "AudioProcessing.objc.hpp"
#include "m4aPassThrough.hpp"

// This function will be called by the larger project
void processAudioInObjCPlusPlus() {
    NSLog(@"Processing audio with Objective-C++ logic...");

    std::string audioFilePath = "resources/audio/mp3audio/Model (14edo)";
    AudioProcessing audioProcessor;
    audioProcessor.loadAudioFile(audioFilePath);
    audioProcessor.playAudio();
}
