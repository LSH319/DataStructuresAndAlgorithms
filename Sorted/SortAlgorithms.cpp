#include "SortAlgorithms.h"

void SortAlgorithms::bubble_sort(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size()-1; i++)
    {
        for(int j = 0; j < arr.size()-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void SortAlgorithms::insert_sort(std::vector<int>& arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j;
        
        for(j = i - 1; j >= 0; j--)
        {
            if(arr[j] > key) arr[j+1] = arr[j];
            else break;
        }
        
        arr[j+1] = key;
    }
}

void SortAlgorithms::selection_sort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size()-1; i++) {
        int min_index = i;
        
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if(min_index != i) std::swap(arr[i], arr[min_index]);
    }
}

void SortAlgorithms::merge_sort(std::vector<int>& arr)
{
    merge_sort_partition(arr, 0 , arr.size()-1);
}

void SortAlgorithms::quick_sort(std::vector<int>& arr)
{
    quick_sort_sort(arr, 0, arr.size()-1);
}

void SortAlgorithms::merge_sort_merge(std::vector<int>& arr, int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;

    std::vector<int> left_vector(left_size);
    std::vector<int> right_vector(right_size);

    for (int i = 0; i < left_size; i++)
        left_vector[i] = arr[left + i];
    for (int j = 0; j < right_size; j++)
        right_vector[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < left_size && j < right_size) {
        if (left_vector[i] <= right_vector[j]) {
            arr[k] = left_vector[i];
            i++;
        } else {
            arr[k] = right_vector[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_vector[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_vector[j];
        j++;
        k++;
    }
}

void SortAlgorithms::merge_sort_partition(std::vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = (right + left) / 2;

        merge_sort_partition(arr, left, mid);
        merge_sort_partition(arr, mid + 1, right);

        merge_sort_merge(arr, left, mid, right);
    }
}

void SortAlgorithms::quick_sort_sort(std::vector<int>& arr, int low, int high)
{
    if (low < high) {
        int key = quick_sort_partition(arr, low, high);

        quick_sort_sort(arr, low, key - 1);
        quick_sort_sort(arr, key + 1, high);
    }
}

int SortAlgorithms::quick_sort_partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}