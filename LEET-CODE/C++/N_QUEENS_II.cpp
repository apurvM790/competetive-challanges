class Solution {
public:
    int totalNQueens(int n) {
        
        vector<vector<string>> grid(n,vector<string>(n,"."));
        int ans=0;
        print(0,grid,ans);
        
        
        return ans;
    }

private:
    void print(int col, vector<vector<string>>& grid, int& ans)
    { 
        if(col==grid.size())
        {
            ans++;
            return ;
        }
        
        for(int i=0;i<grid.size();i++)
        {
            if(isSafe(i,col,grid)==true)
            {   
                grid[i][col]="Q";
                print(col+1,grid,ans);
                grid[i][col]=".";
            }
            
        }
    }
    
    bool isSafe(int row, int col, vector<vector<string>>& grid)
    {
        int n=grid.size();
        for(int i=col;i>=0;i--)
        {
            if(grid[row][i]=="Q") return false;
        }
        
        for(int i=row,j=col;i>=0 and j>=0;i--,j--)
        {
            if(grid[i][j]=="Q") return false;
        }
        
        for(int i=row,j=col;j>=0 and i<n;i++,j--)
        {
            if(grid[i][j]=="Q") return false;
        }
        return true;
    }
        
    
};
