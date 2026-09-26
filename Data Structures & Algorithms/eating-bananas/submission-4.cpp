class Solution {
public:
  int findMax(vector<int> piles){
    int max = piles[0];
    for (int i = 1; i < piles.size(); i++){
      if (piles[i] > max){
        max = piles[i];
      }
    }
    return max;
  }

  int timeEating(vector<int> piles, int k){
    int time = 0;
    for (int i = 0; i < piles.size(); i++){
      time += (piles[i] / k);
      if (piles[i] % k > 0){
        time++;
      }
    }
    return time;
  }


  int minEatingSpeed(vector<int>& piles, int h) {
    int max = findMax(piles);
    int rPointer = max + 1;
    int lPointer = 0;
    int k = (lPointer + rPointer) / 2;
    while (lPointer < rPointer){
      if (k==0){
        return 1;
      }
      if (timeEating(piles, k) > h){
        lPointer = k + 1;
      }
      else{
        rPointer = k;
      }
      k = (lPointer + rPointer) / 2;
    }
    if (k==1 || k == max){
      return k;
    }
    if (timeEating(piles, k-1) <= h){
      return k-1;
    }
    if (timeEating(piles, k) <= h){
      return k;
    }
    return k+1;
  }
};
