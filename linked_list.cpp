#include <iostream>
#include <stdexcept>

struct Node
{
    // The value at the node
    int value;
    // Pointer to the next node
    Node *next = nullptr;
    // Pointer to the previous node
    Node *prev = nullptr;
};

class LinkedList
{
private:
    // Pointer to the first element in the list
    Node *head = nullptr;
    // Pointer to the last element in the list
    Node *tail = nullptr;
    // Size of the list
    int _size = 0;

    /**
     * @brief Check wheter the given index if out of
     * bound and throw a range error if it is
     *
     * @param index The index to be checked
     */
    void check_index_out_of_bounds(int index)
    {
        if ((index < 0) || (index >= length()))
            throw std::range_error("Index out of bounds");
    }

    /**
     * @brief Find the node at a given index
     *
     * @param index The index of the node to be found
     */
    Node *find_node_at_index(int index)
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current;
    }

public:
    // Default constructor
    LinkedList()
    {
    }

    // Vector initializer constructor
    LinkedList(std::vector<int> values)
    {
        for (int v : values)
        {
            append(v);
        }
    }

    // Destructor
    ~LinkedList()
    {
        Node *current = head;
        Node *next = nullptr;
        // Move node until we are at the last element
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    /**
     * @brief Print values in the list
     *
     */
    void print()
    {
        std::cout << "[";
        if (head != nullptr)
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                std::cout << current->value;
                std::cout << ", ";
                current = current->next;
            }
            std::cout << current->value;
        }
        std::cout << "]\n";
    }

    /**
     * @brief Return the length of the list
     *
     * @return int The length
     */
    int length()
    {
        return _size;
    }

    /**
     * @brief Add element to the beginning of the list
     *
     * @param val The value to be added
     */
    void push_front(int val)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->value = val;
            tail = head;
        }
        else
        {
            Node *new_node = new Node;
            new_node->value = val;
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        _size++;
    }

    /**
     * @brief Add element to the end of the list
     *
     * @param val The value to be added
     */
    void append(int val)
    {
        if (head == nullptr)
        {
            head = new Node;
            head->value = val;
            tail = head;
        }
        else
        {
            Node *new_node = new Node;
            new_node->value = val;
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        _size++;
    }

    /**
     * @brief overload the [] operator to get the value at a given index
     */
    int &operator[](int index)
    {
        check_index_out_of_bounds(index);
        Node *current = find_node_at_index(index);
        return current->value;
    }

    /**
     * @brief Insert a value at a given index
     *
     * @param val The value to be inserted
     * @param index The index at which the value should be inserted
     */
    void insert(int val, int index)
    {
        check_index_out_of_bounds(index);
        if (index == 0)
        {
            push_front(val);
        }
        else if (index == _size)
        {
            append(val);
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            Node *new_node = new Node;
            new_node->value = val;
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev->next = new_node;
            current->prev = new_node;
            _size++;
        }
    }

    /**
     * @brief Remove an element at a given index
     *
     * @param index The index of the element to be removed
     */
    void remove(int index)
    {
        check_index_out_of_bounds(index);
        Node *current = find_node_at_index(index);

        if (current == head)
        {
            head = head->next;
            if (head)
            {
                head->prev = nullptr;
            }
        }
        else if (current == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        _size--;
    }
};
