#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] >= pivot)
            count++;
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] >= pivot)
            i++;

        while (arr[j] < pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int n;
    cin >> n;

    int arr[100000];

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    cout << "Top 5: ";
    long long topSum = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
        topSum += arr[i];
    }

    cout << endl;

    cout << "Average of Top 5: " << topSum / 5.0 << endl;

    double avg = (double)sum / n;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
            count++;
    }

    cout << "Values Above Overall Average: " << count;

    return 0;
}