class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k){
      unordered_map<int, int> freqTable;
      int maxFreq = 0;
      vector<int> mostFreqK;
      int numberFound = 0;
      for (unsigned int i = 0; i < nums.size(); i++){
        if (freqTable.count(nums[i]) == 0){
          freqTable[nums[i]] = 0;
        }
        freqTable[nums[i]]++;
        if (freqTable[nums[i]] > maxFreq){
          maxFreq = freqTable[nums[i]];
        }
      }
      // Element at ith index has frequency i
      vector<vector<int>> orderedFreq(maxFreq);
      vector<int> emptyVector;
      for (int i = 0; i < maxFreq; i++){
        orderedFreq[i] = emptyVector;
      }
      for (auto i:freqTable){
        orderedFreq[i.second - 1].push_back(i.first);
      }
      int i = 1;
      while (numberFound < k){
        if (orderedFreq[maxFreq - i].size() > 0){
          for (unsigned int j = 0; j < orderedFreq[maxFreq - i].size(); j++){
            mostFreqK.push_back(orderedFreq[maxFreq - i][j]);
          }
          numberFound += orderedFreq[maxFreq - i].size();
        }
        i++;
      }
      return mostFreqK;

    }
};
