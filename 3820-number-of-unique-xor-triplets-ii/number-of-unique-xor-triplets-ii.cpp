class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAX = 2048;

        bool present[MAX] = {};
        bool pairXor[MAX] = {};
        bool result[MAX] = {};

        for (int x : nums)
            present[x] = true;

        // All possible a ^ b
        for (int a = 1; a < MAX; a++) {
            if (!present[a]) continue;

            for (int b = 1; b < MAX; b++) {
                if (present[b])
                    pairXor[a ^ b] = true;
            }
        }

        // All possible (a ^ b) ^ c
        for (int x = 0; x < MAX; x++) {
            if (!pairXor[x]) continue;

            for (int c = 1; c < MAX; c++) {
                if (present[c])
                    result[x ^ c] = true;
            }
        }

        int count = 0;
        for (bool x : result)
            count += x;

        return count;
    }
};