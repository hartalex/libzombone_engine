#ifndef HEADER_AUDIO
#define HEADER_AUDIO

namespace zombone_engine {

class Audio {
 public:
  virtual ~Audio();
  virtual void playSound(int i) = 0;
  virtual void playMusic() = 0;
  virtual void stopMusic() = 0;
};

}  // namespace zombone_engine

#endif
