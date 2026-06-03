class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();

        if(n <= 1)
        {
            return n;
        }

        int i=0, j=0;
        unordered_map<char,int> mp;

        int res=0, maxi=0;
        while(j < n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);

            if((j-i+1) - maxi <= k)
            {
                res=max(res, j-i+1);
            }
            else
            {
                i++;
            }

            j++;
        }

        return res;
    }
};