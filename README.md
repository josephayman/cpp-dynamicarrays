# H23_project2_josefam
Project 2 for josefam (josefam@mail.uio.no)

## Get started
Start by cloning the repository:
```bash
git clone https://github.uio.no/IN1910/H23_project1_carlk_josefam
cd H23_project1_carlk_josefam
```

## How to Compile and run
Compile and run the program with the following commands:
```bash
clang++ -std=c++14 test_array_list.cpp -o test_array_list
```
Adding the **-std=c++14** flag is **necessary** because I newer features and syntax from C++14.

And then execute the program with ./test_array_list

## List of tasks completed

All of the tasks in the project description has been completed. Compiled, run and tested on Mac OS with clang++ 14.0.0.
- [x] Exercise 1
- [x] Exercise 2
- [x] Exercise 3
- [x] Exercise 4


## Exercise 3 a)

| Operation                     | ArrayList        | LinkedList        |
|-------------------------------|------------------|-------------------|
| Get element \( i \) by index  | \( O(1) \)       | \( O(n) \)        |
| Insert at front               | \( O(n) \)       | \( O(1) \)        |
| Insert at back (append)       | \( O(1) \) avg*  | \( O(1) \)        |
| Insert into middle            | \( O(n) \)       | \( O(n) \)        |
| Remove element from front     | \( O(n) \)       | \( O(1) \)        |
| Remove element from back      | \( O(1) \) avg*  | \( O(1) \)        |
| Remove element from middle    | \( O(n) \)       | \( O(n) \)        |
| Print                         | \( O(n) \)       | \( O(n) \)        |

\* And \( O(n) \) if a resize/shrink is required.

The reasoning here is the following:

* Get element by index: ArrayList has \( O(1) \) because it is a direct access data structure, while LinkedList has \( O(n) \) because it has to traverse the list from the beginning to the index.
* Insert at front: ArrayList has \( O(n) \) because it has to shift all elements one step to the right, while LinkedList has \( O(1) \) because it only has to change the pointers of the first element.
* Insert at back: ArrayList has \( O(1) \) because it has a pointer to the last element, while LinkedList has \( O(1) \) because it only has to change the pointers of the last element.
* Insert into middle: ArrayList has \( O(n) \) because it has to shift all elements one step to the right, while LinkedList has \( O(n) \) because it has to traverse the list from the beginning to the index.
* Remove element from front: ArrayList has \( O(n) \) because it has to shift all elements one step to the left, while LinkedList has \( O(1) \) because it only has to change the pointers of the first element.
* Remove element from back: ArrayList has \( O(1) \) because it has a pointer to the last element, while LinkedList has \( O(1) \) because it only has to change the pointers of the last element (The tail).
* Remove element from middle: ArrayList has \( O(n) \) because it has to shift all elements one step to the left, while LinkedList has \( O(n) \) because it has to traverse the list from the beginning to the index.
* Print: Both ArrayList and LinkedList has \( O(n) \) because they have to traverse the list from the beginning to the end and print each element.
  