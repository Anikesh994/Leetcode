class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        long long a1=0;
        long long a2=0;
        int low=0;int high = piles.size()-1;
        int x=0;
        int i=0;
        while(low<high){
            if(piles[low]<=piles[high]){
                x=piles[low];
                low++;
            }
            else{
                x=piles[high];
                high--;
            }
            if(i%2==0){
                a1+=x;
            }
            else{
                a2+=x;
            }
        }
        if(a1>a2) return true;
        return false;
    }
};