class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n <= 1)
        {
            return n;
        }

        sort(nums.begin(), nums.end());

        int c=1;
        for(int i=0;i<n-1;i++)
        {
            if(abs(nums[i+1]-nums[i]) == 1)
            {
                c++;
            }
        }

        return c;
    }
};
