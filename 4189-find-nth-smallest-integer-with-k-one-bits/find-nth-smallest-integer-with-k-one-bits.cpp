class Solution {
public:
    long long nthSmallest(long long n, int k) {
        // long long comb[51][51] = {0};

        // for(int i=0;i<=50;i++){
        //     comb[i][0]=1;
        //     for(int j=1;j<=i;j++){
        //         comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
        //     }
        // }

        // long long res = 0,c=0;

        // for(int i=49;i>=0;i--){
        //     c = comb[i][k];
        //     if(n>c){
        //         res =  res|1ll<<i;
        //         n-=c;
        //     }
        // }

        // return res;

        long long comb[51][51] = {0};
        for (int i = 0; i <= 50; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            }
        }
        
        long long res = 0, c = 0;
        for (int i = 49; i >= 0; i--) {
            c = comb[i][k];
            if (n > c) {
                res |= 1LL << i;
                n -= c;
                k--;
            }
        }
        return res;
    }
};