class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = 0;

        vector<int> krr(n,0);

        for(int i=0;i<n;i++){
            int z = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 0)z++;
                else break;
            }

            krr[i] = z;
        }

        int start = 0;

        while(start<n){
            int need = n-start-1;
            int frst = n+1;
            int zeros = -1;
            for(int j=start;j<n;j++){
                if(krr[j]>=need){
                    frst = j;
                    zeros = krr[j];
                    break;
                }
            }

            if(zeros == -1)return -1;

            for(int i=frst;i>start;i--){
                krr[i] = krr[i-1];
                ans++;
            }

            krr[start] = zeros;

            start++;

        }

        return ans;
    }
};