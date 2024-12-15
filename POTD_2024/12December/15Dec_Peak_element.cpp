class Solution
{
    public:
     int peakElement(vector<int>& arr)
    {
       int start = 0, end = arr.size() - 1, mid;
       while (start <= end) {
           mid = (start + end) / 2;
           int prev = mid - 1 >= 0 ? mid - 1 : 0;
           int next = mid + 1 < arr.size() ? mid + 1 : arr.size() - 1;
           if (arr[mid] >= arr[prev] && arr[mid] >= arr[next]) return mid;
           else if (arr[mid] < arr[next]) start = mid + 1;
           else end = mid - 1;
       }
       return 0;
    }
};