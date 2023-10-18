#include <iostream>
#include <stdexcept>

class ArrayList
{
private:
    // Array containing the acutaul data in the list
    int *_data;
    // Capacity of the array
    int _capacity = 1;
    // Size of the array
    int _size = 0;
    // Growth factor for resizing
    int _growth_factor = 2;

    /**
     * @brief Resizes the internal array using the growth factor.
     */
    void resize()
    {
        int new_capacity = _capacity * _growth_factor;
        int *new_data = new int[new_capacity];
        for (int i = 0; i < _size; i++)
        {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    // Default constructor
    ArrayList()
    {
        _data = new int[_capacity];
    }

    // Overloaded constructor that takes a vector of integers
    ArrayList(std::vector<int> values)
    {
        _size = values.size();
        _capacity = _size;
        _data = new int[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _data[i] = values[i];
        }
    }

    // Destructor
    ~ArrayList()
    {
        delete[] _data;
    }

    // Length of array
    int length()
    {
        return _size;
    }

    /**
     * @brief Get value at a given index.
     * Throws a range error in index if out of bounds
     *
     * @param index The index
     * @return int The value at that index
     */
    int get(int index)
    {
        if ((index < 0) || (index >= _size))
        {
            throw std::range_error("Index is out of bounds");
        }
        return _data[index];
    }

    /**
     * @brief Prints the array
     *
     */
    void print()
    {
        std::cout << "ArrayList([";
        for (int i = 0; i < _size - 1; i++)
        {
            std::cout << _data[i] << ", ";
        }
        std::cout << _data[_size - 1] << "])\n";
    }

    /**
     * @brief Get a reference to the value at a given index.
     * Throws a range error in index if out of bounds
     *
     * @param index The index
     * @return int The value at that index
     */
    int &operator[](int index)
    {
        if ((index < 0) || (index >= _size))
        {
            throw std::range_error("Index is out of bounds");
        }
        return _data[index];
    }

    /**
     * @brief Add a value to the end of the array
     *
     * @param value The value to add
     */
    void append(int value)
    {
        if (_size >= _capacity)
        {
            resize();
        }
        _data[_size] = value;
        _size++;
    }

    /**
     * @brief Insert a value at a given index
     *
     * @param val The value to insert
     * @param index The index to insert at
     */
    void insert(int val, int index)
    {
        if (index < 0 || index > _size)
        {
            throw std::range_error("Index is out of bounds");
        }
        if (_size >= _capacity)
        {
            resize();
        }
        for (int i = _size; i > index; i--)
        {
            _data[i] = _data[i - 1];
        }
        _data[index] = val;
        _size++;
    }

    /**
     * @brief Remove a value at a given index
     * 
     * @param index The index to remove at
    */
    void remove(int index)
    {
        if (index < 0 || index >= _size)
        {
            throw std::range_error("Index is out of bounds");
        }
        for (int i = index; i < _size - 1; i++)
        {
            _data[i] = _data[i + 1];
        }
        _size--;
    }
};