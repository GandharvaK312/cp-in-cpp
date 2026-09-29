#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                                                 LEETCODE #75

void print(vector<int>&nums){
   for(int x : nums) cout << x << "\t";
   cout  << endl;
}

// brute force approach would be any of the sorting algorithms

// void sortColors(vector<int>& nums) { // better approach
//    int count0 = 0, count1 = 0, count2 = 0;
//
//    for(int i = 0; i < (int)nums.size(); ++ i){
//       if(nums.at(i) == 0) count0 ++;
//       else if(nums.at(i) == 1) count1 ++;
//       else count2 ++;
//    }
//
//    for(int i = 0; i < count0; ++ i) nums[i] = 0;
//    for(int i = count0; i < count0 + count1; ++ i) nums[i] = 1;
//    for(int i = count0 + count1; i < count0 + count1 + count2; ++ i) nums[i] = 2;
// }

void sortColors(vector<int>& nums) { // Dutch National Flag Algorithm
   // block1: [0, .. ....  , low - 1] -> 0s extreme left
   // block2: [low, . ......, mid - 1] -> 1s
   // block3: [mid = , . .. . high] -> 0|1|2s random way unsorted
   // block4: [high + 1, .... n - 1] -> 2s extreme right1ww
   //
   // block1 and 2 are sorted, block 4 is also sorted, so only block 3 needs to be sorted now
   int mid = 0, low = 0, high = nums.size() - 1;
  cout << nums[low] << " " << nums[high] << endl;

   while(mid <= high){
      if(nums[mid] == 0) { swap(nums[low], nums[mid]);  low  ++; mid ++; }
      else if(nums[mid] == 1) { mid ++; }
      else if(nums[mid] == 2) { swap(nums[mid], nums[high]); high --;}
   }
}

int main(void) {

   vector<int> nums = {2, 0, 2, 1, 1, 0};

   print(nums);

   sortColors(nums);

   print(nums);

   return 0;
}
