class Solution:
    def splitArray(self, nums: list[int], k: int) -> int:
        low = max(nums)
        high = sum(nums)
        def splited(mid):
            count = 1
            split = 0
            for i in nums:
                if split + i <= mid:
                    split += i
                else:
                    count += 1
                    split = i
            return count
        while(low <= high):
            mid = low + (high - low) // 2
            if splited(mid) <= k:
                high = mid - 1
            else:
                low = mid + 1
        return low