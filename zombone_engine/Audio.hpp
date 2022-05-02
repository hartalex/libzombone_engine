#ifndef HEADER_AUDIO
#define HEADER_AUDIO

class Audio {
 public:
  virtual ~Audio();
  virtual void playSound(int i) = 0;
  virtual void playMusic() = 0;
  virtual void stopMusic() = 0;
};

#endif
