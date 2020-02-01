
#include <iostream>
#include <list>
using namespace std;
//*************************Collaboration With Andres Rios***************8
// List assistance from http://www.cplusplus.com/reference/list/list/

int total;//allocated size of the table

void Hash_Insert(list<int>T[], int key){ // takes value and inserts into hash table
int i=0;


        int j =key%total; //hashing function
        list<int> :: iterator it; // creates a bidirectional iterator named it to allow for manipulation of the hash table(list)
    T[j].push_front(key); //inserts the inputed value to the front of the list
        //cout<<"test";

}


void Hash_Search(list<int>T[], int key){ //key probes the table for slots that host a element
int i=0;
int j =key%total; //initializes hash function with modulo
bool k;// created bool statement to maintain search logic
 list<int> :: iterator it; //creates a bidirectional iterator named it to allow for manipulation of the hash table(list)

 for(it = T[j].begin(); it !=T[j].end(); ++it){//loop for the itterator poiting to begging and end of the list
//cout <<"It Test";
 //while(i!=m || *it!=NULL){
        if(*it==key){//if element is list is the same inputed key value then true

    cout << key<< ":FOUND_AT"<<j<<","<<i<<";"<<endl; //Output format
    //cout <<"Test";
 k=true; //keeps function running until we cant find a value making it not true
}
i++; //itereate through slots
//}
 }
if(!k){ //boolean statement if a number is not found making k = true false
    cout <<key<< ":NOT_FOUND;"<<endl; // output format if element is not found
// cout<<"Test";
}

}

void Hash_Delete(list<int>T[], int key){ //almost the same as our search function but when it finds the value it deletes it
int i=0;//initlizae slot value
int j =key%total; // initialize slot value
bool k=false;// set bool lofic for running the function
 list<int> :: iterator it;//creates a bidirectional iterator named it to allow for manipulation of the hash table(list)

 for(it = T[j].begin(); it !=T[j].end(); ++it){//loop for the itterator poiting to begging and end of the list
//cout<<"test *it";
 //while(i!=m || *it!=NULL){
        if(*it==key){ //like the seach function will check if the inserted function is the same as hashed function represented by *it
        T[i].erase(it);// We then use the list library delete function to delete the found value
    cout << key<< ":DELETED;"<<endl;
    //cout<<"test";
 k=true;// lets program to run aslong as function is true by way of elements being able to be deleted from table
 break;//ends initial function run to keep it from deleting more than one value in the list.
}
i++; //cout<<i<<endl;
//}
 }
if(!k){//delete logic failed same as search logic
    cout <<key<< ":DELETE_FAILED;"<<endl;
    //cout<<"test";
}

}

void Print(list<int>T[]){ //function allows us to view all elements that hace been hashed into the hashtable(list)
list<int> ::iterator it;//creates a bidirectional iterator named it to allow for manipulation of the hash table(list)
for(int i=0; i<total; i++){ //loops through slots of total indexed at i
        cout << i<< ":"; //cout<<"test";
    for(it = T[i].begin(); it != T[i].end(); ++it){ //loops through table itself
        cout <<*it<< "->";
        //cout<<"test" *it;
    }
cout <<";" << endl;
}

}



int main(){

int key; //inputs to be hashed
char input; // char to determine what function to run
//cout <<endl;
cin>>total; // takes in the total size of the hash table
list<int>T[total]; //creates a double linked list with use of List library named T

while(total!=0){ // terminates if input is 0 self and program cant run
cin >> input; //takes in character to determine funtction call

if(input == 'i'){ //Lab fprmat i before the key input means we Insert with Insert Fucntion
        cin >>key;
        Hash_Insert(T,key); //cout <<"test";
}
if(input == 's'){ // format if s before the key with search for inputed key with Search function
        cin>>key;
        Hash_Search(T,key); //cout <<"test";
}
if(input== 'd'){ // format if d before the key we like search prob for element in list and then delete it with Delete function
    cin >> key;
        Hash_Delete(T,key);//cout <<"test";
}
if(input == 'o'){ // //fomating if o it will show the current list with the Print function
        Print(T);//cout <<"test";
}
if(input=='e'){//formating if e it will terminate the program
        break;//cout <<"test";
}

}

return 0;
}








