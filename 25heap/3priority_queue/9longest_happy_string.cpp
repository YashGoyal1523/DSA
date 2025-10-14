// lc 1405 longest happy string

// ek character do se zyada baar nhi ho skta saath


// greedy

//  at an instant max freq element and usse next max freq elemnt uthao and phle max wale ki freq if>=2 then 2 max place krdo adjacent else (==1 hai) ek place krdo.... fir uske adjacent next wale ko place krege .....uski freq dekho ...if >=2 && >=max wale ki new freq ...then 2 place else 1.....
// last mein agar single element bach jaaye toh uski dekho freq ...if >=2 then 2 place krdo else ek place 
// ans milgya

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // max heap 
        priority_queue<pair<int, char> > maxHeap;
        
        // Push all characters into the heap with freq
        if(a > 0) {
            maxHeap.push({a, 'a'});
        }
        if(b > 0) {
            maxHeap.push({b, 'b'});
        }
        if(c > 0) {
            maxHeap.push({c, 'c'});
        }

        string ans = "";

        while(maxHeap.size() > 1) {
            // Extract the top two elements
            auto phla = maxHeap.top();
            maxHeap.pop();
            auto dusra = maxHeap.top();
            maxHeap.pop();
            
            // Append characters to the result string
            if(phla.first >= 2) {
                ans.push_back(phla.second);
                ans.push_back(phla.second);
                phla.first -= 2;
            } 
            else {
                ans.push_back(phla.second);
                phla.first--;
            } 

            if(dusra.first >= 2 && dusra.first >= phla.first) {
                ans.push_back(dusra.second);
                ans.push_back(dusra.second);
                dusra.first -= 2;
            }
             else {
                ans.push_back(dusra.second);
                dusra.first--;
            } 

            // Push them back into the heap if their count is still greater than 0
            if(phla.first > 0) {
                maxHeap.push(phla);
            }
            if(dusra.first > 0) {
                maxHeap.push(dusra);
            }       
        }

        // Handle the last element in the heap if there is one
        if(maxHeap.size() == 1) {
            auto phla = maxHeap.top();
            maxHeap.pop();

            if(first.first >= 2) {
                ans.push_back(phla.second);
                ans.push_back(phla.second);
                phla.first -= 2;
            } else {
                ans.push_back(phla.second);
                phla.first--;
            } 
        } 
        return ans;
    }
};
