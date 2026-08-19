class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>> mp;

        sort(reservedSeats.begin(),reservedSeats.end());

        //int n = reservedSeats.size();

        for(int i=0;i<reservedSeats.size();i++){
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }

        int ans = 0;
        int curr = 1;

        for(auto it:mp){
            int num = it.first;
            int tot = num-curr;
            curr = num+1;
            ans += tot*2;

            bool flag1 = true;

            int m = it.second.size();

            for(int i=0;i<m;i++){
                if(it.second[i]==2 || it.second[i]==3 || it.second[i]==4 || it.second[i]==5){
                    flag1 = false;
                    break;
                }
            }

            if(flag1)ans++;

            bool flag2 = true;

            for(int i=0;i<m;i++){
                if(it.second[i]==4 || it.second[i]==5 || it.second[i]==6 || it.second[i]==7){
                    flag2 = false;
                    break;
                }
            }

            if(flag1 == false && flag2 == true){
                ans++;
                continue;
            }

            bool flag3 = true;

            for(int i=0;i<m;i++){
                if(it.second[i]==6 || it.second[i]==7 || it.second[i]==8 || it.second[i]==9){
                    flag3 = false;
                    break;
                }
            }

            if(flag3)ans++;
        }

        if(curr<=n){
            ans += 2*(n-curr+1);
        }

        return ans;
    }
};