//using stack data structure...
class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> st;
        
        for(auto i:s)
        {
            if(i=='(' or (i>=97 and i<=122))
            {
                st.push(i);
            }
            else
            {
                string temp="";
                while(!st.empty() and st.top()!='(')
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                //reverse(temp.begin(),temp.end());
                
                for(auto i:temp)
                {   
                    
                    st.push(i);
                }
                
                
            }
        }
        string res="";
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        
        return res;
    }
};
