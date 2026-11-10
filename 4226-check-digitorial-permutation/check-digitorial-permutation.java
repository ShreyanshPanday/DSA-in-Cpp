class Solution {
    private static final int[] FACT = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    public boolean isDigitorialPermutation(int n) {
        if(n <= 0) return false;
        int[] count = new int[10];
        int temp = n;
        int totalFact = 0;
        while(temp > 0){
            int digit = temp % 10;
            count[digit]++;
            totalFact += FACT[digit];
            temp /= 10;
        }
        while(totalFact > 0){
            count[totalFact % 10]--;
            totalFact /= 10;
        }
        for(int i = 0; i < 10; i++) if(count[i] != 0) return false;
        return true;
    }
}