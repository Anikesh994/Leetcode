class DSU {
    public : 
    vector<int>par;
    vector<int>size;

    DSU(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int findPar(int x){
        if(par[x]==x) return x;
        return par[x] = findPar(par[x]);
    }

    bool unite(int u,int v){
        int x= findPar(u);
        int y= findPar(v);
        if(x==y) return true;

        else if(size[x]>size[y]){
            size[x]+=size[y];
            par[y]=x;
        }
        else{
            size[y]+=size[x];
            par[x] =y;
        }
        return false;
    }


};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        DSU dsu(n*m);
        int ar1[2] = {1,0};
        int ar2[2] ={0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int q=0;q<2;q++){
                    int nr = i+ar1[q];
                    int nc = j+ ar2[q];
                    if(nr >=0 && nc >=0 && nr <n && nc <m && grid[i][j]==grid[nr][nc]){
                        int id1 =i*m + j;
                        int id2 =nr *m +nc;
                        if(dsu.unite(id1,id2)) return true;
                    }
                }
            }
        }
        return false;
    }
};