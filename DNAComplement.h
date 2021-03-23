#include <iostream>
#include "GenStack.h"
using namespace std;

class DNAComplement
{
public:
  DNAComplement();
  ~DNAComplement();
  void inputSequence(string strand);
  string getComplement();
  string getReverseComplement();
private:
  GenStack<char> DNASequence;
};
