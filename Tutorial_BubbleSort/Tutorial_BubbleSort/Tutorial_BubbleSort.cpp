// Tutorial_BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void BubbleSort(int* list, int size, bool descending);
void PrintArray(int *list, int size);
void Swap(int &a, int &b);
bool IsFirstGreater(int a, int b);

void OptimisedBubbleSort(int* list, int size, bool descending);
void CocktailShakerSort(int* list, int size, bool descending);

int swaps;
int comparisons;

int main()
{
    cout << "Hello World!\n";

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