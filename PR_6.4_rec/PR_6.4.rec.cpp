// PR_6.4.rec.cpp
// Варіант 8 (рекурсивний спосіб)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Input(double* a, const int size, int i)
{
    cout << "a[" << i << "] = ";
    cin >> a[i];
    if (i < size - 1)
        Input(a, size, i + 1);
}

void Print(const double* a, const int size, int i)
{
    cout << setw(8) << fixed << setprecision(2) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int MinIndex(const double* a, const int size, int i, int minIdx)
{
    if (i >= size)
        return minIdx;
    if (a[i] < a[minIdx])
        minIdx = i;
    return MinIndex(a, size, i + 1, minIdx);
}

int FirstNegativeIndex(const double* a, const int size, int i)
{
    if (i >= size)
        return -1;
    if (a[i] < 0)
        return i;
    return FirstNegativeIndex(a, size, i + 1);
}

int SecondNegativeIndex(const double* a, const int size, int i, int countNeg)
{
    if (i >= size)
        return -1;
    if (a[i] < 0)
    {
        countNeg++;
        if (countNeg == 2)
            return i;
    }
    return SecondNegativeIndex(a, size, i + 1, countNeg);
}

double SumBetweenIndices(const double* a, int current, int end)
{
    if (current >= end)
        return 0.0;
    return a[current] + SumBetweenIndices(a, current + 1, end);
}

double SumBetweenNegatives(const double* a, const int size)
{
    int firstIdx = FirstNegativeIndex(a, size, 0);
    int secondIdx = SecondNegativeIndex(a, size, 0, 0);
    if (firstIdx == -1 || secondIdx == -1 || secondIdx <= firstIdx + 1)
        return 0.0;
    return SumBetweenIndices(a, firstIdx + 1, secondIdx);
}

void Shift(double* a, int j, int to)
{
    if (j > to)
    {
        double tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
        Shift(a, j - 1, to);
    }
}

void Transform(double* a, const int size, int i, int insertPos)
{
    if (i >= size)
        return;
    if (a[i] >= -1.0 && a[i] <= 1.0)
    {
        Shift(a, i, insertPos);
        Transform(a, size, i + 1, insertPos + 1);
    }
    else
    {
        Transform(a, size, i + 1, insertPos);
    }
}

void Transform(double* a, const int size)
{
    Transform(a, size, 0, 0);
}

#if !defined(_WINDLL)
int main()
{
    int n;
    cout << "Enter array size n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid size!" << endl;
        return 1;
    }

    double* a = new double[n];
    Input(a, n, 0);

    cout << "\nOriginal array:" << endl;
    Print(a, n, 0);

    int minIdx = MinIndex(a, n, 1, 0);
    cout << "\n1.1. Index of minimum element: " << minIdx 
         << " (value = " << a[minIdx] << ")" << endl;

    double sumBetween = SumBetweenNegatives(a, n);
    cout << "1.2. Sum of elements between 1st and 2nd negatives: " 
         << sumBetween << endl;

    Transform(a, n);
    cout << "\n2. Transformed array (|a[i]| <= 1 first):" << endl;
    Print(a, n, 0);

    delete[] a;
    return 0;
}
#endif
