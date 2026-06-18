class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ghantaAngle=(hour%12)*30+minutes*0.5;
        double minuteAngle=minutes*6;

        double diff=abs(ghantaAngle-minuteAngle);
        return min(diff,360-diff);
    }
};