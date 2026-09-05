class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for (auto x:tokens){
            if (x!="+" && x!="-" &&x!="*" &&x!="/" ){
                st.push(x);
            }
            else{
                if (x=="+"){
                    int n1=stoi(st.top());
                    st.pop();
                    int n2=stoi(st.top());
                    st.pop();
                    st.push(to_string(n1+n2));
                }
                else if (x=="-"){
                    int n1=stoi(st.top());
                    st.pop();
                    int n2=stoi(st.top());
                    st.pop();
                    st.push(to_string(n2-n1));
                }
                else if (x=="*"){
                    int n1=stoi(st.top());
                    st.pop();
                    int n2=stoi(st.top());
                    st.pop();
                    st.push(to_string(n1*n2));
                }
                else if (x=="/"){
                    int n1=stoi(st.top());
                    st.pop();
                    int n2=stoi(st.top());
                    st.pop();
                    st.push(to_string(n2/n1));
                }
            }
        }
        return stoi(st.top());
    }
};
