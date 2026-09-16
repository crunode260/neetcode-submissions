class Solution{
public:
  int maxArea(vector<int> &heights){
    int maxA = 0;
    int lPointer = 0;
    int rPointer = heights.size() - 1;
    while (lPointer < rPointer){
      int area = min(heights[lPointer], heights[rPointer]) * (rPointer - lPointer);
      if (area > maxA){
        maxA = area;
      }
      if (heights[lPointer] < heights[rPointer]){
        lPointer++;
      }
      else if (heights[rPointer] < heights[lPointer]){
        rPointer--;
      }
      else{
        lPointer++;
      }
    }
    return maxA;
  }
};