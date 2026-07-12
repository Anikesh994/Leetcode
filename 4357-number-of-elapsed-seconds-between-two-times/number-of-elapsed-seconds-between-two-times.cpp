class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int s1 = stoi(startTime.substr(0,2));
        int s2 = stoi(endTime.substr(0,2));
        int s3 = stoi(startTime.substr(3,2));
        int s4 = stoi(endTime.substr(3,2));
        int s5 = stoi(startTime.substr(6,2));
        int s6 = stoi(endTime.substr(6,2));
        long long t1=(s1*3600 + s3*60 +s5);
        long long t2=(s2*3600 + s4*60 + s6);
        return (t2-t1);

    }
};