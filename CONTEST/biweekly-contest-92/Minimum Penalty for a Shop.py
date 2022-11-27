class Solution:
    def bestClosingTime(self, cust: str) -> int:
        c_y=cust.count('Y')
        if c_y==0:
            return 0;
        
        lst=[0,c_y]
        
        for i in range(len(cust)):
            if cust[i]=='Y':
                c_y-=1
                if c_y<lst[1]:
                    lst=[i+1,c_y]
            else:
                c_y+=1
        
        return lst[0]
        
        
        
        
        
