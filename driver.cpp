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
    
    sort.reset();
    std::vector<int> merge_vec = sort.return_vec();
    sort.merge_sort(merge_vec, 0, 49);
    sort.print(std::cout);

    sort.reset();
    sort.selection_sort();
    sort.print(std::cout);

    // sort.quick_sort();
    // sort.selection_sort();
    // sort.heap_sort();

    return 0;
}