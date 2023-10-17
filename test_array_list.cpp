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

int main()
{
    test_empty_array_has_length_zero();
    test_array_with_two_elements_appended_has_length_two();
    test_print();
    test_indexing_operator();
    test_vector_constructor();
}