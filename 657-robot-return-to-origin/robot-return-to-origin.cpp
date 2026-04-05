class Solution {
public:
    bool judgeCircle(string moves) {
        int vert =0,hori = 0;

        for(int i=0;i<moves.length();i++){
            if(moves[i]=='U')vert++;
            else if(moves[i]=='D')vert--;
            else if(moves[i]=='L')hori--;
            else hori++;
        }

        if(vert==0 && hori==0)return true;
        return false;
    }
};