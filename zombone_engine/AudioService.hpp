#ifndef HEADER_AUDIO_SERVICE
#define HEADER_AUDIO_SERVICE

#include "zombone_engine/Audio.hpp"

class AudioService {
 public:
  static Audio &getAudio();

 private:
  static Audio *audio;
};
#endif
