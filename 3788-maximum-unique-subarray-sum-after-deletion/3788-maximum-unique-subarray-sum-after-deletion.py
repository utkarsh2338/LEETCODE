class Solution:
    def maxSum(self, nums: List[int]) -> int:
        res = 0
        visit = set()
        nums1 = [num for num in nums if num>0]
        if not nums1:
            return max(nums)

        for num in nums:
            if num<0 or num in visit: continue
            res += num
            visit.add(num)

        return res

        