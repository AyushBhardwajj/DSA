class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double singlehour = 30.0;
        double singleminute = 6.0;


        double anglehrr = (double)hour*singlehour;
        double anglemin = (double)(singleminute*minutes);

        double calc = (double)((minutes/2.0));
        anglehrr+=calc;

        double ans = abs(anglehrr-anglemin);

        ans = min(ans,360-ans);

        return ans;
    }
};