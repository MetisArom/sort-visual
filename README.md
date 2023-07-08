# Sort Visual - Gabriel Mora
### Project Overview
This program visualizes 5 different sorting algorithms which organize a vector of 
100 elements in ascending order (Bubble Sort, Insertion Sort, Selection Sort, 
Merge Sort, and Quicksort). 

#### To Run:
Either download driver.exe and run the program or clone the repository and follow
an online tutorial to set up SDL2 based on your operating system. The version on
my system uses Mingw32 and vscode, and has a src folder which contains the library
linker files and various .dll files.

#### driver.cpp:
Contains the source code for the program. Visual elements are created using SDL2,
a graphics library that allows for the creation of graphical programs and even
games. We use a renderer object which renders objects like rectangles, images,
and different colors to the window object.

driver.cpp also contains the implementations for all 5 sorting algorithms. These 
implementations were created by myself using general descriptions from GeeksforGeeks.org.
Embedded within these implementations are calls to the drawVector() function which allows
for the "animation" effect seen when running the program.

#### driver.exe:
Current executable for the program. Opens up to a screen with a random vector with
7 different buttons, which in order are reset, randomize, bubblesort, insertion sort,
selection sort, merge sort, and quicksort. The function of these buttons is self explanatory.
The user is encouraged to randomize the vector until they get a distribution they like, and
then test each sorting algorithm by pressing a sorting algo's button and then pressing reset
after the sort is complete to test multiple algorithms on the same randomized vector.

#### globals.h:
Includes all C++ and 3rd party libraries included.

#### Makfile:
Provides compilation instructions with linker options using g++.

#### Sorter_tests.cpp:
Tests the effectiveness of each sorting algorithm using output stream strings that
compare the output of the built in C++ sort function from the algorithm library
to the output of my sorting algorithm implementations. Was used to debug errors.

#### Sorter.h:
Failed attempt at using a class to simplify structure. Failed because SDL2 needed to interface 
directly with the functions in order to properly visualize the sorting algorithms.

#### .assets/:
Folder including all MS Paint button designs that show up in the project.

### Learning Outcomes:
* Introduction to SDL2 library for creating graphical programs using C++.
    * Utilized a graphics renderer to display rectangles, images, and colors to
      a window.
    * Made very very basic button sprites using MS paint.
    * Utilized event control to allow user to interactively choose sorts and randomize dataset.
* Learned about different simple sorting algorithms (bubble, selection, and insertion)
  and two Divide and Conquer sorting algorithms (merge sort and quicksort).
* Learned about pseudorandom number generators to create a shuffle button for interactivity.

### Project To Do List:
* Refactor buttons into a class to reduce use of globals and code copying.
* Implement sound to the program based on the value of the current vector element.
* Debug issue where clicking off screen during a sort or attempting to stop a sort
  causes program to freeze and crash. Additionally, add a way for user to quit out
  of a sort whenever they want to return to the main screen.
* General optimization to improve program.
* Add RMEs to the SDL2 graphical functions like close(), launch(), drawBtns(), and drawVector().
* Optimize/Change quicksort to use LR pointers and pick pivot more intelligently.