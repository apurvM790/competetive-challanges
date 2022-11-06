//POTD -- [06-11-22]
class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        vector<int> coin={2000,500,200,100,50,20,10,5,2,1};
        vector<int> ans;
        
           
            for(auto i:coin)
            {
                int val=0;
                val=n/i;
                //cout<<val<<" ";
                
                if (i<=n) n=n%i;
                if (val!=0)
                {
                    for(int j=1;j<=val;j++)
                    {
                        ans.push_back(i);
                    }
                }
                if(n==0) break;
            }
            return ans;
        
    }
};
