class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int>um1;
        vector<int>temp;
        for(auto it : nums){
            if(!um1.count(it)){
                um1[it]++;
                temp.push_back(it);
            }
        }
        um1.clear();
        for(auto it : temp){
            for(auto it1 : temp){
                int x=it^it1; 
                um1[x]++;
            }
        }
        unordered_map<int,int>um;
        for(auto it : um1){
            for(int i=0;i<nums.size();i++){
                int x=it.first^nums[i]; 
                um[x]++;
            }
        }
        return um.size();
    }
};