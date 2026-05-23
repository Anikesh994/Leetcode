class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>zeros;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                zeros.push_back(i);
            }
        }
        vector<int>ans(n,1);
        unordered_map<int,int>temp;
        for(int i=0;i<n;i++){
            if(temp.find(rains[i])==temp.end() && rains[i]!=0){
                temp[rains[i]]=i;
                ans[i]=-1;
            }
            else if(temp.find(rains[i])!=temp.end() && rains[i]!=0){
                ans[i]=-1;
                auto it = upper_bound(zeros.begin(),zeros.end(),temp[rains[i]]);
                if(it==zeros.end() || *it>i) return {};
                ans[*it]=rains[i];
                zeros.erase(it);
                temp[rains[i]]=i;

            }
        }
        return ans;
    }
};