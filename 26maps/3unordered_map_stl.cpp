#include<iostream>
#include<string>
#include<unordered_map>           // stores <key,value> pairs 
using namespace std ;
int main()
{
    // creation of map
    unordered_map<string,int >mapping;

    // insertion of key value pairs in map
    // we can use pair datastructure

    // 1.initialisation of pairs 
    //m1
    // pair<string,int>p=make_pair("love",25);
     pair<string,int>p;
    p=make_pair("love",25);
     //m2 // yeh yaha error de skta par shi h yeh method bhi
    // pair<string,int>m={"love",25};
    // //  pair<string,int>m;                           // note: pair m auto use nhi kar skte ie pair<auto,auto> not allowed . 
    // // m={"love",25};
    //  //m3
    pair<string,int>q("dipansh",24);             //  two values cant have same key
    //m4
    pair<string,int>r;
    r.first="arun";
    r.second=23;
    //2. insertion of pairs in map
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    
    // note:
    mapping.insert(make_pair("huehue",25));
    


    // size
    cout<<mapping.size()<<endl;

    // access value at key
    cout<<mapping["love"]<<endl;
    cout<<mapping.at("love")<<endl;

    mapping["love"]=10; // love key ki value changed to 10

  // note: jab bhi _[ ] wale se access krte hai tab agar voh key present hai toh value access hojata hai and present nhi ho toh key create hojati hai with value zero(default) ie new key value pair banjata map m

    cout<<mapping["goyal"]<<endl; // key not present toh new key goyal create hogyi with value 0(default) (new key value pair bangya map m)  ...and fir value print hogyi....

    //  (note: agar map m value 'char' type ki ho toh default value '\0' (null character) hogi)

    //note:
    mapping["yash"]=20; // phle key not present so key yash created hogyi with value 0(default) then immediately overwrite to 20 ...new key value pair bangya map m.....note: alter of insertion milgya.....ese directly hi key value pair bana skte 
    mapping["yash"]=23; // value changed to 23


    // search key      
    // __.find() fn : returns iterator (if iterator is on any value then present and if iterator at end after last value then not found)
    if(mapping.find("yash")!=mapping.end()){       // .begin():It is used to return an iterator referring to the first element in the map container....  .end():It is used to return an iterator referring to the past-the-end element in the map container.
        cout<<"found"<<endl;
    }
    else cout<<"not"<<endl;

    //count key
    //__.count() fn : returns count of occurrence of the given key in the map container
    // std::map() container does not store the duplicate values, so why map::count() is needed as we can already check the existence of an element in a map using std::find() or map::find() functions.
    // Other containers such as multimap may contain more than one copy of the key. So the reason is that the containers in C++ STL are required to implement the count() function is to help in generic programming.
    // Returns 1, if the key is present in the map container, as the key is always unique in the map.
    // Returns 0, if the key is not present in the map.
    //can be used as a find key
    cout<<mapping.count("yash")<<endl;

    //erase key
   // ___.erase()
   mapping.erase("yash");

//note:printing map
// m1
for(auto i: mapping){          // i represent map mapping ke key value pair  // auto ki jagah proper define krlo chahe ...pair<string,int> 
    cout<<i.first<<" ->"<<i.second<<endl;   // i.first represent key and i.second represent value of pair i
}
//m2
for(auto [a,b]: mapping){         // [a,b] : Structured binding declaration : unpacks the elements of the containers ie pairs of map directly into a and b with a representing key and b value   // auto hi use krte  with strucutred bindings
    cout<<a<<" ->"<<b<<endl;   
}                                  
//m3
for(auto it= mapping.begin();it!=mapping.end();it++){
    cout<<it->first<<" ->"<<it->second<<endl;
}



// note
 unordered_map<int, vector<int > > adj;
    vector<int>t(5,1);
    adj[0]=t;
    for(auto i:adj[0]){     // i represent map adj ke 0 key ki value ie vector t ie vector t ke elements
        cout<< i<<" , ";
    }

    // note
 unordered_map<int, vector<int > > adjj;
    vector<int>u(5,1);
    adjj[0]=u;
    for(auto i:adjj[1]){    // isme ab adjj[1] present nhi h toh isme yaha nhi hoga ese ki create hoke chalega loop....... create nhi hoga khudse ...loop chalega hi nhi

        cout<< i<<" , ";
    }                        

cout<<endl;

// note: 
    int b;
    unordered_map<int, int > a;
    if(a[0]!=1){      // yaha phle create hogya key 0 with value 0   ....uske ab ab if condition check hogi and accordingly chalega code
        b=1;
    }      
    cout<<b;   


// clear map 
    mapping.clear();   // Clears all key-value pairs from the map 

    
return 0;
}

// note: in case of vector - default value is- empty vector 

// note: 
// unordered_map<int, vector<int> > m ;

//vector<int>v;
// m[0]=v; // phle default vector assigned as value then overwrites the vector v to the key 0

// m[1].push_back(1); // phle default vector assigned as value then the vector is accessed and pushes the value 1 into this vector




// for more  refer to net 