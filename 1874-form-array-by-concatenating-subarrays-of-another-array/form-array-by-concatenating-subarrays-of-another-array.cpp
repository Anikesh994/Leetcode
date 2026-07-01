class Solution {

int kmp(vector<int>&temp ,vector<int>&nums ,int startIndex){
    int n=nums.size();
    int m =temp.size();
    vector<int>lps(m,0);
    int i=1;int length=0;
    while (i < m) {
        if (temp[i] == temp[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    i=startIndex;int j=0;
    while(i<n){
        if(nums[i]==temp[j]){
            i++;j++;
        }
        if(j==temp.size()){
            return i-j;
            
            
        }
        else if(i<n && nums[i]!=temp[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    return -1;
}


public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int prev=0;
        for(auto &it : groups){
            int x = kmp(it,nums ,prev);
            if(x==-1) return false;
            prev =x+it.size(); 
        }
        return true;
    }
};