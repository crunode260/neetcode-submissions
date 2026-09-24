class Solution{
public:
  bool checkInclusion(string s1, string s2){
    if (s1.size() > s2.size()){
      return false;
    }
    int s1Arr[26]{};
    int lPointer = 0;
    int rPointer = lPointer + s1.size();
    int windowArr[26]{};
    for (unsigned int i = 0; i < s1.size(); i++){
      s1Arr[s1[i] - 97]++; 
      windowArr[s2[i] - 97]++;
    }
    while (rPointer < s2.size()){
      if (checkEquality(s1Arr, windowArr)){
        return true;
      }
      windowArr[s2[lPointer] - 97]--;
      windowArr[s2[rPointer] - 97]++;
      lPointer++;
      rPointer++;
    }
    if (checkEquality(s1Arr, windowArr)){
      return true;
    }
    return false;

  }
  bool checkEquality(int s1Arr[26], int s2Arr[26]){
    for (int i = 0; i < 26; i++){
      if (s1Arr[i] != s2Arr[i]){
        return false;
      }
    }
    return true;
  }
};