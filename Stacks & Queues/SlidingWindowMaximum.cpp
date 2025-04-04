// https://www.interviewbit.com/problems/sliding-window-maximum/

/************ Solution 1 ************/

vector<int> Solution::slidingMaximum(const vector<int> &A, int windowSize) {
    int n = A.size();
    vector<int> ret;
    
    // Store indexes of values in increasing order, indexes will be in decreasing order
    deque<int> dq;
    
    // For initial windowSize elements
    for (int i=0; i<windowSize; i++) {
        // While last element is smaller than current element, keep popping
        // Because previous lesser elements will not contribute to maximum element
        while (!dq.empty() && A[dq.back()] < A[i]) dq.pop_back();
        // Push current element
        dq.push_back(i);
    }
    // Front will be the maximum in window, so push it to answer
    ret.push_back(A[dq.front()]);
    
    for (int i=windowSize; i<n; i++) {
        // After moving window by 1, check if front element is now out of window
        // Note: Only one element will go out of window at once and it can only be the front element
        //  as indexes are stored in decreasing order
        if (dq.front() <= i-windowSize) dq.pop_front();
        // While last element is smaller than current element, keep popping
        while (!dq.empty() && A[dq.back()] < A[i]) dq.pop_back();
        // Push current element
        dq.push_back(i);
        // Front will be the maximum in window, so push it to answer
        ret.push_back(A[dq.front()]);
    }
    return ret;
}

/************ Solution 2 ************/

// Read and understand

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> res;
    vector<int> deq(A.size() + 1);
    int front = 0, back = -1;
    for(int i = 0 ; i < A.size(); ++i){
        while(front <= back && A[i] >= A[deq[back]]) back--;
        deq[++back] = i;
        if(deq[front] + B == i) front++;
        if(i + 1 >= B) res.push_back(A[deq[front]]);
    }
    return res;
}