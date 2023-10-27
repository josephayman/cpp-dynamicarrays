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
    LinkedList list{};
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();
}

int main()
{
    test_empty_list_has_zero_length();
    test_push_front();
    return 0;
}