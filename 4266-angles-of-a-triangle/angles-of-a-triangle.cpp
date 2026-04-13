class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int x = sides[0]+sides[1]+sides[2];
        int x1 = max({sides[0],sides[1],sides[2]});
        vector<double>ans;
        if(x1>=(x-x1)) return ans;
        else{
            double a = sides[0];
            double b = sides[1];
            double c = sides[2];
            double A = acos((b*b + c*c - a*a) / (2*b*c)) * 180.0 / M_PI;
            double B = acos((a*a + c*c - b*b) / (2*a*c)) * 180.0 / M_PI;
            double C = acos((a*a + b*b - c*c) / (2*a*b)) * 180.0 / M_PI;
            ans = {A,B,C};
            sort(ans.begin(),ans.end());


        }
        return ans;

    }
};