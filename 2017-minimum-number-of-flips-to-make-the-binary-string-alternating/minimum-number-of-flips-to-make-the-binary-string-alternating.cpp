class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        vector<vector<int>> vec(2,vector<int>(n,0));

        char ch1 = '0',ch2 = '1';
        int ans1 = 0,ans2 = 0;

        for(int i=0;i<n;i++){
            if(ch1!=s[i]){
                ans1++;
            }

            if(ch2!=s[i])ans2++;

            if(ch1=='0')ch1='1';
            else ch1 = '0';

            if(ch2 == '1')ch2='0';
            else ch2 = '1';

            vec[0][i]= ans1;
            vec[1][i] = ans2;
        }

        int ans = min(ans1,ans2);

        for(int i=1;i<n;i++){
            int tot = n-i;

            if(i%2){
                char ch3 = '1';
                char ch4 = '0';

                if(tot%2){
                    continue;
                }
                else{
                    int curr1 = ans1-vec[0][i-1]+vec[1][i-1];
                    int curr2  = ans2-vec[1][i-1]+vec[0][i-1];

                    ans = min({ans,curr1,curr2});
                }
            }
            else{
                if(tot%2==0){
                    continue;
                }
                else{
                    int curr1 = ans1-vec[0][i-1]+vec[1][i-1];
                    int curr2  = ans2-vec[1][i-1]+vec[0][i-1];

                    ans = min({ans,curr1,curr2});
                }
            }
        }

        return ans;

    }
};