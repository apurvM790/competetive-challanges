// recursive approach.
class Solution1 {
    private:
    int solve(int ind, vector<int>& nums, int target)
    {
        if(ind<0)
        {
            if(target==0) return 1;
            else return 0;
        }
        
        int plus = solve(ind-1,nums,target+nums[ind]);
        int minus =  solve(ind-1,nums,target-nums[ind]);
        
        return (plus+minus);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(nums.size()-1,nums,target);
        
    }
};

// memoized approach...
class Solution {
    private:
    int solve(int ind, vector<int>& nums, int target, vector<vector<int>>& dp)
    {
        if(ind<0)
        {
            if(target==0) return 1;
            else return 0;
        }
        
        if(dp[ind][abs(target)]!=-1)
            return dp[ind][abs(target)];
        
        int plus = solve(ind-1,nums,target+nums[ind],dp);
        int minus =  solve(ind-1,nums,target-nums[ind],dp);
        
        return dp[ind][abs(target)] = plus+minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        for(auto &i:nums)
            sum+=i;
        
        
        vector<vector<int>> dp(nums.size(),vector<int>(sum+abs(target)+1,-1));
        
        return solve(nums.size()-1,nums,target,dp);
        
    }
};
