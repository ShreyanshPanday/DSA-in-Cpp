class Solution {
    private boolean contains(int[] nums, int original){
        for(int i : nums) if(i == original) return true;
        return false;
    }
    public int findFinalValue(int[] nums, int original) {
        while(contains(nums, original)) original *= 2;
        return original;
    }
}