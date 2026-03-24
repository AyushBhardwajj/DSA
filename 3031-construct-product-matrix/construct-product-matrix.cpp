class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> back = grid;

        int n = grid.size(),m = grid[0].size();

        int mod = 12345;

        back[n-1][m-1] = (grid[n-1][m-1])%mod;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==m-1){
                    if(i!=n-1){
                        long long curr = (1ll*((back[i][j])%mod)*back[i+1][0])%mod;
                        back[i][j] = (int)curr;
                    }
                }
                else{
                    long long curr = (1ll*((back[i][j])%mod)*back[i][j+1])%mod;
                    back[i][j] = (int)curr;
                }
            }
        }

        vector<vector<int>> anst(n,vector<int>(m,0));

        long long fwd = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                anst[i][j] = (int)fwd;
                if(j==0){
                    if(j+1<m){
                        anst[i][j] = (int)((1ll*anst[i][j]*back[i][j+1]))%mod;
                    }
                    else if(i+1<n){
                        anst[i][j] = (int)((1ll*anst[i][j]*back[i+1][0]))%mod;
                    }
                }
                else if(j==m-1){
                    if(i+1<n){
                        anst[i][j] = (int)((1ll*anst[i][j]*back[i+1][0]))%mod;
                    }
                }
                else{
                    anst[i][j] = (int)((1ll*anst[i][j]*back[i][j+1]))%mod;
                }

                fwd = (fwd*grid[i][j])%mod;
            }
        }

        return anst;
    }
};