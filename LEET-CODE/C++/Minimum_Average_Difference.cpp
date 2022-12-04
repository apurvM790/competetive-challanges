// time: O(n^2) space: O(1)
class Solution1 {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int n=nums.size();
        int mini=INT_MAX;
        int ind=-1;
        long sumi=0;
        for(int i=0;i<nums.size();i++)
        {
            sumi+=nums[i];
            
            long sumi_b=0;
            for(int j=i+1;j<nums.size();j++)
            {
                sumi_b+=nums[j];
            }
            long a1=(sumi/(i+1)),a2=0;
            if((n-i-1)!=0) a2=(sumi_b/(n-i-1));
            if(abs(a1-a2)<mini) 
                {mini=abs(a1-a2);
                ind=i;}
            //cout<<mini<<" "<<ind<<endl;
        }
        return ind;
        
    }
};


// usign prefix sum technique...
// time: O(n) space: O(n)
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        vector<long> pref(nums.size(),0);
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pref[i]=(pref[i-1]+nums[i]);
        }
        
        
        int mini=INT_MAX;
        int ind=-1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            long a1=(pref[i])/(i+1);
            long a2=0; 
            if((n-i-1)!=0) a2=(pref[n-1]-pref[i])/(n-i-1);
            
            if(abs(a1-a2)<mini)
            {
                mini=abs(a1-a2);
                ind=i;
            }
        }
        return ind;
        
    }
};
