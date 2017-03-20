//Heap.cpp
//An implementation of a max heap that can store numbers
//read in from a file or typed in by the user. Also displays the Heap
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <string.h>
using namespace std;

int main() {
  char* input = new char[80];
  cout << "Heap. " << endl;
  cout << "Are you entering numbers in manually or by filename? (MANUAL or FILENAME)?" << endl;
  cin >> input;
  //sets all to uppercase
  for(int i = 0; input[i] != '\0'; i++) {
    input[i] = toupper(input[i]);
  }
  int array[] = new int[100];

  //reads in by filename
  if(!strcmp("FILENAME", input)) {
    ifstream infile;
    //so it can hold up to 100 two digit numbers
    char* contents = new char[201];
    char* filename = new char[80];
    cout << "Enter in the filename (with suffix): " << endl;
    cin >> filename;
    infile.open(filename);
    infile.getline();

    cout << str << flush;
  }
  return 0;
}
