class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double singlehour = 30.0;
        double singleminute = 6.0;

        map<int,double> mphr,mpmin;

        for(int i=1;i<=12;i++){
            mphr[i] = i*singlehour;
        }

        for(int i=1;i<=60;i++){
            mpmin[i] = i*singleminute;
        }

        double anglehrr = mphr[hour];
        double anglemin = mpmin[minutes];

        double calc = (double)((minutes/2.0));
        anglehrr+=calc;

        double ans = abs(anglehrr-anglemin);

        ans = min(ans,360-ans);

        return ans;
    }
};