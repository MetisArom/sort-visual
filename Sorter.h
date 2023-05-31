#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

//template <typename T>
class Sorter {
    //OVERVIEW: sorter using an array with various sorting algorithm members
public:

    Sorter(int size){
        capacity = size;
        vec = std::vector<int>(capacity);
    }

    void bubble_sort(){
        std::cout << "Hello\n";
        assert(true);
    }

    void heap_sort(){
        std::cout << "Hello\n";
        assert(true);
    }

    void insertion_sort(){
        std::cout << "Hello\n";
        assert(true);
    }

    void merge_sort(){
        std::cout << "Hello\n";
        assert(true);
    }

    void quick_sort(){
        std::cout << "Hello\n";
        assert(true);
    }

    void selection_sort(){
        std::cout << "Hello\n";
        assert(true);
    }

    void print(){
        for(int i : vec){
            std::cout << i << " ";
        }
    }

    void randomize(){
        srand (time(NULL));
        for(int i = 0; i < capacity; i++){
            this->vec[i] = (rand() % 100) + 1;
        }
    }

private:
    std::vector<int> vec;
    int capacity = 0;
};

#endif