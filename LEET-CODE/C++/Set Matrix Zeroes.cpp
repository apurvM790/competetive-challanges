class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,vector<int>> mp;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                mp[i].push_back(j);
            }
        }
        
        for(auto entry:mp)
        {
            int row=entry.first;
            for(int i=0;i<m;i++)
            {
                matrix[row][i]=0;
            }
            for(auto i:entry.second)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        
        
        
    }
};
