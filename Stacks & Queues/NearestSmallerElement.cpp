// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {    
    stack<int> s;
    vector<int> ret;

    for (int i=0; i<A.size(); i++) {
        // Elements bigger than current elemnet are not required
        while (!s.empty() && s.top() >= A[i]) s.pop();
        ret.push_back(s.empty() ? -1 : s.top());
        s.push(A[i]);
    }

    return ret;
}