#include <zombone_engine/AudioService.hpp>

#include <cstddef>

#include <zombone_engine/Audio.hpp>
#include <zombone_engine/DefaultAudio.hpp>

namespace zombone_engine {

Audio *AudioService::audio = NULL;

Audio &AudioService::getAudio() {
  if (audio == NULL) {
    audio = new DefaultAudio();
  }
  return *audio;
}

}  // namespace zombone_engine
