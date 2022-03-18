#ifndef HEADER_SDL2_AUDIO
#define HEADER_SDL2_AUDIO

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <Audio.hpp>
#include <string>
using namespace std;

class SDL2Audio : public Audio {
 public:
  SDL2Audio();
  ~SDL2Audio();
  virtual void playSound(int i) override;
  virtual void playMusic() override;
  virtual void stopMusic() override;

 private:
  void loadSounds();
  // The music that will be played
  Mix_Music *gMusic = NULL;

  // The sound effects that will be used
  Mix_Chunk *gSound[4];
  int soundFilesLength = 4;
  string soundFiles[4] = {"sounds/shoot.wav", "sounds/dud.wav",
                          "sounds/destroyed.wav", "sounds/batswoosh.wav"};
};

#endif
