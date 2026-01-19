class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int t) {
        int ans = 0;
        int n = mat.size(),m = mat[0].size();
        int mint = min(n,m);
        int start = 1,end = min(n,m);

        vector<vector<int>> row(n+1,vector<int>(m+1,0));
        vector<vector<int>> col(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i+1][j+1] = mat[i][j] + row[i+1][j];
                col[i+1][j+1] = col[i][j+1]+mat[i][j];
            }
        }

        while(start<=end){
            int mid = (start)+(end-start)/2;
            bool flag = false;

            for(int i=1;i<=n-mid+1;i++){
                for(int j=1;j<=m-mid+1;j++){
                    int sum = 0;
                    
                    for(int k=0;k<mid;k++){
                        sum += row[i+k][j+mid-1]-row[i+k][j-1];
                    }

                    if(sum<=t){
                        flag = true;
                        break;
                    }
                    
                }
                if(flag)break;
            }

            if(flag){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        } 

        return ans;  
    }
};