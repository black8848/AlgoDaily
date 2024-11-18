[反转字符串II](https://leetcode.cn/problems/reverse-string-ii/)

直接将 i 以 2k 为进位向前

- 如果以 i 为起始的位置到 k 的位置还是小于 s.size()

    则直接使用 STL 库函数传入起始迭代器 s.begin() + i 和 终点迭代器 s.begin() + i + k

- 如果以 i 为起始的位置到 k 的位置大于 s.size()

    则将 i 起始的位置以后全部反转，传入 s.begin() + i 和 s.end()


```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k < s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
```