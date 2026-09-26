class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int lPointer = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int rPointer = m * n;
    int midPoint = (lPointer + rPointer) / 2;
    while (lPointer < rPointer){
      if (matrix[midPoint / n][midPoint % n] == target){
        return true;
      }
      if (matrix[midPoint / n][midPoint % n] > target){
        rPointer = midPoint;
      }
      else{
        lPointer = midPoint + 1;
      }
      midPoint = (lPointer + rPointer) / 2;
    }
    return false;
  }
};
