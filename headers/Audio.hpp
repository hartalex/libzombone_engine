#ifndef HEADER_AUDIO
#define HEADER_AUDIO

export class Audio {
 public:
  virtual ~Audio();
  virtual void playSound(int i) = 0;
  virtual void playMusic() = 0;
  virtual void stopMusic() = 0;
  static int SOUND_SHOOT;
  static int SOUND_DUD;
  static int SOUND_DESTROYED;
  static int SOUND_BAT_SWOOSH;
};

#endif
