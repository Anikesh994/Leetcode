class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, pair<int, int>> um;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                if (um.find(s[i]) == um.end()) {
                    um[s[i]] = {1, i};
                } else {
                    um[s[i]].first++;
                }
            }
        }
        vector<vector<int>> temp;
        for (auto it : um) {

            temp.push_back({it.second.first, it.second.second, it.first - 'a'});
        }
        sort(temp.begin(), temp.end(),[](auto & a,auto &b){
            if(a[0]==b[0]) return a[1] < b[1];
            return a[0]>b[0];
        });
        string s1 = "";
        for (auto it : temp) {
            for (int i = 0; i < it[0]; i++) {
                s1 += ('a' + it[2]);
            }
        }
        int r = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                s[i] = s1[r];
                r++;
            }
        }
        return s;
    }
};