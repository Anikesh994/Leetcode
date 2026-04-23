class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,vector<pair<int,long long>>>um;
        for(int i=0;i<n;i++){
            if(um.find(nums[i])==um.end()){
                um[nums[i]].push_back({i,i});
            }
            else{
                int x =um[nums[i]].size();
                um[nums[i]].push_back({i,(um[nums[i]][x-1].second)+i});
            }
        }
        vector<long long >ans;
        for(int i=0;i<n;i++){
            if(um[nums[i]].size()==1){
                ans.push_back(0);
            }
            else{
                auto it = lower_bound(um[nums[i]].begin(),um[nums[i]].end(),make_pair(i, 0LL));
                int x1 =it-um[nums[i]].begin();
                long long  y1 = um[nums[i]][um[nums[i]].size()-1].second - it->second - 1LL *(um[nums[i]].size()-x1-1)*(it->first);
                long long y2 = 1LL *(x1+1)*it->first - it->second;
                ans.push_back(y1+y2);
            }
        }
        return ans;
    }
};