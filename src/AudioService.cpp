#include "AudioService.hpp"

#include <cstddef>

#include "Audio.hpp"
#include "DefaultAudio.hpp"
#include "SDL2Audio.hpp"

Audio *AudioService::audio = NULL;

Audio &AudioService::getAudio() {
  if (audio == NULL) {
    audio = new DefaultAudio();
  }
  return *audio;
}
