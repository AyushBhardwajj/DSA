class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int tot = r-l+1;

        vector<long long> up(tot,1);
        vector<long long> down(tot,1);

        int ind = 1;

        for(int i=1;i<tot;i++){
            up[i] = 1+up[i-1];
        }

        for(int i=tot-2;i>=0;i--){
            down[i] = 1+down[i+1];
        }

        long long mod = 1e9+7;

        while(ind<n){
            vector<long long> nup(tot,0);
            vector<long long> ndown(tot,0);

            for(int i=tot-2;i>=0;i--){
                nup[i] = down[i+1];
            }

            for(int i=1;i<tot;i++){
                nup[i] = (nup[i-1]+nup[i])%mod;
            }

            for(int i=1;i<tot;i++){
                ndown[i] = up[i-1];
            }

            for(int i=tot-2;i>=0;i--){
                ndown[i] = (ndown[i]+ndown[i+1])%mod;
            }

            ind++;
            down = ndown;
            up = nup;
        }

        long long ans = (down[0]+up[tot-1])%mod;

        return ans;
    }
};