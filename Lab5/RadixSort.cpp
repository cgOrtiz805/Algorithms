#include <iostream>
#include <deque>
// Collaboration With Andres Rios
//Some Assistance from Daniel Toriz, Pals Tutor Mark, and Alex Ortiz
// Deque Assistance from http://www.cplusplus.com/reference/deque/deque/

using namespace std;

int sizeArray;

void Combine(deque<int> A[], deque<int> B[]){
     for(int i=0; i < sizeArray; i++){
        A[i] = B[i]; //Makes the elements of the input array = to the outputs array
    }
//cout << "test";
}

    void Counting_Sort(deque<int> A[], deque<int> B[], int k){

    int C[10]; //Creates Count array with length 10

    for(int i =0; i < 10; i++){
        C[i]=0; // initilizes all count array elements to be 0

    }
    for(int j=0; j < sizeArray; j++){ //inspects each input element
        C[(A[j][k])] = C[A[j][k]]+1; //increments count array bases on # of repeating intigers

    }
    for(int i=1; i < 10; i++){ //determines for each i how many inputs are less than i
        C[i]=C[i]+C[i-1];  //keeps a running sum of C

    }
    for(int j= sizeArray-1; j>=0; j--){
        B[C[(A[j][k])]-1] = A[j]; //places each element of A[j] into sorted position onto B
        C[A[j][k]] = C[A[j][k]]-1; //Decrement C each time A element goes into B
    }
Combine(A, B);//Calls Combine

//cout << "test";
    }


void Radix_Sort(deque<int> A[],deque<int>B[]){

for(int k = 9; k >= 0; k--){ //uses k as index to sort through combines A and B arrays
    Counting_Sort(A, B, k); //based on significant digit
        // cout <<"test";
            }
        }

int main(){
int input;
cin >> sizeArray; //takes in size of array


 deque<int>A[sizeArray]; //deque A takes in inputs size
deque<int>B[sizeArray]; //deque B to also take in the input size

for (int i = 0; i < sizeArray; i++){
for(int j = 0; j < 10; j++){ // takes in rows/columns input
cin >> input; //takes in the input
A[i].push_back(input); // adds input elements into the A deque
        }
  }
Radix_Sort(A,B); //calls Radix Sort

 for(int i=0; i < sizeArray; i++){
        for(int j=0; j < B[i].size(); j++){//iterates throught output deque

//cout << "test";
    cout <<B[i][j] << ";"; //output array
      }

cout<<endl;

        }

 // cout << endl;
}
 // }

