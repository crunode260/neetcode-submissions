class Solution {
public:
  int findMin(vector<int> &nums) {
    int lPointer = 0;
    int rPointer = nums.size();
    int k1 = lPointer;
    int k2 = (lPointer + rPointer) / 2;
    while (rPointer > lPointer){
      if (nums[k1] < nums[k2]){
        lPointer = k2;
      }
      else{
        rPointer = k2;
      }
      k1 = lPointer;
      k2 = lPointer + (rPointer - lPointer) / 2;
    }
    return nums[(lPointer + 1) % nums.size()];
  }
};
