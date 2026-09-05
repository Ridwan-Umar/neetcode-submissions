class Solution {
public:
    void nsl(vector<int>arr,vector<int>&arr1){
        stack<pair<int,int>>st;
        for (int i=0;i<arr.size();i++){
            while (!st.empty() && st.top().first>=arr[i]){
                st.pop();
                
            }
            if (st.empty()){
                arr1.push_back(-1);
            }
            else{
                arr1.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
    }
    void nsr(vector<int>arr,vector<int>&arr2){
        stack<pair<int,int>>st;
        for (int i=arr.size()-1;i>=0;i--){
            while (!st.empty() && st.top().first>=arr[i]){
                st.pop();
                
            }
            if (st.empty()){
                arr2.push_back(arr.size());
            }
            else{
                arr2.push_back(st.top().second);
            }
            st.push({arr[i],i});
        }
        reverse(arr2.begin(),arr2.end());
    }
    int largestRectangleArea(vector<int>&arr) {
        vector<int>arr1;
        vector<int>arr2;
        nsl(arr,arr1);
        nsr(arr,arr2);
        int maxi=-1;
        for (int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]*(arr2[i]-arr1[i]-1));
        }
        return maxi;
    }
};