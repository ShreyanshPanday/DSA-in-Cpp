class Solution {
private:
    int sumOfDivisor(vector<int>& nums, int divisor){
        int sum = 0;
        for(int it : nums){
            sum +=it /divisor + (it % divisor != 0) ;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(sumOfDivisor(nums, mid) <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};