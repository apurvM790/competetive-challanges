// using simple bfs and marking into visit array....
// if any room is not visited after using bfs in given array the we have to simply return 'fasle' else return 'true'...

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int> vis(n,-1); //visited array for marking the room is visited or not.
        vis[0]=1;
        queue<vector<int>> q; //queue for using bfs algo.
        q.push(rooms[0]);
        
        while(!q.empty())
        {
            vector<int> temp=q.front();
            q.pop();
            
            for(auto &i:temp)
            {
                if(vis[i]==-1)
                {   
                    vis[i]=1;
                    q.push(rooms[i]);
                }
            }
        }
        
        for(auto &i:vis)
        {
            if(i==-1) return false; //if any room is not visited yet simply return false.
        }
        return true; // if all the room are visited finally return true.
        
    }
};
