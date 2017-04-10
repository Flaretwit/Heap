  //Heap.cpp by Ke Shen... only slightly late this time
  //An implementation of a max heap that can store numbers
  //read in from a file or typed in by the user. Also displays the Heap visually
  #include <iostream>
  #include <iomanip>
  #include <fstream>
  #include <string>
  #include <string.h>
  using namespace std;

  void insert(int heap[], int arrayLength, int number);
  int parent(int n);
  void printTree(int arrayLength, int heap[]);
  void removeNode(int arrayLength, int heap[]);

  int main() {
    char* input = new char[80];
    cout << "This is heap." << endl;
    cout << "Are you entering numbers in manually or by filename? (MANUAL or FILENAME)?" << endl;
    cin >> input;
    //sets all to uppercase
    for(int i = 0; input[i] != '\0'; i++) {
      input[i] = toupper(input[i]);
    }
    int array[100];
    int heap[100] = {};

    for(int a = 0; a < 100; a++) {
      array[a] = 0;
      heap[a] = 0;
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
    }

    //manually reads in the numbers
    else if(!strcmp("MANUAL", input)) {
      cout << "Enter in the numbers, space-separated." << endl;
      cin.getline(contents, contentsLength, '\n');
      cin.ignore();
    }
    //index: a counter to track where to put the characters into the int array
    int index = -1;
    cout << "Prinitng contents" << endl;
    for(int i = 0; i < contentsLength, contents[i] != '\0'; i++) {
        if(contents[i] != ' ' && contents[i] != 13) {
            index++;
            cout << contents[i] << " " << endl;
            array[index] = contents[i]-'0';

        }
    }
    cout << "Index: " << index << endl;
    for(int i = 0; i <= index; i++) {
        cout << "(" << array[i] << ")" << flush;
    }
    cout << endl;
    int arrayLength = 0;
    //iterates through the integer array and inserts things into the heaparray
    for(int b = 0; b <= index; b++) {
      insert(heap, arrayLength, array[b]);
      arrayLength++;
    }


    printTree(arrayLength, heap);
    removeNode(arrayLength, heap);
    return 0;
}
//inserts a integer into the array, maintaining heap
void insert(int heap[], int arrayLength, int number) {
  cout << "Inserting.. " << number << endl;
  int n = arrayLength;
  heap[n] = number;
  while(!n <=0 && heap[n] > heap[parent(n)]){
    cout << "Swapping: " << heap[n] << " and" << heap[parent(n)]<< endl;
    int temp = heap[n];
    heap[n] = heap[parent(n)];
    heap[parent(n)] = temp;
    n = parent(n);
  }
  cout << "\nPrinting array directly" << endl;
  for(int i = 0; i <= arrayLength; i++) {
    cout << heap[i] << " " << flush;
  }
  cout << endl;
}

//removes the root node of the max heap (it is at array index 0)
//And also reorders the reset of the array to retain heap status
void removeNode(int arrayLength, int heap[]) { //WHAT IF BOTH CHILDREN ARE THE SAME IN VALUE, shift right one up?
    cout << "Removing Nodes..." << endl;

    if(arrayLength == 0) {
      return;
    }
    bool finished = false;
    int index = 0;
    //iterates through updating the array to maintain heap
    while(!finished) {
      cout << heap[0] << " " << endl;
      if(2*index + 1 > arrayLength - 1) {
        break;
      }
      //if there is only a left child
      else if(2*index + 1 <= arrayLength - 1 && 2*index + 2 > arrayLength-1) {
        break;
      }
      //if the right child is greater than or equal to left
      //shifts the right child up to the top
      else if(heap[2*index+2] >= heap[2*index+1]) {
        heap[index] = heap[2*index+2];
        index = 2*index + 2;
      }
      //if left child is greater than right
      else if(heap[2*index+1] > heap[2*index+2]) {
        heap[index] = heap[2*index+1];
        index = 2*index + 1;
      }
      arrayLength--;
     }
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

//prints out the heap in the style of a tree
void printTree(int arrayLength, int heap[]){
  cout << "Printing Tree... " << endl;
  for (int i = 0; i < arrayLength; i++){
    // Whenever each level of the tree is filled, go to the next line
    if (i == 1 || i == 3 || i == 7 || i == 15 || i == 31 || i == 63){
      cout << endl;
    }
    cout << heap[i] << "  ";
  }
  cout << endl;
}
