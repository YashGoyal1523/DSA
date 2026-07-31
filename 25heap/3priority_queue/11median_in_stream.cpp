// stream of data h ... instance ka mean nikalna h

//approach
//bruteforce - numbers ki list rkho ... jab bhi chahie sum nikalke mean nikalte jao : not good ... har instance pe O(n) lagega
//better - total sum and total count maintain rkhte jao ... har instance ka mean = total sum/total count

//lc 295

//stream of data h ...  instance ka median nikalna h
// median - ascending order mein (n elements) : n/2+1 th element (if n is odd) , n/2 th and n/2+1 th element ka avg (if n is even)


//bruteforce-numbers ki list rkho ... jab bhi chahie sort krke median nikalte jao : not good ... har instance pe O(nlogn) lagega

//better
// https://youtu.be/jnj87BSi9Is?si=ypquy4B9P7LOvNnB
//(O(logn) insertion using priority_queue
//T.C : The overall time complexity is O(log N) for the addNum method and O(1) for the findMedian method.
//S.C : O(N).

//ek max heap for left half, ek min heap for right half
////always maintain left_max_heap size one greater than rigght_min_heap size
//ya fir, dono ka size equal ho

//on num coming
//if left heap is empty or number is <= top of max heap add to left heap
// else add to right heap
//agar right mein ek zyada hojaye toh top left m daaldena
//similarly agar left mein >1 zyada hojaye toh top right m daaldena

//if size equal then dono ke top ka avg is median 
// if left max heap size is more then uska top


class MedianFinder {
public:
    priority_queue<int> left_max_heap; //max heap
    priority_queue<int, vector<int>, greater<int>> right_min_heap; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num <= left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }
        
        
        //always maintain left_max_heap size one greater than rigfht_min_heap size
        //ya fir, dono ka size equal ho
        
        if(left_max_heap.size()>right_min_heap.size()+1) { // note: .size() returns unsigned int toh isiliye yaha left_max_heap.size()-right_min_heap.size()>1 mat krna as agar case hua 1-2 toh voh -1 na hoke unsgned ke karan wrap hoke large positive banke yeh true hojayega
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if(left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()) {
            // matlab even number of elements hue honge
            
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        }
        
        //else hamare paas odd number of elemenes hue honge
        return left_max_heap.top();
    }
};
