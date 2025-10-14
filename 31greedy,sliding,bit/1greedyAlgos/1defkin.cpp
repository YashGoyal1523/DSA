
// generally we use  sort , sort+comparator , min heap , max heap , set in greedy  algos




//defkin
// ques - https://www.spoj.com/problems/DEFKIN/

#include<iostream>
using namespace std ;
int main()
{

  int row = 8;
  int col = 15;
  int tower = 3;
 
  vector<pair<int, int> > loc;
  loc.push_back(make_pair(3,8));
  loc.push_back(make_pair(11,2));
  loc.push_back(make_pair(8,6));

	vector<int> xCoord;
    //dummy towers add
	xCoord.push_back(0);        
	xCoord.push_back(col + 1);
    //baaki add
	for(int i=0; i<loc.size(); i++){
		xCoord.push_back(loc[i].first);
	}
	sort(xCoord.begin(), xCoord.end());

	vector<int> yCoord;
	yCoord.push_back(0);
	yCoord.push_back(row + 1);
	for(int i=0; i<loc.size(); i++){
		yCoord.push_back(loc[i].second);
	}
	sort(yCoord.begin(), yCoord.end());

	vector<int> xDim;
	for(int i=1; i<xCoord.size(); i++) {
		int diff = xCoord[i] - xCoord[i-1] - 1;
		xDim.push_back(diff);
	}

	vector<int> yDim;
	for(int i=1; i<yCoord.size(); i++) {
		int diff = yCoord[i] - yCoord[i-1] - 1;
		yDim.push_back(diff);
	}
	// approach 1 : saare areas m se max area uthalo
	int maxi = -1;
	for(int i=0; i<xDim.size(); i++) {
		for(int j=0; j<yDim.size(); j++) {
			int prod = xDim[i] * yDim[j];
			maxi = max(maxi, prod);
		}
	}
	cout << "final ANs: " << maxi << endl;

	// approach 2 : saare gaps m se max gaps uthalo fir unka product krlo
	

return 0;
}