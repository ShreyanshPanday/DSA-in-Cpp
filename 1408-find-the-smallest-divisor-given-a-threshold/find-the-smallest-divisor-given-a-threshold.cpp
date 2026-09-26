class Solution {
private:
    int sumOfDivisor(vector<int> nums, int n, int divisor){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i] / (double)divisor);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(sumOfDivisor(nums, n, mid) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};