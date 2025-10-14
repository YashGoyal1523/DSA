
// lc 767

//  greedy

//m1
//find most occured element and fill it alternatively ie in gap of 1 . if nhi kar paaye then return empty else fill rest elements in remaining position by placing in gaps of 1. agar max wale ke baad jagah nhi bachi toh 1 index se shuru hojao and bachi h toh phle voh cover kro fir jab voh khatm then 1 index se lagjao 

// class Solution
// {
// public:
//     string reorganizeString(string s)
//     {
//         int hash[26] = {0};
//         for (int i = 0; i < s.size(); i++)
//         {
//             hash[s[i] - 'a']++;
//         }
//         // find the most frequent char
//         char max_freq_char;
//         int max_freq = INT_MIN;
//         for (int i = 0; i < 26; i++)
//         {
//             if (hash[i] > max_freq)
//             {
//                 max_freq = hash[i];
//                 max_freq_char = i + 'a';
//             }
//         }
//         // place most frequent first in gaps of 1
//         int index = 0;
//         while (max_freq > 0 && index < s.size())
//         {
//             s[index] = max_freq_char;
//             max_freq--;
//             index += 2;
//         }

//         if(max_freq!= 0) // sab place nhi ho paaye ...jagah kam pdgyi
//         {
//             return "";
//         }

//         //sab place krdia 
//         hash[max_freq_char - 'a'] = 0; 

//         // let's place the rest of the characters

//         for (int i = 0; i < 26; i++)
//         {
//             while (hash[i] > 0)
//             {
//                 index = index >= s.size() ? 1 : index;
//                 s[index] = i + 'a';
//                 hash[i]--;
//                 index += 2;
//             }
//         }
//         return s;
//     }
// };


// m2 

// at an instant max freq element and usse next max freq elemnt uthao and adjacent place krdo phle max fir next max ....
// ese do do uthate jao and krte jao
//last m agar ek element bach jaaye toh agar uski freq > 1 hai toh ans not possible and if ==1 hai toh usko lagado and ans milgya
// and koi na bache and sab do do m include hojaye toh ans milgya 



class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        // Count the frequency of each character in the string
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;   // 'a' ka 0 par , 'b' ka 1 par.....
        }

      // max heap
        priority_queue<pair<int, char> > maxHeap;        // pair mein phle priority is given on first member , if tie then second memeber

        // Push all characters with freq into the heap 
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                int fre=freq[i];
                char ch=i+'a';    //i+'a' : 0 se 'a' derive, 1 se 'b' derive, 2 se 'c' ....
                maxHeap.push({fre, ch});    
            }
        }

        string ans = "";

        // Process the heap
        while(maxHeap.size() > 1) {   // >1 kra as 2 elements nikalege toh min 2 toh hone hi chaie na heap m.....last mein agar ek bach gya toh usko alag se handle krlege
            // Extract the top two elements
            auto phla = maxHeap.top();
            maxHeap.pop();
            auto dusra = maxHeap.top();
            maxHeap.pop();

            // Append the characters to the result string
            ans.push_back(phla.second);
            ans.push_back(dusra.second);

            // Decrease their counts and push them back if they are still > 0
            phla.first--;
            dusra.first--;

            if(phla.first > 0) {
                maxHeap.push(phla);
            }
            if(dusra.first > 0) {
                maxHeap.push(dusra);
            }
        }

        // If one element is left in the heap, handle it separately
        if(maxHeap.size() == 1) {
            auto phla = maxHeap.top();
            maxHeap.pop();

            ans.push_back(phla.second);
            phla.first--;

            if(phla.first != 0) {
                // Answer not possible
                return "";
            }
        }

        return ans;
    }
};


// map bhi use kr skte for frequency



class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>freq;

        // Count the frequency of each character in the string
        for(int i = 0; i < s.length(); i++) {
           freq[s[i]]++;   
        }

      // max heap
        priority_queue<pair<int, char> > maxHeap;        // pair mein phle priority is given on first member , if tie then second memeber

        // Push all characters along with freq into the heap 
        for(auto i:freq) {
                int fre=i.second;
                char ch=i.first;  
                maxHeap.push({fre, ch});    
            }
        

        string ans = "";

        // Process the heap
        while (maxHeap.size() > 1) {   // >1 kra as 2 elements nikalege toh min 2 toh hone hi chaie na heap m.....last mein agar ek bach gya toh usko alag se handle krlege
            // Extract the top two elements
            auto phla = maxHeap.top();
            maxHeap.pop();
            auto dusra = maxHeap.top();
            maxHeap.pop();

            // Append the characters to the result string
            ans.push_back(phla.second);
            ans.push_back(dusra.second);

            // Decrease their counts and push them back if they are still > 0
            phla.first--;
            dusra.first--;

            if(phla.first > 0) {
                maxHeap.push(phla);
            }
            if(dusra.first > 0) {
                maxHeap.push(dusra);
            }
        }

        // If one element is left in the heap, handle it separately
        if(maxHeap.size() == 1) {
            auto phla = maxHeap.top();
            maxHeap.pop();

            ans.push_back(phla.second);
            phla.first--;

            if(phla.first != 0) {
                // Answer not possible
                return "";
            }
        }

        return ans;
    }
};