class Solution {
public:
    void r_cw(string &s) {
        char c = s[s.size() - 1];
        int index = s.size() - 2;

        while (index >= 0) {
            s[index + 1] = s[index];
            index--;
        }

        s[0] = c;
    }

    void r_acw(string &s) {
        char c = s[0];
        int index = 0;

        while (index < s.size() - 1) {
            s[index] = s[index + 1];
            index++;
        }

        s[s.size() - 1] = c;
    }

    bool rotateString(string s, string goal) {

        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            return true;
        }

        string cw = s;
        string acw = s;

        for (int i = 0; i < s.size(); i++) {

            r_cw(cw);
            if (cw == goal) {
                return true;
            }

            r_acw(acw);
            if (acw == goal) {
                return true;
            }
        }

        return false;
    }
};