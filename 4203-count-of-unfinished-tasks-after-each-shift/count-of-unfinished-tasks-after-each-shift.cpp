class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n  = tasks.size();
        int m = shifts.size();
        vector<long long>pre(n+1,0);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+tasks[i-1];
        }
        vector<int>ans(m,0);
        long long cur=0;
        for(int i=0;i<m;i++){
            long long x = shifts[i]+cur;
            auto it = upper_bound(pre.begin(),pre.end(),x);
            int y = it-pre.begin();
            if(n+1 - y==0){
                cur=0;
                ans[i]=0;
            }
            else{
                cur = x;
                ans[i] = n+1-y;
            }
        }
        return ans;
    }
};