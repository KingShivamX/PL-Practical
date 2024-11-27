#include<iostream>
using namespace std;

void rotatearray(int n, int k, int arr[]){
    k = k % n;
    for(int i=0; i<n; i++){
        if(i < k)
        {
            cout << arr[n + i - k] << " ";
        }
        else {
            cout << (arr[i - k]) << " ";
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];

    cout << "Enter elements of array : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Original Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int k;
    cout << "Enter k : ";
    cin >> k;

    cout << "Right Rotation of array : ";
    rotatearray(n,k,arr);
}
