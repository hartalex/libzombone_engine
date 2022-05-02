#include "zombone_engine/AudioService.hpp"

#include <cstddef>

#include "zombone_engine/Audio.hpp"
#include "zombone_engine/DefaultAudio.hpp"

Audio *AudioService::audio = NULL;

Audio &AudioService::getAudio() {
  if (audio == NULL) {
    audio = new DefaultAudio();
  }
  return *audio;
}
