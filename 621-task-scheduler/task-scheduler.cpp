class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int t = tasks.size();
        vector<int>count(26,0);
        int x=0;

        for(int i=0;i<t;i++){
            count[tasks[i]-'A']++;
            x=max(x,count[tasks[i]-'A']);
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(count[i]==x) c++;
        }
        int h = t-x*c;   
        long long ans = max(t,(x-1)*(n+1)+c + max(0,(h-(x-1)*n)));
        return ans;
    }
};