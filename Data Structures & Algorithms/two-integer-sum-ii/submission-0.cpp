class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target){
    int lPointer = 0;
    int rPointer = numbers.size() -1;
    while (numbers[lPointer] + numbers[rPointer] != target){
      if (numbers[lPointer] + numbers[rPointer] < target){
        lPointer++;
      }
      else{
        rPointer--;
      }
    }
    return {lPointer+1, rPointer+1};
  }
};