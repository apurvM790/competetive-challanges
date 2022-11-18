class Solution {
    vector<string> ans;
    private:
    void solve(int i, int n, string s, string temp)
    {
        if(i>=n)
        {
            ans.push_back(temp);
            return;
        }
        
        
        if(isdigit(s[i]))
        {
            
            temp.push_back(s[i]);
            solve(i+1,n,s,temp);
            
                
            
        }
        else
        {
            
            string b=temp;
            b.push_back(tolower(s[i]));
            solve(i+1,n,s,b);
            
            string a=temp;
            a.push_back(toupper(s[i]));
            solve(i+1,n,s,a);
            
           
        }
            
    }
    
public:
    vector<string> letterCasePermutation(string s) {
        
        int n=s.size();
        solve(0,n,s,"");
        
        return ans;
        
    }
};
