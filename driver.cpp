#include "Sorter.h"

int main(){
    Sorter sort(50);
    sort.print();
    sort.randomize();
    sort.print();
    sort.built_in_sort();
    sort.print();
    sort.reset();
    sort.bubble_sort();
    sort.print();
    sort.reset();
    sort.insertion_sort();
    sort.print();

    // sort.insertion_sort();
    // sort.merge_sort();
    // sort.quick_sort();
    // sort.selection_sort();
    // sort.heap_sort();

    return 0;
}