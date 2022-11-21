// using backtracking [pick and non-pick ] concept.....
class Solution{
    private:
    void solve(int ind, int target, vector<int>& temp, vector<int>& arr, vector<vector<int>>& ans)
    {
        if(target==0)
        {
            vector<int> curr(temp.begin(),temp.end());
            sort(curr.begin(),curr.end(),[](auto& a, auto& b){
                return a>b;
            });
            ans.push_back(curr);
            return;
        }
        if(ind<0)
        {
            return;
        }
        
        if(arr[ind]<=target)
        {
            temp.push_back(arr[ind]);
            solve(ind,target-arr[ind],temp,arr,ans);
            temp.pop_back();
        }
        solve(ind-1,target,temp,arr,ans);
        
    }
	public:
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int> arr;
        for(int i=n;i>0;i--)
            arr.push_back(i);
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        solve(n-1,n,temp,arr,ans);
        
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
