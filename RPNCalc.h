#include <iostream>
#include "GenStack.h"
using namespace std;

class RPNCalc
{
public:
  RPNCalc();
  ~RPNCalc();
  void pushToStack(int data);
  int stackSize();
  int calculate(string operation);
private:
  GenStack<int> operands;
};
