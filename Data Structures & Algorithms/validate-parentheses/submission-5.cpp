class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (auto x:s){
            if (x=='(' ){
                st.push(x);
            }
            if (x=='{' ){
                st.push(x);
            }
            if (x=='[' ){
                st.push(x);
            }
            else if (x==')'){
                if (st.empty()||st.top()!='(' )
                    return false;
                st.pop();
            }
            else if (x=='}'){
                if (st.empty()||st.top()!='{'  )
                    return false;
                st.pop();
            }
            else if (x==']'){
                if (st.empty()||st.top()!='['  )
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
