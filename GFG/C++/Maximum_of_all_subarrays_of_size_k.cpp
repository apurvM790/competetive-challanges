class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> res;
        int ws=0;
        vector<int> q;
        for(int we=0;we<n;we++){
            while(!q.empty() and arr[we]>q.back()){
                q.pop_back();
            }
            q.push_back(arr[we]);
            
            
            if (we>=k-1){
                res.push_back(q[0]);
                if (q[0]==arr[ws]) q.erase(q.begin());
                ws++;
                
            }
            
        }
        return res;
    }
};
