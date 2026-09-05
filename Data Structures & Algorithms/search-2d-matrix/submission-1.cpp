class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int n=matrix.size()*matrix[0].size();
        int e=n-1;
        while (s<=e){
            int mid=(e-s)/2+s;
            int row=mid/matrix[0].size();
            int col=mid%matrix[0].size();
            if (matrix[row][col]==target){
                return true;
            }
            if (matrix[row][col]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
        
    }
};
