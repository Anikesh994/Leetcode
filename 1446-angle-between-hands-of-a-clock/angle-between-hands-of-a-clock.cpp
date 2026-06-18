class Solution {
public:
    double angleClock(int hour, int minutes) {
        int div = 30;
        double mi =double(minutes)/60.0 ;
        double mi1 = mi*360;
        double hr =mi*30;
        if(hour==12){
            return min(mi1-hr , 360-(mi1-hr));
        }
        else{
            if(30*hour + hr < mi1) return min(mi1-30*hour - hr,360-(mi1-30*hour - hr));
            return min(30*hour + hr - mi1 ,360-(30*hour + hr - mi1));
        }


    }
};