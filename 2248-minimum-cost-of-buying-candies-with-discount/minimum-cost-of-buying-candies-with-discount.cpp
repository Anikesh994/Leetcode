class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int sum=0;
        for(int i=0;i<n;i++){
            if((i+1)%3==0) continue;
            else{
                sum+=cost[i];
            }
        }
        return sum;
    }
};