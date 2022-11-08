class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> res;
        map<int,int> mp;
        int ws=0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            if (i>=k-1){
                res.push_back(mp.size());
                mp[A[ws]]--;
                if (mp[A[ws]]==0) mp.erase(A[ws]);
                ws++;
                
            }
            
        }
        return res;
    }
};
