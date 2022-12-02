#pragma once

#include <stdexcept>

template<typename T>
class Node {
public:
    Node() : prev{nullptr}, next{nullptr} {};

    Node<T> *prev;
    Node<T> *next;
    T value;
};

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        c_start = nullptr;
        c_end = nullptr;
        c_size = 0;
    };

    void push_back(const T &value) {
        auto *node = new Node<T>;
        node->value = value;

        if (c_size > 0) {
            c_end->next = node;
            node->prev = c_end;
            c_end = node;
        } else {
            c_start = c_end = node;
        }

        c_size++;
    }

    void show() {
        if (c_start == nullptr) {
            throw std::runtime_error("ERROR: empty container");
        } else {
            Node<T> *tmp = c_start;
            std::cout << ">>";
            while (nullptr != tmp) {
                std::cout << " " << tmp->value;
                tmp = tmp->next;
            }

            std::cout << std::endl;
        }
    }

    auto size() const {
        return c_size;
    }

    void erase(int pos) {

        if (c_start == nullptr) {
            throw std::runtime_error("ERROR: empty container");
        }
        if (pos == 0) {
            c_start = c_start->next;

            if (c_start != nullptr) {
                c_start->prev = nullptr;
            } else {
                c_end = nullptr;
            }
        } else {
            Node<T> *tmp = c_start;

            int i = 0;
            while (tmp != nullptr && pos - 1 > i) {
                tmp = tmp->next;
                i++;
            }

            if (tmp == nullptr) {
                throw std::runtime_error("ERROR: deleted item not found");
            } else {
                tmp->prev->next = tmp->next;

                if (tmp->next != nullptr) {
                    tmp->next->prev = tmp->prev;
                } else {
                    c_end = tmp->prev;
                }
            }

            delete tmp;
        }

        c_size--;
    }

    void insert(int pos, const T &value) {
        auto *node = new Node<T>;
        node->value = value;
        node->next = nullptr;
        node->prev = nullptr;

        if (pos == 0) {
            node->next = c_start;
            c_start->prev = node;
            c_start = node;
            c_size++;
        } else {
            Node<T> *tmp = c_start;

            for (int i = 0; i < pos - 1; i++) {
                if (tmp != nullptr) {
                    tmp = tmp->next;
                }
            }

            if (tmp != nullptr) {
                node->next = tmp->next;
                node->prev = tmp;
                tmp->next = node;
                if (node->next != nullptr) {
                    node->next->prev = node;
                }

                c_size++;
            } else {
                throw std::runtime_error("ERROR: null node");
            }
        }
    }

    T& operator[](int pos) {
        if (c_start == nullptr)
        {
            throw std::runtime_error("ERROR: empty container");
        }

        Node<T> *tmp = c_start;
        int i = 0;
        while (tmp != nullptr && pos + 1 > i){
            if (i == pos){
                break;
            }
            tmp = tmp->next;
            i++;
        }

        if (tmp == nullptr){
            throw std::runtime_error("ERROR: index outside the bounds of the array");
        }
        else{
            return tmp->value;
        }
    }

private:
    Node<T> *c_start;
    Node<T> *c_end;
    int c_size;
};