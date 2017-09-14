#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


// Structure of each line in the file looks like this.
// 00000000  ff b8 0c ac 03 8f 72 72  20 54 72 68 65 20 49 42  |......rr Trhe IB|
// 00000010  4d 20 50 65 72 73 6f 6e  61 6c 20 43 6f 6d 70 75  |M Personal Compu|

struct Nibble {
  char data[2];
};

struct SplitString {
  // Here's a structure for all the data.
  char memoryAddress[8];
  vector<Nibble> hexBuffer;
  char readable[18];
};

int main () {

  char * splitString;
  char * line;
  
  // Create an output file.
  
  // Read the text file.
  ifstream inputFile;
  inputFile.open("music.hex");
  
  if (inputFile.is_open())
  {
    while (inputFile.getline(line, 500))
    {
      // Define new structure.
      SplitString *newString = new SplitString();
      
      // Tokenise the string.
      splitString = strtok(line, " ");
      
      int index = 0;
      // Create the structure.
      while (splitString != NULL) {
        // Memory address.
        if (index == 0) {
          strncpy(newString -> memoryAddress, splitString, 8);
        }
        
        // Instruction.
        if (index >=1 && index <=16) {
          Nibble instructionNibble;
          strncpy(instructionNibble.data, splitString, 2);
          (newString -> hexBuffer).push_back(instructionNibble);
        }
        
        // Ignore the readables for now.
                              index ++;
        cout << splitString << endl;
        splitString = strtok(NULL, " ");
      }
    }
    
    inputFile.close();
    
  } else {
    cout << "Unable to open the file";
  }
  
  return 0;
}
