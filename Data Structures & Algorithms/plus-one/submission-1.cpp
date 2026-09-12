class Solution {
public:
vector<int> plusOne(vector<int>& digits){
  vector<int> reversedDigits;
  for (int i = digits.size() - 1; i >= 0; i--){
    reversedDigits.push_back(digits[i]);
  }
  reversedDigits[0] += 1;
  int i = 0;
  while (reversedDigits[i] == 10 && i < reversedDigits.size() - 1){
    reversedDigits[i] = 0;
    reversedDigits[i+1]++;
    i++;
  }
  if (reversedDigits[reversedDigits.size() - 1] == 10){
    reversedDigits[reversedDigits.size() - 1] = 0;
    reversedDigits.push_back(1);
  }
  vector<int> newDigits;
  for (int i = reversedDigits.size() - 1; i >=0; i--){
    newDigits.push_back(reversedDigits[i]);
  }
  return newDigits;
}
};
