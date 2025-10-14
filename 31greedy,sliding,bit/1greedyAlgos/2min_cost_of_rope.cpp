// min cost of rope
//  There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths.
// The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 
 
 
 
 #include<iostream>
 #include<queue>
 using namespace std ;


int solve(int arr[], int n) {
	priority_queue<int,vector<int>, greater<int> > minHeap;
	//insert all elements
	for(int i=0; i<n; i++ ){
		int val = arr[i];
		minHeap.push(val);
	}
	int cost = 0;
	while(minHeap.size() > 1) {
		int a = minHeap.top();
		minHeap.pop();
		int b = minHeap.top();
		minHeap.pop();
		
		cost += a + b;
		int sum = a+ b;
		minHeap.push(sum);
	}
	return cost;
}

 int main()
 {

    int arr[] = {4,3,2,6};
int size = 4;
int ans = solve(arr,size);
cout << "Final Ans: "<< ans << endl;
 return 0;
 }


 // try ques huffman encoding ...(same tarika)