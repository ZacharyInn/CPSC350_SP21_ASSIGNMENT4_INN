#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include "FileProcessor.h"
#include "DNAComplement.h"
#include "GenStack.h"
using namespace std;

FileProcessor::FileProcessor()
{

}

FileProcessor::~FileProcessor()
{

}

void FileProcessor::processFile(string inputFile)
{
  string sequence;
  ifstream inputStream;
  ofstream outputStream;
  DNAComplement* dna = new DNAComplement();

  //opens the input file
  cout << "Opening " << inputFile << "." << endl;
  inputStream.open(inputFile);

  //opens the output file
  cout << "Opening dnaoutput.txt." << endl;
  outputStream.open("dnaoutput.txt");

  //checks if input file could not be opened
  if (!inputStream.is_open())
  {
    cout << "Could not open " << inputFile << "." << endl;
  }

  //checks if the output file could not be opened
  if (!outputStream.is_open())
  {
    cout << "Could not open dnaoutput.txt." << endl;
  }

  //as long as there is input from the input file, this loop will run
  while (!inputStream.eof())
  {
    //gets the whole line
    getline(inputStream, sequence);
    //inputs the whole sequence
    dna->inputSequence(sequence);
    outputStream << "Original Sequence: " << sequence << endl;
    //outputs the complement to the output file
    outputStream << "Complement: " << dna->getComplement() << endl;
    //since the stack is popped in getComplement() you have to input the sequence to the stack again
    dna->inputSequence(sequence);
    //outputs the reverse complement to the output file
    outputStream << "Reverse Complement: " << dna->getReverseComplement() << endl;
    outputStream << endl;
  }

  //deletes the DNAComplement object
  delete dna;
  //closes the input file
  inputStream.close();
  cout << inputFile << " was closed." << endl;
  //closes the output file
  outputStream.close();
  cout <<"dnaoutput.txt was closed." << endl;
}
