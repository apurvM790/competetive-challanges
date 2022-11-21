// using simple bfs algorithm........
class Solution {
    private:
    int bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& maze,int brow[], int bcol[])
    {
         vis[row][col]=1;
         queue<vector<int>> q;
         q.push({row,col,1});
        int n=maze.size();
        int m=maze[0].size();
        while(!q.empty())
        {   vector<int> temp=q.front();
            row=temp[0];
            col=temp[1];
            int time=temp[2];
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int trow=row+brow[i];
                int tcol=col+bcol[i];
                
                if(trow>=0 and trow<n and tcol>=0 and tcol<m and maze[trow][tcol]!='+' and !vis[trow][tcol])
                {
                    if((trow==0 and tcol>=0) or (trow==n-1 and tcol>=0) or (trow>=0 and tcol==0) or (trow>=0 and tcol==m-1))
                    {
                        return time;
                    }
                    else
                    {
                        vis[trow][tcol]=1;
                        q.push({trow,tcol,time+1});
                    }
                }
            }
                
        }
        return -1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int brow[]={-1,0,1,0};
        int bcol[]={0,1,0,-1};
        
        
        int r=bfs(ent[0],ent[1],vis,maze,brow,bcol);
        //for(auto i:vis){
        //    for(auto j:i)
        //        cout<<j<<" ";
        //    cout<<endl;
        //}
        return r;
        
        
    }
};
