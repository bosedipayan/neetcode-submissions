class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        sort(s1.begin(), s1.end());

        int j=0;
        while(j < s2.size())
        {
            string temp = s2.substr(j, k);
            sort(temp.begin(), temp.end());

            if(temp == s1)
            {
                return true;
            }
            j++;
        }
        return false;
    }
};
