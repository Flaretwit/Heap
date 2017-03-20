//Heap.cpp by Ke Shen... only slightly late this time
//An implementation of a max heap that can store numbers
//read in from a file or typed in by the user. Also displays the Heap visually
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
/*
int main() {
    int sum = 0;
    int x;
    ifstream inFile;

    inFile.open("temp.txt");
    if (!inFile) {
        cout << "Unable to open file";
    }

    while (inFile >> x) {
        sum = sum + x;
    }

    inFile.close();
    cout << "Sum = " << sum << endl;
    return 0;
}
*/

void insert(int (*&x)[])

int main() {
  char* input = new char[80];
  cout << "This is heap." << endl;
  cout << "Are you entering numbers in manually or by filename? (MANUAL or FILENAME)?" << endl;
  cin >> input;
  //sets all to uppercase
  for(int i = 0; input[i] != '\0'; i++) {
    input[i] = toupper(input[i]);
  }
  int array[100] = {};
  for(int a = 0; a < 100; a++) {
    array[a] = 0;
  }
  cout << "printing stuff" << flush;
  for(int j = 0; j < 100; j++) {
    cout << array[j] << " " << flush;
  }
  char contents[201];
  int contentsLength = sizeof(contents)/sizeof(contents[0]);
  //reads in by filename
  if(!strcmp("FILENAME", input)) {
    //so it can hold up to 100 two digit numbers
    char filename[80];
    cout << "Enter in the filename (with suffix): " << endl;
    cin >> filename;
    ifstream infile(filename);
    //if unable to open the file
    if(!infile) {
        cout << "Unable to open the file ... exiting" << flush;
        return -1;
    }
    infile.getline(contents, contentsLength, '\n');
    cout << contents << flush;
  }
  else if(!strcmp("MANUAL", input)) {
    cout << "Enter in the numbers, space-separated." << endl;
    cin.getline(contents, contentsLength, '\n');
    cin.ignore();
  }
  //a counter to track where to put the charactesr into the int array
  int index = 0;
  for(int i = 0; i < contentsLength, contents[i] != '\0'; i++) {
      if(contents[i] != ' ' && contents[i] != 13) {
          array[index] = contents[i]-'0';
          index++;
      }
  }



  cout << "Printing out the integer array" << endl;
  //outputs the int array
  for(int j = 0; j < 100; j++) {
    cout << array[j] << " " << flush;
  }
  cout << endl;

  return 0;
}
