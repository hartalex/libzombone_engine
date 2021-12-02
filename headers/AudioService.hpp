#ifndef HEADER_AUDIO_SERVICE
#define HEADER_AUDIO_SERVICE

#include "Audio.hpp"

export class AudioService {
 public:
  static Audio &getAudio();

 private:
  static Audio *audio;
};
#endif
