class Solution{
public:
  int lengthOfLongestSubstring(string s){
    if (s.size() == 0){
      return 0;
    }
    unsigned int maxLength = 1;
    unsigned int lPointer = 0;
    unsigned int rPointer = 1;
    unordered_map<char, unsigned int> uniqueLetters;
    vector<int> toErase;
    uniqueLetters[s[lPointer]] = lPointer;
    while (rPointer < s.size()){
      rPointer++;
      if (uniqueLetters.count(s[rPointer - 1]) != 0){
        lPointer = uniqueLetters[s[rPointer - 1]] + 1;
        for (auto i : uniqueLetters){
          if (i.second < lPointer){
            toErase.push_back(i.first);
          }
        }
        for (unsigned int i = 0; i < toErase.size(); i++){
          uniqueLetters.erase(toErase[i]);
        }
        toErase.clear();
        uniqueLetters[s[rPointer-1]] = rPointer-1;
      }
      else{

        uniqueLetters[s[rPointer - 1]] = rPointer - 1;
      }
      if (rPointer - lPointer > maxLength){
        maxLength = rPointer - lPointer;
      }
    }
    return maxLength;
    
  }
};
