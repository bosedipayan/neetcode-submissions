// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<int> st;
//         for(int i=0;i<tokens.size();i++)
//         {
//             if(st.size() > 2)
//             {
//                 if(tokens[i] == "+")
//                 {
//                     int res1 = st.top();
//                     st.pop();

//                     int res2 = st.top();
//                     st.pop();

//                     st.push(res2 + res1);
//                 }
//                 else if(tokens[i] == "-")
//                 {
//                     int res1 = st.top();
//                     st.pop();

//                     int res2 = st.top();
//                     st.pop();

//                     st.push(res2 - res1);
//                 }
//                 else if(tokens[i] == "*")
//                 {
//                     int res1 = st.top();
//                     st.pop();

//                     int res2 = st.top();
//                     st.pop();

//                     st.push(res2 * res1);
//                 }
//                 else if(tokens[i] == "/")
//                 {
//                     int res1 = st.top();
//                     st.pop();

//                     int res2 = st.top();
//                     st.pop();

//                     st.push(res2 / res1);
//                 }
//                 else{
//                     st.push(stoi(tokens[i]));
//                 }
//             }
//             else
//             {
//                 st.push(stoi(tokens[i]));
//             }
//         }

//         return st.top();
//     }
// };



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        while (tokens.size() > 1) {
            for (int i = 0; i < tokens.size(); i++) {
                if (tokens[i] == "+"
                    || tokens[i] == "-"
                    || tokens[i] == "*"
                    || tokens[i] == "/")
                {
                    int a = stoi(tokens[i - 2]);
                    int b = stoi(tokens[i - 1]);
                    int result = 0;
                    if (tokens[i] == "+") result = a + b;
                    else if (tokens[i] == "-") result = a - b;
                    else if (tokens[i] == "*") result = a * b;
                    else if (tokens[i] == "/") result = a / b;

                    tokens.erase(tokens.begin() + i - 2, tokens.begin() + i + 1);
                    tokens.insert(tokens.begin() + i - 2, to_string(result));
                    break;
                }
            }
        }
        return stoi(tokens[0]);
    }
};