class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(st.size() > 2)
            {
                if(tokens[i] == "+")
                {
                    int res1 = stoi(st.top());
                    st.pop();

                    int res2 = stoi(st.top());
                    st.pop();

                    st.push(to_string(res2 + res1));
                }
                else if(tokens[i] == "-")
                {
                    int res1 = stoi(st.top());
                    st.pop();

                    int res2 = stoi(st.top());
                    st.pop();

                    st.push(to_string(res2 - res1));
                }
                else if(tokens[i] == "*")
                {
                    int res1 = stoi(st.top());
                    st.pop();

                    int res2 = stoi(st.top());
                    st.pop();

                    st.push(to_string(res2 * res1));
                }
                else if(tokens[i] == "/")
                {
                    int res1 = stoi(st.top());
                    st.pop();

                    int res2 = stoi(st.top());
                    st.pop();

                    st.push(to_string(res2 / res1));
                }
                else{
                    st.push(tokens[i]);
                }
            }
            else
            {
                st.push(tokens[i]);
            }
        }

        return stoi(st.top());
    }
};
