class Solution {
private:
    long long pileEaten(const vector<int>& piles, int mid, int h){
        long long eaten = 0;
        for(int it : piles){
            eaten += (it + mid - 1) / mid;
            if(eaten > h) break;
        }
        return eaten;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = -1;
        while(low <= high){
            int mid =low + (high - low) / 2;
            if(pileEaten(piles, mid, h) <= h){
                high = mid - 1;
                ans = mid;
            } 
            else low = mid + 1;
        }
        return ans;
    }
};