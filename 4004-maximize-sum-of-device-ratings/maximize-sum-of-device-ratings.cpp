class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        multiset<int> mt;

        long long ans = 0;

        vector<int> vect;

        int mint = units[0][0];

        for(int i=0;i<units.size();i++){
            sort(units[i].begin(),units[i].end());
            mint = min(mint,units[i][0]);
            int siz = units[i].size();
            if(siz>1)vect.push_back(units[i][1]);
            else{
                vect.push_back(units[i][0]);
            }
        }

        sort(vect.begin(),vect.end());

        int n = units.size();

        for(int i=n-1;i>=1;i--){
            ans += vect[i];
        }

        ans+=mint;

        return ans;
    }
};