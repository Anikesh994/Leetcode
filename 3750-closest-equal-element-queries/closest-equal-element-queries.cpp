class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>um;
        int n =nums.size();
        for(int i =0;i<n;i++){
            um[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(um[nums[queries[i]]].size()==1){
                ans.push_back(-1);
            }
            else{
                auto it = lower_bound(um[nums[queries[i]]].begin(),um[nums[queries[i]]].end() ,queries[i] );
                int index = (it-um[nums[queries[i]]].begin());
                int prev = (um[nums[queries[i]]].size()+index-1)%(um[nums[queries[i]]].size());
                int next = (index + 1) % um[nums[queries[i]]].size();
                int d1 =abs(queries[i]-um[nums[queries[i]]][prev]);
                int d2 = abs(queries[i]-um[nums[queries[i]]][next]);
                d1=min(d1,n-d1);
                d2=min(d2,n-d2);
                int x = min(d1,d2);
                ans.push_back(x);
            }
        }
        return ans;
    }
};