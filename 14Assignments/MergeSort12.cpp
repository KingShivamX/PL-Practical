#include <iostream>
using namespace std;

class Sorter {
public:
    void merge(float arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        float L[n1], R[n2];
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    void mergeSort(float arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
};

int main() {
    Sorter sorter;
    float percentages[] = {85.5, 72.0, 90.5, 65.5, 88.8};
    int n = 5;
    sorter.mergeSort(percentages, 0, n - 1);
    for (int i = 0; i < n; i++) cout << percentages[i] << " ";
}
