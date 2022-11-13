class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        #count=0
        s=set()
        while len(nums)!=0:
            mini=min(nums)
            maxi=max(nums)
            nums.remove(mini)
            nums.remove(maxi)
            val=(mini+maxi)/2
            s.add(val)
        
        return len(s)
