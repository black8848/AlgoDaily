[四数相加II](https://leetcode.cn/problems/4sum-ii/)

这题好难，看了答案才敲出来

首先遍历 nums1 nums2 数组的值，将其组合到一起，与上一题两数之和一样，将两数的值作为 Key ，该值出现次数为 Value

然后将 nums3 nums4 视作一组，将其组合到一起（有点类似分治），查看是否有与 map 中当前 Key 相加为 0 的值，有则 count++ ，最后返回count

```c++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        int count = 0;
        for (int a : nums1) {
            for(int b : nums2) {
                map[a + b]++;
            }
        }
        for(int c : nums3) {
            for (int d : nums4) {
                if (map.find(0 - c - d) != map.end()) {
                    count += map[0 - c - d];
                }
            }
        }
        return count++;
    }
};
```