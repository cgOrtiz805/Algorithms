//% I collaborated with Andres Rios
#include<iostream>
#include <vector>
#include<map>
#include<queue>
#include<string>
using namespace std;

static char letterarray[]={'A','B','C','D','E','F'};

map<char, string>C;
struct  Node {
    char letter;
    double freq;
    Node* left;
    Node* right;

//Node * test;
};
struct comparenodes {

    bool operator()(Node* left, Node* right){



        //help from http://www.cplusplus.com/reference/algorithm/sort/ for the bool operator

        return (left->freq > right->freq);
    }
};

/*void getMin(deque<int> &v){
    return *min_element(v.begin(), v.end());
    */





priority_queue<Node *, vector<Node *>, comparenodes> Q;
//https://en.cppreference.com/w/cpp/container/priority_queue
//priority_queue <Type, vector<Type>, ComparisonType > min_heap;

Node* newnode(char letter, double freq){

    Node* newnode= new Node();
    newnode->freq=freq;
    newnode->letter=letter;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}
Node* empty(){
    Node* temp= new Node();

    temp->left=NULL;
    temp->right=NULL;
    temp->letter=NULL;
    temp->freq=NULL;
    return temp;
    //cout <<"test"
}

static void encoding(Node *Q, string enc, int i) {



    if (Q==NULL) {
        return;
    }

    if (Q->letter == letterarray[i]) {
        C.insert(make_pair (letterarray[i],enc));
    }
    if (Q->letter!= letterarray[i]){

    //cout<<"test";

    //cout<<letterarray[i];




    encoding(Q->left, enc + "0", i);
    //adds on to the string
    encoding(Q->right, enc + "1", i);
    }
}

void huffmantree(){

    //creates temprory nodes for new tree and childs
   Node *x= empty();

    Node *y= empty();

    Node *z=empty();

    for(int p=6; p!=1;p--){
        x = Q.top();

        //cout << "test";
        //gets new min
        Q.pop();
        //min element gets removed
        y = Q.top(); //puts y node onto top of the priorty queue
        Q.pop();
        z = newnode(' ', (x->freq + y->freq));
        // sum of node frequencys
        z->left = x;
        //left child equal x min
        z->right = y;
        //right child equal to y min

        Q.push(z);
        //cout<<"test";
    }
       for (int i = 0; i < 6; i++) {
            //cout<<"test";
        encoding(Q.top(), "",i);

        //cout<<Q.top;
    }
}


int main(){
    double freq;

    int x=0;
    while (x!=6){

        cin>>freq;
        if (x==0){

            Q.push(newnode('A', freq));
        }
        if (x==1){
            Q.push(newnode('B', freq));

        }
        if (x==2){
            Q.push(newnode('C', freq));

        }
        if (x==3){
            Q.push(newnode('D', freq));

        }
        if (x==4){
            Q.push(newnode('E', freq));

        }

        if (x==5){
            Q.push(newnode('F', freq));

        }

        x++;
    }
    huffmantree();

    map<char, string>::iterator it = C.begin();
    while(it != C.end()){
            cout<<it->first<<":"<<it->second<<std::endl;
    it++;
        }
}
