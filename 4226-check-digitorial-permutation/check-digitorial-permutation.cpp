class Solution {
private:
    int factorial(int num){
        static const int FACT[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        return FACT[num];
    }
public:
    bool isDigitorialPermutation(int n) {
        if(n <= 0) return false;
        int count[10] = {0};
        int temp = n;
        int totalFact = 0;
        while(temp > 0){
            int digit = temp % 10;
            count[digit]++;
            totalFact += factorial(digit);
            temp /= 10;            
        }
        while(totalFact > 0){
            count[totalFact % 10]--;
            totalFact /= 10;
        }
        for(int i = 0; i < 10; i++) if(count[i] != 0) return false;
        return true;
    }
};