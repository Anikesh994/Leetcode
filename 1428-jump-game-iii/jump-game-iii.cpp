class Solution {

bool solve(int start,vector<int>& arr,vector<int>&vis ){
    if(start <0 || start >=arr.size()) return false;
    if(vis[start]!=-1) return false;
    if(arr[start]==0) return true;
    vis[start]=1;
    int low=solve(start-arr[start] ,arr ,vis);
    int high=solve(start+arr[start] ,arr ,vis);
    return low||high;
}




public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),-1);
        return solve(start ,arr,vis);
        
    }
};