//using bfs...
class Solution {
    private:
    int bfs(int row,int col,vector<vector<int>>& vis, vector<vector<int>>& grid, int brow[], int bcol[])
    {
        
        queue<vector<int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2) 
                {
                    q.push({i,j,0});
                    vis[i][j]=2;
            
                }
            }
        }
        int time=0;
        while(!q.empty())
        {
            vector<int> temp=q.front();
            int row=temp[0];
            int col=temp[1];
            q.pop();
            time=max(time,temp[2]);
            for(int i=0;i<4;i++)
            {
                int trow=row+brow[i];
                int tcol=col+bcol[i];
                
                if(trow>=0 and trow<grid.size() and tcol>=0 and tcol<grid[0].size() and grid[trow][tcol]==1 and vis[trow][tcol]!=2)
                {
                    vis[trow][tcol]=2;
                    q.push({trow,tcol,temp[2]+1});
                }
            }
        }
        return time;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int brow[]={-1,0,1,0};
        int bcol[]={0,1,0,-1};
        vector<vector<int>> vis=grid;
        int time=bfs(0,0,vis,grid,brow,bcol);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1) return -1;
            }
        }
        return time;
        
    }
};
