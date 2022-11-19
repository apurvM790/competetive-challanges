// Recursion......TLE
class Solution1 {
    private:
    int solve(int row, int col, vector<vector<int>>& matrix, int n)
    {
        if(col<0 or col>=n)
        {
            return 1e9;
        }
        
        if(row==n-1)
        {
            return matrix[row][col];
        }
        
        
        
        int down = matrix[row][col] + solve(row+1,col,matrix,n);
        int down_left = matrix[row][col] + solve(row+1,col-1,matrix,n);
        int down_right = matrix[row][col] + solve(row+1,col+1,matrix,n);
        
        return min(down, min(down_left, down_right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int mini= INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,solve(0,i,matrix,n));
        }
        
        return mini;
        
        
    }
};

// Recursion+Memoization....
class Solution {
    private:
    int solve(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp)
    {
        if(col<0 or col>=n)
        {
            return 1e9;
        }
        
        if(row==n-1)
        {
            return matrix[row][col];
        }
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        
        int down = matrix[row][col] + solve(row+1,col,matrix,n,dp);
        int down_left = matrix[row][col] + solve(row+1,col-1,matrix,n,dp);
        int down_right = matrix[row][col] + solve(row+1,col+1,matrix,n,dp);
        
        return dp[row][col] = min(down, min(down_left, down_right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int mini= INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            mini=min(mini,solve(0,i,matrix,n,dp));
        }
        
        return mini;
        
        
    }
};
