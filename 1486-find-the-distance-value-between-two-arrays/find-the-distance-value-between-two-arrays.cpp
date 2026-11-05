class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        int left = 0,right = arr2.size()-1;

        int n = arr1.size();

        int ans = n;

        for(int i=0;i<n;i++){
            bool flag = false;
            auto it = lower_bound(arr2.begin(),arr2.end(),arr1[i]);

            if(it!=arr2.end()){
                int ind = it-arr2.begin();
                if(abs(arr1[i]-arr2[ind])<=d)flag = true;
            }

            if(it!=arr2.begin()){
                it--;
                int ind = it-arr2.begin();
                if(abs(arr1[i]-arr2[ind])<=d)flag = true;
            }

            if(flag)ans--;
        }

        return ans;
    }
};