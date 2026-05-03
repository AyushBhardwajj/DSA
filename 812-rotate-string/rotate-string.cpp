class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char> q1,q2;

        int n = s.length();
        int m = goal.length();

        if(n!=m)return false;


        for(int i=0;i<n;i++){
            q1.push(s[i]);
            q2.push(goal[i]);
        }

        while(n>0){
            if(q1 == q2)return true;
            q1.push(q1.front());
            q1.pop();
            n--;
        }

        return false;
    }
};