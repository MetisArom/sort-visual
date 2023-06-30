#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>

//template <typename T>
class Sorter {
    //OVERVIEW: sorter using an array with various sorting algorithm members
public:

    Sorter(int size){
        capacity = size;
        vec = std::vector<int>(capacity);
        vec_reset = std::vector<int>(capacity);
    }

    void bubble_sort(){
        std::cout << "Bubble Sort O(n^2)\n";
        for(int i = 0; i < vec.size()-1; i++){
            bool swapped = false;
            for(int j = 0; j < vec.size()-1; j++){
                if(vec[j] > vec[j+1]){
                    swap(vec[j], vec[j+1]);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }
    }

    void heap_sort(){
        std::cout << "Hello\n";
    }

    void insertion_sort(){
        std::cout << "Insertion Sort O(n^2)\n";
        int j, recent;
        for(int i = 1; i < vec.size(); i++){
            j = i-1;
            recent = vec[j+1];
            while(j>-1 && recent < vec[j]){
                swap(vec[j], vec[j+1]);
                j--;
            }
        }
    }

    void merge_sort(std::vector<int>& merge_vector, int l, int r){
        if(r+1-l == 50){
            std::cout << "Merge Sort O(nlog(n))\n";
        }
        if(l < r){
            int m = (l + (r-1))/2;
            //sort left = arr[l to m]
            merge_sort(merge_vector, l, m);
            //sort right = arr[m to r]
            merge_sort(merge_vector, m+1, r);

            //put all stuff together using helper
            merge(merge_vector, l, m, r);
        }
    }

    void quick_sort(){
        std::cout << "Hello\n";
    }

    void selection_sort(){ //min weighted
        std::cout << "Selection Sort O(n^2)\n";
        for(int i = 0; i < vec.size(); i++){
            int min_idx = i;
            for(int j = i; j < vec.size(); j++){
                if(vec[j] < vec[min_idx]){
                    min_idx = j;
                }
            }
            swap(vec[i],vec[min_idx]);
        }
    }

    void print(std::ostream &os){
        for(int i : vec){
            os << i << " ";
        }
        os << "\n";
    }

    void randomize(){
        srand (time(NULL));
        for(int i = 0; i < capacity; i++){
            this->vec[i] = (rand() % 100) + 1;
        }
        vec_reset = vec;
    }

    void built_in_sort(){
        std::cout << "Testing Built in Sort (Quicksort)\n";
        std::sort(vec.begin(), vec.end());
    }

    void reset(){
        vec = vec_reset;
    }

    std::vector<int> return_vec(){
        return vec;
    }

private:
    std::vector<int> vec;
    int capacity = 0;
    std::vector<int> vec_reset;

    void swap(int & a, int & b){
        int temp = a;
        a = b;
        b = temp;
    }

    void merge(std::vector<int>& merge_vector, int l, int m, int r){
        //indexes
        int i,j,k;
        //sizes
        int size_left = m-l+1;
        int size_right = r - m;
        //create left and right vectors
        std::vector<int> left, right;

        for(i=0; i<size_left; i++){
            left.push_back(merge_vector[l+i]);
        }
        for(j=0; j<size_right; j++){
            right.push_back(merge_vector[m+1+j]);
        }

        //then put together the sorted vectors together
        i=0,j=0;
        k=l;
        while(i < size_left && j < size_right){
            if(left[i] <= right[j]){
                merge_vector[k] = left[i];
                i++;
            }
            else{
                merge_vector[k] = right[j];
                j++;
            }
            k++;
        }

        //them continue until sizes are used up
        while(i < size_left){
            merge_vector[k] = left[i];
            i++; k++;
        }
        while(j < size_right){
            merge_vector[k] = right[j];
            j++; k++;
        }

        vec = merge_vector;
    }
};

#endif
