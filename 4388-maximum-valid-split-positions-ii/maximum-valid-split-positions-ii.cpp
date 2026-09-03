class Solution {
public:
    int getScore(vector<int>& arr) {
        int n = arr.size();

        
        if (n < 2)
            return 0;

        vector<int> pref(n), suff(n);

        
        pref[0] = arr[0];

        for (int i = 1; i < n; i++) {
            pref[i] = gcd(pref[i - 1], arr[i]);
        }

        
        suff[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = gcd(suff[i + 1], arr[i]);
        }

        int score = 0;

        for (int i = 0; i < n - 1; i++) {

            if (pref[i] == suff[i + 1]) {
                score++;
            }
        }

        return score;
    }

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();

       
        int answer = getScore(nums);


       
        if (n > 1) {

            vector<int> temp;

            for (int i = 1; i < n; i++) {
                temp.push_back(nums[i]);
            }

            answer = max(answer, getScore(temp));
        }


    
        if (n > 1) {

            vector<int> temp;

            for (int i = 0; i < n - 1; i++) {
                temp.push_back(nums[i]);
            }

            answer = max(answer, getScore(temp));
        }


        
        vector<int> pref(n), suff(n);

        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = gcd(pref[i - 1], nums[i]);
        }

        suff[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = gcd(suff[i + 1], nums[i]);
        }


        
        for (int i = 1; i < n - 1; i++) {

    
            int left = pref[i - 1];

            int right = suff[i + 1];

            int common = gcd(left, right);


            
            if (gcd(common, nums[i]) != common) {

                vector<int> temp;

                
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        temp.push_back(nums[j]);
                    }
                }

                answer = max(answer, getScore(temp));
                break;
            }
        }

        return answer;
    }
};