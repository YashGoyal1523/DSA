//lc 295

//stream of data h ...  instance ka median nikalna h

//bruteforce-numbers ki list rkho ... jab bhi chahie sort krke median nikalte jao : not good ... har instance pe O(nlogn) lagega

//better
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



class MedianFinder {
public:
    
    priority_queue<int> maxi;
	priority_queue<int,vector<int>, greater<int> > mini;
    double median;
    MedianFinder() {
        median=0;
    }
    
    void addNum(int num) {
        if(maxi.size() == mini.size()) {
		if(num > median) {
			mini.push(num);
			median = mini.top();
		}
		else {
			maxi.push(num);
			median = maxi.top();
		}
	}
	else if(maxi.size() == mini.size()+1) {
		if(num > median) {
			mini.push(num);
		}
		else {
			int maxTop = maxi.top();
			maxi.pop();
			mini.push(maxTop);
			maxi.push(num);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
	else if(mini.size() == maxi.size()+1) {
		if(num > median) {
			int minTop = mini.top();
			mini.pop();
			maxi.push(minTop);
			mini.push(num);
		}
		else {
			maxi.push(num);
		}
		median = (mini.top() + maxi.top())/2.0;
	}
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */