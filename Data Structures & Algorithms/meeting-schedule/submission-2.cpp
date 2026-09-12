/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

vector<Interval> merge(vector<Interval> list1, vector<Interval> list2){
  int l1Pointer = 0;
  int l2Pointer = 0;
  int length1 = list1.size();
  int length2 = list2.size();
  vector<Interval> mergedList;
  while (l1Pointer < length1 || l2Pointer < length2){
    if (l1Pointer == length1){
      mergedList.push_back(list2[l2Pointer]);
      l2Pointer++;
    }
    else if (l2Pointer == length2){
      mergedList.push_back(list1[l1Pointer]);
      l1Pointer++;
    }
    else{
      if (list1[l1Pointer].start <list2[l2Pointer].start){
        mergedList.push_back(list1[l1Pointer]);
        l1Pointer++;
      }
      else{
        mergedList.push_back(list2[l2Pointer]);
        l2Pointer++;
      }
    }
  }
  return mergedList;
}

vector<Interval> mergeSort(vector<Interval> nums){
  int length = nums.size();
  if (nums.size() > 1){
    vector<Interval> firstHalf(&nums[0], &nums[0] + length / 2);
    vector<Interval> secondHalf(&nums[0] + length / 2, &nums[length]);
    vector<Interval> list1 = mergeSort(firstHalf);
    vector<Interval> list2 = mergeSort(secondHalf);

    vector<Interval> mergedList = merge(list1, list2);
    return mergedList;
  }
  else{
    return nums;
  }
}

class Solution {
  public:
    bool canAttendMeetings(vector<Interval>& intervals) {
      if (intervals.size() == 0){
        return true;
      }  
      intervals = mergeSort(intervals);
      for (int i = 0; i < intervals.size() - 1; i++){
        if (intervals[i].end > intervals[i+1].start){
          return false;
        }
      }
      return true;
    }
};


