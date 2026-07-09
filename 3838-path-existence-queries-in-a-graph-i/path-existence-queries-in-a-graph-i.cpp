class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>temp(n,0);
        int c=0;
        for(int  i=1;i<n;i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                temp[i]=c;
            }
            else{
                c++;
                temp[i]=c;
            }
        }
        vector<bool> ans;
        for(auto it : queries){
            if(temp[it[0]]==temp[it[1]]) ans.push_back(true);
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};