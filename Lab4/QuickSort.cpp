
#include <iostream>
#include <cstdlib> //needed for rand function
using namespace std;

int Partition(int arr[], int low, int high){
int pivot = arr[high]; //always selects the highest element to be pivot but swapped with random element i
int i = low-1;

for (int j=low; j <= (high-1); j++){ //compares the lowest element j to the pivot element
    if(arr[j] <= pivot){ // when low is larger than the pivot increase i and swap with j until j = pivot
        i++;
    swap(arr[i],arr[j]);
    }
    }
    swap(arr[i+1],arr[high]); //when j = pivot move pivot to i the right if the i element.
    return i+1;

    }


int Random_Partition(int arr[], int low, int high){ //*******Collaboration With Andres Rios************

int i =(rand()% (high-low)) + low; // sets indexed element i to be the pivot at random
swap(arr[high],arr[i]); //exchange the last element with random element i for the the pivot

return Partition(arr, low, high);

}

void QuickSort (int arr[], int low, int high){
int mid;
if(low < high){ //divides array into two sub arrays

    mid= Random_Partition(arr, low, high); //rearranges array using a pivot element chosen at random

    QuickSort(arr, low, mid-1); //sorts left
    QuickSort(arr, mid+1, high); // sorts right
}               // for both sorts once mid is equal to the pivot element.
}


main(){

int total; // takes in variable for length of array

cin >> total; //user input array size

int arr[total]; // initialize variable

for(int i=0; i<total; i++){ //inputs elements into array

    cin >>arr[i];
}

QuickSort(arr, 0, total-1);

for(int i=0; i < total; i++){ //Outputs resulting array

    cout << arr[i] << ";";
}




}
