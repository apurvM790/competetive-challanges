class pair:
    def __init__(self):
        self.element=None
        self.index=None

class Solution:
    
    #Function to calculate the span of stockâ€™s price for all n days.
    def calculateSpan(self,a,n):
        #code here
        stack=[]
        result=[0]*n
        for i in range(n):
            curr=a[i]
            while  len(stack)!=0 and stack[-1][0]<=curr:
                stack.pop()
            
            if len(stack)==0:
                result[i]=-1
            else:
                result[i]=stack[-1][1]
            stack.append([a[i],i])
        #print(result)
        for i in range(n):
            result[i]=(i-result[i])
        
        return result
        
class Solution1:
    def calculateSpan(self,a,n):
        stack=[]
        
