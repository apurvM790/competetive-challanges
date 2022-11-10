class Solution:
    def minJumps(self, arr, n):
        #code here
        if n==1:
            return 0
        result=[False]*n
        result[-1]=True
        for i in range(n-2,-1,-1):
            for j in range(i,arr[i]+i+1):
                if result[j]:
                    result[i]=True
                    break
        #print(result)
        if result[0]:
            
            maxi,end,jump=arr[0],arr[0],1
            for i in range(1,n-1):
                maxi=max(maxi,arr[i]+i)
                if i==end:
                    jump+=1
                    end=maxi
            
            return jump
        else:
            return -1
