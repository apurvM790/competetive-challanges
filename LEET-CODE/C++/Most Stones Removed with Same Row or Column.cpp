//using dfs algorithm.....
class Solution {
    private:
    bool valid(vector<int>& one, vector<int>& two)
    {
        if(one[0]==two[0]) return true;
        if(one[1]==two[1]) return true;
        return false;
    }
    
    void dfs(int ind, vector<bool>& vis, vector<vector<int>>& stones)
    {
        vis[ind]=true;
        for(int j=0;j<stones.size();j++)
        {
            if(vis[j]==false)
            {
                if(valid(stones[ind],stones[j]))
                {
                    dfs(j,vis,stones);
                }
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,vis,stones);
                count++;
            }
        }
        return n-count;
        
        
        
    }
};
