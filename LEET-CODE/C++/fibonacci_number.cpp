//using simple recursion....
class Solution1 {
    private:
    int solve(int n)
    {
        if(n<=1)
        {
            return n;
        }
        
        return solve(n-1)+solve(n-2);
    }
public:
    int fib(int n) {
        
        return solve(n);
        
        
    }
};
// using recursion with dp table....
class Solution {
    private:
    int solve(int n,vector<int> &dp)
    {
        if(n<=1)
        {
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    
    public:
    int fib(int n) {
        
        vector<int> dp(n+1,-1);
        return solve(n,dp);
        

    }
};
    
