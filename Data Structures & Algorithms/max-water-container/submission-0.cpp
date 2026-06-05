class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();

        int st=0, e=n-1;

        int ans=INT_MIN;
        while(st <= e)
        {
            int mini=min(heights[st], heights[e]);
            ans=max(ans, mini*(e-st));

            if(heights[st] < heights[e])
            {
                st++;
            }
            else
            {
                e--;
            }
        }

        return ans;
    }
};
