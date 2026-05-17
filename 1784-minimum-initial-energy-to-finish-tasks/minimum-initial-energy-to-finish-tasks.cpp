class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int index=-1;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(tasks[i][1]-tasks[i][0]);
        }
        sort(tasks.begin(),tasks.end() , [](vector<int>&a , vector<int>&b){
           return a[2]>b[2];
        });
        int ans=0;
        int hold=0;
        for(int i=0;i<n;i++){
            if(hold < tasks[i][1]) {
                ans += (tasks[i][1] - hold);
                hold = tasks[i][1];
            }
            hold -= tasks[i][0];
        }
        return ans;

    }
};