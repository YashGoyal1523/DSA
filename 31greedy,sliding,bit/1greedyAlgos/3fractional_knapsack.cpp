//fractional knapsack

//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item here. 


// The greedy approach selects the item with the highest value/weight ratio first, then the next highest, and so on. If you can't take the full item (because of weight limits), take as much as possible (fractional part).

//algo
// Compute the value-to-weight ratio  for each item.
// Sort items in decreasing order of this ratio.
// Add items to the knapsack in this order until the knapsack is full (or the items are exhausted).
// If adding a full item would exceed the capacity, take the fractional amount that fits.

// method - sabki  per unit wt value nikal lo fir max wale se bharna shuru ho jao...agar capacity uske wt se kam h toh capacity jitna bhardo ...->capactity 0-> khatm kro ...vrna agar cap equal h toh sara bhardo ->capactity 0 -> khatm kro ....vrna agar zyada h toh saara bhardo fir next par jao and remaining cap ke saath same repeat kro....ese krte jao till capacity khatm hojaye ya wts khatm hojaye


#include<iostream>
#include<queue>
using namespace std ;


int fractionalKnapsack(vector<int> val, vector<int> wt, int n, int capacity) {
	vector<float> valWtRatio;
	for(int i=0; i<n; i++) {
		float ratio  = (val[i] * 1.0) / wt[i];      // 1.0 se multiply kiya h taaki typecast hojaye to float  as float m ho skti ratio and int/int will give float , float/int will give float
		valWtRatio.push_back(ratio);
	}

	priority_queue<pair<float,pair<int,int> > > maxi;
	for(int i=0; i<n; i++) {
		maxi.push(make_pair(valWtRatio[i], make_pair(val[i], wt[i] ) ) ); 
	}
	//max heap is ready 
	int totalVal = 0;
	while( !maxi.empty() ) {
		auto front = maxi.top();
		float ratio = front.first;
		int value = front.second.first;
		int weight = front.second.second;
		maxi.pop();
		
		if(capacity > weight) { //fulll insert hoga
			totalVal += value;
			capacity = capacity - weight;
		}
		else if(capacity==weight){
			// full insert
			totalVal += value;
			capacity=0;
			// capacity khatm rukjao
			break;

		}
		else { // capacity<weight
			//fractional insert hoga
			int valueToInclude = ratio * capacity;
			totalVal += valueToInclude;
			capacity=0;
			// capacity khatm rukjao
			 break;  
		}
	}
	return totalVal;
}

int main()
{
    vector<int> val ;
    val.push_back(60);
    val.push_back(100);
	vector<int> wt;
    wt.push_back(10);
    wt.push_back(20);
	int n = 2;
	int W = 50;
	int ans = fractionalKnapsack(val,wt,n,W);
	cout << "Final Ans: " << ans << endl;
return 0;
}