class Solution {

    bool chek(int q ,int k , vector<vector<int>>&temp){
        int n =temp.size();
        for(int i=0;i<n;i++){
            int count=1;
            int last =i;
            for(int j=1;j<n;j++){
                int idx =(i + j)%n;
                if(idx<=i) return false;
                int dist = abs(temp[idx][0]-temp[last][0]) + abs(temp[idx][1]-temp[last][1]);
                if(dist >=q){
                    count++;
                    last =idx;
                    if (count == k) {
                        int finalDist = abs(temp[last][0] - temp[i][0]) + abs(temp[last][1] - temp[i][1]);

                        if (finalDist >= q) return true;
                        break;
                    }
                }

            }

        }
        return false;
    }


public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<vector<vector<int>>>temp(4);
        int n =points.size();
        for (auto it : points) {
            if (it[0] == 0 && it[1] != side) {
                temp[0].push_back(it); 
            }
            else if (it[1] == side && it[0] != side) {
                temp[1].push_back(it);    
            }
            else if (it[0] == side && it[1] != 0) {
                temp[2].push_back(it); 
            }
            else {
                temp[3].push_back(it); 
            }
        }
        sort(temp[0].begin(), temp[0].end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        sort(temp[1].begin(), temp[1].end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });

        sort(temp[2].begin(), temp[2].end(), [](auto &a, auto &b){
            return a[1] > b[1]; 
        });

        sort(temp[3].begin(), temp[3].end(), [](auto &a, auto &b){
            return a[0] > b[0];  
        });
        temp[0].insert(temp[0].end(),temp[1].begin(),temp[1].end());
        temp[0].insert(temp[0].end(),temp[2].begin(),temp[2].end());
        temp[0].insert(temp[0].end(),temp[3].begin(),temp[3].end());
        temp.pop_back();
        temp.pop_back();
        temp.pop_back();
        long long low=0;
        long long high = 2*side;
        long long ans=0;
        while(low<=high){
            long long mid =(low + high)/2;
            if(chek(mid,k,temp[0])){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};