class Solution {
    int solve(int n){
       vector<int>temp;
        while(n>0){
            temp.push_back(n%10);
            n=n/10;
        }
        int ans;
        for(int i=1;i<temp.size()-1;i++){
            if(temp[i]>temp[i-1] && temp[i]>temp[i+1]) ans++;
            else if(temp[i]<temp[i-1] && temp[i]<temp[i+1]) ans++;
        }
        return ans;
    }
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=solve(i);
        }
        return ans;
    }
};