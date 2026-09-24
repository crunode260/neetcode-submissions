class Solution {
public:
  int characterReplacement(string s, int k){
    unsigned int lPointer = 0;
    unsigned int rPointer = 1;
    unsigned int maxOccurrences = 1;
    unsigned int longestLength = 1;
    char mostOccurred;
    unordered_map<char, unsigned int> occurrences;
    mostOccurred = s[lPointer];
    occurrences[s[lPointer]] = 1;
    occurrences[s[rPointer]]++;
    while (rPointer < s.size()){

      // Valid substring - right pointer moves
      if (occurrences[s[rPointer]] + k >= rPointer - lPointer + 1){
        if (occurrences[s[rPointer]] > maxOccurrences){
          maxOccurrences = occurrences[s[rPointer]];
          mostOccurred = s[rPointer];
        }

        rPointer++;
        if (rPointer < s.size()){
          occurrences[s[rPointer]]++;
        }

        if (rPointer - lPointer > longestLength){
          longestLength = rPointer - lPointer;
        }



      }
      // Need to correct for moving left pointer
      else if (maxOccurrences + k >= rPointer - lPointer + 1){

        if (occurrences[s[rPointer]] > maxOccurrences){
          maxOccurrences = occurrences[s[rPointer]];
          mostOccurred = s[rPointer];
        }


        rPointer++;
        if (rPointer < s.size()){
          occurrences[s[rPointer]]++;
        }


        if (rPointer - lPointer > longestLength){
          longestLength = rPointer - lPointer;
        }


      }

      // Invalid substring - left pointer moves
      else{

        occurrences[s[lPointer]]--;
        if (s[lPointer] == mostOccurred){
          maxOccurrences--;
        }
        for (auto i: occurrences){
          if (i.second > maxOccurrences){
            maxOccurrences = i.second;
            mostOccurred = i.first;
          }
        }

        lPointer++;
      }
      
     
    }
    return longestLength;

  }
};

