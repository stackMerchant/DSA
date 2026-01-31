// https://www.interviewbit.com/problems/generate-all-parentheses-ii/

void trav(int a, int b, string currString, vector<string> &ans) {
    if (a == 0 && b == 0) {
        ans.push_back(currString);
        return;
    }
    if (a<0 || b<0 || a>b) return;
    
    trav(a-1, b, currString + '(', ans);
    trav(a, b-1, currString + ')', ans);
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    trav(A, A, "", ans);
    return ans;
}