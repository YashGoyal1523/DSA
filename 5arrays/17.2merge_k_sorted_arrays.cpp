// given k sorted arrays ,merge into one sorted array 
// arrays ka size can be diff 

// jse two sorted arrays merge mein  krte ...two pointer method ...starting se shuru hoke dono ka element compare...jo chote voh wala daalke ...usme aage bhadado... vsa sa hi krega 

// sabke starting element se shuru hojao ....sab ka element compare kro .....jo chota voh ans mein daaldo and usme aage bhado.....ese ese

// sab arrays ke first element ka min heap(min priority queue) banado ....ab heap se element uthao ans array m daalo ....and jis array m se ans nikla uska agla (if exist) heap m daaldo.....repeat jabtak heap is not empty
// yeh next element pata krne k liye 
// hum heap m element ka index bhi daalege saath mein
// toh iss index se ...nexxt element ka index pata chaljayega and access kr paaege usse

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class compare {
  public:
    bool operator()(vector<int> a, vector<int> b) {
      return a[0] > b[0];   // min heap k liye > lagega
    } 
};

void mergeKSortedArrays(vector<vector<int> >arr, int k , vector<int> &ans) {
    // min heap
    priority_queue<vector<int>, vector<vector<int> >, compare> pq;        

    // first elements daaldo
    for(int row = 0; row < k; row++) {
      int element = arr[row][0];
      //vector<int> temp = {element, row, 0};
      vector<int> temp(3);
      temp[0] = element;
      temp[1] = row;
      temp[2] = 0;
      pq.push(temp);
    }

    while(!pq.empty()) {
      vector<int> temp = pq.top();
      pq.pop();
      int topData = temp[0];
      int topRow = temp[1];
      int topCol = temp[2];

      // Store in ans vector
      ans.push_back(topData);

      //push Next element for the same row of min wala , if available
      if(topCol + 1 < arr[topRow].size()) { //iska matlab row me or element abhi present hai
       // vector<int> newInfo = {arr[topRow][topCol+1], topRow, topCol+1};
       vector<int> newInfo(3);
       newInfo[0]= arr[topRow][topCol+1];
       newInfo[1]=  topRow;
       newInfo[2]= topCol+1;
        pq.push(newInfo);
      }
    }
}

int main() {
  // vector<vector<int> >arr= {
  //               {1,4,8},
  //               {2,3,6},
  //               {5,7}
  // };


vector<int>v1;
v1.push_back(1);
v1.push_back(4);
v1.push_back(8);
vector<int>v2;
v2.push_back(2);
v2.push_back(3);
v2.push_back(6);
vector<int>v3;
v3.push_back(5);
v3.push_back(7);


vector<vector<int> >arr;
arr.push_back(v1);
arr.push_back(v2);
arr.push_back(v3);

 
  int k = 3;

  vector<int> ans;
  mergeKSortedArrays(arr, k, ans);

  cout << "Printing Ans array: " << endl;
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
