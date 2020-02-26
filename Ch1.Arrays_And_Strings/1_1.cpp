// --------------------------------------------------------
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

// https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
// hash map 方法 （散列表）
// --------------------------------------------------------

class Solution {
public:
    bool isUnique(string astr) {
        bitset<256> bits(0);
	for(int i = 0; i < astr.length(); i++) {
		int val = astr[i];
		if(bits.test(val) > 0) {
			return false;
		}
		bits.set(val);
	}
	return true;
    }
};


// https://baike.baidu.com/item/BitSet/5816051?fr=aladdin
// https://www.cnblogs.com/magisk/p/8809922.html
// 位向量
// 测试某个单独的位是否为1 也有两种方式
// 1. test()操作。用位置做参数
// 2. 我们也可以用下标操作符
