class Solution {
private:
    bool possible(const vector<int>& bloomDay, int day, int m, int k){
        int count = 0, bouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                    if (bouquets >= m) {
                        return true;
                    }
                }
            }else count = 0;
        }
        return bouquets >= m;
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1;
        int low = bloomDay[0], high = bloomDay[0], ans = -1;
        for(int i = 1; i < bloomDay.size(); i++){
            if(bloomDay[i] < low) low = bloomDay[i];
            if(bloomDay[i] > high) high = bloomDay[i];
        }
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k) == true){
                high = mid - 1;
                ans = mid;
            }else low = mid + 1;
        }
        return ans;
    }
};