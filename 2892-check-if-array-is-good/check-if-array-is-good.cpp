class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>temp;
        for(int i=0;i<n;i++){
            temp[nums[i]]++;
        }
        for(int i=1;i<n;i++){
            if(temp.find(i)==temp.end()) return false;
        }
        if(temp[n-1]!=2) return false;
        return true;
    }
};