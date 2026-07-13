class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs_n = haystack.size();
        int nd_n = needle.size();

        // Check every possible starting position
        for (int i = 0; i <= hs_n - nd_n; i++) {

            int j = 0;

            // Compare characters one by one
            while (j < nd_n && haystack[i + j] == needle[j]) {
                j++;
            }

            // If all characters matched
            if (j == nd_n) {
                return i;
            }
        }

        return -1;
    }
};