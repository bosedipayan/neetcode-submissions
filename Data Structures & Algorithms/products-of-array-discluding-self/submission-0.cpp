class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int c=1;
            for(int j=0;j<n;j++)
            {
                if(i != j)
                {
                    c*=nums[j];
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};
