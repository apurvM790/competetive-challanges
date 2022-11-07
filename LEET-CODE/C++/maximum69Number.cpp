//easy 
class Solution {
public:
    int maximum69Number (int nu) {
        
        vector<int> num;
        int temp=nu;
        while(temp)
        {
            num.insert(num.begin(),temp%10);
            temp/=10;
        }
        
        for(int i=0;i<num.size();i++)
        {
            if(num[i]==6)
            { 
                num[i]=9;
                break;
            }
        }
        //int si=num.size();
        int val=0;
        int i=0;
        while(i<num.size())
        {
            val=val*10+num[i];
            i++;
        }
        //cout<<val;
        return val;
        
    }
};
