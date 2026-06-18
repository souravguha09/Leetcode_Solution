class Solution {
public:
    double angleClock(int hour, int minutes) {
        double in=0.5*(double)minutes;
        double mini=(double)minutes/5;
        double ans=0.00;
        double a1,a2,a3;
    //    if(minutes<hour) minutes
        if(hour==12) hour=0;
       if(mini>hour)
        a1=abs(hour-mini)*30-in;
        else
        a1=abs(hour-mini)*30+in;
        
        hour=hour+12;
        a2=abs(hour-mini)*30+in;
        mini=mini+12;
        hour=hour-12;
        a3=abs(hour-mini)*30-in;
        ans=min(a1,min(a2,a3));
        return ans>0?ans:abs(ans);
    }
};