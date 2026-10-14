class Solution {
private:
    int splited(const vector<int>& nums, int mid){
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
public:
    int splitArray(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        int low = 0, high = 0;
        for(int i : nums){
            low = max(low, i);
            high += i;
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(splited(nums, mid) <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};