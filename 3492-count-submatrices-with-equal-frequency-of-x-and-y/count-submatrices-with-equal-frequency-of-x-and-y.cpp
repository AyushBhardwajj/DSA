class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> xx(n,vector<int>(m,0));

        if(grid[0][0]=='X')xx[0][0]=1;
        for(int i=1;i<m;i++){
            xx[0][i] = xx[0][i-1];
            if(grid[0][i]=='X')xx[0][i]++;
        }

        for(int i=1;i<n;i++){
            xx[i][0] = xx[i-1][0];
            if(grid[i][0]=='X')xx[i][0]++;
        }

        int ans = 0;

        vector<vector<int>> vec(n,vector<int>(m,0));

        if(grid[0][0]=='X'){
            vec[0][0]=1;
        }
        else if(grid[0][0]=='Y')vec[0][0]=-1;

        int r = n,c = m;
        

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]=='X'){
                    xx[i][j]++;
                }
                xx[i][j] += xx[i-1][j]+xx[i][j-1]-xx[i-1][j-1];

            }
        }


        for(int i=1;i<n;i++){
            vec[i][0] = vec[i-1][0];
            if(grid[i][0]=='X')vec[i][0]++;
            else if(grid[i][0]=='Y')vec[i][0]--;
            if(xx[i][0]>0 && vec[i][0]==0)ans++;
        }

        for(int i=1;i<m;i++){
            vec[0][i] = vec[0][i-1];
            if(grid[0][i]=='X')vec[0][i]++;
            else if(grid[0][i]=='Y')vec[0][i]--;
            if(xx[0][i]>0 && vec[0][i]==0)ans++;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                vec[i][j] = vec[i-1][j]+vec[i][j-1]-vec[i-1][j-1];
                xx[i][j] = xx[i-1][j]+xx[i][j-1]-xx[i-1][j-1];
                if(grid[i][j]=='X'){
                    vec[i][j]++;
                    xx[i][j]++;
                }
                else if(grid[i][j]=='Y'){
                    vec[i][j]--;
                }
                if(vec[i][j]==0 && xx[i][j]>0){
                    ans++;
                }
            }
        }

        return ans;
    }
};