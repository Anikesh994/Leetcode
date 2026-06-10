class Solution {
public:
    int n ;
    vector<pair<int,int>> sgmt;
    void build(int i , int l , int r,vector<int>& nums){
        if(l==r){
            sgmt[i] = {nums[l],nums[r]};
            return;
        }
        int mi = l + (r-l)/2;
        build(i*2+1 , l , mi , nums);
        build(i*2+2 , mi+1 , r , nums);
        sgmt[i].first = max( sgmt[i*2+1].first , sgmt[i*2+2].first );
        sgmt[i].second = min( sgmt[i*2+1].second , sgmt[i*2+2].second );
    }
    pair<int,int> q(int i , int start , int last , int l , int r ){
        if( l > last ||  r < start) return {INT_MIN  , INT_MAX};
        if( l >= start && r <= last) return sgmt[i];
        int mi = l + (r-l)/2;
        auto lft = q(i*2 + 1,start,last,l,mi);
        auto rght = q(i*2 + 2,start,last,mi+1,r);
        return {max(lft.first,rght.first) , min(lft.second,rght.second)};
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        int sz = nums.size();
        n = sz;
        sgmt.resize(n*4);
        build(0,0,sz-1,nums);
        long long ans = 0 ;
        priority_queue<tuple<int,int,int>> pq;
        for(int i = 0 ; i < n-1 ; i++){
            auto [mx,mn] = q(0,i,n-1,0,n-1);
            pq.push({mx-mn , i , n-1});
        }
        while(k-- && !pq.empty()){
                auto[val,l,r] = pq.top();
                pq.pop();
                ans+=val;
                if(r-l > 1){
                auto [mx,mn] = q(0,l,r-1,0,n-1);
                pq.push({mx-mn,l,r-1});
                }
            }
    return ans;
    }
};