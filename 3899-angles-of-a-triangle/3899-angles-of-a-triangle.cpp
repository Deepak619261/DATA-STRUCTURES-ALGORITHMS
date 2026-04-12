class Solution {
    // double clamp 
    double clamp(double a){
        if(a<-1)return -1.0;
        if(a>1)return 1.0;
        return a;
    }
public:
    vector<double> internalAngles(vector<int>& sides) {
        // first check 
        //  area =sqrt(s(s-a)(s-b)(s-c))
        //  s=a+b+c/2 
        //  area>0 and put the value of s -> we get threee conditnon a+b>c , b+c>a, c+a>b
        // angles -> Cosine law
        //  CosA= b^2+c^2-a^2/2bc
        // CosB=a^2+c^2-b^2/2ac
        // similiary CosC=b^2+a^2-c^2/2ab
        // for converting the radian to degree we multipy with 180/pi

        // must condition a+b>c , b+c>a , c+a>b
        int a=sides[0];
        int b=sides[1];
        int c=sides[2];

        if(!(a+b>c && b+c>a && c+a>b))return {};

        // positive area check 

        // now angle calculation 
        double A=acos(clamp((b*b+c*c-a*a)/(2.0*b*c)))*(180/M_PI);
        double B=acos(clamp((a*a+c*c-b*b)/(2.0*a*c)))*(180/M_PI);
        double C=acos(clamp((b*b+a*a-c*c)/(2.0*a*b)))*(180/M_PI);

        vector<double>res={A,B,C};
        sort(res.begin(),res.end());

        return res;
        
    }
};