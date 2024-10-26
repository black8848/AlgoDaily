[螺旋矩阵II](https://leetcode.cn/problems/spiral-matrix-ii/)

//代码掌控问题，从循环中找出能停止的不变量

```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int mid = n / 2;  // 如果 n 是奇数的话，[mid,mid]为中间位置
        int loop = n / 2; // 循环 loop 圈
        int x = 0, y = 0; // 初始坐标
        int d = 1;
        int count = 1;
        while (loop--) {
            int i = x, j = y;

            for (; i < n - d; i++) { // 第一圈
                matrix[j][i] = count++;
            }

            for (; j < n - d; j++) { // 第二圈
                matrix[j][i] = count++;
            }

            for (; i > x; i--) {
                matrix[j][i] = count++;
            }

            for (; j > y; j--) {
                matrix[j][i] = count++;
            }
            d++;
            x++;
            y++;
        }
        if (n % 2) {
            matrix[mid][mid] = n * n;
        }
        return matrix;
    }
};
```