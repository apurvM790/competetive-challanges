// using backtracking [pick and not-pick concept].........
class Solution {
    private:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(target==0) return true;
        
        
        if(ind==0) return (target==nums[0]);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=false;
        if(nums[ind]<=target) take=solve(ind-1,target-nums[ind],nums, dp);
        
        bool not_pick=solve(ind-1,target,nums,dp);
        
        return dp[ind][target]=(take | not_pick);
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int val=0;
        for(auto &i:nums)
            val+=i;
        
        if(val%2==1) return false;
        
        vector<vector<int>> dp(nums.size(),vector<int>(val/2+1,-1));
        int n=nums.size();
        return solve(n-1,val/2,nums,dp);
        
    }
};
