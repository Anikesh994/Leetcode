class Solution {
private:
    const int mod=1e9 +7;
    vector<bool>prime;
    vector<int>spf;
    void sieve(){
        prime.resize(1000002,true);
        spf.resize(1000002);
        prime[1]=false;
        spf[1]=1;
        for(long long i=2;i<=1000000;i++){
            if(prime[i]){
                spf[i]=i;
                for(long long j=i*i;j<=1000000;j+=i){
                    prime[j]=false;
                    if(spf[j]==0){
                        spf[j]=i;
                    }
                }
            }
        }
    }
public:

    int divisibleGame(vector<int>& nums) {
        sieve();
        int n=nums.size();
        bool f1=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=1){
                f1=false;
                break;
            }
        }
        if(f1){
            return mod-2;
        }
        vector<int>pref(n+1);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        long long mx=-1e9;
        long long mn=1e9;

        set<int>chck;
        for(int i=0;i<n;i++){
            int w=nums[i];
            while(w>1){
                int temp=spf[w];
                chck.insert(temp);
                while(w%temp==0){
                    w/=temp;
                }
            }
        }

        for(auto &x:chck){
            long long curr=0;
            long long best=-1e9;
            for(int i=0;i<n;i++){
                long long dum=nums[i];
                if(nums[i]%x!=0) dum*=-1;
                curr+=dum;
                curr=max(curr,dum);
                best=max(best,curr);
            }
            // cout<<x<<' '<<best<<endl;
            if(best>mx){
                mx=best;
                mn=x;
            }
        }
        return (mx*mn + mod)%mod;
    }
};