#include "compressor.hpp"

Compressor::Compressor(float t, float r, float a, float rel, float sr)
    : threshold(t), ratio(r), attack(a), release(rel), sampleRate(sr), envelope(0.0f) 
    {

    }

void Compressor::process(float* buffer, size_t numSamples) 
{
    float alphaAttack = exp(-1.0f / (attack * sampleRate / 0.001f));
    float alphaRelease = exp(-1.0f / (release * sampleRate / 0.001f));

    for (size_t i = 0; i < numSamples; ++i) 
    {
        float inputLevel = fabsf(buffer[i]);

        envelope = (inputLevel > envelope) ? 
                   (alphaAttack * (envelope - inputLevel) + inputLevel) : 
                   (alphaRelease * (envelope - inputLevel) + inputLevel);

        float gainReduction = computeGainReduction(envelope);
        buffer[i] *= gainReduction;
    }
}

float Compressor::computeGainReduction(float inputLevel) 
{
    if (inputLevel < threshold) return 1.0f; 
    
    float dBInput = 20.0f * log10f(inputLevel);
    float dBOutput = threshold + (dBInput - threshold) / ratio;
    float gainReduction = powf(10.0f, (dBOutput - dBInput) / 20.0f);
    
    return gainReduction;
}

void Compressor::setThreshold(float t) 
{ 
    threshold = t; 
}
void Compressor::setRatio(float r) 
{ 
    ratio = r; 
}
void Compressor::setAttack(float a) 
{ 
    attack = a; 
}
void Compressor::setRelease(float r) 
{ 
    release = r; 
}