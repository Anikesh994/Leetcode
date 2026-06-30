class Solution {
public:
    string shortestPalindrome(string s) {
       long long base = 131;
        long long mod = 1e9 + 7;

        long long forward = 0;
        long long backward = 0;
        long long power = 1;

        int length = 0;

        for (int i = 0; i < s.size(); i++) {
            int val = s[i];

            // hash of s[0...i]
            forward = (forward * base + val) % mod;

            // hash of reverse(s[0...i])
            backward = (backward + val * power) % mod;

            if (forward == backward) {
                length = i + 1;
            }

            power = (power * base) % mod;
        }

        string s2 = s.substr(length);
        reverse(s2.begin(), s2.end());

        return s2 + s;
    }
};