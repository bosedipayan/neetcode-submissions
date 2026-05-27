class Solution {
public:
    vector<string> encoded_string;
    string encode(vector<string>& strs) {
        for(auto it: strs)
        {
            encoded_string.push_back(it);
        }

        return "";
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        for(auto it: encoded_string)
        {
            decoded_strs.push_back(it);
        }

        return decoded_strs;
    }
};
