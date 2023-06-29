#include "Sorter.h"

int main(){
    Sorter sort(50);
    sort.print(std::cout);
    sort.randomize();
    sort.print(std::cout);
    sort.built_in_sort();
    sort.print(std::cout);
    sort.reset();
    sort.bubble_sort();
    sort.print(std::cout);
    sort.reset();
    sort.insertion_sort();
    sort.print(std::cout);

    // sort.insertion_sort();
    // sort.merge_sort();
    // sort.quick_sort();
    // sort.selection_sort();
    // sort.heap_sort();

    return 0;
}