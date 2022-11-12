
class Solution:
    def longestCommonPrefix(self, arr, n):
        # code here
        mini=self.minimum(arr)
        result=[0]*mini
        common=self.common_prefix(arr,result,n,mini)
        #print(common)
        st=""
        for i in common:
            if i!=0:
                st+=i
            else:
                break
        if len(st):
            return st
        else:
            return -1
        
        
    def minimum(self,arr):
        mini=1000
        for i in arr:
            if len(i)<mini:
                mini=len(i)
        return mini
    
    
    def common_prefix(self,arr,result,n,mini):
        k=0
        for i in range(mini):
            flag=True
            for j in range(n):
                if arr[0][i] != arr[j][i]:
                    flag=False
                    break
            if flag:
                result[k]=arr[0][i]
                k+=1
            else:
                break
        return result
