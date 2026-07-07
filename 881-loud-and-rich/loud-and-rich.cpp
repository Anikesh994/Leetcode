class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> temp(n, 0);
        vector<vector<int>> adj(n);

        for (auto it : richer) {
            adj[it[0]].push_back(it[1]);
            temp[it[1]]++;
        }

        queue<int> qt;
        for (int i = 0; i < n; i++) {
            if (temp[i] == 0) qt.push(i);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = i;

        while (!qt.empty()) {
            auto it = qt.front();
            qt.pop();

            for (auto it1 : adj[it]) {
                if (quiet[ans[it1]] > quiet[ans[it]])
                    ans[it1] = ans[it];

                temp[it1]--;
                if (temp[it1] == 0)
                    qt.push(it1);
            }
        }

        return ans;
    }
};