class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
    // code here
    sort(capacity.begin(),capacity.end());
    long long ans=capacity[0];
   for(int i=1;i<n;i++)
   {
      ans= (ans*(capacity[i]-i))%(1000000000+7);

    }
    return ans; 

    }
};
