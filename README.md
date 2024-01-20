# Sorting Algorithms Project

## Overview

This project, titled **0x1B. C - Sorting algorithms & Big O**, is to be completed by teams of two people. The project started on Jan 17, 2024, at 6:00 AM and must be completed by Jan 24, 2024, at 6:00 AM. The checker was released on Jan 19, 2024, at 12:00 AM.

## Background Context

This project aims to familiarize students with sorting algorithms and Big O notation. The tasks involve implementing different sorting algorithms and analyzing their time complexities. Each group is expected to pair program for at least the mandatory part.

## Resources

Students are encouraged to read or watch various materials on sorting algorithms, Big O notation, and related topics. Some recommended resources include:

- Sorting algorithm
- Big O notation
- Sorting algorithms animations
- 15 sorting algorithms in 6 minutes (Note: Be cautious, as the video contains visual effects that can trigger seizures/epilepsy)
- CS50 Algorithms explanation in detail by David Malan
- All about sorting algorithms

## Learning Objectives

At the end of this project, students are expected to:

### General

- Implement at least four different sorting algorithms.
- Understand the concept of Big O notation and evaluate the time complexity of an algorithm.
- Select the best sorting algorithm for a given input.
- Know what a stable sorting algorithm is.

## Copyright - Plagiarism

Students are reminded that they are expected to come up with solutions for the tasks independently. Copying and pasting someone else’s work, publishing any content of the project, and any form of plagiarism are strictly forbidden and will result in removal from the program.

## Requirements

### General

- Allowed editors: vi, vim, emacs.
- All files will be compiled on Ubuntu 20.04 LTS using gcc with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All files should end with a new line.
- A `README.md` file, at the root of the project folder, is mandatory.
- Code should follow the Betty style and will be checked using `betty-style.pl` and `betty-doc.pl`.
- No global variables are allowed.
- No more than 5 functions per file.
- Unless specified otherwise, the standard library is not allowed.
- The prototypes of all functions should be included in a header file called `sort.h`.
- Don’t forget to push your header file.
- All header files should be include guarded.
- A list/array does not need to be sorted if its size is less than 2.
- There should be one project repository per group. Cloning/forking a project repository with the same name before the second deadline may result in a 0% score.

## Data Structure and Functions

For this project, students are provided with the following `print_array` and `print_list` functions:

```c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```c
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```
These files (print_array.c and print_list.c) containing the print_array and print_list functions will be compiled with students' functions during the correction.

Please declare the prototype of the functions print_array and print_list in the sort.h header file.

The doubly linked list structure should be as follows:

```c
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
Big O Notation
The following notations are provided for use:

O(1)
O(n)
O(n!)
O(n^2) (n square)
O(log(n))
O(n * log(n))
O(n +
...
Short notation should be used, and constants should be omitted. For example, O(nk) or O(wn) should be written as O(n).

Tests
Students are advised to use the Random.org website to test sorting algorithms with big sets of random integers.