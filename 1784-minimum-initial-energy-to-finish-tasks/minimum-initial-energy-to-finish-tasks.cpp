class Solution {
public:
    int solve(vector<pair<int,int>> &vec,int mid){
        for(int i=0;i<vec.size();i++){
            if(vec[i].first>mid)return false;

            mid = mid-vec[i].second;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int start = 0,end = 1e9;
        int ans = 1e8;

        vector<pair<int,int>> vec;

        for(int i=0;i<tasks.size();i++){
            vec.push_back({tasks[i][1],tasks[i][0]});
        }

        sort(vec.begin(),vec.end(),[&](pair<int,int> &a,pair<int,int> &b){
            return a.first-a.second > b.first-b.second ;
        });

        while(start<=end){
            int mid = start+(end-start)/2;

            bool f = solve(vec,mid);

            if(f){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return ans;
    }
};