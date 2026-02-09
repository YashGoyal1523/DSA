
#include<iostream>
#include<vector> // krni pdegi  // using STL
using namespace std ;


void print(vector<int>vec){        // v naam bhi rkh skte 

    int size=vec.size();   

    for (int i = 0; i < size; i++)
    {
       cout<<vec[i]<<" ";
    }
    
    return;        // size bhi pass kar hi skteee...yaha hum yeh func alag alag situations jab size kuch kuch hoga usme use krege isiliye toh baar baar size find krna na pade size ka bhi func ke andar hi daaldiya
}





int main()
{
    // declaration
vector<int>v; // int type name v ka vector 

// intitialise

v.push_back(1);  // phla  element is 1 
v.push_back(2);  // second  element is 2
v.push_back(3);  // third  element is 3
v.push_back(4);  // fourth  element is 4

// accessing elements : v[index] or v.at(index)  .... first ka index is zero and so on
v[0]=0; // first element is changed to 0

cout<<v.at(0)<<endl; // print first element of vector

// note: v[index] or v.at(index) can only be used when that index has been created that is uska dabba  ban chuka ho ...dabba banne ke baad we can use this to do all stuffs by accessing element at that index......we cant use this to give initial values

cout<<endl;

//finding size of vector
int size=v.size(); 
cout<<"size is "<<size<<endl;

// printing vector 

//     for (int i = 0; i < size; i++)
//     {
//        cout<<v[i]<<" ";
//     }

// lets make function to print 

print(v);       //  vector is passed by value unlike array which is passed by ref


cout<<endl;

// finding capacity
int capacity=v.capacity();

cout<<"capacity is "<<capacity;

cout<<endl;

// removing elements from back
// note removing elements only decreases size and not capacity......  elements remove hojayege par dabbe present hi hoge as it is 
 v.pop_back();  //element removing...... last ie fourth element is removed ....size becomes 3 cap is 4
 print(v);
 v.pop_back();//element removing......last ie third element is removed ...size becomes 2 cap is 4
  v.pop_back(); //element removing......last ie second element is removed ...size becomes 1 cap is 4
  v.pop_back(); 
int capacitynow=v.capacity();
int sizenow=v.size();
cout<<endl<<capacitynow<<sizenow<<endl;
 // so on..... note sab remove ke baad pop kroge toh error dikhaega 


//input elements
int n;
cout<<"enter no of elements";
cin>>n;
for (int i = 0; i < n; i++)
{   
    int d;
    cout<<"enter element";
    cin>>d;
    v.push_back(d);                    // more elements added to vector v  
}                          

print(v);

cout<<endl;
// inserting 5 more elements valued 1

// v.push_back(1);
// v.push_back(1);
// v.push_back(1);
// v.push_back(1);
// v.push_back(1);

//better
for (int i = 0; i < 5; i++)
{
    v.push_back(1);
}

print(v);


cout<<endl;


// clearing the vector
v.clear();     // saare elements remove hojate ie size zero hojata...capacity utni hi rhti



v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.push_back(6);


// erase() fn : used to delete an element from any position or elements from a range
// element: v.erase(position)   ,  range : v.erase(start pos,next to end pos)  
// note: positions are given in form of iterators ..use v.begin() , v.end()
// v.begin()  will give positioning (iterator) of first element ie index: 0
// v.end() will give positioning of next to last element 


// erasing xth element ie x-1 index wala ....use : v.erase(v.begin()+(x-1))
// erasing 3rd element ie 2nd index wla
v.erase(v.begin()+2);

// erasing range from xth element to yth element ie x-1 index se y-1 index tak ... use v.erase(v.begin()+(x-1),v.begin()+y)
// erasing 2nd to 4th element
v.erase(v.begin()+1,v.begin()+4);

// note erasing only reduces sizes and not capacity ...elements remove dabbes as it is rhe ...also  removed elements ke right wale leftwards shift hojate toh cover gaps
cout<<v.size()<<endl<<v.capacity()<<endl;
cout<<v[1]<<endl;

// to delete extra dabbas : shrink_to_fit() function :o(n) : reduces the capacity of the container to fit its size : extra dabbe delete krke capacity=size krdeta
// abhi v ka size 2 and cap 8 h
v.shrink_to_fit();  // ab cap bhi 2 hojayegi ...extra dabbe deleted
cout<<v.size()<<endl<<v.capacity()<<endl;


// to check vector is empty or not  // v.empty() : return true or false
bool flag=v.empty();   
cout<<v.empty()<<endl<<flag; 

// insert() fn : inserts the element before specified position // elements aage shift hojate and indexing adjust hojati
v.insert(v.begin(),1);  // inserts 1 shuru mein...initial wale aage shift hojayege yeh 0 index banjayega
v.insert(v.begin()+1,2);  // inserts 2 ..1 index wale ke phle....initial walw aage shift hojayege ..yeh 1 index banjayege


// swap two vectors: v1.swap(v2);  ; sab kuch swap hojata : v1 mein sabkuch v2 wala hojata and v2 mein sab v1 wala

// v.fill(begin,end,val) : The ‘fill’ function assigns the value ‘val’ to all the elements in the range [begin, end), where ‘begin’ is the initial position and ‘end’ is the last position.
return 0;
}


//sorting vector :
// sort(v.begin(),v.end()) : sorts in ascending order
// sort(v.begin(),v.end(),greater<int>()) : sorts in descending order
//or
// sort(rbegin(v),rend(v)) : sorts in descending order