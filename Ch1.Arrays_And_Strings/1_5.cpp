class Solution {
public:
    bool oneEditAway(string first, string second) {
        // 长度diff是否超过1
        if (fabs(double(first.length()) - double(second.length())) > 1 ) {
            return false;
        }
        
        // 判断两个字符串长短
        string s_short = (first.length() < second.length()) ? first : second;
        string s_long = (first.length() < second.length()) ? second: first;
        // 设置指针参数
        int index_short = 0;
        int index_long = 0;
        bool FindDiff = false;
        // 遍历字符串
        while (index_long < s_long.length() && index_short < s_short.length()) {
            // 如果字节不相等 记录
            if (s_long.at(index_long) != s_short.at(index_short)) {
                if (FindDiff) return false;
                FindDiff = true;

                // 如果字符串长度相等 移动较短指针
                
                if (s_short.length() == s_long.length()) {
                    index_short++;
                }
            } 
            else {
                index_short++; // 如果char指针相匹配 移动较短字符串指针
            }

            // 总是移动较长字符串指针
            index_long++;
        }
        return true;
    }
};
// 关于绝对值函数用fabs的解释
// ref: https://blog.csdn.net/linwh8/article/details/50754147
// 关于fabs如果不将数字cast成double会出现溢出报错
// 另找不到abs的function
