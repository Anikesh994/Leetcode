class Solution {
    vector<vector<string>> ans;

    bool ispal(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void solve(int i, string s, string curr,
               vector<string>& temp) {

        int n = s.size();

        if (i == n) {
            if (curr.empty())
                ans.push_back(temp);
            return;
        }

        curr += s[i];

        // TAKE
        if (ispal(curr)) {
            temp.push_back(curr);
            solve(i + 1, s, "", temp);
            temp.pop_back();
        }

        // NOT TAKE
        solve(i + 1, s, curr, temp);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, s, "", temp);
        return ans;
    }
};