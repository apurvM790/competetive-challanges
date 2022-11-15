class Solution {
    private:
    int solve(int row, int col, int m, int n, vector<vector<int>>& dp)
    {
        
        if(row==m-1 or col==n-1)
        {
            return 1;
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        
        
        dp[row][col]=solve(row+1,col,m,n,dp)+solve(row,col+1,m,n,dp);
        return dp[row][col];
        
        
    }
    
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return solve(0,0,m,n,dp);
        
         
        
    }
};
