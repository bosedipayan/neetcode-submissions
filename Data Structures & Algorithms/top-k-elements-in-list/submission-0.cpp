class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        priority_queue<pair<int,int>> pq;
        int c=1, i=0;
        for(i=0;i<n;)
        {
            while(i<n-1 && nums[i] == nums[i+1])
            {
                c++;
                i++;
            }

            pq.push({c, nums[i]});
            c=1;
            i++;
            if(i == n-1)
            {
                pq.push({c, nums[i]});
                break;
            }
        }

        vector<int> ans;
        while(k--)
        {
            auto it=pq.top();
            pq.pop();

            ans.push_back(it.second);
        }
        return ans;
    }
};
