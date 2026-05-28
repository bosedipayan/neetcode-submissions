class Solution {
public:
    bool isPalindrome(string s) {
        string str="", temp="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                str+=temp;
                temp="";
            }

            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                temp+=tolower(s[i]);
            }
        }

        str+=temp;

        int st=0, e=str.size()-1;

        while(st <= e)
        {
            if(str[st] == str[e])
            {
                st++;
                e--;
            }
            else return false;
        }
        return true;
    }
};
