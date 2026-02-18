class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag = true;
        if((n&1) == 0)flag = false;

        while(n>0){
            if((n&1)){
                if(!flag)return false;
            }
            else{
                if(flag)return false;
            }

            flag = !flag;
            n = n/2;
        }

        return true;
    }
};