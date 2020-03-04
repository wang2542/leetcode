class Solution {
    // 可以用类似isSubstring的函数 或者自己写一个
    // C++ 这里可以用find解决此问题
    // s2一定是s1s1的子串
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() == s2.length()) {
            string s1s1 = s1 + s1;
            if (s1s1.find(s2) != s1s1.npos) return true;
        }
        return false;
    }
};
