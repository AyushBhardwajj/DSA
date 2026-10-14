class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(((sum+num-1)/num) > 9)return ans;

        for(int i=0;i<num;i++){
            if(sum>=9){
                ans.push_back('9');
                sum-=9;
            }
            else{
                char ch = '0'+sum;
                ans.push_back(ch);
                sum = 0;
            }

        }

        return ans;
    }
};