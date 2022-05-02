#ifndef HEADER_DEFAULT_AUDIO
#define HEADER_DEFAULT_AUDIO

#include <zombone_engine/Audio.hpp>

class DefaultAudio : public Audio {
 public:
  DefaultAudio();
  ~DefaultAudio();
  virtual void playSound(int i) override;
  virtual void playMusic() override;
  virtual void stopMusic() override;
};

#endif
