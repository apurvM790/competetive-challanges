//using dp and memoization...
class Solution {
    int ans=0;
    private:
    void solve(int ind, string& temp, vector<char>& res, int n)
    {
    
        if(temp.size()==n)
        {
            ans++;
            return ;
        }
        
        
        for(int i=ind;i<5;i++)
        {
            temp.push_back(res[i]);
            solve(i,temp,res,n);
            temp.pop_back();
        }
        
        return ;
        
    }
public:
    int countVowelStrings(int n) {
        vector<char> res{'a','e','i','o','u'};
        string temp;
        solve(0,temp,res,n);
        return ans;
    }
};
