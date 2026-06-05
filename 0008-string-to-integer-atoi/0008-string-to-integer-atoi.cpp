#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int res = 0;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and handle overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Check overflow/underflow conditions before modifying res
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return res * sign;
    }
};