class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v1;
        v1.push_back(intervals[0]);
        int n =intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<= v1[v1.size()-1][1]){
                v1[v1.size()-1][1] = max(intervals[i][1],v1[v1.size()-1][1]);
            }
            else{
                v1.push_back(intervals[i]);
            }
        }
        return v1;
    }
};