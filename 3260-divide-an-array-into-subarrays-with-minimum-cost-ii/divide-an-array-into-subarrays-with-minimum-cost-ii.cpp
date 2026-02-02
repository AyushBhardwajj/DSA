class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        
        int n = nums.size();
        int start = 1,end = dist+1;
        multiset<int> frst,sec;
        long long sum = 0;

        for(int i=start;i<=end;i++){
            sec.insert(nums[i]);

            if(frst.size()<k-1){
                int val = *sec.begin();
                auto it = sec.find(val);
                sec.erase(it);
                frst.insert(val);
                sum+=val;
            }
            else{
                int ffst = *frst.rbegin();
                int lst = *sec.begin();

                if(lst<ffst){
                    sum-=ffst;
                    sum+=lst;
                    auto it = frst.find(ffst);
                    auto at = sec.find(lst);
                    frst.erase(it);
                    sec.erase(at);
                    frst.insert(lst);
                    sec.insert(ffst);
                }
            }     
        }

        long long last = sum;
        sum+=nums[0];
        end++;

        while(end<n){
            int rem = nums[start];
            int add = nums[end];
            sec.insert(add);
            int ffst = *frst.rbegin();
            int lst = *sec.begin();
            long long curr = last;

            if(rem<=ffst){
                auto it = frst.find(rem);
                curr-=rem;
                frst.erase(it);
            }
            else{
                auto at = sec.find(rem);
                sec.erase(at);
            }

            while(frst.size()<k-1){
                int val = *sec.begin();
                auto at = sec.find(val);
                curr+=val;
                frst.insert(val);
                sec.erase(at);
            }

            while(sec.size()>0 && true){
                int ffst = *frst.rbegin();
                int lst = *sec.begin();

                if(ffst<=lst){
                    break;
                }

                curr-=ffst;
                curr+=lst;
                auto it = frst.find(ffst);
                auto at = sec.find(lst);
                frst.erase(it);
                sec.erase(at);
                frst.insert(lst);
                sec.insert(ffst);

            }

            last = curr;

            long long tot = curr+nums[0];

            sum = min(sum,tot);
            start++;
            end++;

        }

        return sum;
    }
};