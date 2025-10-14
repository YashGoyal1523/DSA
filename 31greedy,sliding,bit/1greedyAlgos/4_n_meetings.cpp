// n meetings in one room

//There is one meeting room in a firm. There are n meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time? Return the maximum number of meetings that can be held in the meeting room.
// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

//https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// m1 : end time par sort krdo ... phla include krlo fir aage bhado and if next waleka start > prev ka end ho toh include vrna exclude and krte jao ese ese
// m2 : sort ke bajaye min heap se bhi kr skte ...end time ke acc banalo min heap and phla include krke aage same uper wale mech se krte jao

// sort se krlete

#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}

int minMeetings(int st[], int end[], int n) {
	vector<pair<int,int> > time;
	for(int i=0; i<n; i++) {
		time.push_back({st[i], end[i]});
	}
	sort(time.begin(), time.end(),cmp);   // by default pair ke first ke acc krta sort ...second ke acc k liye comparator use krlete

	int count = 1; // phla leliyaa

	int prevStart = time[0].first;
	int prevEnd = time[0].second;
    // baaki k liye
	for(int i=1; i<n; i++) {
		int currStart = time[i].first;
		int currEnd = time[i].second;
		if(currStart > prevEnd) {
			//include current meeting
			count++;
			prevStart = currStart;
			prevEnd = currEnd;
		}
	}
	return count;
}



int main() {

	int st[] = {10,12,20};
	int end[] = {20,25,30};
	int n = 3;
	int ans = minMeetings(st, end, n);
	cout << "Final Ans: " << ans << endl;
	
  return 0;
}