#ifndef HEADER_INPUT
#define HEADER_INPUT

namespace zombone_engine {

class Input {
 public:
  Input(char ch) : ch(ch){};
  char getInput() { return ch; };

 protected:
  char ch;
};

}  // namespace zombone_engine

#endif
