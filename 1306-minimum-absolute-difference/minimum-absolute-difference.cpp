class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int maxt  =1e9;

        sort(arr.begin(),arr.end());

        for(int i=0;i<arr.size()-1;i++){
            int diff  = abs(arr[i]-arr[i+1]);

            maxt = min(maxt,diff);
        }

        vector<vector<int>> ans;

        for(int i=0;i<arr.size()-1;i++){
            int diff  = abs(arr[i]-arr[i+1]);

            if(diff == maxt){
                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;
    }
};