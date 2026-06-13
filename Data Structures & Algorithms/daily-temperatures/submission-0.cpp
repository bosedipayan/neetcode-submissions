// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> ans;

//         int n=temperatures.size();
//         stack<int> st;
//         for(int i=n-1;i>=0;i--)
//         {
//             while(!st.empty() && st.top() < temperatures[i])
//             {
//                 st.pop();
//             }

//             if(st.empty())
//             {
//                 ans.push_back(0);
//             }
//             else
//             {
//                 ans.push_back(st.size());
//             }
//             st.push(temperatures[i]);
//         }

//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
};