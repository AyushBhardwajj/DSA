class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        //multiset<long long> s1,s2,s,s3;
        vector<int> s1(1e5+1,0),s2(1e5+1,0),s3(1e5+1,0),s(1e5+1,0);

        int n = grid.size(),m = grid[0].size();


        long long sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
                s1[grid[i][j]]++;
                s[grid[i][j]]++;
            }
        }

        if(n==1){
            long long sum2= 0;
            for(int i=0;i<m-1;i++){
                sum2+=grid[0][i];
                long long left = sum-sum2;

                if(left>sum2){
                    long long diff = left-sum2;
                    if(diff == grid[0][i+1] || diff == grid[0][m-1])return true;
                }
                else if(left == sum2)return true;

                else{
                    long long diff = sum2-left;
                    if(diff == grid[0][0] || diff == grid[0][i])return true;
                }


            }

            return false;
        }
        if(m==1){
            long long sum2= 0;
            for(int i=0;i<n-1;i++){
                sum2+=grid[i][0];
                long long left = sum-sum2;

                if(left>sum2){
                    long long diff = left-sum2;
                    if(diff == grid[i+1][0] || diff == grid[n-1][0])return true;
                }
                else if(left == sum2)return true;

                else{
                    long long diff = sum2-left;
                    if(diff == grid[0][0] || diff == grid[i][0])return true;
                }

            }

            return false;
        }

        long long sum2 = 0;

        for(int i=0;i<n;i++){
            vector<int> vec;
            for(int j=0;j<m;j++){
                sum2+=grid[i][j];
                if(i==0 && j!=0 && j!=m-1){
                    vec.push_back(grid[i][j]);
                }
                else{
                    s2[(grid[i][j])]++;
                }

                s[grid[i][j]]--;
                
            }

            long long left = sum-sum2;

            long long diff = abs(left-sum2);

            if(diff == 0){
                return true;
            }

            if(left>sum2){
                if(i!=n-2 && diff<=1e5 && s[diff]>0){
                    return true;
                }
                else if((i==n-2) && (grid[i+1][0] == diff || grid[i+1][m-1]==diff)){
                    return true;
                }
            }
            else{
                
                if(diff<=1e5 && s2[diff]>0){
                    return true;
                }
    
            }

            for(int k=0;k<vec.size();k++){
                s2[(vec[k])]++;
            }
        }

        sum2 = 0;

        for(int j=0;j<m;j++){
            vector<int> vec;
            for(int i=0;i<n;i++){
                sum2+=grid[i][j];
                if(j==0 && (i!=0 && i!=n-1) ){
                    vec.push_back(grid[i][j]);
                }
                else{
                    s3[(grid[i][j])]++;
                }

                s1[grid[i][j]]--;
                
            }

            long long left = sum-sum2;

            long long diff = abs(left-sum2);

            if(diff == 0){
                
                return true;
            }

            if(left>sum2){
                if(j!=m-2 && diff<=1e5 && s1[diff]>0){
                    
                    return true;
                }
                else if((j==m-2) && (grid[0][j+1]==diff || grid[n-1][j]==diff)){
                    
                    return true;
                }

            }
            else{
                if(diff<=1e5 && s3[diff]>0){
                    
                    return true;
                }
            }

            for(int k=0;k<vec.size();k++){
                s3[(vec[k])]++;
            }
        }

        return false;
        
    }
};