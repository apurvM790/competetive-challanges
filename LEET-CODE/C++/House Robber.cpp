// recursion with memoization...
class Solution1 {
    private:
    int solve(int ind,vector<int>& nums, vector<int>& dp)
    {
        if(ind<0)
        {
            return 0;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        
        int one=nums[ind]+solve(ind-2,nums,dp); 
        
        int two=0+solve(ind-1,nums,dp);
        
        return dp[ind]=max(one,two);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
        
        
    }
};

class Solution {
    public:
    int rob(vector<int>& nums) {
    
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i>1) dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            
            else dp[i]=max(nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
        
        
    }
};
