class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR = (int)t.back();
        for(int i = 0; i < s.size(); i++){
            XOR ^= int(s[i] ^ t[i]);
        }
        return (char)XOR;
    }
};