// https://www.interviewbit.com/problems/reverse-string/

string Solution::reverseString(string a) {
    stack<char> st;
    for(auto _a: a) st.push(_a);
    
    string ans="";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}
