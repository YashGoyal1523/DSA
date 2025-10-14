// // lc 1334


//  floyd warshall use krke har node ka har node se min dist nikal lege
// fir har node ke liye dekhlege usse kitne nodes ka min dist <=Threshold h
// fir nikal lege ans



// class Solution {
// public:

// 	void floydwarshall(vector<vector<int>>& edges, vector<int>&count,int n,int Threshold) {
		
// 		// dist matrix banaliya .... each dabba will store ans dist from row index (node)to col index(node) .... index represent nodes
// 		vector<vector<int> > dist(n, vector<int>(n, 1e9)); // ek baar 1e9 daaldete

//         //intial states
// 		//  graph k andar given weights ke according update krlete dist array 
// 		for(auto i:edges){
//             dist[i[0]][i[1]]=i[2];  // bidirectional given h
//             dist[i[1]][i[0]]=i[2];
//         }

// 		//self se self ka wt  zero hoga...graph m yeh given nhi hoga.....toh khudse ...matrix mein diagnol pr 0 daaldo.... 
// 		for(int i=0; i<n; i++) {
// 			dist[i][i] = 0;
// 		}

//     // now
// 		//main logic - helper logic (ek src se ek dest ke liye hum krege ki src se dest ki traf jaayege bich m ek helper node ke via....ab yeh helper node banjayegi baaki saari nodes ek ek krke  aur unn sab ka min ans will be the ans for this src to dest....yhi logic lagana h bas sab ke liye  )
// 		for(int helper = 0; helper < n; helper++) {
// 			for(int src =0; src < n; src++) {
// 				for(int dest = 0; dest < n; dest++) {
// 					dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
// 				}
// 			}                               // isse matrix ke dabbos mein new value and old value ke bich ka min dalta jaayega
// 		}

//         // ab dist array m min distances stored milege

//         // threshold  wale dekhlo
// 		for(int i=0; i<n; i++) {
// 			for(int j=0; j<n; j++ ) {
// 				if(i!=j&&dist[i][j]<=Threshold) count[i]++; // self dist nhi dekhna so i!=j
// 			}
			
// 		}
// 	}

//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        

//         vector<int>count(n,0);   // will maintain count of cities for each city // city are numbered from 0 to n-1 // index will represnt city number jiska count hai
//         floydwarshall(edges,count,n,distanceThreshold);

//  // ans nikal lete
//    int minCount = INT_MAX;
//         int city = -1;
         
//         for (int i = 0; i < n; i++) {
//             if (count[i] <= minCount) {
//                 minCount = count[i];
//                 city = i;
//             }
//         }

//         return city;

//     }


// };


// dijstra se bhi kr skte...har ek node k liye lagado