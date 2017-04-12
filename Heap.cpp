  //Heap.cpp by Ke Shen... only slightly late this time
  //An implementation of a max heap that can store numbers
  //read in from a file or typed in by the user. Also displays the Heap visually
  #include <iostream>
  #include <fstream>
  #include <string>
  #include <string.h>
  using namespace std;

  void insert(int heap[], int arrayLength, int number);
  int parent(int n);
  void printTree(int arrayLength, int heap[]);
  void removeNode(int &arraySize, int array[100]);

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
    char* contents = new char[201];


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
      infile.getline(contents, 1000, '\n');
    }
    //manually reads in the numbers
    else if(!strcmp("MANUAL", input)) {
      cout << "Enter in the numbers, space-separated." << endl;
      cin.ignore();
      cin.getline(contents, 201);

    }
    int contentsLength = strlen(contents);
    //index: a counter to track where to put the characters into the int array
    int index = -1;
    for(int i = 0; i < contentsLength, contents[i] != '\0'; i++) {
        int temp = 0;
        int multiplier = 1;
        int* digits = new int[10];
        int whichdigit = 9;
        //sets all values to -1 for later use
        for(int k = 0; k < 10; k++) {
          digits[k] = -1;
        }
        while(contents[i] != ' ' && contents[i] != 13 && i < contentsLength) {
            digits[whichdigit] = contents[i] - '0';
          //  cout << "copied in" << digits[whichdigit] << endl;
            whichdigit--;
            i++;
        }
      //  cout << "Printing digits" << endl;
        whichdigit++;
        while(digits[whichdigit] != -1 && whichdigit <= 9) {
          temp += multiplier * digits[whichdigit];
          multiplier *= 10;
          whichdigit++;
        }
    //    cout << "Added value: "  << temp << endl;
        index++;
        array[index] = temp;
    }

    cout << endl;
    int arrayLength = 0;
    //iterates through the integer array and inserts things into the heaparray
    for(int b = 0; b <= index; b++) {
      insert(heap, arrayLength, array[b]);
      arrayLength++;
    }
    printTree(arrayLength, heap);
    cout << "Printing out heap..." << endl;
    removeNode(arrayLength, heap);
    return 0;
}
//inserts a integer into the array, maintaining heap
void insert(int heap[], int arrayLength, int number) {
//  cout << "Inserting.. " << number << endl;
  int n = arrayLength;
  heap[n] = number;
  while(!n <=0 && heap[n] > heap[parent(n)]){
  //  cout << "Swapping: " << heap[n] << " and" << heap[parent(n)]<< endl;
    int temp = heap[n];
    heap[n] = heap[parent(n)];
    heap[parent(n)] = temp;
    n = parent(n);
  }
  //  cout << "\nPrinting array directly" << endl;

}

//removes the root node of the max heap (it is at array index 0)
//And also reorders the reset of the array to retain heap status
void removeNode(int &arraySize, int array[100]) {

  if(arraySize == 0){
    return;
  }
  while(arraySize != 0){
    cout << array[0] << " " << flush;
    array[0] = array[arraySize - 1];
    arraySize--;
    int index = 0;
    int maxChild;
    int moveDown =1;
    while (moveDown ==1) {
      //Case: No Child
      if(2*index + 1 > arraySize - 1){
        maxChild = -1;
      }
      //Left Child
      else if(2*index + 1 <= arraySize - 1 && 2*index + 2 > arraySize - 1){
        maxChild = 2*index + 1;
      }
      //Left Child is larger
      else if(array[2*index + 1] >= array[2*index + 2]){
        maxChild = 2*index + 1;
      }
      //Right Child is larger
      else{
	maxChild = 2*index + 2;
      }
      //Switch with the larger child
      if(maxChild > 0 && array[index] < array[maxChild]){
	int temp = 0;
	temp = array[index];
	array[index] = array[maxChild];
	array[maxChild] = temp;
	index = maxChild;
      }
      else
	{ // it is larger than child, stop moveDown
	  moveDown =0;
	}
    }

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
