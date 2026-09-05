class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxh;
        for (auto x:stones){
            maxh.push(x);
        }
        while (maxh.size()>1){
            int a1=maxh.top();
            maxh.pop();
            int a2=maxh.top();
            maxh.pop();
            if (a1==a2){
                if (maxh.size()==0){
                    return 0;
                }
                continue;
            }
            maxh.push(a1-a2);
        }
        return maxh.top();
    }
};
