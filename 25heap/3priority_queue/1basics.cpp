 // priority queue replicates heap properties  

 // gives max/min element in o(1)


#include<iostream>     
#include<queue>  // include this for priority queue
using namespace std ;
int main()
{

//syntax

//priority_queue<T,Container,Compare> name ;  

//T: Represents the type of elements stored in the priority queue.
//Container: Represents the type of underlying container used to store the elements. if we not define then  By default, std::vector<T> is used.
//Compare: Represents the type of comparison function object used to order the elements.if we not define then By default, std::less<T> is used, which orders the elements in descending order (i.e., highest priority element at the top). You can provide a custom comparison function or use std::greater<T> for ascending order (i.e., lowest priority element at the top). 

// note:
// <T>  : valid
// <T,container> : valid 
// <T,compare> : invalid
// <T,Container,Compare> : valid 
// agar compare use kroge toh container specify use krna necessary h
// agar container use kroge toh compare specify use krna necessary h

// Note that the Compare parameter is defined such that it returns true if its first argument comes before its second argument in a weak ordering. 
// in priority queue the elements that "come before" are actually output last. That is, the front of the queue contains the "last" element according to the weak ordering imposed by Compare.

 //max heap creation
priority_queue<int> pq; // by default its max priority queue
//insertion
pq.push(1);
pq.push(2);
pq.push(3);
pq.push(4);
pq.push(5);

// top element
cout<<pq.top()<<endl;

// deletion
pq.pop(); // will delete top element

cout<<pq.top()<<endl;

// size
cout<<pq.size()<<endl;

// empty 
if(pq.empty())
cout<<"empty"<<endl;
else cout<<"not"<<endl;




// min heap

priority_queue<int,vector<int>,greater<int> >pqq;  // > > space is neeeded // min priority queue
pqq.push(1);
pqq.push(2);
pqq.push(3);
pqq.push(4);
pqq.push(5);

cout<<pqq.top()<<endl;
return 0;
}



//custom comparator

// Note that the Compare parameter is defined such that it returns true if its first argument comes before its second argument in a weak ordering. 
// in priority queue the elements that "come before" are actually output last. That is, the front of the queue contains the "last" element according to the weak ordering imposed by Compare.
// a,b
// return a<b ->max heap
// return a>b ->min heap

//(ulta of custom comp logic of sort function)

//thoda syntax bhi alag h dekhlo...functor banate

//eg
// pair<char,int> 
//arrange in such a way that
//smaller char comes first and if char same then larger int comes first
#include<iostream>     
#include<queue>  // include this for priority queue
using namespace std ;
    struct comp{
        bool operator()(pair<char, int> &p1, pair<char, int>& p2){
            if(p1.first == p2.first) {
                return p1.second < p2.second;  // max heap
            }
            return p1.first > p2.first;   // min heap
        }
    };

    int main(){   
  priority_queue<pair<char,int>, vector<pair<char,int>>, comp> pq;
    }