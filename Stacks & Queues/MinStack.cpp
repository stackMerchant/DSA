// https://www.interviewbit.com/problems/min-stack/

stack<pair<int, int>> st;

MinStack::MinStack() {
    st = stack<pair<int, int>>();
}

void MinStack::push(int x) {
    int currMin = st.size() == 0 ? x : min(x, st.top().second);
    st.push({x, currMin});
}

void MinStack::pop() {
    if (st.size() <= 0) return;
    st.pop();
}

int MinStack::top() {
    if (st.size() <= 0) return -1;
    return st.top().first;
}

int MinStack::getMin() {
    if (st.size() <= 0) return -1;
    return st.top().second;
}
