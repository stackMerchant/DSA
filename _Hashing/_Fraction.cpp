// https://www.interviewbit.com/problems/fraction/

string Solution::fractionToDecimal(int numerator, int denominator) {
    // Assign to long
    long num = numerator, den = denominator;
    
    // Handle edge cases
    if (num == 0) return "0";
    if (den == 0) return "";
    
    // Start creating string
    string result = "";
    
    // Add if negative
    if ((num < 0) ^ (den < 0)) result += "-";

    // Take positive values and calculate value before .
    num = abs(num); den = abs(den);
    result += to_string(num/den);

    // Get remainder
    long rem = (num % den) * 10;
    
    // If remainder is 0, return as there will be no .
    if (rem == 0) return result;
    // Else add .
    result += ".";
    
    // Map of remainder to length of result till then
    unordered_map<long, int> map;
    while (rem != 0) {
        if (map.find(rem) != map.end()) {
            string part1 = result.substr(0, map[rem]);
            string part2 = result.substr(map[rem]);
            return part1 + "(" + part2 + ")";
        }

        map[rem] = result.length();
        result += to_string(rem/den);
        rem = (rem % den) * 10;
    }
    return result;
}