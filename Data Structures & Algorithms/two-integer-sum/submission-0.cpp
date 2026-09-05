class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>arr;
        for (int x:nums){
            arr.push_back(target-x);
        }
        for (int x:nums){
            mp[x]++;
        }
        for (int i=0;i<arr.size();i++){
            if (arr[i]!=nums[i]){
                mp[arr[i]]++;
            }
        }
        vector<bool>arr1(n);
        for (int i=0;i<n;i++){
            if (mp[nums[i]]>1 && arr1[i]==false){
                arr1[i]=true;
            }
        }
        vector<int>arr2;
        for (int i=0;i<n;i++){
            if (arr1[i]==true){
                arr2.push_back(i);
            }
        }
        return arr2;
    }
};
