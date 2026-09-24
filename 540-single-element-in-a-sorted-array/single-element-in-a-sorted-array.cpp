class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid == 0) return nums[mid];
            if(mid == nums.size() - 1) return nums[mid];
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) return nums[mid];
            else if(nums[mid] == nums[mid + 1] && mid % 2 == 0) low = mid + 2;
            else if(nums[mid] == nums[mid - 1] && mid % 2 != 0) low = mid + 1;
            else if(nums[mid] == nums[mid + 1] && mid % 2 != 0) high = mid - 1;
            else if(nums[mid] == nums[mid - 1] && mid % 2 == 0) high = mid - 1;
        }
        return -1;
    }
};