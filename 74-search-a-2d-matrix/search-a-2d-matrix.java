class Solution {
    private int reqRow(int[][] matrix, int target){
        int low = 0, high = matrix.length - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(matrix[mid][0] <= target) low = mid + 1;
            else high = mid - 1;
        }
        return low - 1;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int low = 0, high = matrix[0].length - 1;
        int row = reqRow(matrix, target);
        if(row < 0) return false;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
}