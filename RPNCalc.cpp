#include <iostream>
#include <string>
#include <cctype>
#include "RPNCalc.h"
using namespace std;

RPNCalc::RPNCalc()
{

}

RPNCalc::~RPNCalc()
{

}

void RPNCalc::pushToStack(int data)
{
  operands.push(data);
}

int RPNCalc::stackSize()
{
  return operands.getSize();
}

int RPNCalc::calculate(string operation)
{
  //since stacks are LIFO, you have to instantiate op2 first then op1
  int op2 = operands.pop();
  int op1 = operands.pop();
  int result = 0;
  if (operation == "+")
  {
    result = op1 + op2;
    operands.push(result);
  }
  else if (operation == "-")
  {
    result = op1 - op2;
    operands.push(result);
  }
  else if (operation == "*")
  {
    result = op1 * op2;
    operands.push(result);
  }
  else if (operation == "/")
  {
    //making sure you dont divide by 0
    if (op2 == 0)
    {
      cout << "Error: Can not divide by 0." << endl;
      exit(0);
    }
    result = op1 / op2;
    operands.push(result);
  }
  else if (operation == "%")
  {
    result = op1 % op2;
    operands.push(result);
  }
  else
  {
    //if for some reason am unusual character or a number was taken as the parameter
    cout << "Error incorrect formatting." << endl;
    exit(0);
  }

  return result;
}
