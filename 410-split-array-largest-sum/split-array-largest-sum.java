class Solution {
    private int split(int[] nums, int mid){
        int count = 1, split = 0;
        for(int i : nums){
            if(split + i <= mid) split += i;
            else{
                count++;
                split = i;
            }
        }
        return count;
    }
    public int splitArray(int[] nums, int k) {
        int low = 0, high = 0;
        for(int i : nums){
            low = Math.max(low, i);
            high += i;
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(split(nums, mid) <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
}