class Solution {
public:
    string compressString(string S) {
        string result = "";
        int count = 0;
        // 遍历字符串
        for (int i = 0; i < S.length(); i++) {
            count++;
            if (i >= S.length() || S[i] != S[i+1]) {
                result = result + S[i] + to_string(count);
                count = 0;
            }
        }
        return result.length() < S.length() ? result : S;
    }
};
// 思路： 首先遍历原字符串 再建立一个新字符串记录
//        如果新字符串长就用原来的 如果短就用新结果
// 缺点： 执行时间：O（p+k^2） p为原始字符串长度 k^2为拼接字符串时间
// 注：   字符串拼接操作时间复杂度为O(n^2)
// Java的话可以考虑用 StringBuilder来提升性能
// 方法一 存在一种内存无谓损耗
// 可以先检查输出后的长度是否比原先长 再去执行字符串操作(O(N^2))
class Solution {
public:
    string compressString(string S) {
        int finalR = countResult(S);
        if (finalR >= S.length()) return S;
        string result = "";
        int count = 0;
        // 遍历字符串
        for (int i = 0; i < S.length(); i++) {
            count++;
            if (i >= S.length() || S[i] != S[i+1]) {
                result = result + S[i] + to_string(count);
                count = 0;
            }
        }
        return result;
    }

    int countResult(string S) {
        int result_length = 0;
        int index = 0;
        for (int i = 0; i < S.length(); i++) {
            index++;
            if (i >= S.length() || S[i] != S[i+1]) {
                result_length = result_length + 1 + to_string(index).length();
                index = 0;
            }
        }
        return result_length;
    }

};

