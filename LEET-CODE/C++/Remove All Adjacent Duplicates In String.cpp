class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for(auto i:s)
        {   //char val=st.top();
            //cout<<val<<" ";
            if(st.empty()==false and st.top()==i)
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        string temp="";
        while(st.empty()==false)
        {
            temp=st.top()+temp;
            st.pop();
        }
        return temp;
        
    }
};
