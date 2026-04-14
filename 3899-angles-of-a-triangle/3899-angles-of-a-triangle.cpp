class Solution {
    double clamp(double c){
       if(c<-1.0)return -1.0;
       if(c>1.0)return 1.0;
       return c;
    }
public:
    vector<double> internalAngles(vector<int>& sides) {
        // lets the check the valid triangle first 
        int a=sides[0];
        int b=sides[1];
        int c=sides[2];

        if(!(a+b>c && b+c>a && c+a>b))return {};

        double A=acos(clamp((b*b+c*c-a*a)/(2.0*b*c)))*180/M_PI;
        double B=acos(clamp((a*a+c*c-b*b)/(2.0*a*c)))*180/M_PI;
        double C=acos(clamp((a*a+b*b-c*c)/(2.0*b*a)))*180/M_PI;

        vector<double>res={A,B,C};
        sort(res.begin(),res.end());

        return res;
    }
};