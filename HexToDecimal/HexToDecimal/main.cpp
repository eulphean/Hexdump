//  Author: Amay Kataria
//  Date: 09/13/2017
//  Description: This program reads a text file with an organized hexdump of
//  hexadecimal values and converts them into integers and stores them in a file.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// We are just reading regular hexadecimal value of that file's representation.

unsigned long hex2dec(string hex)
{
  unsigned long result = 0;
  for (int i=0; i<hex.length(); i++) {
    if (hex[i]>=48 && hex[i]<=57)
    {
      result += (hex[i]-48)*pow(16,hex.length()-i-1);
    } else if (hex[i]>=65 && hex[i]<=70) {
      result += (hex[i]-55)*pow(16,hex.length( )-i-1);
    } else if (hex[i]>=97 && hex[i]<=102) {
      result += (hex[i]-87)*pow(16,hex.length()-i-1);
    }
  }
  return result;
}

int main () {
  
  char hexValue[3];
  // Create an output file.
  ofstream outputFile;
  outputFile.open("music.dec");
  
  // Read the hex text file.
  ifstream inputFile;
  inputFile.open("music.txt");
  
  if (inputFile.is_open())
  {
    char prevHex[3];
    while (inputFile.getline(hexValue, 3))
    {
      long val;
      
      // Handle *.
      if (hexValue[0] == '*') {
        val = hex2dec(string(prevHex));
      } else {
        // Convert hex into.
        val = hex2dec(string(hexValue));
      }
      
      // Store the output in the file.
      outputFile << val << endl;
      
      // Maintain previous hex value for decoding a *.
      strncpy(prevHex, hexValue, 2);
    }
    cout << "Success! File was converted.";
    outputFile.close();
    inputFile.close();
    
  } else {
    cout << "Unable to open the file";
  }
  
  return 0;
}
