#include <iostream>
#include <vector>
using namespace std;

// Utility: print array
void printArray(const vector<int>& a) {
    for(int x : a) cout << x << " ";
    cout << "\n";
}

// Global/pass counter for analysis
int passCount = 0;

// Lomuto partition: partitions a[lo..hi] around pivot a[hi]
int partition(vector<int>& a, int lo, int hi) {
    int pivot = a[hi];
    int i = lo - 1;
    for(int j = lo; j < hi; j++) {
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[hi]);
    return i + 1;
}

// QuickSort with pass-by-pass analysis printing after each partition
void quickSort(vector<int>& a, int lo, int hi) {
    if(lo >= hi) return;
    int p = partition(a, lo, hi);

    // Pass analysis: after each partition, print current array and subarray bounds
    passCount++;
    cout << "Pass " << passCount << " (pivot index " << p << ", pivot " << a[p]
         << ", subarray [" << lo << "," << hi << "]): ";
    printArray(a);

    // Recurse on left and right partitions
    quickSort(a, lo, p - 1);
    quickSort(a, p + 1, hi);
}

// Divide and conquer to find min and max recursively
pair<int,int> findMinMax(const vector<int>& a, int lo, int hi) {
    // Base cases
    if(lo == hi) {
        return {a[lo], a[lo]};
    }
    if(hi == lo + 1) {
        int mn = min(a[lo], a[hi]);
        int mx = max(a[lo], a[hi]);
        return {mn, mx};
    }

    // Recurse on halves
    int mid = lo + (hi - lo) / 2;
    auto left = findMinMax(a, lo, mid);
    auto right = findMinMax(a, mid + 1, hi);

    // Combine results
    int mn = min(left.first, right.first);
    int mx = max(left.second, right.second);
    return {mn, mx};
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter marks of " << n << " students:\n";
    for(int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    cout << "\nInitial marks: ";
    printArray(marks);

    passCount = 0;
    quickSort(marks, 0, n - 1);

    cout << "\nSorted marks (ascending): ";
    printArray(marks);

    pair<int,int> result = findMinMax(marks, 0, n - 1);
    cout << "Minimum mark: " << result.first << "\n";
    cout << "Maximum mark: " << result.second << "\n";

    return 0;
}
