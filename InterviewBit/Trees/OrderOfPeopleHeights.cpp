// https://www.interviewbit.com/problems/order-of-people-heights/

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    
    // Prepare a map of height to in front count
    map<int, int> heightToInFront;
    for (int i=0; i<n; i++) heightToInFront[A[i]] = B[i];

    vector<int> ret(n, -1);
    // Iterate over map
    for (auto hf: heightToInFront) {
        int height = hf.first;
        int inFront = hf.second;
        int i = 0; // Index at which we will put current height
        // Skip inFront no. of empty places
        while (inFront > 0 || ret[i] != -1) {
            if (ret[i] == -1) inFront--;
            i++;
        }
        // Find first empty place after that, and put height
        while (ret[i] != -1) i++;
        ret[i] = height;
    }
    return ret;
}