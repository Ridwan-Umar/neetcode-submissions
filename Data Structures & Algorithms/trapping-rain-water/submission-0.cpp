class Solution {
public:
    int trap(vector<int>&arr) {
        int n=arr.size();
        int i=0;
        int j=1;
        int area=0;
        int sum=0;
        while (j!=n){
            if (arr[j]>=arr[i]){
                area+=min(arr[j],arr[i])*(j-i-1)-sum;
                if (j==n-1){
                    break;
                }
                sum=0;
                i=j;
                j=i+1;
            }
            else{
                sum+=arr[j];
                // cout<<sum<<" ";
                j++;
            }
        }
        int i1=n-1;
        int j1=n-2;
        int area1=0;
        int sum1=0;
        while (j1!=-1){
            if (arr[j1]>arr[i1]){
                area1+=min(arr[j1],arr[i1])*(i1-j1-1)-sum1;
                if (j1==0){
                    break;
                }
                sum1=0;
                i1=j1;
                j1=i1-1;
            }
            else{
                sum1+=arr[j1];
                j1--;
            }
        }
        return area+area1;
    }
}; 