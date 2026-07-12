class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string>temp(m,string(n,'#'));
        if(k==1){
            
            
            for(int i=0;i<m;i++){
                temp[i][n-1]='.';
            }
            for(int i=0;i<n;i++){
                temp[0][i]='.';
            }
            return temp;
        }
        if(k==2){
            int x =min(n,m);
            if(x==1) return {};
            else{
                
                temp[m-1][n-1]='.';
                temp[m-1][n-2]='.';
                temp[m-2][n-1]='.';
                temp[m-2][n-2]='.';
                for(int i=0;i<m-1;i++){
                    temp[i][n-2]='.';
                }
                for(int i=0;i<n-1;i++){
                    temp[0][i]='.';
                }
                return temp;
            }
        }
        if(k==3){
            if(m==2 && n>=3){
                for(int i=0;i<n;i++){
                    temp[0][i]='.';
                }
                temp[1][n-1]='.';
                temp[1][n-2]='.';
                temp[1][n-3]='.';
                return temp;
            }
            else if(n==2 && m>=3){
                for(int i=0;i<m;i++){
                    temp[i][0]='.';
                }
                temp[m-1][1]='.';
                temp[m-2][1]='.';
                temp[m-3][1]='.';
                return temp;
            }
            else if(m>=3 && n>=3){
        
                temp[m-1][n-1]='.';
                temp[m-1][n-2]='.';
                temp[m-2][n-1]='.';
                temp[m-2][n-2]='.';
                temp[m-1][n-3]='.';
                temp[m-2][n-3]='.';
                temp[m-3][n-3]='.';
                for(int i=0;i<m-2;i++){
                    temp[i][n-3]='.';
                }
                for(int i=0;i<n-2;i++){
                    temp[0][i]='.';
                }
                return temp;
            }
            return {};
        }
        if(k==4){
            if(m==2 && n>=4){
                for(int i=0;i<n;i++){
                    temp[0][i]='.';
                }
                temp[1][n-1]='.';
                temp[1][n-2]='.';
                temp[1][n-3]='.';
                temp[1][n-4]='.';
                return temp;
            }
            else if(n==2 && m>=4){
                for(int i=0;i<m;i++){
                    temp[i][0]='.';
                }
                temp[m-1][1]='.';
                temp[m-2][1]='.';
                temp[m-3][1]='.';
                temp[m-4][1]='.';
                return temp;
            }
            else if(m>=3 && n>=3){
        
                temp[m-1][n-1]='.';
                temp[m-1][n-2]='.';
                temp[m-2][n-1]='.';
                temp[m-2][n-2]='.';
                temp[m-2][n-3]='.';
                temp[m-3][n-2]='.';
                for(int i=0;i<m-2;i++){
                    temp[i][n-3]='.';
                }
                for(int i=0;i<n-2;i++){
                    temp[0][i]='.';
                }
                return temp;
            }
            return {};
        }
        return {};
    }
};