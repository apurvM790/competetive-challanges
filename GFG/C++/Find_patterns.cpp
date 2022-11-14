class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
        int count=0;
        
        vector<bool> visited(S.size(),true);
        int st=0;
        for(int i=0;i<S.size();i++)
        {
            if(W[0]==S[i] and visited[i])
            {   bool flag=true;
                vector<int> vis;
                for(int j=i;j<S.size();j++)
                {
                    if(W[st]==S[j] and visited[j])
                    {
                        vis.push_back(j);
                        st++;
                    }
                    if(st==W.size())
                    {
                        count++;
                        flag=false;
                        st=0;
                        break;
                    }
                }
                if(flag)
                {
                    st=0;
                   
                }
                else
                {
                    for(auto i:vis)
                    {
                        visited[i]=false;
                    }
                }
                
            }
        }
        return count;
        
    }
};
