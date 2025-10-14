// leetcode 155 
// implement a stack which do: push,pop,get top element,get min element :in o(1)




// class MinStack {
// public:
//     vector<pair<int, int>> st;
//     MinStack() {}

//     void push(int val) {
//         if (st.empty()) {
//             // it means, i am inserting first element
//             pair<int, int> p;
//             p.first = val;
//             p.second = val;
//             st.push_back(p);
//         } else {
//             pair<int, int> p;
//             p.first = val;
//             int puranaMin = st.back().second;
//             p.second = min(puranaMin, val);
//             st.push_back(p);
//         }
//     }

//     void pop() { st.pop_back(); }

//     int top() {
//         pair<int, int> rightmostPair = st.back();
//         return rightmostPair.first;
//     }

//     int getMin() {
//         pair<int, int> rightmostPair = st.back();
//         return rightmostPair.second;
//     }
// };