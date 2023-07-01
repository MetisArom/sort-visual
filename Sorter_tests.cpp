#include "Sorter.h"
#include "unit_test_framework.h"
#include <sstream>

TEST(test_bubble_sort){
    Sorter sort(50);
    sort.randomize();
    sort.built_in_sort();
    std::ostringstream oss_built_in_sort;
    sort.print(oss_built_in_sort);
    sort.reset();
    sort.bubble_sort();
    std::ostringstream oss_bubble_sort;
    sort.print(oss_bubble_sort);

    ASSERT_TRUE(oss_built_in_sort.str() == oss_bubble_sort.str());
}

TEST(test_heap_sort){
    Sorter sort(50);
    sort.randomize();
    sort.built_in_sort();
    std::ostringstream oss_built_in_sort;
    sort.print(oss_built_in_sort);
    sort.reset();
    sort.heap_sort();
    std::ostringstream oss_heap_sort;
    sort.print(oss_heap_sort);

    ASSERT_TRUE(oss_built_in_sort.str() == oss_heap_sort.str());
}

TEST(test_insertion_sort){
    Sorter sort(50);
    sort.randomize();
    sort.built_in_sort();
    std::ostringstream oss_built_in_sort;
    sort.print(oss_built_in_sort);
    sort.reset();
    sort.insertion_sort();
    std::ostringstream oss_insertion_sort;
    sort.print(oss_insertion_sort);

    ASSERT_TRUE(oss_built_in_sort.str() == oss_insertion_sort.str());
}

TEST(test_merge_sort){
    Sorter sort(50);
    sort.randomize();
    sort.built_in_sort();
    std::ostringstream oss_built_in_sort;
    sort.print(oss_built_in_sort);
    sort.reset();
    sort.merge_sort(0, sort.return_vec().size()-1);
    std::ostringstream oss_merge_sort;
    sort.print(oss_merge_sort);

    ASSERT_TRUE(oss_built_in_sort.str() == oss_merge_sort.str());
}

TEST(test_quick_sort){
    Sorter sort(50);
    sort.randomize();
    sort.built_in_sort();
    std::ostringstream oss_built_in_sort;
    sort.print(oss_built_in_sort);
    sort.reset();
    sort.quick_sort(0, 50-1);
    std::ostringstream oss_quick_sort;
    sort.print(oss_quick_sort);

    ASSERT_TRUE(oss_built_in_sort.str() == oss_quick_sort.str());
}

TEST(test_selection_sort){
    Sorter sort(50);
    sort.randomize();
    sort.built_in_sort();
    std::ostringstream oss_built_in_sort;
    sort.print(oss_built_in_sort);
    sort.reset();
    sort.selection_sort();
    std::ostringstream oss_selection_sort;
    sort.print(oss_selection_sort);

    ASSERT_TRUE(oss_built_in_sort.str() == oss_selection_sort.str());
}

TEST_MAIN()