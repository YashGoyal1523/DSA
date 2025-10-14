// given an array .find no of pairs whose sum > k

//m1 bruteforce : two for loops :n^2

//m2
//two pointer

        int cnt=0;
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size()-1;
        while(s<e) {
            int sum = nums[s]+ nums[e];
            if(sum>k) {
                cnt+=e-s;
                e--;
            }
            else {
                s++;
            }
        }
        return cnt;