class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<long long>arr(maxi+1,0);
        vector<long long>arr1(abs(mini)+1,0);
        for (long long i=0;i<nums.size();i++){
            if (nums[i]<0){
                arr1[abs(nums[i])]=1;
            }
            else{
                arr[nums[i]]=1;
            }
        }
        vector<long long>arr2;
        for (int i=arr1.size()-1;i>=1;i--){
            arr2.push_back(arr1[i]);
        }
        for (int x:arr){
            arr2.push_back(x);
        }
        int ans=0;
        int maxi1=0;
        for (auto x:arr2){
            if (x==0){
                ans=0;
            }
            else if (x==1){
                ans++;
                maxi1=max(maxi1,ans);
            }
        }
        return maxi1;
    }
};
