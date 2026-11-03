class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int row,int prev,vector<vector<char>> &seats){
        if(row == n)return 0;

        int ans = 0;

        if(dp[row][prev]!=-1)return dp[row][prev];

        for(int i=0;i<(1<<m);i++){
            int num = i;
            int cnt = 0;
            vector<char> str = seats[row];
            int col = 0;
            while(num>0){
                if(num&1){
                    if(str[col]!='.')break;
                    if(col>0){
                        if(seats[row][col-1]=='$')break;
                        if(row>0 && seats[row-1][col-1]=='$')break;
                    }
                    if(col<m-1){
                        if(seats[row][col+1]=='$')break;
                        if(row>0 && seats[row-1][col+1]=='$')break;
                    }

                    cnt++;
                    if(num!=0)num = num>>1;
                    if(num&1)break;
                    col++;
                }

                if(num!=0)num = num>>1;
                col++;
            }

            if(num==0){
                num = i;
                col = 0;
                while(num>0){
                    if(num&1){
                        seats[row][col]='$';
                    }

                    num = num>>1;
                    col++;
                }
                ans = max(ans,cnt+solve(row+1,i,seats));
                num = i;
                col = 0;
                while(num>0){
                    if(num&1){
                        seats[row][col]='.';
                    }

                    num = num>>1;
                    col++;
                }
            }
        }

        return dp[row][prev] = ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        this->n = seats.size(), this->m = seats[0].size();
        dp.resize(n,vector<int>((1<<m),-1));

        return solve(0,0,seats);
    }
};