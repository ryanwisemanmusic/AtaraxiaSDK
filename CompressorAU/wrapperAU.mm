#import <AudioToolbox/AudioToolbox.h>
#import "compressor.h"

@interface AUCompressor : AUAudioUnit 
{
    Compressor compressor;
}

- (void)processAudioBuffer:(AudioBufferList *)bufferList frameCount:(UInt32)frameCount;
@end

@implementation AUCompressor

- (instancetype)init 
{
    self = [super init];
    if (self) 
    {
        compressor = Compressor(-20.0f, 4.0f, 5.0f, 50.0f, 44100.0f);
    }
    return self;
}

- (void)processAudioBuffer:(AudioBufferList *)bufferList frameCount:(UInt32)frameCount 
{
    for (UInt32 i = 0; i < bufferList->mNumberBuffers; i++) 
    {
        float* buffer = (float*)bufferList->mBuffers[i].mData;
        compressor.process(buffer, frameCount);
    }
}
@end