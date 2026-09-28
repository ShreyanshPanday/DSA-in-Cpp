class Solution {
    public int maxArea(int[] height) {
        int maxWater = 0;
        int i = 0;
        int j = height.length - 1;
        while(i < j){
            int currentWater = Math.min(height[i], height[j]) * (j - i);
            maxWater = Math.max(maxWater, currentWater);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxWater;
    }
}