class Solution {
    vector<vector<int>> ans;
    set<vector<int>> res;
    private:
    void solve(int ind, vector<int> nums, vector<int> temp, int n)
    {
        if(ind>=n)
        {
            sort(temp.begin(),temp.end());
            res.insert(temp);
            return ;
        }
        
        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp,n);
        temp.pop_back();
        solve(ind+1,nums,temp,n);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> temp;
        solve(0,nums,temp,n);
        for(auto i:res)
            ans.push_back(i);
        return ans;
        
    }
};
