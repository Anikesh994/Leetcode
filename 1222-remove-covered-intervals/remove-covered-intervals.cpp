class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];   
        return a[0] < b[0];       
        });
        int ans=1;
        auto it1  =intervals[0];
        for(int i=1;i<n;i++){
            if(it1[0]<=intervals[i][0]  && it1[1]>= intervals[i][1]) continue;
            else{
                it1=intervals[i];
                ans++;
            }
        }
        return ans;
    }
};