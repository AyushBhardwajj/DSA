class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> div;

        if(n==1)return 1;

        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0){
                div.push_back(i);
                if((n/i) != i)div.push_back(n/i);
            }
        }

        vector<int> srt = nums;
        div.push_back(n);

        sort(srt.begin(),srt.end());

        int ans = 0;

        if(srt == nums)ans+=1;
        vector<int> arr = nums;


        for(int i=0;i<div.size();i++){
            int k = div[i];
            int ind1 = 0;
            bool flag = true;

            for(int j=0;j<n;j+=k){
                int ind = min_element(nums.begin()+j,nums.begin()+j+k)-nums.begin();
                int ele = nums[ind];
                if(nums[j+k-1]==ele){
                    ind = j+k-1;
                    while(ind>=j && nums[ind] == ele){
                        ind--;
                    }
                    ind++;
                }
                while(ind1<j+k){
                    if(nums[ind]!=srt[ind1]){
                        //if(k==3)cout<<ind<<"\n";
                        flag = false;
                        break;
                    }
                    ind1++;
                    ind +=1 ;
                    if(ind>=j+k){
                        ind = j;
                    }
                }

                if(flag == false)break;

                // reverse(nums.begin()+ind,nums.begin()+j+k);
                // reverse(nums.begin()+j,nums.begin()+ind);
                // reverse(nums.begin()+j,nums.begin()+j+k);

            }

            if(flag){
                //cout<<k<<"\n";
                ans += k;
            }

            // if(nums == srt)ans += k;

            // nums = arr;
        }

        // int ind = min_element(nums.begin(),nums.end()) - nums.begin();

        // reverse(nums.begin()+ind,nums.end());
        // reverse(nums.begin(),nums.begin()+ind);
        // reverse(nums.begin(),nums.end());

        // if((nums == srt) && n!=1){
        //     //cout<<n<<"\n";
        //     ans +=n;
        // }
        

        return ans;
    }
};