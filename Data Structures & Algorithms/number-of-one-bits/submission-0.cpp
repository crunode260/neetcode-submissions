class Solution{
  public: 
    int hammingWeight(uint32_t n){
      int j = 1;
      int ones = 0;
      for (int i = 0; i < 32; i++){
        if ((j & n) != 0){
          ones++;
        }
        j = j << 1;
      }
      return ones;
    }
};