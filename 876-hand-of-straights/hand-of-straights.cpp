class Solution {

public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n =hand.size();
        map<int,int>um;
        for(int i=0;i<n;i++){
            um[hand[i]]++;
        }
        while(!um.empty()){
            int x= um.begin()->first;
            um[x]--;
            if(um[x]==0) um.erase(x);
            for(int i=0;i<groupSize-1;i++){
                if(um.find(x+1)==um.end()) return false;
                um[x+1]--;
                if(um[x+1]==0) um.erase(x+1);
                x++;
            }
        }
        return true;
    }
};