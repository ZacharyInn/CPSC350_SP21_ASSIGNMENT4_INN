#include <iostream>
#include <unistd.h>
#include "GenStack.h"
#include "RPNCalc.h"
#include "DNAComplement.h"
#include "FileProcessor.h"
using namespace std;

int main(int argc, char* argv[])
{
  if (argc == 2)
  {
    string mode = argv[1];
    if (mode == "RPN")
    {
      RPNCalc* newCalc = new RPNCalc();
      string equation;
      cout << "Enter your equation in postfix notation. Only use positive ints and include a space between each operand and operator." << endl;
      getline(cin, equation);
        string temp = "";
        //you look for spaces and then take a substring of before the space and see if its an operand or an operator.
        //this loops as long as there are spaces in the equation which is edited to remove an operand or operator after it is used
        //since at the very end there is no space, there is a call to the calculate method after this while loop
        while (equation.find(' ') != -1)
        {
          temp = equation.substr(0, equation.find(' '));
          if (temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == "%")
          {
            if (newCalc->stackSize() >= 2)
            {
              newCalc->calculate(temp);
            }
            else
            {
              cout << "Error: Invalid format." << endl;
              exit(0);
            }
          }
          else
          {
            newCalc->pushToStack(stoi(temp));
          }
            equation = equation.substr(equation.find(' ') + 1);
        }
        cout << "Answer: " << newCalc->calculate(equation) << endl;
    }
    else if (mode == "DNA")
    {
      FileProcessor* newFile = new FileProcessor();
      string inputFile;
      cout << "What is the name of the file that you want to input from?" << endl;
      getline(cin, inputFile);
      //this is my error checking to make sure that the file name is valid and ends in .txt
      bool incorrect = true;
      while (incorrect)
      {
        if (inputFile.length() < 5)
        {
          cout << "Enter a valid file name." << endl;
          getline(cin, inputFile);
        }
        else if (inputFile.substr(inputFile.length() - 4) != ".txt")
        {
          cout << "Enter a valid file name." << endl;
          getline(cin, inputFile);
        }
        else
        {
          incorrect = false;
        }
      }
      newFile->processFile(inputFile);
      return 0;
    }
    //these run if the command line arguments are not RPN or DNA
    else
    {
      cout << "Please enter a valid command line argument. Either \"RPN\" or \"DNA\"." << endl;
      return 0;
    }
  }
  else
  {
    cout << "Please enter only 1 command line argument. Either \"RPN\" or \"DNA\"." << endl;
    return 0;
  }
}
