class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        def reqRow(matrix, target):
            low, high = 0, len(matrix) - 1
            while low <= high:
                mid = (low + high) // 2
                if matrix[mid][0] <= target:
                    low = mid + 1
                else:
                    high = mid - 1
            return low - 1
        
        row = reqRow(matrix, target)
        if row < 0:
            return False
        low, high = 0, len(matrix[0]) - 1
        while low <= high:
            mid = (low + high) // 2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] > target:
                high = mid - 1
            else:
                low = mid + 1
        return False