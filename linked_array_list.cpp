#include <iostream>
#include <stdexcept>
#include <memory>

#include "array_list.cpp"

struct ArrayListNode
{
    // Unique pointer to an ArrayList
    std::unique_ptr<ArrayList> val;

    ArrayListNode *prev = nullptr;

    ArrayListNode *next = nullptr;

    // Constructor
    ArrayListNode(std::vector<int> values, ArrayListNode *prevNode, ArrayListNode *nextNode)
        : val(std::make_unique<ArrayList>(values)), prev(prevNode), next(nextNode)
    {
    }
};

class LinkedArrayList
{
private:
    ArrayListNode *head = nullptr;
    ArrayListNode *tail = nullptr;

public:
    // Default constructor
    LinkedArrayList() {}

    /**
     * @brief Append a new ArrayListNode to the end
     *
     * @param values of the new ArrayListNode
     */
    void append(std::vector<int> values)
    {
        ArrayListNode *newNode = new ArrayListNode(values, nullptr, nullptr);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /**
     * @brief Print the list
     */
    void print()
    {
        std::cout << "[\n";
        ArrayListNode *current = head;
        while (current != nullptr)
        {
            current->val->print();
            current = current->next;
        }
        std::cout << "]\n";
    }

    // Overload the indexing operator
    std::unique_ptr<ArrayList> &operator[](int index)
    {
        ArrayListNode *current = head;
        int count = 0;

        while (current != nullptr)
        {
            if (count == index)
                return current->val;

            current = current->next;
            count++;
        }

        throw std::out_of_range("Index out of range");
    }

    ~LinkedArrayList()
    {
        while (head != nullptr)
        {
            ArrayListNode *next = head->next;
            delete head;
            head = next;
        }
    }
};

int main()
{
    ArrayListNode node({1, 2, 3}, nullptr, nullptr);
    node.val->print();

    LinkedArrayList lal{};
    lal.append({1, 2});    
    lal.append({4, 5, 6}); 
    lal.print();           
    lal[0]->append(42);    
    lal.print();           

    return 0;
}

/**
Prints out
[
ArrayList([1, 2])
ArrayList([4, 5, 6])
]
[
ArrayList([1, 2, 42])
ArrayList([4, 5, 6])
]
*/