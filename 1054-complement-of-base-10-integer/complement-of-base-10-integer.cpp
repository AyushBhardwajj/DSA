class Solution {
public:
    int bitwiseComplement(int n) {
        int p=n;
        int k = 0;
        int mask=0;
        if(n==0)
         return 1;
        while(p!=0){
            mask=(mask<<1) |1;
            p=p>>1;
        }
        
         return  (~n) & mask;

    }
};