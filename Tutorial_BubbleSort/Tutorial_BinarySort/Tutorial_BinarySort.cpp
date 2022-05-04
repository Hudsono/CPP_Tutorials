// Tutorial_BinarySort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int BinarySearch(int* list, int size, int target);
void PrintSearch(int l, int m, int r, int* list, int size);

int main()
{
    cout << "Hello World!\n";

    const int arrSize = 25;
    int arr[arrSize] = { 4,65,63,1,54,
        89,84,9,98,57,
        71,18,21,84,69,
        28,11,83,13,42,
        64,58,78,82,13 };

    int target = 71;

    int result = BinarySearch(arr, arrSize, target);

    cout << result;
}

//Returns the index of a given target int within an array, if found.
//Returns -1 if not found in the given array.
int BinarySearch(int* list, int size, int target)
{
    //start with the leftmost at the start of the array, and the rightmost and the end of the array
    int l = 0;
    int r = size - 1;
    int m = r / 2;
    PrintSearch(l, m, r, list, size);

    while (l <= r) {
        //the middle of the array is calculated each time we adjust the search boundaries L and/or R.
        m = (l + r) / 2;

        //if the middle IS our target, return that. Convenient.
        if (list[m] == target)
            return m;

        //if the middle is LESS than the target, we adjust our range to the right side by moving L to the middle + 1 (as we have already checked the middle above)
        if (list[m] < target)
            l = m + 1;

        //if the middle is MORE than the target, we adjust our range to the left side by moving R to the middle - 1 (as we have already checked the middle above)
        if (list[m] > target)
            r = m - 1;

        PrintSearch(l, m, r, list, size);
    }

    //If we haven't found anything, return -1.
    return -1;
}


void PrintSearch(int l, int m, int r, int* list, int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (i >= l && i <= r)
            if (i == m)
                cout << "<" << list[i] << ">";
            else
                cout << list[i];
        else
            cout << "..";

        if (i + 2 <= size)
            cout << " ";
        else
            cout << "]" << endl;
    }
}