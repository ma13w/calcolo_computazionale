# Sorting Algorithm Analysis

This repository contains the source code and analysis for various sorting algorithms implemented in C language. It was created as part of an assignment for ITSOS MARIE CURIE.

## Overview

In this project, the goal was to determine the most efficient sorting algorithm. However, instead of relying solely on time-based measurements, we opted to calculate the computational complexity for each algorithm and compare them.

In pursuit of this goal, we implemented the following sorting algorithms:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort

Each algorithm's computational complexity was analyzed and compared to ascertain its efficiency in sorting data.
Each algorithm is implemented in C language and tested with different input sizes to analyze its performance.

## Files

- `bubble.h`: Implementation of Bubble Sort algorithm.
- `selectionSort.h`: Implementation of Selection Sort algorithm.
- `insertionSort.h`: Implementation of Insertion Sort algorithm.
- `merge.h`: Implementation of Merge Sort algorithm.
- `quicksort.h`: Implementation of Quick Sort algorithm.
- `generalLibrary.h`: Utility functions for generating random arrays, variable initialization, and data output.
- `princ.cpp`: Main program to test, manage and analyze the sorting algorithms.

## Usage

To compile and run the program, follow these steps:

1. Compile the `princ.cpp` file:

```bash
g++ -o sort princ.cpp
```
2. Run the compiled executable:
```bash
./sort
```

## The program will create two files:

- `arrayToSort.txt`: Contains the numbers sorted by all the algorithms.
 - `calcolo_computazionale_output.txt`: Stores the output table with all the test results.

## Additional Notes
- Each sorting algorithm is implemented in its respective library (`bubble.h`, `selectionSort.h`, etc.), with its corresponding functions and logic.
- The `princ.cpp` file contains parameters to personalize the program and function calls to sort arrays.
