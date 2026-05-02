class Solution {
public:
    int rotatedDigits(int n) {

        int ans = 0;
        
        for(int i=1;i<=n;i++){
            int num = i;

            bool flag = false;



            while(num>0){
                int curr = num%10;
                if(curr==3 || curr==4 || curr==7)break;
                if(curr==2 || curr==5 || curr==6 || curr==9){
                    flag = true;
                }
                num = num/10;
            }
            if(num==0 && flag)ans++;
        }

        return ans;
    }
};