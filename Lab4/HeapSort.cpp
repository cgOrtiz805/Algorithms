
#include <iostream>

using namespace std;

// ************************************Assisted By Andres Rios *********************************************
        // Helped Define length and heap_size by defining in Function Parameters.

void Max_Heapify(int arr[],int length, int i){  // Lets Value for arr[i] step through the max-heap for sub tree i

int left = 2*i; // Left Child of Max Heap
int right = 2*i+1; // Right Child of Max Heap
int largest; //  Stores the largest largest element of Left or Right sub tree

if(left < length && arr[left] > arr[i]){ //checks if largest element in left
    largest = left;
}
else {
    largest = i; //if largest element cannot be compared then i element is the largest.
}
if(right < length && arr[right] > arr[largest]){//checks if largest element is in right
    largest = right;
}
if(largest != i){ //if largest in left or right swap indexed element with largest element
    swap(arr[i],arr[largest]);

    Max_Heapify(arr,length, largest);
}
}

void Build_Heap(int arr[], int length){
//int heap_size = length+1 moved to HeapSort
for(int i=length/2; i >= 0; i--){ //loops through each node of the tree and turns them into max heaps

    Max_Heapify(arr,length, i); //converts array into a max heap


}
}


void HeapSort(int arr[], int length){

int heap_size=length+1; //intializes the heapsize be length +1

Build_Heap(arr, length); //builds the initial max-heap

for(int i=length; i >= 1; i--){ //max elemenbt of array stored in correct position by swapping with elemented indexed at i
    swap(arr[0],arr[i]); //

heap_size--; // discard nodes by decrementing heapsize with is equal to length+1
   Max_Heapify(arr,heap_size, 0); //Restores Max- Heap
}
}


int main(){

int total; //initialize varable for arr size

cin >> total; // use enters array size

int arr[total]; // create array


for (int i =0; i < total; i++){ //stores #'s into array indexed at i

    cin >>arr[i];
}

HeapSort(arr, total-1); //Starts sorting

for(int i=0; i < total; i++){//Spits out sorted array
    cout << arr[i] << ";";
}

}
