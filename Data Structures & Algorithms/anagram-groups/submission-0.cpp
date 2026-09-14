string repeatChar(char character, int number){
  string s = "";
  for (int i = 0; i < number; i++){
    s+=character;
  }
  return s;
}

string sortString(string s){
  int letterHash[26];
  string newS = "";
  for (int i = 0; i < 26; i++){
    letterHash[i] = 0;
  }
  for (unsigned int i = 0; i < s.size(); i++){
    letterHash[tolower(s[i]) - 97]++;
  }
  for (int i = 0; i < 26; i++){
    newS += repeatChar(char(i + 97), letterHash[i]);
  }
  return newS;
}

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
      unordered_map<string, vector<string>> hashMap;
      string curWord;
      vector<vector<string>> output;
      for (int i = 0; i < strs.size(); i++){
        curWord = strs[i];
        curWord = sortString(curWord);
        vector<string> words;
        if (hashMap[curWord].empty()){
          hashMap[curWord] = words;
        }
        words = hashMap[curWord];
        words.push_back(strs[i]);
        hashMap[curWord] = words;
      }
      for (auto i : hashMap){
        output.push_back(i.second);
      }
      return output;
    }
};
