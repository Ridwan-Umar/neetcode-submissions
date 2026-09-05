class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        int mul=1;
        arr[0]=mul;
        for (int i=1;i<n;i++){
            arr[i]=nums[i-1]*mul;
            mul=arr[i];
        }
        int mul1=1;
        for (int i=n-1;i>=0;i--){
            arr[i]=arr[i]*mul1;
            mul1*=nums[i];
        }
        // for (auto x:arr){
        //     cout<<x<<" ";
        // }
        return arr;
    }
};
