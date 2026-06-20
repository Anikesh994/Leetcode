class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty()) return n - 1;
        sort(restrictions.begin(),restrictions.end());
        int n1 =restrictions.size();
        for(int i=0;i<n1;i++){
            if(i==0){
                if(restrictions[i][1]>restrictions[i][0]-1){
                    restrictions[i][1]=restrictions[i][0]-1;
                }
            }
            else{
                if(restrictions[i][1]>(restrictions[i][0]-restrictions[i-1][0] + restrictions[i-1][1])){
                    restrictions[i][1]=(restrictions[i][0]-restrictions[i-1][0] + restrictions[i-1][1]);
                }
            }
        }

        for(int i = n1 - 2; i >= 0; i--){
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                restrictions[i + 1][0] - restrictions[i][0]
            );
        }


        int ans=0;
        for(int i=n1-1;i>0;i--){
            int a0 =restrictions[i][0] - restrictions[i-1][0];
            int a1 =abs(restrictions[i][1] - restrictions[i-1][1]);
            int m1 = max(restrictions[i][1] , restrictions[i-1][1]);
            ans =max(ans ,(m1+(a0-a1)/2));
        }
        if(restrictions[0][1] >=restrictions[0][0]-1){
            ans=max(ans,restrictions[0][0]-1);
        }
        else if(restrictions[0][1] < restrictions[0][0]-1){
            ans=max(ans , (restrictions[0][0]-1+restrictions[0][1] )/2);
        }
        ans=max(ans,min(restrictions[0][1],restrictions[0][0]-1));
        if(restrictions[n1-1][0]!=n1){
            ans =max(ans , restrictions[n1-1][1]+ (n-restrictions[n1-1][0]));
        }
        return ans;
    }
};