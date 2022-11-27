// using stack data structure......
class Solution {
public:
    string interpret(string command) {
        
        stack<char> st;
        string res="";
        for(auto &i:command)
        {
            if(i=='(' )
            {
                st.push('(');
            }
            else if(i==')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                    res+='o';
                }
                else
                {
                    while(!st.empty() and st.top()!='(')
                    {
                        st.pop();
                    }
                    if(!st.empty())
                        {st.pop();}
                }
            }
            else
            {
                res+=i;
                st.push(i);
            }
            
            
        }
        
        return res;
        
    }
};
