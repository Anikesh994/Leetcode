class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int i=0;
        int ans=0;
        if(k==1) return r-l+1;
        while( true){
            long long x=1;
            for(int j=0;j<k;j++){
                x*=i;
            }
            if(x>r) break;
            if(x>=l) ans++;
            i++;
        }
        return ans;
    }
};