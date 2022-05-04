// Tutorial_BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//BubbleSort
void Task1();
void BubbleSort(int* list, int size, bool descending);
void PrintArray(int *list, int size);
void Swap(int &a, int &b);
bool IsFirstGreater(int a, int b);

void OptimisedBubbleSort(int* list, int size, bool descending);
void CocktailShakerSort(int* list, int size, bool descending);

int swaps;
int comparisons;

//BinarySearch
void Task2();
int BinarySearch(int* list, int size, int target);
void PrintSearch(int l, int m, int r, int* list, int size);

int main()
{
    Task1();
    Task2();
}

//Binary searching initialisation.
void Task2()
{
    cout << "BinarySearch" << endl;

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

//Bubble sorting initialisation.
void Task1()
{
    cout << "BubbleSort" << endl;

    const int array_size = 50;
    int array_to_be_sorted[array_size] = {
        14,65,63,1,54,
        89,84,9,98,57,
        71,18,21,84,69,
        28,11,83,13,42,
        64,58,78,82,13,
        9,96,14,39,89,
        40,32,51,85,48,
        40,23,15,94,93,
        35,81,1,9,43,
        39,15,17,97,52
    };

    //BubbleSort(array_to_be_sorted, array_size, false);

    //cout << "Swaps = " << swaps << endl;
    //cout << "Comparisons = " << comparisons << endl;

    //swaps = 0;
    //comparisons = 0;

    //cout << endl << endl;

    //OptimisedBubbleSort(array_to_be_sorted, array_size, false);

    CocktailShakerSort(array_to_be_sorted, array_size, false);

    cout << "Swaps = " << swaps << endl;
    cout << "Comparisons = " << comparisons << endl;


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

//Print the search results in a readable format.
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

//Sort a C array of integers in ascending or descending order.
void BubbleSort(int *list, int size, bool descending)
{
    //if our list has less than 2 members, then there's nothing to sort. Just print the number or an empty array representation
    if (size == 1)
    {
        cout << "{ " << list[0] << " }" << endl;
        return;
    }
    else if (size < 1)
    {
        //though this shouldn't ever come up since arrays with less than 1 member can't exist
        cout << "{ }" << endl;
        return;
    }

    //Loop until no more sorting can be done; it's sorted
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            //Different comparison depending on what order of sorting was requested
            if (!descending)
            {
                //if a value is greater than the next value, swap them (ascending)
                if (IsFirstGreater(list[i], list[i + 1]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
            else
            {
                //if a value is less than the next value, swap them (descending)
                if (IsFirstGreater(list[i + 1], list[i]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
        }
    }

    //for convenience, print the result
    PrintArray(list, size);
}

//Sort a C array of integers in ascending or descending order, optimised.
//??? Optimization 1 does not work. Looping 1 less time does not reflect its comparison/swap values, nor is the largest number guaranteed to be at the end on the fist swap. This makes no sense.
void OptimisedBubbleSort(int* list, int size, bool descending)
{
    //if our list has less than 2 members, then there's nothing to sort. Just print the number or an empty array representation
    if (size == 1)
    {
        cout << "{ " << list[0] << " }" << endl;
        return;
    }
    else if (size < 1)
    {
        //though this shouldn't ever come up since arrays with less than 1 member can't exist
        cout << "{ }" << endl;
        return;
    }



    //Loop until no more sorting can be done; it's sorted
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < size - 2; ++i)
        {
            //Different comparison depending on what order of sorting was requested
            if (!descending)
            {
                //if a value is greater than the next value, swap them (ascending)
                if (IsFirstGreater(list[i], list[i + 1]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
            else
            {
                //if a value is less than the next value, swap them (descending)
                if (IsFirstGreater(list[i + 1], list[i]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
        }
    }

    //for convenience, print the result
    PrintArray(list, size);
}

//also doesn't work
void CocktailShakerSort(int* list, int size, bool descending)
{
    //if our list has less than 2 members, then there's nothing to sort. Just print the number or an empty array representation
    if (size == 1)
    {
        cout << "{ " << list[0] << " }" << endl;
        return;
    }
    else if (size < 1)
    {
        //though this shouldn't ever come up since arrays with less than 1 member can't exist
        cout << "{ }" << endl;
        return;
    }

    //Loop until no more sorting can be done; it's sorted
    bool isSorted = false;

    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            //Different comparison depending on what order of sorting was requested
            if (!descending)
            {
                //if a value is greater than the next value, swap them (ascending)
                if (IsFirstGreater(list[i], list[i + 1]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
            else
            {
                //if a value is less than the next value, swap them (descending)
                if (IsFirstGreater(list[i + 1], list[i]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
        }

        for (int i = size; i < 1; i++)
        {
            //Different comparison depending on what order of sorting was requested
            if (!descending)
            {
                //if a value is greater than the next value, swap them (ascending)
                if (IsFirstGreater(list[i], list[i + 1]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
            else
            {
                //if a value is less than the next value, swap them (descending)
                if (IsFirstGreater(list[i + 1], list[i]))
                {
                    Swap(list[i], list[i + 1]);
                    isSorted = false;   //tell the loop that we had to swap something and are thus not done sorting; go again
                }
            }
        }
    }

    //for convenience, print the result
    PrintArray(list, size);
}

//Print a C array.
void PrintArray(int *list, int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << list[i];
        if (i + 1 < size)
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

//Swap 2 integers.
//Use: Swap(&a, &b);
void Swap(int &a, int &b)
{
    //this method makes the pointers swap; pointer now points to the others' value instead.
    int temp = a;
    a = b;
    b = temp;

    swaps++;
}

//Returns true if a > b
bool IsFirstGreater(int a, int b)
{
    comparisons++;
    return a > b;
}