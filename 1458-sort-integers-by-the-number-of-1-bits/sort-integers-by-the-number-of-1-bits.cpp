class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vec;

        for(int i=0;i<arr.size();i++){
            int num = arr[i];
            int cnt = 0;

            while(num>0){
                if(num&1)cnt++;
                num = num>>1;
            }

            vec.push_back({cnt,arr[i]});
        }

        sort(vec.begin(),vec.end());

        vector<int> ans;

        for(int i=0;i<vec.size();i++){
            ans.push_back(vec[i].second);
        }

        return ans;


    }
};