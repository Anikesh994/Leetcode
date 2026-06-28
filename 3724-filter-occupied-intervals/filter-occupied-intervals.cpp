class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n =occupiedIntervals.size();
        vector<vector<int>>temp,ans;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        temp.push_back(occupiedIntervals[0]);
        for(int i=1;i<n;i++){
            if(occupiedIntervals[i][0]>=freeStart && occupiedIntervals[i][1]<=freeEnd) continue;
            auto &it = temp[temp.size()-1];
            if((it[1]>= occupiedIntervals[i][0]) || (it[1]+1== occupiedIntervals[i][0])){
                it[1]=max(it[1],occupiedIntervals[i][1]);
            }
            else{
                temp.push_back(occupiedIntervals[i]);
            }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i][1] < freeStart || temp[i][0] > freeEnd){
                ans.push_back(temp[i]);
                continue;
            }
            if(temp[i][0] < freeStart ){
                ans.push_back({temp[i][0],freeStart-1});
                 
                
            }
            if(temp[i][1] > freeEnd){
                ans.push_back({freeEnd+1,temp[i][1]});
            }
            
        }
        return ans;
    }
};