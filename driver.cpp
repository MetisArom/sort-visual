#include "Sorter.h"

int main(){
    Sorter sort(30);
    sort.print();
    sort.randomize();
    sort.print();

    sort.bubble_sort();
    sort.heap_sort();
    sort.insertion_sort();
    sort.merge_sort();
    sort.quick_sort();
    sort.selection_sort();

    return 0;
}