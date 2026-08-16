class Solution {

int digitProduct(int n){
    int ans=1;
    while(n>0){
        ans*=(n%10);
        n=n/10;
    }
    return ans;
}

public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+100;i++){
            int x = digitProduct(i);
            if(x%t==0) return i;
        }
        return -1;
    }
};