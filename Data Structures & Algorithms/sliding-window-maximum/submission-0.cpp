class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        int second_maxi=INT_MIN;
        while (j<n){
            maxi=max(maxi,nums[j]);
            second_maxi=max(second_maxi,nums[j]);
            if ((j-i+1)==k){
                arr.push_back(maxi);
                if (maxi==nums[i]){
                    maxi=INT_MIN;
                    for (int t=i+1;t<=j;t++){
                        maxi=max(maxi,nums[t]);
                    }
                }
                i++;
            }
            j++;
        }
        return arr;
    }
};
