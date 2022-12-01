class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int pro=1;
        int count=0;
        for(auto i:nums)
        {
            if (i!=0) pro*=i;
            else count++;
        }
        
        vector<int> res(nums.size(),0);
        if(count>1) return res;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0 and count==0)
                res[i]=pro/nums[i];
            else if(nums[i]!=0 and count!=0)
                res[i]=0;
            else res[i]=pro;
        }
        
        return res;
        
    }
};
