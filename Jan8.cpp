149. Max Points on a Line
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

// Example 1:


// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        double diff=0;
       
        for(int i=0;i<points.size()-1;i++){
             unordered_map<double,int>mp;
            for(int j=i+1;j<points.size();j++){
                
                
                if(points[j][0]-points[i][0]==0){
                    diff=INT_MAX;
                    
                }
               
                else{
                   diff = (double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                }
                mp[diff]++;
                ans = max(ans,mp[diff]);
            }
        }

       
        return ans+1;
    }
};
