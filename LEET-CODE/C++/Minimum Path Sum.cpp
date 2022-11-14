//using backtracking...........
class Solution {
    private:
    
    long dfs(vector<vector<int>>& grid, int row, int col,int n, int m, vector<vector<int>>& dp)
    {
        if(row==n-1 and col==m-1)
        {
            return grid[row][col];
        }
        if(row==n || col==m) return INT_MAX;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        return dp[row][col]=min(grid[row][col]+dfs(grid,row+1,col,n,m,dp),grid[row][col]+dfs(grid,row,col+1,n,m,dp)); 
        
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return dfs(grid,0,0,n,m,dp);
        
    }
};
