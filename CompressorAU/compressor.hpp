
#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <cmath>
#include <vector>
#include <Accelerate/Accelerate.h>

class Compressor
{
    public:
        Compressor(float threshold = 
            -20.0f, float ratio = 4.0f, float attack_ms = 5.0f, 
            float release_ms = 50.0f, float sampleRate = 44100.0f);
        void process(float* buffer, size_t numSamples);

        void setThreshold(float t);
        void setRatio(float r);
        void setAttack(float a);
        void setRelease(float r);
        
        float getThreshold() const 
        { 
            return threshold; 
        }
        float getRatio() const 
        { 
            return ratio; 
        }
        float getAttack() const 
        { 
            return attack; 
        }
        float getRelease() const 
        { 
            return release; 
        }
        float getEnvelope() const 
        { 
            return envelope; 
        }
        
        // Make this public for UI visualization
        float computeGainReduction(float inputLevel);
    
    private:
        float threshold;
        float ratio;
        float attack;
        float release;
        float sampleRate;
        float envelope;
};

#endif
