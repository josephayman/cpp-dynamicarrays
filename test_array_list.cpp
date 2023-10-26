#include <cassert>
#include <iostream>
#include <vector>

#include "array_list.cpp"

/**
 * @brief Test that an empty array list has length zero
 *
 */
void test_empty_array_has_length_zero()
{
    ArrayList a{};
    std::cout << "Test that empty array has length zero";
    assert(a.length() == 0);
    std::cout << " - Success!\n";
}

void test_array_with_two_elements_appended_has_length_two()
{
    ArrayList a{};
    a.append(1);
    a.append(2);
    std::cout << "Test that array with two elements appended has length two";
    assert(a.length() == 2);
    std::cout << " - Success!\n";
}

void test_print()
{
    ArrayList a{};
    a.append(1);
    a.append(2);
    a.append(3);
    std::cout << "Test print: ";
    a.print();
}

void test_indexing_operator()
{
    ArrayList a{};
    a.append(1);
    a.append(2);
    a.append(3);
    std::cout << "Test indexing operator: ";
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    a[1] = 7;
    assert(a[1] == 7);
    std::cout << " - Success!\n";
}

void test_vector_constructor()
{
    std::vector<int> primes_values = {2, 3, 5, 7, 11};
    ArrayList primes(primes_values);
    std::cout << "Test vector constructor: ";
    primes.print();
}

void test_insert()
{
    ArrayList a{{0, 1}};
    assert(a.length() == 2);
    a.insert(42, 0);
    std::cout << "Test insert: ";
    assert(a.length() == 3);
    assert(a[0] == 42);
    assert(a[1] == 0);
    assert(a[2] == 1);
    a.insert(43, 1);
    assert(a.length() == 4);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    a.insert(44, 4);
    assert(a.length() == 5);
    assert(a[0] == 42);
    assert(a[1] == 43);
    assert(a[2] == 0);
    assert(a[3] == 1);
    assert(a[4] == 44);
    a.print();
    std::cout << " - Success!\n";
}

void test_remove()
{
    ArrayList a{{0, 1, 2, 3, 4}};
    assert(a.length() == 5);
    a.remove(0);
    std::cout << "Test remove: ";
    assert(a.length() == 4);
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    assert(a[3] == 4);
    std::cout << " - Success!\n";
}

void test_pop_at_index()
{
    ArrayList a{{0, 1, 2, 3, 4}};
    assert(a.length() == 5);
    int value = a.pop(0);
    std::cout << "Test pop at index: ";
    assert(a.length() == 4);
    assert(value == 0);
    assert(a[0] == 1);
    a.print();
    std::cout << "Popped value: " << value << "\n - Success!\n";
}

void test_pop()
{
    ArrayList a{{0, 1, 2, 3, 4}};
    assert(a.length() == 5);
    int value = a.pop();
    std::cout << "Test pop at index: ";
    assert(a.length() == 4);
    assert(value == 4);
    assert(a[3] == 3);
    a.print();
    std::cout << "Popped value: " << value << "\n - Success!\n";
}

void test_shrink_to_fit()
{
    ArrayList a{{0, 1, 2, 3}};
    assert(a.capacity() == 4);
    a.append(4);
    a.append(5);
    assert(a.capacity() == 8);
    a.pop();
    a.pop();
    a.pop();
    std::cout << "Test shrink to fit: ";
    assert(a.capacity() == 4);
    std::cout << " - Success!\n";
}

void test_argmin()
{
    ArrayList a{{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5}};
    std::cout << "Test argmin: index " << a.argmin();
    std::cout << " value: " << a[a.argmin()];
    assert(a.argmin() == 1);
    std::cout << " - Success!\n";
}

void test_argmax()
{
    ArrayList a{{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5}};
    std::cout << "Test argmax: index: " << a.argmax();
    std::cout << " value: " << a[a.argmax()];
    assert(a.argmax() == 5);
    std::cout << " - Success!\n";
}

int main()
{
    test_empty_array_has_length_zero();
    test_array_with_two_elements_appended_has_length_two();
    test_print();
    test_indexing_operator();
    test_vector_constructor();
    test_insert();
    test_remove();
    test_pop_at_index();
    test_pop();
    test_shrink_to_fit();
    test_argmin();
    test_argmax();
}