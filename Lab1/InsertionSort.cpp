
#include <iostream>

using namespace std;


void print(int arr[], int total){
    for(int a =0; a < total+1; a++){
            cout << arr[a]<<";";
    }
    cout << endl;
    }



void swap (int *i, int *j){
int temp=*i;
*i=*j;
*j=temp;
}

void insertionSort (int arr[], int total)
{
    int a, b;

    for(a=1; a<total; a++){
        b=a;
        while (b>0 && arr[b-1]>arr[b]){
            swap(arr[b], arr[b-1]);
            b--;

        }
print(arr,a);

    }

}

main(){
int total;
cin >> total;
int arr[total];
for(int a=0; a< total; a++ ){
    cin >> arr[a];
}
insertionSort(arr, total);

}







