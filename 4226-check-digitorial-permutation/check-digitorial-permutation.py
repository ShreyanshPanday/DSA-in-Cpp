class Solution:
    def isDigitorialPermutation(self, n: int) -> bool:
        if(n <= 0):
            return False
        FACT = (1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880)
        temp = n
        count = [0] * 10
        totalFact = 0
        while temp > 0:
            digit = temp % 10
            totalFact += FACT[digit]
            count[digit] += 1
            temp //= 10
        while totalFact > 0:
            count[totalFact % 10] -= 1
            totalFact //= 10
        return all(c == 0 for c in count) 