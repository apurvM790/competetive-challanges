class Solution {
    
    private:
    vector<vector<string>> ans;
    void solve(int ind,string s, vector<string>& temp)
    {
        if(ind==s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=ind;i<s.size();i++)
        {
            if(palindrome(s,ind,i))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,temp);
                temp.pop_back();
                
            }
        }
    }
    
    bool palindrome(string s, int strt, int end)
    {
        while(strt<end)
        {
            if(s[strt]!=s[end]) return false;
            strt++;end--;
        }
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        vector<string> temp;
        solve(0,s,temp);
        return ans;
    }
};
