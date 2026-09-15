class Solution {
  public: 
    string escapeString = "%linebr/%";
    string encode(vector<string> &strs){
      string encodedString = "";
      for (unsigned int i = 0; i < strs.size(); i++){
        encodedString += strs[i];
        encodedString += escapeString;
      }
      return encodedString;

    }

    vector<string> decode(string s){
      vector<string> decodedString;
      string word = "";
      unsigned int i = 0;
      while (i < s.size()){
        if (s[i] == '%'){
          bool f = true;
          for (unsigned int j = 1; j < 9; j++){
            if (i + j == s.size()){
              word += s.substr(i, j);
              i+=j;
              f=false;
              break;
            }
            if (s[i+j] != escapeString[j]){
              word += s.substr(i, j);
              i+=j;
              f=false;
              break;
            }
          }
          if (f){
            decodedString.push_back(word);
            i+=9;
            word = "";
          }
        }
        else{
          word += s[i];
          i++;
        }
      }
      return decodedString;
    }
};
