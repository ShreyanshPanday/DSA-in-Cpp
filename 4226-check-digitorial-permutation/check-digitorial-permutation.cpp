class Solution {
private:
    int factorial(int num){
        static const int FACT[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        return FACT[num];
    }
public:
    bool isDigitorialPermutation(int n) {
        if(n <= 0) return false;
        vector<int> countN(10, 0);
        int temp = n;
        int totalFactorial = 0;
        while(temp > 0){
            int digit = temp % 10;
            countN[digit]++;
            totalFactorial += factorial(digit);
            temp /= 10;            
        }
        temp = totalFactorial;
        vector<int> countFact(10, 0);
        while(temp > 0){
            countFact[temp % 10]++;
            temp /= 10;
        }
        return countN == countFact;
    }
};