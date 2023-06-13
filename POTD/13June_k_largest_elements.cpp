class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int, std::vector<int>, 
        std::greater<int>> pq;
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++) {
        if (arr[i] >= pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> al;
    while (!pq.empty()) {
        al.push_back(pq.top());
        pq.pop();
    }
    sort(al.rbegin(), al.rend());
    vector<int> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = al[i];
    }
    return result;
}


};