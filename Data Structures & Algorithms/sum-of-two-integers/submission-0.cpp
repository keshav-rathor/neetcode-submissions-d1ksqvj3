class Solution {
public:
    int getSum(int a, int b) {
        return solver(a, b);
    }

    int solver(int a, int b) {
        int ans = 0;  // The result of the sum
        int carry = 0;  // The carry value
        int mask = 1;  // Mask to extract the ith bit

        for (int i = 0; i < 32; i++) {
            // Get the current bits of a and b
            int x = (a & mask) != 0;  // ith bit of a
            int y = (b & mask) != 0;  // ith bit of b

            // Sum of the current bits and the carry
            int sum = x ^ y ^ carry;

            // Update the result with the sum at the ith bit
            ans |= (sum << i);

            // Update carry for the next bit
            carry = (x & y) | (carry & (x ^ y));

            // Move the mask to the next bit
            mask <<= 1;
        }

        return ans;
    }
};
