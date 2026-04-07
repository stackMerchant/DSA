# Math notes

# Lessons

## Beggar's method
- Distribute n identical coins to k beggars
- Formula => (n+k-1) C (k-1) OR (n+k-1) C (n)
- For atleast one to each, assign one to each and then apply above
- Formula becomes => (n-1) C (k-1) OR (n-1) C (n-k)

## Beggar's method with ceiling
- Get all from Beggar's method
- Add ceiling to one, then go to next, then add to 2, and so on
- Inclusion exclusion like in A U B

## LCM and GCD
- LCM(a, b) = (a * b) / GCD(a, b)

```cpp
int gcd(int A, int B) {
    if (A < B) {
        int temp = A;
        A = B;
        B = temp;
    }
    
    if (B == 0) return A;    
    return gcd(B, A % B);
}
```
