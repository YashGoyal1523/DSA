// // ques- You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.You are also given an integer 'k' which denotes the number of aggressive cows.You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.Print the maximum possible minimum distance.
// 2 <= 'n' <= 10 ^ 5
// 2 <= 'k' <= n
// 0 <= 'arr[i]' <= 10 ^ 9
// Time Limit: 1 sec.
// // https://www.naukri.com/code360/problems/aggressive-cows_1082559

// striver

// // tip- if in ques wordings are:  min is max , max is min : binary search ques
// // method- search space banao,binary search lagao

// now
//  note: k<=n : ans is possible in all cases

// // in a case the min dist between two cows can be in range [minimum of adjacent stalls pos differencess(adjacent stalls par cow lagana) ,stalls ka min pos and max pos ka diff(sabse dur dur wali stall)]. we got the range of dist possible so we got the search space so check isme and as we want max so starting se last valid is the ans.Ideally hume isme check krna chahie taaki optimised ho par agar yeh min of differences nikalne wala jhanjhat na krna ho toh hum  1 (minimum value jo lower end par aa skti range ke in a case (ek pair of adjacent stalls ek ke diff par ho...(isse kam par nhi ho skta))) se shuru hoke nikal lege ie range banalege [1,stalls ka min pos and max pos ka diff]....isse less optimised hojayega in cases when 1 is not supposed to be there due to..kuch iterations extra hojayegi original se due to some initial nos from 1 if they are not in original range  .  yeh 1 wale se  krte abhi .
// linear se kar skte.....starting se ek ek krke check kro last valid case uthalo.......
// ya binary se kr skte

// // linear
// bool canWePlace (vector<int> &stalls, int dist, int cows) {
// int lastcowpos = stalls[0];  // phli cow ko shuru waali par rkhdo
// int cntCows = 1;  // no of cows placed
// for(int i = 1;i<stalls.size();i++) {
// if(stalls[i]-lastcowpos >= dist)          // curr stall pos and last cow ki stall ki pos ka gap >= checking dist ho toh place vrna no place
//  { cntCows++;
//  lastcowpos= stalls[i];
// }
// if(cntCows >= cows) return true;
// }
// return false;
// }
// int aggressiveCows(vector<int> &stalls, int k)
// {
// sort(stalls.begin(),stalls.end());   // stalls ki pos order m krlo ... need in order for our checking logic           ... max min pos nikalne m bhi kaam aazayega
// int n =stalls.size();
// int i;
// for( i=1;i<=stalls[n-1]-stalls[0];i++){          // range mein ek ek dist ko check kro  shuru se        // note : sorted hai toh max last and min start m hi hoga toh last-start klria
//     if(canWePlace(stalls,i,k)==true){  // checking whether possible or not by checking if we can place all cows
//         continue;
//     }
//     else break;
// }
// return i-1;
// }

// // binary

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int lastcowpos = stalls[0]; // phli cow ko shuru waali par rkhdo
    int cntCows = 1;            // no of cows placed
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastcowpos >= dist) // curr stall pos and last cow ki stall ki pos ka gap >= checking dist ho toh place vrna no place
        {
            cntCows++;
            lastcowpos = stalls[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end()); // stalls ko order m krlo phle .... need in order for our logic of checking if possible or not......... max min pos nikalne m bhi kaam aazayega
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0]; // low ko min of range par rkhida and high ko max  of range
    int ans;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        { // checking whether possible or not by checking if we can place all cows
            ans = mid;
            low = mid + 1; //  note agar mid par possible h toh uske left toh hoga hi par voh kam hoga and hume max chahie toh ab kya pata yeh last hi ho ya kya pata aage bhi ho .....toh isko store krke (kya pata aage na ho) uske right m check krte hai ....
        }
        else
        {
            high = mid - 1; // mid pe posssible nhi h toh uske aage bhi mhi hi hoga..lets check left m
        }
    }
    return ans;
}
