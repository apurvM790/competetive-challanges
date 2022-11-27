class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        vector<pair<int,int>> row;
        vector<pair<int,int>> col;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            int c_z=0,c_o=0;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    c_z++;
                }
                else c_o++;
            }
            row.push_back({c_z,c_o});
        }
        for(int j=0;j<m;j++)
        {
            int c_z=0,c_o=0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j]==0)
                {
                    c_z++;
                }
                else c_o++;
            }
            col.push_back({c_z,c_o});
        }
        //onesRowi + onesColj - zerosRowi - zerosColj
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               grid[i][j]= (row[i].second+col[j].second-row[i].first-col[j].first);
            }
        }
        
        return grid;
        
    }
};
