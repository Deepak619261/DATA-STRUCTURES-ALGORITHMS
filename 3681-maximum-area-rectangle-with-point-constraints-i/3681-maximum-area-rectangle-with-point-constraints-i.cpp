class Solution {
    int   getarea(vector<int>p1,vector<int>p2,vector<int>p3,vector<int>p4){
        //  we have to find out the points which are at opposite corner 
        int x1=p1[0];
        int y1=p1[1];

        if(x1!=p2[0] && y1!=p2[1]){
            return abs(p2[0]-x1)*abs(p2[1]-y1);
        }
        
        if(x1!=p3[0] && y1!=p3[1]){
            return abs(p3[0]-x1)*abs(p3[1]-y1);
        }

        if(x1!=p4[0] && y1!=p4[1]){
            return abs(p4[0]-x1)*abs(p4[1]-y1);
        }


        return -1;
    }

    bool valid(vector<int>p1,vector<int>p2,vector<int>p3,vector<int>p4,set<vector<int>>st){
            //  selection criteria 
            int x_min=INT_MAX,y_min=INT_MAX;
            int x_max=INT_MIN,y_max=INT_MIN;

            // take each point and check the distance from its common points dist 
        vector<vector<int>>points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);

        

        // now we have to check for every 
        for(int i=0;i<4;i++){
            x_min=min(x_min,points[i][0]);
            x_max=max(x_max,points[i][0]);
            y_min=min(y_min,points[i][1]);
            y_max=max(y_max,points[i][1]);
            int cnt=0;
            for(int j=0;j<4;j++){
                if(i==j)continue;
                if(points[i][0]!=points[j][0] && points[i][1]!=points[j][1]){
                    cnt++;
                }
                if(cnt>1)return false;
            }
        }


           //  check if any point is not inside the rectangle 
           for(auto it :st){
                if(it!=p1 && it!=p2 && it!=p3 && it!=p4){
                    if(it[0]>=x_min && it[0]<=x_max && it[1]>=y_min && it[1]<=y_max )return false;
                }
           }

        return true;
    }
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        if(points.size()<4)return -1;

        int n=points.size();

        //  we have to select 4 points out of the plane and check if these are valid then boom just calculate the answer and store in the variable 
        int ans=-1;
        set<vector<int>>st(points.begin(),points.end());

        //  we can implement the four loop to take four seprate points 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        //  take the four points 
                        auto it1=points[i];
                        auto it2=points[j];
                        auto it3=points[k];
                        auto it4=points[l];
                        if(valid(it1,it2,it3,it4,st)){
                            std::cout<<it1[0]<<","<<it1[1]<<" ";
                            std::cout<<it2[0]<<","<<it2[1]<<" ";
                            std::cout<<it3[0]<<","<<it3[1]<<" ";
                            std::cout<<it4[0]<<","<<it4[1]<<" ";
                            int area=getarea(it1,it2,it3,it4);
                            ans=max(ans,area);
                        }
                    }
                }
            }
        }
        return ans;
    }
};