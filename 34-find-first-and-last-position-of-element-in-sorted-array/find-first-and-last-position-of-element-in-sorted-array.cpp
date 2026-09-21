class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        int firstOccurrence = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(firstOccurrence == nums.size() || nums[firstOccurrence] != target) return {-1, -1};
        int lastOccurrence = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {firstOccurrence, lastOccurrence};
    }
};