#include <iostream>

using namespace std;


/*void print(int arr[], int total){
    for (int k=0; k<total+1; k++){
        cout << arr[k]<< ";";
    }
cout << endl;

}
*/


void Merge (int arr[],int l, int m, int h){

int n1 = m-l+1;
int n2 = h-m;

int ltemp[n1];
int rtemp[n2];


for (int i=0; i < n1; i++ ){
        ltemp[i] = arr[l+i];
}
for (int j=0; j < n2; j++){
        rtemp[j]=arr[m+j+1];

}



int i=0;
int j=0;
int k=0;
for( k=l; i < n1 && j< n2; k++){
    if(ltemp[i]<rtemp[j]){
        arr[k] = ltemp[i++];

    }
    else{
            arr[k]=rtemp[j++];


    }


}

while (i < n1){
    arr[k++]=ltemp[i++];

}

while (j < n2){
    arr[k++]=rtemp[j++];
}


 }



void mergeSort(int arr[], int l, int h){
    int m;
    if (l <h ){
            m = (l+h)/2;

            mergeSort(arr,l,m);
            mergeSort(arr,m+1,h);
            Merge(arr,l,m,h);



    }



}
int main(){


    int total;
    cin >> total;
    int arr[total];



    for(int i=0; i<total; i++){
        cin>> arr[i];
    }

mergeSort(arr,0,total-1);
for (int i=0; i<total; i++){
        cout << arr[i]<< ";";
    }
}

