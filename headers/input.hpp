#ifndef HEADER_INPUT
#define HEADER_INPUT

class Input {
 public:
  Input(char ch) : ch(ch){};
  char getInput() { return ch; };

 protected:
  char ch;
};

#endif
