class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1
        n1, n2 = len(nums1), len(nums2)
        low, high = 0, n1
        INF = float('inf')
        while(low <= high):
            mid1 = (low + high) // 2
            mid2 = (n1 + n2 + 1) // 2 - mid1
            left1 = -INF if mid1 == 0 else nums1[mid1 - 1]
            left2 = -INF if mid2 == 0 else nums2[mid2 - 1]
            right1 = INF if mid1 == n1 else nums1[mid1]
            right2 = INF if mid2 == n2 else nums2[mid2]
            if left1 <= right2 and left2 <= right1:
                if (n1 + n2) % 2 == 0:
                    return (max(left1, left2) + min(right1, right2)) / 2
                else:
                    return max(left1, left2)
            elif left1 > right2:
                high = mid1 - 1
            else:
                low = mid1 + 1
        return 0.0