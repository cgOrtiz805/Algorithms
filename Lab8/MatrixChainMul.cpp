// % I collaborated with Andre Rios
#include <climits>

#include <iostream>
#include <deque>
using namespace std;


//used deque cause couldnt figure out how to pass the Parens
void Parens(deque<deque<int > >&s, int i, int j){

    if(i==j){
        cout <<"A"<<(i-1); //outputs which matrix is optimal
        return;
    }

    else


       cout<< "(";
                    Parens(s, i, s[i][j]);
                    Parens(s, s[i][j]+1, j);
        cout<<")";

}

void myMatrix(int p[], int n){

 n=n-1;
deque<deque<int> >s;
s.resize(n+1, deque<int>(n+1,0)); //matrix deque for S
int m[n+1][n+1]; //matrix table for m

int i,j;
for(int i=1; i <= n; i++ ){ //computes the minimum cost for chains of length 1

m[i][i]=0; //m matrix to 0 is min
}
// l is chain length
for(int l=2; l<=n; l++){ // uses recurrence to compute m matrix

    for(int i=1; i<=n-l+1; i++){ //
           int  j=i+l-1;

            m[i][j] = INT_MAX;

        for(int k=i; k<=j-1; k++){ //computes cost depended on table entries of m array

            int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; // matrix recursion

                if(q < m[i][j]){

                    m[i][j]=q;
                    s[i][j]=k;
                }
                //cout<<"poke";
        }

    }
}
//return m[1][n];

cout << m[1][n]<< endl;
Parens(s,1,n);
cout <<endl;

//cout<<"poke";
}



int main(){
//int matrix;
int length;
cin>>length;

int p[length+1];

for(int i =0; i <length+1; i++){
    cin>> p[i];
}


//cout <<"poke";
myMatrix(p, length+1);



}
