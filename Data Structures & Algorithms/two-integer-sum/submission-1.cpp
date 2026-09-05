class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp; 
        vector<int> arr;
        for (int x:nums){
            arr.push_back(target-x);
        }
        for (int x : nums){
            mp[x]++;
        }
        vector<int>ans;
        for (int i=0;i<n;i++){
            if (mp[arr[i]]>0){          
                if (arr[i]!=nums[i] || mp[arr[i]]>1){
                    ans.push_back(i);
                    if (ans.size()==2){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
