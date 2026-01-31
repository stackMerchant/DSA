// https://www.interviewbit.com/problems/kth-permutation-sequence/

vector<int> prepareFactorial() {
    int limit = 12;
    vector<int> fr(limit + 1);
    fr[0] = fr[1] = 1;
    
    for (int i=2; i<=limit; i++)
        fr[i] = i * fr[i-1];
    return fr;
}

int getFr(int n, vector<int> &fr) {
    if (n > 12) return INT_MAX;
    return fr[n];
}

string getPerm(int k, vector<int> &nums, vector<int> &fr) {
    int n = nums.size(); // total elements left to pick from
    if (n == 0) return "";
    
    int factorial = getFr(n-1, fr); // total permutations on left
    int index = k/factorial; // which index element to pick from vector
    int num = nums[index]; // num to be picked
    
    // Remove used num from nums
    for (int i=index; i<nums.size() - 1; i++) nums[i] = nums[i+1];
    nums.pop_back();
    
    int kNew = k % factorial;
    return to_string(num) + getPerm(kNew, nums, fr);
}

string Solution::getPermutation(int A, int B) {
    // Prepare factorial
    vector<int> fr = prepareFactorial();
    
    // Prepare set
    vector<int> nums;
    for (int i=1; i<=A; i++) nums.push_back(i);
    
    return getPerm(B-1, nums, fr);
}
