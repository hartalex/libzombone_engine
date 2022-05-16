#ifndef HEADER_AUDIO_SERVICE
#define HEADER_AUDIO_SERVICE

#include "zombone_engine/Audio.hpp"

namespace zombone_engine {

class AudioService {
 public:
  static Audio &getAudio();

 private:
  static Audio *audio;
};

}  // namespace zombone_engine

#endif
