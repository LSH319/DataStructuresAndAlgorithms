#pragma once
#include <vector>

class SortAlgorithms
{
public:
    static void bubble_sort(std::vector<int>& arr);
    static void insert_sort(std::vector<int>& arr);
    static void selection_sort(std::vector<int>& arr);
    static void merge_sort(std::vector<int>& arr);
    static void quick_sort(std::vector<int>& arr);
private:
    static void merge_sort_merge(std::vector<int>& arr, int left, int mid, int right);
    static void merge_sort_partition(std::vector<int>& arr, int left, int right);
    static void quick_sort_sort(std::vector<int>& arr, int low, int high);
    static int quick_sort_partition(std::vector<int>& arr, int low, int high);
};
