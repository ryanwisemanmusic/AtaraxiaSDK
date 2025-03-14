/*
Author: Ryan Wiseman

This is a barebones approach to windowing via SDL3. Any
intenseive windowing required will require some major refactoring
*/

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>

/*Third party image library for SDL3*/
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
/*Header for SQLite, if you aren't using local
databases, this can be deleted.*/
#include <sqlite3.h>

//Debug headers
#include <unistd.h>
#include <stdio.h>

//Universal libraries
#include <iostream>
#include <array>
#include <stdexcept>

//App headers
#include "gameScores.h"
#include "SDLColors.h"
#include "screenScenes.h"
#include "videoRendering.h"

SDL_Window *window;
SDL_Renderer *renderer;
constexpr int ScreenWidth = 600;
constexpr int ScreenHeight = 600;

TTF_Font* font = nullptr;

extern "C" void cocoaBaseMenuBar();
extern "C" void openSDLWindowAboutMenu();

bool init();
bool initSDL_ttf();
void initMP4(const std::string &filename);
void render();
void renderText(const char* message, int x, int y, SDL_Color color);
SDL_Texture* getNextFrame(VideoState &video, SDL_Renderer* renderer);
void handleEvents(bool& done);
void close();

//External Calls
bool loadMP4(const std::string &filename, VideoState &video);
bool loadAudioFile(const std::string &filename);
void playAudio();
void playSFX();
bool testAudioPlayback();



int main(int argc, char* argv[]) {
    (void)argc; 
    (void)argv; 

    if (!init()) {
        SDL_Log("Unable to initialize program!\n");
        return 1;
    }
    
    // Add Cocoa base menu bar
    cocoaBaseMenuBar();

    bool done = false;

    // Main loop for window event handling
    while (!done) 
    {
        handleEvents(done);
        render();
        initSDL_ttf();
    }

    close();

    return 0;
}

bool init()
{
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow(
        "AtaraxiaSDK", ScreenWidth,
        ScreenHeight, SDL_WINDOW_OPENGL);
    
    if (window == NULL)
    {
        SDL_Log("Window can't be created! SDL error: %s\n",
        SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, 0);
    if (!renderer)
    {
        SDL_Log("Renderer could not be created! SDL error: %s\n",
        SDL_GetError());
        SDL_Quit();
        return false;
    }
    
    return true;
}

bool initSDL_ttf()
{
    if (!TTF_Init()) {
        SDL_Log("TTF_Init failed");
        return false;
    }

    std::string fontPath = "assets/fonts/ArianaVioleta.ttf";

    font = TTF_OpenFont(fontPath.c_str(), 20);
    if (!font) 
    {
        SDL_Log("Cannot load font");
        return false;
    }

    return true;
}

void initMP4(const std::string &filename)
{
    VideoState video;

    if (loadMP4(filename, video))
    {
        std::cout << "MP4 file loaded successfully: " << 
        filename << std::endl;
        std::cout << "Video Stream Index: " << 
        video.videoStream << std::endl;
        std::cout << "Codec: " << video.pCodec->name << std::endl;
        std::cout << "Resolution: " << video.pCodecCtx->width << 
        "x" << video.pCodecCtx->height << std::endl;
    }
    else
    {
        std::cerr << "Failed to load MP4 file: " << 
        filename << std::endl;
    }

    avcodec_free_context(&video.pCodecCtx);
    avformat_close_input(&video.pFormatCtx);
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer); 
    renderText("AtaraxiaSDK", 180, 250, cMagenta);
    SDL_RenderPresent(renderer);
}

void renderText(const char* message, int x, int y, SDL_Color color)
{
    
    TTF_Init();
    std::string fontPath = "assets/fonts/ArianaVioleta.ttf";

    font = TTF_OpenFont(fontPath.c_str(), 50);
    if (!font) 
    {
        SDL_Log("Cannot load font!");
    }
    size_t messageLength = strlen(message);

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, message, messageLength, color);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int textW = textSurface->w; 
    int textH = textSurface->h;
    SDL_DestroySurface(textSurface);

    if (!textTexture)
    {
        SDL_Log("Texture creation failed!");
        return;
    }

    SDL_FRect destRect = { static_cast<float>(x), static_cast<float>(y), 
                           static_cast<float>(textW), static_cast<float>(textH) };

    SDL_RenderTexture(renderer, textTexture, nullptr, &destRect);

    SDL_DestroyTexture(textTexture);
}

SDL_Texture* getNextFrame(VideoState &video, SDL_Renderer* renderer)
{
    AVPacket packet;
    AVFrame *frame = av_frame_alloc();

    while (av_read_frame(video.pFormatCtx, &packet) >= 0)
    {
        if (packet.stream_index == video.videoStream)
        {
            avcodec_send_packet(video.pCodecCtx, &packet);
            if (avcodec_receive_frame(video.pCodecCtx, frame) == 0)
            {
                // Allocate swsContext if needed
                if (!video.swsCtx)
                {
                    video.swsCtx = sws_getContext(
                        video.pCodecCtx->width, video.pCodecCtx->height,
                        video.pCodecCtx->pix_fmt,
                        video.pCodecCtx->width, video.pCodecCtx->height,
                        AV_PIX_FMT_RGB24,
                        SWS_BILINEAR, nullptr, nullptr, nullptr
                    );
                    if (!video.swsCtx)
                    {
                        std::cerr << "Failed to create SwsContext\n";
                        av_frame_free(&frame);
                        av_packet_unref(&packet);
                        return nullptr;
                    }
                }

                // Allocate frame buffer if needed
                if (!video.pFrameRGB)
                {
                    video.pFrameRGB = av_frame_alloc();
                    int numBytes = av_image_get_buffer_size(
                        AV_PIX_FMT_RGB24, video.pCodecCtx->width,
                        video.pCodecCtx->height, 1);
                    if (numBytes < 0)
                    {
                        std::cerr << "Failed to calculate buffer size\n";
                        av_frame_free(&frame);
                        av_packet_unref(&packet);
                        return nullptr;
                    }
                    video.buffer = (uint8_t*) av_malloc(numBytes * sizeof(uint8_t));
                    if (!video.buffer)
                    {
                        std::cerr << "Failed to allocate buffer\n";
                        av_frame_free(&frame);
                        av_packet_unref(&packet);
                        return nullptr;
                    }
                    av_image_fill_arrays(
                        video.pFrameRGB->data, video.pFrameRGB->linesize,
                        video.buffer, AV_PIX_FMT_RGB24,
                        video.pCodecCtx->width, video.pCodecCtx->height, 1
                    );
                }

                // Convert frame to RGB format
                int ret = sws_scale(
                    video.swsCtx, frame->data, frame->linesize,
                    0, video.pCodecCtx->height,
                    video.pFrameRGB->data, video.pFrameRGB->linesize
                );
                if (ret < 0)
                {
                    std::cerr << "sws_scale failed\n";
                    av_frame_free(&frame);
                    av_packet_unref(&packet);
                    return nullptr;
                }

                // Create SDL_Surface
                SDL_Surface* surface = SDL_CreateSurface(
                    video.pCodecCtx->width,
                    video.pCodecCtx->height,
                    SDL_PIXELFORMAT_RGB24
                );
                if (!surface)
                {
                    std::cerr << "Failed to create SDL surface: " << SDL_GetError() << std::endl;
                    av_frame_free(&frame);
                    av_packet_unref(&packet);
                    return nullptr;
                }

                // Copy pixel data line by line
                uint8_t* srcData = video.pFrameRGB->data[0];
                int srcPitch = video.pFrameRGB->linesize[0];
                uint8_t* dstData = (uint8_t*)surface->pixels;
                int dstPitch = surface->pitch;
                int height = video.pCodecCtx->height;
                int width = std::min(srcPitch, dstPitch); // Copy the minimum of both pitches

                for (int y = 0; y < height; y++)
                {
                    memcpy(dstData + y * dstPitch, srcData + y * srcPitch, width);
                }

                // Convert Surface to Texture
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_DestroySurface(surface);

                av_frame_free(&frame);
                av_packet_unref(&packet);

                return texture;
            }
        }
        av_packet_unref(&packet);
    }

    av_frame_free(&frame);
    return nullptr;
}

void handleEvents(bool& done)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            done = true;
        }
    }
}


void close()
{
    if (font)
    {
        TTF_CloseFont(font);
        font = nullptr;
    }
    
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}