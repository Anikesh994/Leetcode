class Solution {

void solve(int n ,vector<int>&ans){
    int i=0;
    while(n>0){
        ans.push_back(n%10);
        n=n/10;
        i++;
    }
    reverse(ans.end()-i ,ans.end());
    
}



public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            solve(nums[i],ans);
        }
        return ans;
    }
};