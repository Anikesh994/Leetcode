class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> um;

        for (auto it : nums) {
            um[it]++;
        }

        int ans = 1;

        if (um.count(1)) {
            if (um[1] % 2) ans = um[1];
            else ans = um[1] - 1;
        }

        for (auto it : um) {
            if (it.first == 1) continue;

            long long x = it.first;
            int cnt = 0;
            bool t = false;

            while (um.find(x) != um.end()) {
                if (um[x] >= 2) {
                    cnt += 2;
                }
                else if (um[x] == 1) {
                    cnt++;
                    t = true;
                    break;
                }

                if (x > 100000) break;
                x *= x;
            }

            if (!t) cnt--;

            ans = max(ans, cnt);
        }

        return ans;
    }
};