#pragma once
#include <iostream>
using namespace std;

template<class T>
struct node {
    node<T>* next;
    T data;
};



template<class T>
class LinkedList
{
public:
    node<T>* first;
    LinkedList<T>() {
        first = NULL;

    }

    void push(T data) {

        // The list is empty
        if (!first)
        {
            node<T>* inserted = new node<T>;
            inserted->data = data;
            inserted->next = NULL;
            this->first = inserted;
        }
        else
        {
            node<T>* inserted = new node<T>;
            inserted->data = data;
            inserted->next = this->first;
            this->first = inserted;

        }
        std::cout << "Push : " << data << std::endl;
        display();

    }
    void insert_mid(T data)
    {
        node<T>* node_to_insert = new node<T>;
        node_to_insert->data = data;
        if (!first)
        {
            node_to_insert->next = NULL;
            this->first = node_to_insert;
        }
        else
        {
            auto slow = first;
            auto fast = first->next;
            while (fast && fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;

            }
            auto next = slow->next;
            node_to_insert->next = next;
            slow->next = node_to_insert;


        }
        std::cout << "Insert Mid : " << data << std::endl;
        display();
    }
    void add(int index, T value)
    {
        auto curr = get_node(index);
        auto next = curr->next;
        auto inserted = new node<T>;
        inserted->data = value;
        inserted->next = next;
        curr->next = inserted;
        std::cout << "Add : " << value << " at index : " << value << std::endl;
        display();
    }
    node<T>* get_node(int index)
    {
        if (index == 0)
        {
            // Get the first element
            return this->first;
        }
        else
        {
            // Get the index'th element
            node<T>* curr = this->first;
            for (int i = 0; i < index; ++i)
            {
                if (curr->next == nullptr)
                    return curr;
                curr = curr->next;

            }
            return curr;
        }
    }
    T get(int index)
    {
        return get_node(index)->data;
    }

    T operator[](int index) {
        return get(index);
    }
    void update(int index, T value)
    {
        auto curr = get_node(index);
        curr->data = value;
        std::cout << "Update index : " << index << " To value : " << value << std::endl;
        display();
    }
    void del(int index)
    {
        if (index == 0)
        {
            auto curr = this->first;
            this->first = this->first->next;
            delete curr;

        }
        else
        {
            auto prev = get_node(index - 1);
            auto curr = prev->next;
            prev->next = curr->next;
            delete curr;

        }
        std::cout << "Delete index : " << index << std::endl;
        display();

    }
    void display()
    {
        auto curr = this->first;
        std::cout << "Current List : ";
        while (curr != nullptr)
        {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};