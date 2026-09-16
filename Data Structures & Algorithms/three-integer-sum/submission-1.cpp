class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums){
    int lPointer;
    int rPointer;
    int requiredSum;
    vector<vector<int>> solution;
    sort(nums.begin(), nums.end());
    vector<int> storage;
    for (int i = 0; i < nums.size(); i++){
      if (i > 0 && nums[i] == nums[i-1]){
        continue;
      }
      lPointer = i+1;
      rPointer = nums.size() - 1;
      requiredSum = -nums[i];
      while (lPointer < rPointer){
        if (nums[lPointer] + nums[rPointer] == requiredSum){
          storage = {nums[i], nums[lPointer], nums[rPointer]};
          solution.push_back(storage);
          lPointer++;
          while (nums[lPointer - 1] == nums[lPointer] && lPointer < rPointer){
            lPointer++;
          }
        }
        else if (nums[lPointer] + nums[rPointer] < requiredSum){
          lPointer++;
        }
        else{
          rPointer--;
        }
      }
    }
    return solution;
  }
};