class Solution {
public:
    double average(vector<int>& salary) {
        
        int mini=*min_element(salary.begin(),salary.end());
        int maxi=*max_element(salary.begin(),salary.end());
        
        double avg=0;
        for(int i:salary)
        {
            if(i!=mini and i!=maxi)
            {
                avg+=i;
            }
        }
        int n=(salary.size())-2;
        
        
        return avg/n;
        
        
        
        
    }
};
