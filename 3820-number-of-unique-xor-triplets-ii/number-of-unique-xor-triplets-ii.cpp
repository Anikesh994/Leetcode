class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int>um1;
        unordered_map<int,int>um2;
        vector<int>temp;
        for(auto it : nums){
            if(!um1.count(it)){
                um1[it]++;
                temp.push_back(it);
            }
        }
        for(auto it : temp){
            for(auto it1 : temp){
                int x=it^it1; 
                um2[x]++;
            }
        }

        for(auto it : um2){
            for(int i=0;i<temp.size();i++){
                int x=it.first^temp[i]; 
                um1[x]++;
            }
        }
        return um1.size();
    }
};