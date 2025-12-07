#include <iostream>
#include <vector>

// Q1 ------------------------------------------
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void maxheap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// Q2 ------------------------------------------

#include <unordered_map>
#include <queue>
using namespace std;
vector<int> mostfrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> frequency;
    for (int i = 0; i < nums.size(); i++)
    {
        int value = nums[i];
        frequency[value] = frequency[value] + 1;
    }
    priority_queue<pair<int, int>> maxheap;
    unordered_map<int, int>::iterator it;
    for (it = frequency.begin(); it != frequency.end(); it++)
    {
        int num = it->first;
        int freqvalue = it->second;
        maxheap.push(make_pair(freqvalue, num));
    }
    vector<int> result;
    while (k > 0 && !maxheap.empty())
    {
        pair<int, int> toppair = maxheap.top();
        maxheap.pop();
        int number = toppair.second;
        result.push_back(number);
        k--;
    }
    return result;
}
// Q3 ------------------------------------------
using namespace std;
struct Compare
{
    bool operator()(pair<int, char> a, pair<int, char> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};
string frequencysort(string s)
{
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;
    priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> pq;
    unordered_map<char, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
        pq.push(make_pair(it->second, it->first));
    string result = "";
    while (!pq.empty())
    {
        pair<int, char> top = pq.top();
        pq.pop();
        result.append(top.first, top.second);
    }
    return result;
}

// A4 ------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
double mincosttohire(vector<int> &quality, vector<int> &wage, int k)
{
    vector<pair<double, int>> workers;
    for (int i = 0; i < quality.size(); i++)
        workers.push_back({(double)wage[i] / quality[i], quality[i]});
    sort(workers.begin(), workers.end());
    priority_queue<int> maxheap;
    int qualitysum = 0;
    double mincost = 999999999999.0; // high val
    for (auto &w : workers)
    {
        double ratio = w.first;
        int q = w.second;
        maxheap.push(q);
        qualitysum += q;
        if (maxheap.size() > k)
        {
            qualitysum -= maxheap.top();
            maxheap.pop();
        }
        if (maxheap.size() == k)
            mincost = min(mincost, qualitysum * ratio);
    }
    return mincost;
}

int main()
{

    // A1 ------------------------------------------

    cout << "===================Ans 1==========================" << endl;

    vector<int> arr = {10, 30, 20, 5};
    maxheap(arr);
    for (int x : arr)
        cout << x << " ";
    return 0;

    // A2 ------------------------------------------
    cout << "===================Ans 2==========================" << endl;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int k = 2;
    vector<int> answer = mostfrequent(nums, k);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;

    // A3 ------------------------------------------
    cout << "===================Ans 3==========================" << endl;

    string s = "tree";
    cout << frequencysort(s);
    return 0;

    // A4 ------------------------------------------
    cout << "===================Ans 4==========================" << endl;

    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    int k = 2;
    cout << mincosttohire(quality, wage, k);
    return 0;
}
