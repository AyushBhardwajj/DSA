class Solution {
public:
    bool isRadius(vector<int>& houses,vector<int> &heaters,int mid){

        for(int i=0;i<houses.size();i++){
            auto it = lower_bound(heaters.begin(),heaters.end(),houses[i]);

            if(it == heaters.end()){
                it--;
                int heaterPos = *it;

                if(abs(heaterPos-houses[i])>mid)return false;
            }

            else if(it == heaters.begin()){
                int heaterPos = *it;

                if(abs(heaterPos-houses[i])>mid)return false;
            }

            else {
                int heaterPos1 = *it;
                it--;
                int heaterPos2 = *it;

                if(abs(heaterPos1-houses[i])> mid && abs(heaterPos2-houses[i])>mid)return false;
            }
        }

        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {

        int start = 0,end = 1e9;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int ans = 1e9;

        while(start<=end){
            int mid = start + (end-start)/2;

            bool flag = isRadius(houses,heaters,mid);

            if(flag){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return ans;
    }


};