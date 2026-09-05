class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>>maxh;
        for (int i=0;i<points.size();i++){
            double d=sqrt(abs(points[i][0]*points[i][0])+abs(points[i][1]*points[i][1]));
            maxh.push({d,{points[i][0],points[i][1]}});
            if (maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>>arr;
        while (!maxh.empty()){
            int a1=(maxh.top().second.first);
            int a2=(maxh.top().second.second);
            arr.push_back({a1,a2});
            maxh.pop();
        }
        return arr;
    }
};