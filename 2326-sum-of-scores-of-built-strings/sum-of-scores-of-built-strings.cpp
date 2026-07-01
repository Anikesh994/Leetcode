class Solution {

long long  Z(string &s){
    int n=s.size();
    long long ans=0;
    vector<int>z(n,0);
    int l=0;
    int r=0;
    for(int i=1;i<n;i++){
        if(i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }

        while(i+z[i] <n && s[z[i]] == s[z[i]+i]){
            z[i]++;
        }
        if(i+z[i]-1 >r){
            l=i;
            r=i+z[i]-1;
        }
        ans+=z[i];

    }
    ans+=s.size();
    return ans;
    
}



public:
    long long sumScores(string s) {
        return Z(s);
    }
};




