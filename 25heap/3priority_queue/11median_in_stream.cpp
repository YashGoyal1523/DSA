// tip : 'stream' wale ques mein har instant ka ans hota

// Median in a stream

// median - ascending order mein (n elements) : n/2+1 th element (if n is odd) , n/2 th and n/2+1 th element ka avg (if n is even)


// bruteforce- baar baar sort krte jao and nikalte jao : not good .....baar baar nlogn lagega


// better

// sorted order ka first part max heap m rkho , second half min heap m rkho
// ( even elements case):
//    1 2 3 4 5 6
//    -max- -min-
//  size of max heap=size of min heap -> median = max ka top and min ka top ka avg

// (odd elements case):
//  1 2 3  4 5
//  -max- -min-
// size of max heap=size of min heap +1 -> median = max ka top 
//   1 2  3 4 5
//  -max- -min-
//  size of min heap=size of max heap +1 -> median = min ka top 


// algo
// ek max heap maxi banao, ek min heap mini banao 
// initialise median=0;
//  element aaya :
// if maxi size ==  mini size : then if element>median toh push in mini and median= min ka top (size of min heap=size of max heap +1) ....else push in maxi and median= max ka top (size of max heap=size of min heap +1) 
// else if maxi size== mini size +1 : then if element>median toh push in mini ....else maxi ka top mini mein daaldo fir element maxi mein and median= min ka top and max ke top ka avg (size of max heap=size of min heap)
// else ( mini size== maxi size +1 ) :  if element>median toh mini ka top maxi m daaldo fir element mini mein ...else maxi m push krdo element and median= min ka top and max ke top ka avg (size of max heap=size of min heap)


#include <iostream>
#include<queue>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int,vector<int>, greater<int> > &mini, int element) {

	
	if(maxi.size() == mini.size()) {
		if(element > median) {
			mini.push(element);
			median = mini.top();
		}
		else {
			maxi.push(element);
			median = maxi.top();
		}
	}
	else if(maxi.size() == mini.size()+1) {
		if(element > median) {
			mini.push(element);
		}
		else {
			int maxTop = maxi.top();
			maxi.pop();
			mini.push(maxTop);
			maxi.push(element);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
	else if(mini.size() == maxi.size()+1) {
		if(element > median) {
			int minTop = mini.top();
			mini.pop();
			maxi.push(minTop);
			mini.push(element);
		}
		else {
			maxi.push(element);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
}

int main() {

	int arr[] = {12,10,8,4,2,3,15};
	int n = 7;

	//12 enter: sorted order : 12 -> 12
	//10 enter :sorted order : 10 12 -> 11
	//8 enter : sorted order :8 10 12 -> 10
	//4 enter: sorted order :4 8 10 12 -> 9
	//2 enter:sorted order :2 4 8 10 12 -> 8
	//3 enter:sorted order :2 3 4 8 10 12 0 -> 6
	//15 enter:sorted order :2 3 4 8 10 12 15 -> 8

	double median  = 0;
	priority_queue<int> maxi;
	priority_queue<int,vector<int>, greater<int> > mini;
	
	for(int i=0; i<n; i++) {
		int element = arr[i];
		solveForMedian(median, maxi, mini, element);
		cout << "Median found: " << median << endl;
	}



	return 0;
}