class Solution {
    /* 题解思路：
    记录0所在的位置 然后清空行和列 时间复杂度为O(MN)
    但实际上我们只需要记录需要清空的行和列就可以了
    */
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(matrix.size(), false);
        vector<bool> column(matrix[0].size(), false);
        // 遍历二维数组
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        // 清空行
        for (int i = 0; i < row.size(); i++) {
            if (row[i]) cleanRow(matrix, i);
        }
        // 清空列
        for (int j = 0; j < column.size(); j++) {
            if (column[j]) cleanColumn(matrix, j);
        }
    }
    void cleanRow(vector<vector<int>>& matrix, int row) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[row][j] = 0;
        }
    }
    void cleanColumn(vector<vector<int>>& matrix, int column) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][column] = 0;
        }
    }
};
