// using dfs find the area of all the islands and then figure out which is maximum.
class Solution {
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,-1));
        int brow[]={-1,0,1,0}; // all the four directions of row i.e. upward,downward,left and right
        int bcol[]={0,1,0,-1}; // all the four directions of column i.e. upward,downward,left and right
        int maxi=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(vis[i][j]==-1 and grid[i][j]==1)
                {   int val=1;
                    dfs(i,j,vis,grid,brow,bcol,val);
                    maxi=max(val,maxi);
                    //val=0;
                }
            }
        }
        return maxi;
        
    }
    
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid,int brow[], int bcol[], int& maxi)
    {   
        vis[row][col]=2;
        for(int i=0;i<4;i++)
        {   
            int trow=row+brow[i];
            int tcol=col+bcol[i];
            
            if(trow>=0 and trow<grid.size() and tcol>=0 and tcol<grid[0].size() and vis[trow][tcol]==-1 and grid[trow][tcol]==1)
            {   maxi++;
                dfs(trow,tcol,vis,grid,brow,bcol,maxi);
                
            }
            
            
        }
        
        
    }
};
