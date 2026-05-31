class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n =asteroids.size();
        priority_queue<int,vector<int> ,greater<int>>pq;
        long long ans=mass;
        for(int i=0;i<n;i++){
            pq.push(asteroids[i]);
        }
        for(int i=0;i<n;i++){
            if(ans < pq.top()) return false;
            else{
                ans+=pq.top();
                pq.pop();
            }
        }
        return true;
    }
};