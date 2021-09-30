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
    node<T>* last;
    LinkedList<T>() {
        first = NULL;
        last = NULL;
    }

    void add(T data) {
        if (!first) {
            // The list is empty
            first = new node<T>;
            first->data = data;
            first->next = NULL;
            last = first;
        }
        else {
            // The list isn't empty
            if (last == first) {
                // The list has one element
                last = new node<T>;
                last->data = data;
                last->next = NULL;
                first->next = last;
            }
            else {
                // The list has more than one element
                node<T>* insdata = new node<T>;
                insdata->data = data;
                insdata->next = NULL;
                last->next = insdata;
                last = insdata;
            }
        }
    }
    void add(int index, T value)
    {
        auto curr = get_node(index);
        auto next = curr->next;
        auto inserted = new node<T>;
        inserted->data = value;
        inserted->next = next;
        curr->next = inserted;
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