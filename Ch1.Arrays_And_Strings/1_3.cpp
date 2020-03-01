class Solution {
public:
    string replaceSpaces(string S, int length) {
        string str = “”;
        for(int i=0;i<length;i++){
            if(S[i]==' '){
                str+="%20";
            }else{
                str+=S[i];
            }
        }
        return str;
    }
};
// 遍历替换 可能使用了额外的空间可以尝试不用string
// 内存消耗28.1M
class Solution {
public:
    string replaceSpaces(string S, int length) {
        int numOfSpaces = 0;
        int i = 0, j = 0;
        for ( i = 0; i < length; ++i ) {
            if (S[i] == ' ') {
                ++numOfSpaces;
            }
        }

        int extendedLen  = length + 2 * numOfSpaces;
        i = extendedLen - 1;
        if(length < S.length()) {
            S[extendedLen] = '\0';
        }
        for( j = length - 1; j >= 0; --j ) {
            if ( S[j] != ' ' ) {
            S[i--] = S[j];
            } else {
                S[i--] = '0';
                S[i--] = '2';
                S[i--] = '%';
            }
        }
        return S;
    }
};
// 减少内存消耗 22.8M 时间消耗相同
