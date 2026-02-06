// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> map; // xor to count of occurence map
    int currXor, requiredXor, ret = 0;
    
    currXor = 0;
    map[0] = 1;
    
    for (int i=0; i<A.size(); i++) {
        currXor = currXor ^ A[i]; // calculate running xor
        requiredXor = B ^ currXor; // required xor complement to reach target
        
        if (map.find(requiredXor) != map.end()) // if present already add count to answer
            ret += map[requiredXor];
        
        map[currXor]++; // increase count of current xor
    }
    return ret;
}
