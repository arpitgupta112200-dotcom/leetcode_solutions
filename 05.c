#include <stdio.h>
#include <stdlib.h>
char* longestPalindrome(char* s) {
    int n = strlen(s);

    if (n < 2)
        return s;

    int start = 0;
    int maxLen = 1;

    for (int center = 0; center < n; center++) {

        // Odd length palindrome
        int left = center;
        int right = center;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        // Even length palindrome
        left = center;
        right = center + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    char* result = (char*)malloc((maxLen + 1) * sizeof(char));

    for (int i = 0; i < maxLen; i++)
        result[i] = s[start + i];

    result[maxLen] = '\0';

    return result;
}