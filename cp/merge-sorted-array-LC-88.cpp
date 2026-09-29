#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                                                 Leetcode #88

void print(vector<int> &arr){
   for(int i : arr) cout << i << "\t";
        cout << endl;
}

int main(void) {

   vector<int> nums1 = {1, 2, 3, 0, 0, 0}; int m = 3, n = 3;
   vector<int> nums2 = {2, 5, 6};
   print(nums1);
   print(nums2);

   for(int i = m, j = 0; i < m + n && j < n; i ++){
      nums1[i] = nums2[j];
      j ++;
   }
   sort(nums1.begin(), nums1.end());

   print(nums1);

   return 0;
}
