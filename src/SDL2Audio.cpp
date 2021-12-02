#include "SDL2Audio.hpp"
using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

SDL2Audio::SDL2Audio() {
  if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    std::exit(1);
  }
  // Initialize SDL_mixer
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
           Mix_GetError());
    std::exit(1);
  }

  // Load music
  gMusic = Mix_LoadMUS("sounds/Music.wav");
  if (gMusic == NULL) {
    printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
    std::exit(1);
  }
  loadSounds();
}

void SDL2Audio::loadSounds() {
  // Load sound effects
  for (int i = 0; i < soundFilesLength; i++) {
    gSound[i] = NULL;
    gSound[i] = Mix_LoadWAV(soundFiles[i].data());
    if (gSound[i] == NULL) {
      printf("Failed to load %s sound effect! SDL_mixer Error: %s\n",
             soundFiles[i].data(), Mix_GetError());
      std::exit(1);
    }
  }
}

SDL2Audio::~SDL2Audio() {
  // Free the sound effects
  for (int i = 0; i < soundFilesLength; i++) {
    Mix_FreeChunk(gSound[i]);
    gSound[i] = NULL;
  }

  // Free the music
  Mix_FreeMusic(gMusic);
  gMusic = NULL;

  // Quit SDL subsystems
  Mix_Quit();
  SDL_Quit();
}
void SDL2Audio::playSound(int i) { Mix_PlayChannel(-1, gSound[i], 0); }

void SDL2Audio::playMusic() {
  // Play the music
  Mix_PlayMusic(gMusic, -1);
}
void SDL2Audio::stopMusic() { Mix_PauseMusic(); }
