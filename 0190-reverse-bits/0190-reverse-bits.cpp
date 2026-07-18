class Solution {
public:
    int reverseBits(int n) {
        int reverse = 0;

         for (int i = 0; i < 32; i++) {
            int bit = n & 1;         // last bit nikala
            reverse = reverse << 1;  // reverse me jagah banayi
            reverse = reverse | bit; // bit add kiya

            n = n >> 1; // n ko right shift kiya
        }

        return reverse;
    }
};