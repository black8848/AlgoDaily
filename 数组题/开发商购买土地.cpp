//[开发商购买土地](https://kamacoder.com/problempage.php?pid=1044)

//区间和问题

#include <iostream>

int minnum(int x, int y) {
  int m = 0;
  x = x > 0 ? x : -x;
  y = y > 0 ? y : -y;
  m = x > y ? y : x;
  return m;
}

int main(void) {
  // 输入
  int n, m, tmp = 0, min = 2147483647;
  int total = 0;
  std::cin >> n >> m;
  int nums[n][m];
  int vertical[n], vt = 0;
  int horizontal[m], ht = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> nums[i][j];
      total += nums[i][j];
      tmp += nums[i][j];
    }
    horizontal[i] = tmp;
    tmp = 0;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      tmp += nums[j][i];
    }
    vertical[i] = tmp;
    tmp = 0;
  }
  tmp = total;
  if (n != 1) {
    // 横着划线计算
    for (int i = 0; i < n; i++) {
      ht += horizontal[i];
      min = minnum(min, ht - (total - ht));
    }
  }
  tmp = total;
  if (m != 1) {
    // 竖着划线计算
    for (int i = 0; i < m; i++) {
      vt += vertical[i];
      min = minnum(min, vt - (total - vt));
    }
  }
  std::cout << min << std::endl;
}
