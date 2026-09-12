class Solution {
public:
bool isHappy(int n){
  int slow = n;
  int fast = squareSum(n);
  while (fast != slow){
    slow = squareSum(slow);
    fast = squareSum(squareSum(fast));
  }
  if (fast == 1){
    return true;
  }
  return false;
  

}

int squareSum(int n){
  if (n==0) return 0;
  return (n%10) * (n%10) + squareSum(n/10);
}
};
