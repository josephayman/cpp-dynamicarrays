#include <cassert>
#include <iostream>

#include "linked_list.cpp"

/**
 * @brief
 *
 */
void test_empty_list_has_zero_length()
{
    LinkedList ll{};
    std::cout << "Test that empty list has length zero";
    assert(ll.length() == 0);
    std::cout << " - Success!\n";
}

void test_push_front()
{
    LinkedList ll{};
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.print();
}

void test_append()
{
    LinkedList ll{};
    ll.append(1);
    ll.append(2);
    std::cout << "Test append: ";
    assert(ll.length() == 2);
    std::cout << " - Success!\n";
}

void test_index_operator()
{
    LinkedList ll{};
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    std::cout << "Test index operator: ";
    assert(ll[1] == 2);
    ll[1] = 42;
    assert(ll[1] == 42);
    std::cout << " - Success!\n";
}

void test_insert()
{
    LinkedList ll{};
    ll.push_front(1);
    ll.push_front(3);
    std::cout << "Test insert: ";
    ll.insert(2, 1);
    assert(ll[1] == 2);
    ll.insert(4, 0);
    assert(ll[0] == 4);
    ll.insert(5, 3);
    assert(ll[3] == 5);
    std::cout << " - Success!\n";
}

void test_vector_constructor()
{
    std::vector<int> values = {1, 2, 3, 4, 5};
    LinkedList list(values);
    std::cout << "Test vector constructor: ";
    assert(list.length() == 5);
    assert(list[2] == 3);
    std::cout << " - Success!\n";
}

int main()
{
    test_empty_list_has_zero_length();
    test_push_front();
    test_append();
    test_index_operator();
    test_insert();
    test_vector_constructor();
    return 0;
}