class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 检查矩阵是否为正方形矩阵
        if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {
            cout << "input error" << endl;
        } 
        else {
            int n = matrix.size();
            // 遍历需要执行多少层
            for (int layer = 0; layer < n/2; layer++) {
                int first = layer;
                int last = n - 1 - layer;
                for (int i = first; i < last; i++) {
                    int offset = i - first;
                    //  储存上边
                    int top = matrix[first][i];                    
                    // 左边移动到上边
                    matrix[first][i] = matrix[last - offset][first];
                    // 下边移动到左边
                    matrix[last - offset][first] = matrix[last][last - offset];
                    //右边移动到下边
                    matrix[last][last - offset] = matrix[i][last];
                    //上边移动到右边
                    matrix[i][last] = top;
                }
            }
        }
    }
};
