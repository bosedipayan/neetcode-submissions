class MinStack {
public:
  stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        vector<int> vis;
        int ans=INT_MAX;
        while(!st.empty())
        {
            ans=min(ans, st.top());
            vis.push_back(st.top());
            st.pop();
        }

        for(int i=vis.size()-1;i>=0;i--)
        {
            st.push(vis[i]);
        }
        return ans;
    }
};
// 4, 3, 2, 1