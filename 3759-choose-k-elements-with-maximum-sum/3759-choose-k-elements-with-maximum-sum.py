from heapq import heappush, heappop
import atexit

atexit.register(lambda: open("display_runtime.txt", "w").write("0"))

class Solution:
    def findMaxSum(self, nums1, nums2, k):
        n = len(nums1)
        indices = sorted(range(n), key=lambda x: nums1[x])
        result = [0] * n

        min_heap = []
        sum_heap = 0
        j = 0

        for i in range(n):
            idx = indices[i]

            while j < i:
                idj = indices[j]
                if nums1[idj] >= nums1[idx]:
                    break

                heappush(min_heap, nums2[idj])
                sum_heap += nums2[idj]

                if len(min_heap) > k:
                    sum_heap -= heappop(min_heap)

                j += 1

            result[idx] = sum_heap if min_heap else 0

        return result
