// lc 1482

//striver


// note : if m*k>n then not possible 
//       : for possible :
//        : bouquet banna phle bloom day ke baad shuru ho skte
//      : so hum phla bloom day se last bloom day ke bich check krege ie search space is phla bloom ke liye days se last bloom ke liye days ie [min of array, max of array]
//       : as we want minimum days so starting se phla valid is our ans ...


// bruteforce (linear search) : tle dega
//starting se ek ek krke check krte jaayege and phla valid (need minimum) milte hi ans miljayega ....

// class Solution {
// public:
   
// bool possible(vector<int> &arr, int day, int m, int k) {
//     int n = arr.size(); //size of the array
//     int cnt = 0;
//     int noOfB = 0;
//     // count the number of bouquets:
//     for (int i = 0; i < n; i++) {
//         if (arr[i] <= day) {
//             cnt++;
//         }
//         else {
//             noOfB += (cnt / k);
//             cnt = 0;
//         }
//     }
//     noOfB += (cnt / k);
//     return noOfB >= m;
// }
// int minDays(vector<int> &bloomDay, int m, int k) {

//     int n = bloomDay.size(); //size of the array

//     long val = (long)m  * k ;
//     if (val > n) return -1; //impossible case.

//     //we will find maximum and minimum of array as ans will lie in that range only then shuru se ek ek krke check krte jaayege
//     int mini = INT_MAX, maxi = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         mini = min(mini, bloomDay[i]);
//         maxi = max(maxi, bloomDay[i]);
//     }
// // we got range ie [mini,maxi]...ek ek krke check krlo (linear search)
//     for (int i = mini; i <= maxi; i++) {
//         if (possible(bloomDay, i, m, k))  // check whether valid ie checking bouquet banjayge kya ispe 
//             return i;
//     }
//     return -1;
// }                       // note vse voh initial -1 wali condition isme cover hojayegi toh likhne ki zrurat noi ...uper likhne se optimise hogya thda......... (vse uper likhne ke baad niche wali -1 ka koi importane nhi h as answer possible hi hoga agar uper wala cross kr aaye ie -1 wale cases hi voh hai toh unke alawa -1 aayega hi nhi........voh toh hume yeh last mein kuch return krna hi tha fn ke isiliye likhdia baaki agar yeh -1 nhi likhna dobara toh voh return i wala udhar ans mein store krke break leke niche ans return krlo )
// };                     // note  val out of range of int chala jaara tha toh iskoo  long m leliya and (long)m*k krliya               // note yeh intial -1 wali condtion na bhi likhe toooh bhi chal jaayega aage handle hojayega




// optimised : range par ek ek check ki jagah binary search lagayege and starting se phla valid nikalege



// class Solution {
// public:
// bool possible(vector<int> &arr, int day, int m, int k) {
//     int n = arr.size(); //size of the array
//     int cnt = 0;
//     int noOfB = 0;
//     // count the number of bouquets:
//     for (int i = 0; i < n; i++) {
//         if (arr[i] <= day) {
//             cnt++;
//         }
//         else {
//             noOfB += (cnt / k);
//             cnt = 0;
//         }
//     }
//     noOfB += (cnt / k);
//     return noOfB >= m;
// }
// int minDays(vector<int>&bloomDay, int m, int k) {
   
//     int n = bloomDay.size(); //size of the array

//      long val = (long)m * k ;
//     if (val > n) return -1; //impossible case.

//     //find maximum and minimum:
//     int mini = INT_MAX, maxi = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         mini = min(mini, bloomDay[i]);
//         maxi = max(maxi, bloomDay[i]);
//     }

//     //apply binary search:
//     int low = mini, high = maxi;
//     int ans=-1;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (possible(bloomDay, mid, m, k)) {    // check whether valid ispe ie checking bouquet banjayge kya               // agar mid m possible h toh uske aage toh hoga hi par hume min chahie toh aage wala toh ignore..ab kya pata yeh phla hi ho ya kya pata iske phle bhi ho,,,,toh ek baar isko ans rkh ke(kya pata peeche na mile) iske peeche check krlete 
//             ans=mid;
//             high = mid - 1;
//         }
//         else low = mid + 1;                               // agar mid m possible nhi h toh uske peeche bhi nhi hi hoga and uske hi aage hoga agar hoga toh... check fir
//     }
//     return ans;               // initial -1 wala condition isme handle hoo zaayega toh uper na bhi daalo toh chalzayega...
// }                                   // note: val out  of range of int chala jaara tha toh iskoo  long m leliya and (long)m*k krliya 
// };

