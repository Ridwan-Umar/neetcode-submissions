class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()>s.size()){
            return "";
        }
        int n=s.size();
        int i=0;
        int j=0;
        int mini=INT_MAX;
        int start_i=-1;
        unordered_map<char,int>mp;
        int count=t.size();
        for (auto x:t){
            mp[x]++;
        }
        while (j<n){
            if (mp[s[j]]>0){
                count--;
            }
            mp[s[j]]--;
            while (count==0){
                int currsize=j-i+1;
                if (mini>currsize){
                    mini=currsize;
                    start_i=i;
                }
                mp[s[i]]++;
                if (mp[s[i]]>0){
                    count++;
                }
                i++;
            }
            j++;
        }
        if (mini==INT_MAX){
            return "";
        }
        else{
            return s.substr(start_i,mini);
        }
    }
};
