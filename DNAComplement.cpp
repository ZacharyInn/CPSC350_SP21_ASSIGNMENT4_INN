#include <iostream>
#include <string>
#include <cctype>
#include "DNAComplement.h"
#include "GenStack.h"
using namespace std;

DNAComplement::DNAComplement()
{

}

DNAComplement::~DNAComplement()
{

}

void DNAComplement::inputSequence(string strand)
{
  //puts the entire sequence into the stack
  for (int i = 0; i < strand.length(); i++)
  {
    DNASequence.push(strand.at(i));
  }
  //checks to make sure the the strand is in the correct format
  for (int i = 0; i < strand.length(); i++)
  {
    if (strand.at(i) != 'A' || strand.at(i) != 'T' || strand.at(i) != 'C' || strand.at(i) != 'G')
    {
      cout << "Invalid sequence." << endl;
      exit(0);
    }
  }
}

string DNAComplement::getComplement()
{
  //since stacks are LIFO, you have to reverse the order of the stack to get the complement
  string comp = "";
  int size = DNASequence.getSize();
  for (int i = 0; i < size; i++)
  {
    comp += DNASequence.pop();
  }
  string temp = "";
  for (int i = comp.length() - 1; i >= 0; i--)
  {
    temp += comp.at(i);
  }
  string final = "";
  //gets the complement for each nucleotide
  for (int i = 0; i < comp.length(); i++)
  {
    if (temp.at(i) == 'A')
    {
      final += "T";
    }
    else if (temp.at(i) == 'T')
    {
      final += "A";
    }
    else if (temp.at(i) == 'C')
    {
      final += "G";
    }
    else if (temp.at(i) == 'G')
    {
      final += "C";
    }
  }
  return final;
}

string DNAComplement::getReverseComplement()
{
  //since stacks are LIFO the reverse is easy and you just have to convert each nucleotide as it comes out of the stack
  string rComp = "";
  int size = DNASequence.getSize();
  for (int i = 0; i < size; i++)
  {
    rComp += DNASequence.pop();
  }
  string final = "";
  //conversion
  for (int i = 0; i < size; i++)
  {
    if (rComp.at(i) == 'A')
    {
      final += "T";
    }
    else if (rComp.at(i) == 'T')
    {
      final += "A";
    }
    else if (rComp.at(i) == 'C')
    {
      final += "G";
    }
    else if (rComp.at(i) == 'G')
    {
      final += "C";
    }
  }
  return final;
}
