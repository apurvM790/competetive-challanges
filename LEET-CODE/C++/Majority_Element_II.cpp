class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto &i:nums)
            mp[i]++;
        int n=nums.size();
        vector<int> ans;
        for(auto &i:mp)
        {
            if(i.second>floor(n/3))
            {
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};
