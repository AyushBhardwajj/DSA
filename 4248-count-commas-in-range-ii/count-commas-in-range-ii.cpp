class Solution {
public:
    long long countCommas(long long n) {
        vector<pair<long long,int>> vec;

        vec.push_back({0ll,0});
        vec.push_back({1000,1});
        vec.push_back({1000000,2});
        vec.push_back({1000000000,3});
        vec.push_back({1000000000000,4});
        vec.push_back({1000000000000000,5});

        long long ans = 0;

        for(int i=5;i>=1;i--){
            long long frst = vec[i].first;
            int sec = vec[i].second;
            if(frst<=n){
                ans =  ans + (n-frst+1)*sec;
                n = frst-1;
            }
        }

        return ans;
        
    }
};