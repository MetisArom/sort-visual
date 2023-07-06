#include "globals.h"

const int SCREEN_WIDTH= 1000;
const int SCREEN_HEIGHT= 500;
SDL_Rect resetBtn = {115, 420, 75, 50};
SDL_Rect randomizeBtn = {226, 420, 75, 50};
SDL_Rect bubblesortBtn = {338, 420, 75, 50};
SDL_Rect insertionsortBtn = {449, 420, 75, 50};
SDL_Rect selectionsortBtn = {561, 420, 75, 50};
SDL_Rect mergesortBtn = {672, 420, 75, 50};
SDL_Rect quicksortBtn = {784, 420, 75, 50};

SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;

const int rectWidth=4;
const int capacity = 100;
std::vector<int> vec(capacity);
std::vector<int> vec_reset(capacity);

// REQUIRES : Two separate references
// MODIFIES : a, b
// EFFECTS  : Swaps elements by reference using a temp variable 
void drawVector(int idx1=-1, int idx2=-1, int idx3=-1, bool delay = false){
    SDL_SetRenderDrawColor(renderer, 50, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    int i = 50;
    
    for(int j = 0; j < vec.size(); j++){
        SDL_Rect rect={i+50, 400, rectWidth, vec[j]*-1};
        if(j == idx1 || j == idx2){
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
        else if(j == idx3){
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
        else{
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect);
        }
        i+=rectWidth*2;
        if(delay){
            SDL_Delay(2);
            SDL_RenderPresent(renderer);
        }
    }
    if(!delay){
        SDL_RenderPresent(renderer);
    }
}

void drawBtns(){
    SDL_SetRenderDrawColor(renderer, 172, 169, 169, 255);
    SDL_RenderFillRect(renderer, &resetBtn);
    SDL_RenderFillRect(renderer, &randomizeBtn);
    SDL_RenderFillRect(renderer, &bubblesortBtn);
    SDL_RenderFillRect(renderer, &insertionsortBtn);
    SDL_RenderFillRect(renderer, &selectionsortBtn);
    SDL_RenderFillRect(renderer, &mergesortBtn);
    SDL_RenderFillRect(renderer, &quicksortBtn);

    SDL_RenderPresent(renderer);
}

// REQUIRES : Two separate references
// MODIFIES : a, b
// EFFECTS  : Swaps elements by reference using a temp variable 
void swap(int & a, int & b){
    if(&a != &b){
        int temp = a;
        a = b;
        b = temp;
    }
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : vec
// EFFECTS  : Sorts vector using bubble sort technique w/ swap helper function
void bubble_sort(){
    std::cout << "Bubble Sort O(n^2)\n";
    for(int i = 0; i < vec.size()-1; i++){
        bool swapped = false;
        for(int j = 0; j < vec.size()-1; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
                swapped = true;
                drawVector(i, j);
                SDL_Delay(1);
            }
            else{
                drawVector(i, j);
                SDL_Delay(1);
            }
        }
        if(!swapped) break;
    }
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : vec
// EFFECTS  : Sorts vector using insertion sort technique w/ swap helper function
void insertion_sort(){
    std::cout << "Insertion Sort O(n^2)\n";
    int j, recent;
    for(int i = 1; i < vec.size(); i++){
        j = i-1;
        recent = vec[j+1];
        while(j>-1 && recent < vec[j]){
            swap(vec[j], vec[j+1]);
            drawVector(i, j);
            SDL_Delay(5);
            j--;
        }
    }
}

// REQUIRES : Valid call from merge_sort with left bound, middle, amd right bound indexes
// MODIFIES : this->vec (nonstatic member)
// EFFECTS  : Uses subvectors of vec to sort and combine into vec using two pointer method
void merge(int l, int m, int r){
    int i,j,k; //indexes
    
    int size_left = m-l+1;
    int size_right = r - m;
    
    std::vector<int> left, right;

    for(i=0; i<size_left; i++){
        left.push_back(vec[l+i]);
    }
    for(j=0; j<size_right; j++){
        right.push_back(vec[m+1+j]);
    }

    i=0, j=0, k=l;
    
    while(i < size_left && j < size_right){
        if(left[i] <= right[j]){
            vec[k] = left[i];
            drawVector(i+l, j+m+1, k);
            SDL_Delay(20);
            i++;
        }
        else{
            vec[k] = right[j];
            drawVector(i+l, j+m+1, k);
            SDL_Delay(20);
            j++;
        }
        k++;
    }

    while(i < size_left){
        vec[k] = left[i];
        drawVector(k, i+l);
        SDL_Delay(20);
        i++; k++;
    }
    while(j < size_right){
        vec[k] = right[j];
        drawVector(k, j+m+1);
        SDL_Delay(20);
        j++; k++;
    }
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : vec
// EFFECTS  : Sorts vector using merge sort technique w/ merge helper function
void merge_sort(int l, int r){
    if(r+1-l == capacity){std::cout << "Merge Sort O(nlog(n))\n";}

    if(l < r){
        int m = (l + (r-1))/2;

        merge_sort(l, m);
        merge_sort(m+1, r);

        merge(l, m, r);
    }
}

// REQUIRES : Valid call from quick_sort with low index and high index
// MODIFIES : this->vec (nonstatic member), partition_idx in func quick_sort()
// EFFECTS  : Sets pivot to value at highest index, swaps elements lower than
//            the pivot value with iterator i until iterator j has fully travered.
//            Then, pivot is sorted at index i+1, which is returned as the index of
//            partition in the recursive calls in the parent quick_sort function.
int partition(int low, int high){
    int pivot = vec[high];
    int i = low-1;
    for(int j = low; j < high; j++){
        if(vec[j] < pivot){
            i++;
            swap(vec[i], vec[j]);
            drawVector(i,j,high);
            SDL_Delay(20);
        }
    }
    swap(vec[i+1], vec[high]);
    drawVector(-1,i+1,high);
    SDL_Delay(20);
    return (i+1);
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : vec
// EFFECTS  : Sorts vector using quicksort technique ...
void quick_sort(int low, int high){
    if(high-low+1 == capacity){std::cout << "Quicksort O(nlog(n))\n";}
    if(low < high){
        int partition_idx = partition(low, high);

        quick_sort(low, partition_idx-1);
        quick_sort(partition_idx+1, high);
    }
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : vec
// EFFECTS  : Sorts vector using selection sort technique and swap helper function
void selection_sort(){
    std::cout << "Selection Sort O(n^2)\n";
    for(int i = 0; i < vec.size(); i++){
        int min_idx = i;
        for(int j = i; j < vec.size(); j++){
            if(vec[j] < vec[min_idx]){
                min_idx = j;
            }
            drawVector(i, j);
            SDL_Delay(1);
        }
        swap(vec[i],vec[min_idx]);
    }
}

// REQUIRES : Initialized Sorter
// MODIFIES : Output Stream
// EFFECTS  : Provides output of the Sorter's vector to os placed in function parameters
void print(std::ostream &os){
    for(int i : vec){
        os << i << " ";
    }
    os << "\n";
}

// REQUIRES : Initialized Sorter
// MODIFIES : vec, vec_reset
// EFFECTS  : Uses random seed based on time to provide psuedorandom values to the
//            Sorter's vector and changing the reset vector.
void randomize(){
    srand (time(NULL));
    for(int i = 0; i < capacity; i++){
        vec[i] = (rand() % 375) + 5;
    }
    vec_reset = vec;
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : vec
// EFFECTS  : Sorts vector using C++ built in implementation of quicksort(?).
void built_in_sort(){
    std::cout << "Testing Built in Sort (Quicksort)\n";
    std::sort(vec.begin(), vec.end());
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : vec
// EFFECTS  : Sets the Sorter's vector to the original vector generated by the last
//            use of this->randomize()
void reset(){
    vec = vec_reset;
}

// REQUIRES : Initialized Sorter and the member function randomize to fill the vector
// MODIFIES : None
// EFFECTS  : Returns the Sorter's vector
std::vector<int> return_vec(){
    return vec;
}

bool launch(){
    if(SDL_Init(SDL_INIT_EVERYTHING < 0)){
        std::cout << "SDL could not be initialized" << SDL_GetError() << "\n";
        return false;
    }
    else{
        std::cout << "SDL is read to go \n";
        window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
        if ( window == NULL ) {
            std::cout << "Window could not be created: " << SDL_GetError() << "\n";
            return false;
        }
        else{
            renderer = SDL_CreateRenderer(window, -1, 0);
            if ( renderer == NULL ) {
                std::cout << "Renderer could not be created: " << SDL_GetError() << "\n";
                return false;
            }
        }
    }
    return true;
}

void close(){
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
    exit(1);
}

int main(int argc, char** argv){
    
    if(!launch()){close();}
    randomize();
    drawVector(-1,-1,-1, true);
    SDL_Delay(1000);

    /* Steps to Visualize:
    maybe add sound pitched to the height of the values to add interactivity?
    */
    
    SDL_Event windowEvent;
    SDL_Point mousePosition;

    while(true){
        if(SDL_PollEvent (&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }
            mousePosition.x = windowEvent.motion.x; 
            mousePosition.y = windowEvent.motion.y;

            if (SDL_PointInRect(&mousePosition, &resetBtn) && SDL_GetMouseState(NULL, NULL) == 1) {
                reset();
                drawVector(-1,-1,-1,true);
                SDL_Delay(100);
            }

            if (SDL_PointInRect(&mousePosition, &randomizeBtn) && SDL_GetMouseState(NULL, NULL) == 1) {
                randomize();
                drawVector(-1,-1,-1,true);
                SDL_Delay(100);
            }

            if (SDL_PointInRect(&mousePosition, &bubblesortBtn) && SDL_GetMouseState(NULL, NULL) == 1) {
                bubble_sort();
                drawVector();
                SDL_Delay(100);
            }

            if (SDL_PointInRect(&mousePosition, &insertionsortBtn) && SDL_GetMouseState(NULL, NULL) == 1) {
                insertion_sort();
                drawVector();
                SDL_Delay(100);
            }

            if (SDL_PointInRect(&mousePosition, &selectionsortBtn) && SDL_GetMouseState(NULL, NULL) == 1) {
                selection_sort();
                drawVector();
                SDL_Delay(100);
            }

            if (SDL_PointInRect(&mousePosition, &mergesortBtn) && SDL_GetMouseState(NULL, NULL) == 1) {
                merge_sort(0, capacity-1);
                drawVector();
                SDL_Delay(100);
            }

            if (SDL_PointInRect(&mousePosition, &quicksortBtn) && SDL_GetMouseState(NULL, NULL) == 1) {
                quick_sort(0, capacity-1);
                drawVector();
                SDL_Delay(100);
            }

            drawBtns();
        }
    }
    close();
    return EXIT_SUCCESS;
}