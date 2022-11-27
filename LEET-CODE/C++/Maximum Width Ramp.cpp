class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.empty() or nums[s.top()]>nums[i])
            {
                s.push(i);
            }
        }
        
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!s.empty() and nums[s.top()]<=nums[i])
            {
                ans=max(ans,i-s.top());
                s.pop();
            }
        }
        return ans;
        
    }
};
