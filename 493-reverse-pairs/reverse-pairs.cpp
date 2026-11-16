class Solution {
public:
    int ans;

    void merge(vector<int> &nums,int s,int mid,int e){
        int l1 = s,l2 = mid+1;

        while(l1<=mid && l2<=e){
            if(1ll*nums[l1]<=2ll*nums[l2]){
                l1++;
            }
            else{
                ans += mid-l1+1;
                l2++;
            }
            
        }

        vector<int> temp;

        l1 = s,l2 = mid+1;

        while(l1<=mid && l2<=e){
            if(nums[l1]<=nums[l2]){
                temp.push_back(nums[l1]);
                l1++;
            }
            else{
                temp.push_back(nums[l2]);
                l2++;
            }
            
        }

        while(l1<=mid){
            temp.push_back(nums[l1]);
            l1++;
        }

        while(l2<=e){
            temp.push_back(nums[l2]);
            l2++;
        }

        for(int i=s;i<=e;i++){
            nums[i] = temp[i-s];
        }



    }
    
    void mergeSort(vector<int> &nums,int s,int e){
        if(s>=e)return;

        int mid = (s+e)/2;

        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);

        return;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size()-1;

        ans = 0;

        mergeSort(nums,0,n);

        return ans;
    }
};