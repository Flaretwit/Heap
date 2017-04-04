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

  void insert(int heap[], int lastindex, int number);
  int parent(int n);

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
    int heap[100];
    for(int a = 0; a < 100; a++) {
      array[a] = 0;
      heap[a] = 0;
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

    //manually reads in the numbers
    else if(!strcmp("MANUAL", input)) {
      cout << "Enter in the numbers, space-separated." << endl;
      cin.getline(contents, contentsLength, '\n');
      cin.ignore();
    }

    //a counter to track where to put the characters into the int array
    int index = 0;
    for(int i = 0; i < contentsLength, contents[i] != '\0'; i++) {
        if(contents[i] != ' ' && contents[i] != 13) {
            array[index] = contents[i]-'0';
            index++;
        }
    }

    int lastindex = 0;
    cout << "What is index" << index << flush;
    //iterates through the integer array and inserts things into the heaparray
    for(int b = 0; b <= index; b++) {
      insert(heap, lastindex, array[b]);
      ++lastindex;
    }

    cout << "\n Printing out the integer array" << endl;
    //outputs the int array
    for(int j = 0; j < 100; j++) {
      cout << heap[j] << " " << flush;
    }
    cout << endl;

    return 0;
}
//inserts a integer into the array, maintaining heap
void insert(int heap[], int lastindex, int number) {
  heap[lastindex] = number;
  cout << "Number: " << number << endl;
  int n = lastindex;
  while(n != 0 && heap[n] > heap[parent(n)]){
    cout << "swapped" << endl;
    int temp = heap[n];
    heap[n] = heap[parent(n)];
    heap[parent(n)] = temp;
    n = parent(n);
  }
  cout << "last index" << lastindex << endl;

  cout << "A[n] = " << heap[n] << ", A[parent(n)] = " << heap[parent(n)] << endl;

}
//calculates and returns the parent index of a node at index n
int parent(int n) {
  if(n % 2 == 0) {
    return ((n-2)/2);
  }
  else if(n % 2 == 1) {
    return ((n-1)/2);
  }
  return 0;
}

void printHeap(int heap[]) {

}

void removeNode() {
  
}
