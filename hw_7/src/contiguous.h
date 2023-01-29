#pragma once

template<class T>
class ContiguousContainer {
public:
    ContiguousContainer() {
        p_capacity = 0;
        p_size = 0;
        p_data = nullptr;
    };

    ~ContiguousContainer() {
        delete[] p_data;
    };

    T &operator[](int index) const {
        int lastElemIdx = p_size - 1;

        if (index <= lastElemIdx) {
            return p_data[index];
        }

        throw std::runtime_error("index out of bounds");
    };

    auto size() const {
        return p_size;
    }

    void push_back(const T &value) {
        check_capacity();
        p_data[p_size++] = value;
    };

    void erase(int idx) {
        int lastElemIdx = p_size - 1;

        if (idx == lastElemIdx) {
            resize_data(p_size - 1);
            return;
        }

        for (int i = idx; i < lastElemIdx; i++) {
            p_data[i] = p_data[i + 1];
        }

        resize_data(p_size - 1);
    }

    void insert(int pos, const T &value) {
        check_capacity();

        for (int i = 0; i <= p_size - pos; i++) {
            p_data[p_size - i + 1] = p_data[p_size - i];
        }

        p_data[pos] = value;
        p_size++;
    }

    void show() {
        std::cout << ">> ";

        for (int i = 0; i < p_size; i++) {
            std::cout << p_data[i] << " ";
        }

        std::cout << std::endl;
    }

private:
    int p_size;
    int p_capacity;
    T *p_data;

    void add_capacity(int size) {
        T *tmp = new T[size];
        std::copy(p_data, p_data + p_size, tmp);
        p_capacity = size;
        delete[] p_data;
        p_data = tmp;
    }

    void check_capacity() {
        if (p_size >= p_capacity) {
            if (p_capacity == 0)
                add_capacity(p_capacity + 1);
            else
                add_capacity(p_capacity * 2);
        }
    }

    void resize_data(int size) {
        p_size = size;
    }
};
