// https://www.interviewbit.com/problems/colorful-number/

#define ll long long

int Solution::colorful(int A) {
    // Extract digits
    vector<int> digits;
    while (A>0) {
        digits.push_back(A % 10);
        A = A / 10;
    }
    
    // Calculate product from each digit and keep track of it in set
    unordered_set<ll> set;
    ll product;
    for (int i=0; i<digits.size(); i++) {
        product = 1;
        for (int j=i; j<digits.size(); j++) {
            product *= digits[j];
            if (set.find(product) != set.end()) return 0;
            set.insert(product);
        }
    }
    return 1;
}
