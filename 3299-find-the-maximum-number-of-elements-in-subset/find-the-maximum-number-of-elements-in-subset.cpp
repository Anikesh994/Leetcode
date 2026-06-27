class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> um;
        int ans = 0;
        for (auto it : nums) {
            um[it]++;
        }
        if (um.count(1)) {
            if (um[1] % 2) ans = um[1];
            else ans = um[1] - 1;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, int> um1;
        
        for (auto it : nums) {
            if (it == 1) continue; 
            if(um1.find(it)!=um1.end()) continue;
            int cnt = 0;
            long long x = it;
            bool t=false;
            while (um.find(x) != um.end()) {
                if (um[x] >= 2) {
                    cnt += 2;

                    um1[it]++;
                   
                } 
                else if (um[x] == 1) {
                    cnt++;
                   um1[it]++;
                    t = true;
                    break;
                }
                if(x > 1e5) break;
                x*=x;
            }
            if(!t) cnt--;
            ans=max(ans,cnt);
            
            

        }
        return ans;
    }
};