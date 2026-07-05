class Solution {
public:
    int MOD = 1e9 + 7;

    int divisibleGame(vector<int>& nums) {
        unordered_set<int> st;

        // Collect all candidate divisors (>1)
        for (int x : nums) {
            for (int d = 2; 1LL * d * d <= x; d++) {
                if (x % d == 0) {
                    st.insert(d);
                    st.insert(x / d);
                }
            }
            if (x > 1)
                st.insert(x);
        }

        if (st.empty())
            st.insert(2);

        vector<int> divs(st.begin(), st.end());
        sort(divs.begin(), divs.end());

        long long bestDif = LLONG_MIN;
        int bestK = 2;

        for (int k : divs) {
            long long cur = LLONG_MIN;

            for (int x : nums) {
                long long val = (x % k == 0) ? x : -1LL * x;

                if (cur == LLONG_MIN)
                    cur = val;
                else
                    cur = max(val, cur + val);

                if (cur > bestDif || (cur == bestDif && k < bestK)) {
                    bestDif = cur;
                    bestK = k;
                }
            }
        }

        long long ans = ((bestDif % MOD) + MOD) % MOD;
        ans = (ans * bestK) % MOD;

        return (int)ans;
    }
};