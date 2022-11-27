// using prefix sum technique...
class Solution {
public:
    int pivotInteger(int n) {
        
        if(n==1) return 1;
        vector<int> arr;
        vector<int> num;
        int count=0;
        for(int i=1;i<=n;i++)
        {
            count+=i;
            num.push_back(i);
            arr.push_back(count);
        }
        
        for(int i=0;i<n;i++)
        {
            int val=(arr[n-1]-arr[i])+num[i];
            if(val==arr[i])
            {
                return num[i];
            }
        }
        
        return -1;
        
    }
};
