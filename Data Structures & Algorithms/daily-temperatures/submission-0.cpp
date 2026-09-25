class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> temp;
    temp.push({temperatures[0], 0});
    vector<int> daysAfter(temperatures.size());
    pair<int, int> lastElem;
    for (int i = 1; i < temperatures.size(); i++){
      lastElem = temp.top();
      while (temperatures[i] > lastElem.first){
        daysAfter[lastElem.second] = (i - lastElem.second);
        temp.pop();
        if (temp.size() > 0){
          lastElem = temp.top();
        }
        else{
          break;
        }
      }
      temp.push({temperatures[i], i});
    }
    while (temp.size() > 0){
      lastElem = temp.top();
      daysAfter[lastElem.second] = 0;
      temp.pop();
    }
    return daysAfter;
  }
};
