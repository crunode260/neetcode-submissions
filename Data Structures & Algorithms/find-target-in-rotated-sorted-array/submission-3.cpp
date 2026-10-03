class Solution {
public:
  int search(vector<int>& nums, int target) {
    int lPointer = 0;
    int rPointer = nums.size();
    int m;
    while (lPointer < rPointer){
      m = (lPointer + rPointer) / 2;
      if (nums[m] == target){
        return m;
      }
      if (nums[lPointer] == target){
        return lPointer;
      }
      if (nums[lPointer] < target && nums[m] < target){
        if (nums[m] > nums[lPointer]){
          lPointer = m+1;
        }
        else{
          rPointer = m;
        }
      } 
      else if (nums[lPointer] < target && nums[m] > target){
        rPointer = m ;
      }
      else if (nums[lPointer] > target && nums[m] > target){
        if (nums[m] > nums[lPointer]){
          lPointer = m+1;
        }
        else{
          rPointer = m;
        }
      }
      else if (nums[lPointer] > target && nums[m] < target){
        lPointer = m + 1;
      }
    }
    return -1;
  }
};
