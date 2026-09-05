class Solution {
public:
    int maxArea(vector<int>&arr) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int maxi=0;
        while (i<j){
            int area1=(j-i)*min(arr[i],arr[j]);
            if (arr[i]<arr[j]){
                i++;
            }
            else{
                j--;
            }
            maxi=max(maxi,area1);
        }
        return maxi;
    }
};
