#include <SDL2/SDL.h>
#include "Sorter.h"

int main(int argc, char** argv){

    if(SDL_Init(SDL_INIT_VIDEO < 0)){
        std::cout << "SDL could not be initialized" << SDL_GetError();
    }
    else{
        std::cout << "SDL video is read to go \n";
    }

    // Sorter sort(50);
    // sort.print(std::cout);
    // sort.randomize();
    // sort.print(std::cout);
    // sort.built_in_sort();
    // sort.print(std::cout);
    
    // sort.reset();
    // sort.bubble_sort();
    // sort.print(std::cout);
    
    // sort.reset();
    // sort.insertion_sort();
    // sort.print(std::cout);
    
    // sort.reset();
    // sort.merge_sort(0, sort.return_vec().size()-1);
    // sort.print(std::cout);

    // sort.reset();
    // sort.selection_sort();
    // sort.print(std::cout);

    // sort.reset();
    // sort.quick_sort(0, 49);
    // sort.print(std::cout);

    return 0;
}