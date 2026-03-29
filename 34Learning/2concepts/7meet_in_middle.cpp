Meet-in-the-Middle (MITM) is a powerful technique used when brute force is too slow (usually 
2^n) but splitting the problem makes it manageable (around 
2^𝑛/2).

🔥 Core Idea

Instead of solving the problem in one go:

👉 Split the input into two halves
👉 Solve both halves independently
👉 Combine results efficiently

⚡ When to Use MITM

Use it when:

n≤40 (too big for 
2^𝑛, but okay for 
2^𝑛/2
)
You are dealing with:
Subsets
Sums / XOR / combinations
Typical problems:
Subset sum
Max subset ≤ target
Count subsets with given sum

🏆 When MITM Beats DP
Case	                    Use MITM	  Use DP
n ≤ 40	                       ✅	         ❌
sum ≤ 1e5	                   ❌	         ✅
values large(1e9)	           ✅	         ❌



🧠 Classic Example: Subset Sum
Problem:

Given array 𝑎
 of size n, find if any subset has sum = target.

🚀 Approach
Split array into two halves:
Left: first n/2
Right: remaining
Generate all subset sums:
leftSums → all sums of left half
rightSums → all sums of right half
Sort one side (usually right)
For each value in left:
Check if (target - leftSum) exists in right


#include <bits/stdc++.h>
using namespace std;

// function to generate subset sums
void generate(int idx, int end, vector<int>& a, long long sum, vector<long long>& res) {
    if (idx == end) {
        res.push_back(sum);
        return;
    }

    // take element
    generate(idx + 1, end, a, sum + a[idx], res);

    // don't take element
    generate(idx + 1, end, a, sum, res);
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mid = n / 2;

    vector<long long> left, right;

    // generate sums
    generate(0, mid, a, 0, left);
    generate(mid, n, a, 0, right);

    sort(right.begin(), right.end());

    // check
    for (auto x : left) {
        if (binary_search(right.begin(), right.end(), target - x)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}

Time Complexity 

1. Generate subset sums:
   Left half  -> O(2^(n/2))
   Right half -> O(2^(n/2))

2. Sorting:
   Sorting one half -> O(2^(n/2) * log(2^(n/2)))

3. Checking (binary search for each left sum):
   O(2^(n/2) * log(2^(n/2)))

----------------------------------------

Total Complexity:
   O(2^(n/2) * log(2^(n/2)))

----------------------------------------

Simplified:
   O(2^(n/2) * n)

----------------------------------------

Space Complexity:
   O(2^(n/2))



   🧩 Variations
Max subset sum ≤ target
Use upper_bound instead of binary search
Count subsets with sum = target
Use hashmap / frequency map
XOR problems
Same idea but replace sum with XOR
🧠 Intuition Trick

Think:

"Brute force is too big → Can I split into 2 smaller brute forces?"