#include <iostream>
using namespace std;

void swap(int *a, int firstIndex, int secondIndex) {
    int temp = a[firstIndex];
    a[firstIndex] = a[secondIndex];
    a[secondIndex] = temp;
}

int findPivot(int *a, int left, int right,
              bool (*compareFunc)(const int &a, const int &b)) {
    int middle = (left + right) / 2;
    if (compareFunc(a[right], a[left])) {
        swap(a, right, left);
    }
    if (compareFunc(a[right], a[middle])) {
        swap(a, middle, right);
    } else if (compareFunc(a[middle], a[left])) {
        swap(a, middle, left);
    }
    return middle;
}


int partition(int *a, int left, int right,
              bool (*compareFunc)(const int &a, const int &b)) {
    if (right - left < 1) {
        return left;
    }
    int pivotPosition = findPivot(a, left, right, compareFunc);
    swap(a, left, pivotPosition);
    int i = right;
    int j = i;
    while (j > 0) {
        if (compareFunc(a[left], a[j])) {
            swap(a, i, j);
            i--;
        }
        j--;
    }
    swap(a, left, i);
    return i;
}

bool defaultCompare(const int &a, const int &b) {
    return a < b;
}

int findKStat(int *a, int n, int k,
            bool (*compareFunc)(const int &a, const int &b) = defaultCompare) {
    int left = 0;
    int right = n - 1;
    int part = partition(a, left, right, compareFunc);
    while (part != k) {
        if (k < part) {
            right = part - 1;
        } else {
            left = part + 1;
        }
        part = partition(a, left, right, compareFunc);
    }
    return a[part];
}


int main() {
    int n = 0;
    int k = 0;
    while(1) {
        cout << " N: ";
        cin >> n;
        cout << "\n K: ";
        cin >> k;
        int *A = new int[n];
        cout << "\n Enter: ";
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        cout << "\n K-stat (from zero): " << findKStat(A, n, k) << endl;
        delete[] A;
    }
    return 0;
}
