//[区间和](https://kamacoder.com/problempage.php?pid=1070)

#include <iostream>

int main() {
  int n, a, b, sum = 0;
  std::cin >> n;
  int nums[n];
  int p[n];
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
    sum += nums[i];
    p[i] = sum;
  }
  while (std::cin >> a >> b && a <= b) {
    if(a == 0){
      std::cout << p[b] << std::endl;
    }else{
        std::cout << p[b] - p[a - 1] << std::endl;
        }
    }
}