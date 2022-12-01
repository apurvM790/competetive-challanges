class Solution {
    map<string,int> mp;
    string ans="";
    private:
    void solve(int ind,string& temp,vector<char>& ma, int n)
    {
        if(ind==2)
            return;
        if(temp.size()==n)
        {
            if(mp.find(temp)==mp.end())
            {
                ans=temp;
                return;
            }
            
            return;
        }
        
        solve(ind+1,temp,ma,n);
        if(temp.size()<n)
        {
            temp.push_back(ma[ind]);
            solve(ind,temp,ma,n);
            temp.pop_back();
        }
        
        
        return;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto &i:nums)
        {
            mp[i]++;
        }
        
        int n=nums[0].size();
        vector<char> ma{'0','1'};
        
        string temp;
        solve(0,temp,ma,n);
        
        return ans;
    }
};
