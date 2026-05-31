class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n == 1)
        {
            return 0;
        }
        int miniPrice = prices[0];

        int ans=INT_MIN;
        for(int i=1;i<n;i++)
        {
            miniPrice=min(miniPrice, prices[i]); // 1
            ans=max(ans, abs(prices[i] - miniPrice));
        }

        return ans;
    }
};
