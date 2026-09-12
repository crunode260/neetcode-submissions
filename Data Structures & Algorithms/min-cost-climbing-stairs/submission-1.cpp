class Solution {
public:
int minCostClimbingStairs(vector<int>& cost){
  int topStep = cost.size();
  if (topStep == 1){
    return 0;
  }
  vector<int> c(topStep + 1);
  c[0] = 0;
  c[1] = 0;
  for (int i = 2; i <= topStep; i++){
    c[i] = min(c[i-2] + cost[i-2], c[i-1] + cost[i-1]);
  }
  return c[topStep];
}};
