#include <iostream>

using namespace std;
//*************ASSISTANCE WITH ANDRES RIOS**************************

int CUT_ROD(int arr[], int n){ //takes in array of prices and rod length

int r[n+1];
int s[n+1];

r[0]=0; // initializes elemtents of r array to be 0

for(int j=1; j <= n; j++){ //loops alsong as sub problem j doest exceed the rod length

    int q = 0;
    //int q = INT_MIN;
for(int i=1; i <= j; i++){

    if(q < arr[i] + r[j-i]){ // looks for the max value of q

        q = arr[i] + r[j-i]; //max value of q

        s[j]=i; // holds the optimal size of i of the first piece when solving for sub problem j


}

}
r[j]=q;// holds optimal size of q of the first piece when solving for sub problem j
}

cout<<r[n]<<endl; // outsputs maximum value

 while (n>0){ // if n is 0 then no revenue is possible
        cout<<s[n]<<" "; //prints out list of optimal first-piece size
        n= n-s[n]; // checks where the last cut took place
    }
      return -1;

}

int main(){
int total;
cin>>total; //takes in rod size
int arr[total+1]; // array for rod size
arr[0]=0; // sets elements to 0
    for(int i=1; i<total+1;i++){
        cin>>arr[i]; // takes in element inputs
    }
 int fin = CUT_ROD(arr, total); // places results cut rod into a varaible

 cout <<fin<<endl; //outputs calced values

return 0;
}

