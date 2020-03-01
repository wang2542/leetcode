class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char , int> wordFreq;
        // 遍历字符串 拆成字节
        for (char w : s) {
            wordFreq[w]++;
        }   
        // 迭代器遍历 计数
        bool oddAppeared = false;
        unordered_map<char, int>:: iterator p;
        for (p = wordFreq.begin(); p != wordFreq.end(); p++) {
            if ( p -> second % 2  && oddAppeared ) {
                return false;
            } else if ( p -> second % 2 && !oddAppeared ) {
                oddAppeared = true;
            }
        }   
        return true;
    }
};
// canPermutePalindrome 回文排列
// 1.用hash map计数
// 2.迭代器遍历 查是否符合要求（一个中间奇数是否出现，其余都是偶数倍）
