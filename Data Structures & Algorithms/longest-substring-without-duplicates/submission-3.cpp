class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
        {
            return 0;
        }
        int n=s.size();

        vector<int> vis(256, -1);
        int i=0, j=0;

        int ans=INT_MIN;
        while(j < n)
        {
            if(vis[s[j]] != -1)
            {
                i=max(i, vis[s[j]]+1);
            }

            vis[s[j]] = j;

            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
