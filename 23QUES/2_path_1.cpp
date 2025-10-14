// shortest path from ancestor node to its child node

// ques will be of type - we will be given a ancestor node  of a binary tree as source and its any child node as destination (all nodes unique).we will have to return the path from source to destination in form of string consisting of only the uppercase letters 'L', 'R'. 'L' means to go from a node to its left child node.'R' means to go from a node to its right child node.

// note: koi bhi source ho (chahe root node ya bich m se koi) sabme same method lagega

// eg ques 
// given root node of a binary tree and a destination node (all nodes unique). return the path from root to destination in form of string consisting of only the uppercase letters 'L', 'R'. 'L' means to go from a node to its left child node.'R' means to go from a node to its right child node.

// ans link- https://youtu.be/tZ3tUOrB790?si=4eGFx9j5ojNqGdIc : iska subpart hai
#include<iostream>  
using namespace std ;

class node{           
  public:
	int data;
	node* left;
	node* right;

    // para ctor
	node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};


void findpath(node* node,int target,string &temp,string &path){   

    if(node==NULL) {
        return ;
    }
    if(node->data==target){
        path=temp ;
        return ; // yaha return likho ya nhi marzi h  ....likhne se thoda optimise krdia ki iss direction m toh ab aage na jaaye atleast kyuki task toh hogya h....nhi likhege toh bhi chalega hi 
    }

    temp.push_back('L');
    findpath(node->left,target,temp,path) ;
   temp.pop_back(); // backtrack 

    temp.push_back('R');
    findpath(node->right,target,temp,path) ;
    temp.pop_back(); // backtrack
                                   // note: kisi bhi direction m phle baad m jaa skte ie phle right m and baad m left m ya phle left and baad m right m jana ..kse bhi kr skte ie uper niche kisi ka bhi likh ke kr skte // note ya toh dono ke backtrack m pop krlo vrna sirf uper wale ke backtrack m pop krne se bhi chaljayega par note:  agar dono ke backtrack mein pop krege toh by val ya by ref dono chaljayega temp ka ...agar sirf uper wale ke ie jisme phle jaare uske backtrack m pop krre toh sirf temp  by val se chalega // preffered is dono m krke by ref lo as kam space lega fir by ref se  // path toh by ref hi lena pdega..... uska yeh backtrack wale se koi relation noi ....int main wale string m hi daalna seedha ans
    return;
}


int main()
{

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    node* src=root;
     int target=7;

     string temp;
    string path;

    findpath(src,target,temp,path);
 
    cout<<path<<endl;
   
return 0;
}

// note isme child node ki value di h...toh if condition m value hi compare kr skte ........agar pointer diya hota toh....chaho pointer compare krlo ya pointer use krke value compare marzi h

// note : agar ancestor se uske do child ka path krna hota....toh .....
// ya toh dono ka alag alag nikal lo uper wale se...dono ke liye alag alag call krlo
// agar dono ka ek saath ek hi call m nikalna ho fir uper wale m thoda modify krke krlo ...ese




// void findpath(node* node,int target1,int target2,string temp,string &path1,string &path2){

//     if(node==NULL) {
//         return ;
//     }
//     if(node->data==target1){
//         path1=temp ;
//                       // yaha return nhi kr skte as kya pata dusre wala isi direction m aage ho
//     }
//     if(node->data==target2){
//         path2=temp ;
//                       // yaha return nhi kr skte as kya pata dusre wala isi direction m aage ho
//     }

//     temp.push_back('L');
//     findpath(node->left,target1,target2,temp,path1,path2) ;
//     temp.pop_back();

//     temp.push_back('R');
//     findpath(node->right,target1,target2,temp,path1,path2) ;
//     temp.pop_back();

//     return;
// }


// int main()
// {

//     node* root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->left->left = new node(4);
//     root->left->right = new node(5);
//     root->right->left = new node(6);
//     root->right->right = new node(7);

//     node* src=root;
//      int target1=7;
//      int target2=5;

//      string temp;
//     string path1;
//     string path2;

//     findpath(src,target1,target2,temp,path1,path2);

//     cout<<path1<<endl;
//     cout<<path2<<endl;
   
// return 0;
// }