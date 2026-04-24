class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int l = 0;
        int em = 0;


        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L')l++;
            else if(moves[i]=='R')l--;
            else em++;
        }

        int ans = abs(l-0)+em;

        return ans;
    }
};