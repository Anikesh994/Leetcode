class Solution {

public:
    int countSubstrings(string s) {
        int n =s.size();
        vector<vector<bool>>pal(n,vector<bool>(n,0));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        pal[i][j]=true;
                    }
                    else{
                        pal[i][j] = pal[i+1][j-1];
                    }
                }
                if(pal[i][j]) ans++;
            }

        }
        return ans;
    }
};