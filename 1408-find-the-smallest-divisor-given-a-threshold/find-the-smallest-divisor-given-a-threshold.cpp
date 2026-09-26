class Solution {
private:
    int sumOfDivisor(const vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (int it : nums) {
            sum += (it + divisor - 1) / divisor;
            if (sum > threshold) return sum;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(sumOfDivisor(nums, mid, threshold) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};