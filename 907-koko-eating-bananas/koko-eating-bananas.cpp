class Solution {
private:
    int pileEaten(const vector<int>& piles, int mid, int h){
        int eaten = 0;
        for(int it : piles){
            eaten += (it + mid - 1) / mid;
            if(eaten > h) break;
        }
        return eaten;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = -1;
        for(int it : piles) maxi = max(maxi, it);
        int low = 1, high = maxi;
        while(low <= high){
            int mid =low + (high - low) / 2;
            if(pileEaten(piles, mid, h) <= h) high = mid - 1; 
            else low = mid + 1;
        }
        return low;
    }
};