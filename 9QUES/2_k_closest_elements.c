// lc 658

// m1

// saare elements ka unka abs diff (diff same toh element value) par sorted order nikal lo fir  phle k lelo  (iss method ke liye given array sorted hona zruri nhi)

// using set : tle dega
// by default set stores in ascending order
// class Solution {
// public:

//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//        set<pair<int,int> > s;
//        for(int i=0;i<arr.size();i++){
//         int diff=abs(x-arr[i]);
//         s.insert({diff,arr[i]});
//        }
//        vector<int>ans;
//         while(k--){
//             auto startelement=s.begin();
//             auto startpair=*startelement;
//             int element=startpair.second;
//             ans.push_back(element);
//             s.erase(s.begin());
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
// };

// using vector : chalega

// class Solution {
// public:

//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//        vector<pair<int,int> > temp;
//        for(int i=0;i<arr.size();i++){
//         int diff=abs(x-arr[i]);
//         temp.push_back({diff,arr[i]});
//        }
//        sort(temp.begin(),temp.end());
//        vector<int>ans;
//        int i=0;
//         while(k--){
//             ans.push_back(temp[i].second);
//             i++;
//         }
//    sort(ans.begin(),ans.end());
//         return ans;
//     }
// };

// m2 : two pointer_1
// need sorted array ....nhi hota toh krlete
// ek pointer l start par rkhdete , ek h end par . dono compare krte jiska abs  diff bada usko andar khiska dege ek fir dobara compare fir khiskana ....ese ese khiskate rho till dono pointers forms range of k elements....range l se h ke elements is the ans ...

// class Solution
// {
// public:
//     vector<int> findClosestElements(vector<int> &arr, int k, int x)
//     {
//         int l = 0, h = arr.size() - 1;
//         while (h - l >= k)
//         {
//            if (abs( arr[l]-x) > abs(arr[h] - x))       //   note: if( x-arr[l] > arr[h]-x ) bhi chaljayega
//             {
//                 l++;
//             }
//             else
//             {
//                 h--;
//             }
//         }
//         vector<int> ans;
//         for (int i = l; i <= h; i++)
//         {
//             ans.push_back(arr[i]);
//         }
//         return ans;   // sorted order m hi mile h
//     }                                     // tc o(n-k)  sc o(k) ans array se aari space   // note: agar ans array na banake seedha hi return vector<int>(arr.begin+l,arr.begin()+h+1) krde toh sc o(1) hojayegi
// };

// m3  2ptr_2
// sorted needed.....sorted nhi hota toh krlete
// find smallest element in array which is >=x  ie lower bound of x.....if lower bound nhi ho toh take last element of array   {lower bound-(next smallest number just greater than or equal to that number.) upper bound- (next smallest number just greater than  that number.) }
// put h pointer to it
// put l pointer to h-1
// l,h ko expand krege till get window of k : this range ke elements ans
// expand logic:
// dono ka abs diff compare kro ...jo bada h usse dusre wale ko bahar khiskao...ese ese krlo k times....fir l se h ke bich ke (excluding l and h) elements is the ans
// note : agar pointer out of array chale jaaye toh usse dusra khiskate rhoo

// lower bound linear search se nikal skte ,binary search se bhi nikal skte...binary se krlege


class Solution
{
public:
    int lowerBound(vector<int> &arr, int x)
    {
        int start = 0, end = arr.size() - 1;
        int ans = end;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;      // ek baar ans leliya
                end = mid - 1;   // ab left m dekho
            }
            else if (x > arr[mid])
            {
                start = mid + 1;   // right m dekho
            }
        }
        return ans;
    }

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int h = lowerBound(arr, x);
        int l = h - 1;
        while (k--)
        {
            if (l==-1)
            {
                h++;
            }
            else if (h == arr.size())
            {
                l--;
            }
            else if (abs(x - arr[l]) > abs(arr[h] - x))   // if( x-arr[l] > arr[h]-x ) bhi chaljayega
            {
                h++;
            }
            else
            {
                l--;
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }
};