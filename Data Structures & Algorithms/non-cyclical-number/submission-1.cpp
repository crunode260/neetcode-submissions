class Solution {
public:
bool isHappy(int n){
  int current = n;
  unordered_set<int> seen;
  while (current != 1){
    if (seen.count(current) > 0){
      return false;
    }
    seen.insert(current);
    current = squareSum(current);
  }
  return true;

}

int squareSum(int n){
  if (n==0) return 0;
  return (n%10) * (n%10) + squareSum(n/10);
}};
