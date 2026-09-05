class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minh;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        k1=k;
        for (auto x:nums){
            minh.push(x);
        }
    }
    
    int add(int val) {
        minh.push(val);
        while (minh.size()>k1){
            minh.pop();
        }
        return minh.top();
    }
};
