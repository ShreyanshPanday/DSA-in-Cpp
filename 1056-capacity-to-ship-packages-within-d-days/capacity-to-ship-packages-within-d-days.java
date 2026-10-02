class Solution {
    private int numberOfDays(int[] weights, int capacity){
        int totalDays = 1, load = 0;
        for(int it : weights){
            if(load + it > capacity){
                load = it;
                totalDays++;
            } else load += it;
        }
        return totalDays;
    }
    public int shipWithinDays(int[] weights, int days) {
        int low = 0, high = 0;
        for(int it : weights){
            if(it > low) low = it;
            high += it;
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(numberOfDays(weights, mid) <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
}