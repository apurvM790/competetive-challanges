class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int i_s=0,j_t=0;
        while(i_s<s.size() or j_t<t.size())
        {
            if(i_s<s.size() and j_t<t.size() and t[j_t]==s[i_s])
            {
                i_s++;j_t++;
            }
            else if(i_s>=s.size() or j_t>=t.size())
            {
                break;
            }
            else
            {
                i_s++;
            }
        }
        
        return (t.size()-j_t);
        
    }
};
