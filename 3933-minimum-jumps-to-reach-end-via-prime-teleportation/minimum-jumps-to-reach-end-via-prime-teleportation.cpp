class Solution {


void seive(int n , vector<bool>&isprime){
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(!isprime[i]) continue;
        for(int j=i*i;j<=n;j+=i){
            isprime[j]=false;
        }
    }
}



public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool>isprime(mx+1,true);
        seive(mx,isprime);
        vector<vector<int>> temp(mx+1);
        for (int i=0; i<n; i++) {
            temp[nums[i]].push_back(i);
        }
        
        queue<pair<int,int>>qt;
        vector<int>vis(n,-1);
        vis[0]=1;
        qt.push({0,0});
        while(!qt.empty()){
            auto it =qt.front();
            qt.pop();
            if(it.first==n-1) return it.second;
            if(it.first+1 <n && vis[it.first+1]==-1){
                vis[it.first+1]=1;
                qt.push({it.first+1,it.second+1});
            }
            if(it.first-1 >=0 && vis[it.first-1]==-1){
                qt.push({it.first-1,it.second+1});
                vis[it.first-1]=1;
            }
            if(isprime[nums[it.first]]){
                for(int m =nums[it.first];m<=mx;m+=nums[it.first]){
                    for(auto w : temp[m]){
                        if(vis[w]==-1){
                            qt.push({w,it.second+1});
                            vis[w]=1;
                        }
                    }
                    temp[m].clear();
                }
                isprime[nums[it.first]]=false;
                
            }

        }
        return 0;
    }
};