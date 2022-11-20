class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number=0;
        char oper='+';
        //
        for(int i=0;i<s.size();i++)
        {
            char curr=s[i];  
            if(isdigit(curr))
            {
                number=(number*10)+(curr-'0');
            }
            if(!isdigit(curr) and !iswspace(curr) or i==s.size()-1)
            {
                if(oper=='+')
                {
                    st.push(number);
                }
                else if(oper=='-')
                {
                    st.push(-number);
                }
                else if(oper=='/')
                {
                    int val=st.top();
                    st.pop();
                    st.push(val/number);
                }
                else if(oper=='*')
                {
                    int val=st.top();
                    st.pop();
                    st.push(val*number);
                }
                
                oper=curr;
                number=0;
            }
        }
        number=0;
        while(!st.empty())
        {
            number+=st.top();
            st.pop();
        }
        return number;
        
    }
};
