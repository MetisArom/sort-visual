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
        std::cout << "Bubble Sort Average O(n^2)\n";
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
        std::cout << "Insertion Sort Average O(n^2)\n";
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

    void merge_sort(){
        std::cout << "Hello\n";
    }

    void quick_sort(){
        std::cout << "Hello\n";
    }

    void selection_sort(){
        std::cout << "Hello\n";
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

private:
    std::vector<int> vec;
    int capacity = 0;
    std::vector<int> vec_reset;

    void swap(int & a, int & b){
        int temp = a;
        a = b;
        b = temp;
    }
};

#endif
