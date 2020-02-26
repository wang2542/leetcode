class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2)
            return true;
        else
            return false;
    }
};

// * sort 函数
// ref: https://www.cnblogs.com/TX980502/p/8528840.html
// -------------------------------------------------
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char , int> r1;
        unordered_map<char , int> r2;
        for (char w : s1) {
            r1[w]++;
        }
        for (char w : s2) {
            r2[w]++;
        }
        if (r1 == r2)
            return true;
        else
            return false;
    }
};

// * sort 函数 O(N)
// ref: https://www.cnblogs.com/TX980502/p/8528840.html
/* 执行用时 : 0 ms 内存消耗 : 8.7 MB
*/
