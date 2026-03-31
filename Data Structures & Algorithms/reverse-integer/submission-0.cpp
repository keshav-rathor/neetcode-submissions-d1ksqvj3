class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0) ? -1 : 1;  // Determine the sign
        x = abs(x);  // Work with the absolute value
        
        // Convert integer to string
        string val = to_string(x);
        // Reverse the string
        std::reverse(val.begin(), val.end());

        // Try to convert the reversed string back to integer
        long long reversedNum = stoll(val);  // Use stoll to prevent overflow while parsing

        // Check if reversed number is within the valid 32-bit signed integer range
        if (reversedNum > INT_MAX) return 0;

        // Return reversed number with the correct sign
        return sign * static_cast<int>(reversedNum);
        
    }
};
