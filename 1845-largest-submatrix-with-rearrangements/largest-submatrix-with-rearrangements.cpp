class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]=1+matrix[i-1][j];
                }
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            vector<int> vec;
            for(int j=0;j<m;j++){
                vec.push_back(matrix[i][j]);
            }

            sort(vec.begin(),vec.end(),greater<int>());

            for(int k=0;k<m;k++){
                int curr = vec[k]*(k+1);
                ans = max(ans,curr);
            }
        }

        return ans;
    }
};