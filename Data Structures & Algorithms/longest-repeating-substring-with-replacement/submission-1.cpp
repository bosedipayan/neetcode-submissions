class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();

        if(n <= 1)
        {
            return n;
        }

        int ans=0;

        unordered_set<char> st(s.begin(), s.end());

        for(char ch: st)
        {
            int st = 0, c=0;
            for(int i=0;i<n;i++)
            {
                if(s[i] == ch)
                {
                    c++;
                }


                while((i-st+1)-c > k)
                {
                    if(s[st] == ch)
                    {
                        c--;
                    }
                    st++;
                }

                ans=max(ans, (i-st+1));
            }
        }
        return ans;
    }
};