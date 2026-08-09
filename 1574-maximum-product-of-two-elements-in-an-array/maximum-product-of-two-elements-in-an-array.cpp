class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int  m1=INT_MIN;
        int m2=INT_MIN;
        for(auto it : nums){
            if(m1 <it){
                m2=m1;
                m1=it;
            }
            else{
                m2=max(m2,it);
            }
        }
        return ((m1-1)*(m2-1));
    }
};