#pragma once
#include <chrono>
#include "County.h"

template<typename T>
struct Sorting
{
    //Adapted from GeeksForGeeks - https://www.geeksforgeeks.org/cpp-program-for-quicksort/
    void quickSort(vector<T>& arr, int start, int end)
    {

        // base case
        if (start >= end)
            return;

        // partitioning the array
        int p = partition(arr, start, end);

        // Sorting the left part
        quickSort(arr, start, p - 1);

        // Sorting the right part
        quickSort(arr, p + 1, end);
    }

    //Adapted from SlayStudy  -  https://slaystudy.com/c-merge-sort-vector/
    void mergeSort(vector<T>& arr, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }







private:

    void swap(T& x, T& y)
    {
        T temp = x;
        x = y;
        y = temp;

    }

    //Adapted from GeeksForGeeks - https://www.geeksforgeeks.org/cpp-program-for-quicksort/
    int partition(vector<T>& arr, int start, int end)
    {

        T pivot = (arr[start]);

        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }

        // Giving pivot element its correct position
        int pivotIndex = start + count;
        swap(arr[pivotIndex], arr[start]);

        // Sorting left and right parts of the pivot element
        int i = start, j = end;

        while (i < pivotIndex && j > pivotIndex) {

            while (arr[i] <= pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }

        return pivotIndex;
    }

    //Adapted from SlayStudy -     https://slaystudy.com/c-merge-sort-vector/
    void merge(vector<T>& arr, int start, int mid, int end) {

        // temp is used to temporary store the vector obtained by merging
        // elements from [s to m] and [m+1 to e] in v
        vector<T> temp;

        int i, j;
        i = start;
        j = mid + 1;

        while (i <= mid && j <= end) {

            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }

        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = start; k <= end; k++)
            arr[k] = temp[k - start];

    }

};