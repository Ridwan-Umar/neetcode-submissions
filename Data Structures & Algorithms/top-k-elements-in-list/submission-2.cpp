class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for (auto i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>arr;
        for (auto i:mp){
            arr.push_back({i.second,i.first});
        }
        sort(arr.rbegin(),arr.rend());
        vector<int>arr1;
        for (int i = 0; i < k; ++i) {
            arr1.push_back(arr[i].second);
        }
        return arr1;
    }
};
