class Solution {
public:
    int strStr(string haystack, string needle) {
        // int hs_n = haystack.size();
        // int nd_n = needle.size();

        // // Check every possible starting position
        // for (int i = 0; i <= hs_n - nd_n; i++) {

        //     int j = 0;

        //     // Compare characters one by one
        //     while (j < nd_n && haystack[i + j] == needle[j]) {
        //         j++;
        //     }

        //     // If all characters matched
        //     if (j == nd_n) {
        //         return i;
        //     }
        // }

        // return -1;


        if (needle.empty()) return 0;

    vector<int> lps(needle.size(), 0);

    // Compute LPS array
    int pre = 0, suf = 1;
    while (suf < needle.size()) {
        if (needle[pre] == needle[suf]) {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        } else {
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } else {
                pre = lps[pre - 1];
            }
        }
    }

    // KMP Search
    int i = 0, j = 0;

    while (i < haystack.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;

            if (j == needle.size())
                return i - j;
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j - 1];
            }
        }
    }

    return -1;



    }
};