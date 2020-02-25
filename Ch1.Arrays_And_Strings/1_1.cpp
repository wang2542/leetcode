class Solution {
public:
    bool isUnique(string astr) {
        unordered_map<char , int> wordFreq;
		** 遍历字符串 拆成字节
        for (char w : astr) {
            wordFreq[w]++;
        }
		** 迭代器遍历 计数
        unordered_map<char, int>:: iterator p;
        for (p = wordFreq.begin(); p != wordFreq.end(); p++) {
            if (p -> second > 1) 
                return false;
        }
        return true;
    }
};

* https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
* hash map 方法 （散列表）
