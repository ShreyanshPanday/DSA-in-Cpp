class Solution {
    private boolean possible(int[] bloomDay, int day, int m, int k){
        int count = 0, bouquet = 0;
        for(int i : bloomDay){
            if(i <= day) count++;
            else{
                bouquet += (count / k);
                count = 0;
            }
        }
        bouquet += (count / k);
        return bouquet >= m;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        if((long) m * k > bloomDay.length) return -1;
        int low = bloomDay[0], high = bloomDay[0], ans = -1;
        for(int i : bloomDay){
            if(i < low) low = i;
            if(i > high) high = i;
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
                ans = mid;
            }else low = mid + 1;
        }
        return ans;
    }
}