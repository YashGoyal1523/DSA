// lc 3016  Minimum Number of Pushes to Type Word II

// Intuition
// To solve this problem, we use a greedy algorithm approach combined with sorting. Keeping in mind that we have 8 keys available (2-9), the primary intuition is to remap the keys so the 8 most frequently occurring characters in the given string are assigned as first key presses, the next most common 8 characters as second key presses, and so on.
// We begin by counting the occurrences of each letter using a counter, which provides the frequency of each distinct letter. Next, we sort these frequencies in descending order.
// Since there are 8 possible key assignments, we'll divide the frequency rank by 8 to group it as a first, second, or third key press. Note that dividing the frequencies by 8 will result in 0, 1, and 2. We must add 1 to this group number to get the actual number of presses required for letters in that group. Multiplying this by the number of times the character appears in the given string yields the total number of presses for that letter.
// Finally, we will sum the total presses required to type the word.
// This greedy way, combined with sorting by frequency, ensures that each decision (assignment of letters to keys) is optimal for minimizing key presses.

// Algorithm
// Initialize a frequency vector frequency of size 26 to store the count of each letter in the word.
// Iterate through each character c in word and increment the count in frequency at the index corresponding to c - 'a'.
// Sort the frequency vector in descending order to prioritize letters with higher counts.
// Initialize a variable totalPushes to store the total number of key presses required.
// Iterate through the sorted frequency vector:
// If the frequency of a letter is zero, break the loop as there are no more letters to process.
// Calculate the number of pushes for each letter based on its position in the sorted list: (i / 8 + 1) * frequency[i].
// Accumulate this value in totalPushes.
// Return totalPushes as the minimum number of key presses required to type the word.


// class Solution {
// public:
//     int minimumPushes(string word) {
//         // Frequency vector to store count of each letter
//         vector<int> frequency(26, 0);

//         // Count occurrences of each letter
//         for (char& c : word) {
//             ++frequency[c - 'a'];
//         }

//         // Sort frequencies in descending order
//         sort(frequency.rbegin(), frequency.rend());

//         int totalPushes = 0;

//         // Calculate total number of presses
//         for (int i = 0; i < 26; ++i) {
//             if (frequency[i] == 0) break;
//             totalPushes += (i / 8 + 1) * frequency[i];
//         }

//         return totalPushes;
//     }
// };