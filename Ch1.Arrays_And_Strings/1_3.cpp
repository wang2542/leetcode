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
