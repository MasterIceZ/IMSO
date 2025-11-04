#include <string>

const int MxN = 1000010;

char s[MxN];
int len;

void Init() {
  len = 0;
}

void TypeLetter(char L) {
  s[len++] = L;
}

void UndoCommands(int U) {
  len -= U;
}

char GetLetter(int P) {
  return s[P];
}
