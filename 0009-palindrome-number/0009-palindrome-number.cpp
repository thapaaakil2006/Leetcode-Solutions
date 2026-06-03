class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfies this property.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNum = 0;
        while (x > reversedNum) {
            reversedNum = reversedNum * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by reversedNum/10
        // For example when x = 121, at the end of the while loop we get x = 1, reversedNum = 12,
        // since the middle digit doesn't matter in palindrome, we can simply get rid of it.
        return x == reversedNum || x == reversedNum / 10;
    }
};
