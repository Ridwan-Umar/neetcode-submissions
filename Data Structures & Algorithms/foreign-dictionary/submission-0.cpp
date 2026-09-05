class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<char>>edges;
        for (int i=0;i<words.size()-1;i++){
            string w1=words[i];
            string w2=words[i+1];
            int j=0;
            char u,v;
            int flag=-1;
            while (j<min(w1.size(),w2.size())){
                if (w1[j]!=w2[j]){
                    u=w1[j];
                    v=w2[j];
                    flag=1;
                    break;
                }
                j++;
            }
            if (flag==-1 && (w1.size()>w2.size())){
                return "";
            }
            if (flag==1){
                edges.push_back({u,v});
            }
        }
        unordered_set<int>check;
        for (auto w:words){
            for (auto c:w){
                check.insert(c-'a');
            }
        }
        vector<int>indegree(26,0);
        vector<vector<int>>adj(26);
        for (auto edge:edges){
            int u=edge[0]-'a';
            int v=edge[1]-'a';
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for (int i=0;i<indegree.size();i++){
            if (indegree[i]==0 && check.count(i)){
                q.push(i);
            }
        }
        vector<int>temp;
        while (!q.empty()){
            int u=q.front();
            q.pop();
            temp.push_back(u);
            for (auto v:adj[u]){
                indegree[v]--;
                if (indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if (temp.size()!=check.size()){
            return "";
        }
        string s="";
        for (int i=0;i<temp.size();i++){
            s+=temp[i]+'a';
        }
        return s;
    }
};
