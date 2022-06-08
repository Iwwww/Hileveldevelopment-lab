#pragma once
#include <iostream>
#include <cstddef>
#include <ostream>

namespace YMM {
    template<class T> class MyVector {
        public:
            class MyIterator {
                friend class MyVector;

                public:
                    MyIterator(const MyIterator &it) : m_item(it.m_item) {}

                    MyIterator(T *ptr) : m_item(ptr) {}

                    bool operator==(const MyVector<T>::MyIterator &it) const {
                        return m_item == it.m_item;
                    }

                    bool operator!=(const MyVector<T>::MyIterator &it) const {
                        return m_item != it.m_item;
                    }

                    MyIterator &operator++() {
                        ++m_item;
                        return *this;
                    }

                    T &operator*() const {
                        return *m_item;
                    }

                private:
                    T *m_item{};
            };

            typedef MyIterator iterator;
            typedef MyIterator const_iterator;

            MyVector() {
                initItem();
            }

            MyVector(const T item) : MyVector() {
                addItem(item);
            }

            MyVector(T *items, const int count) : MyVector() {
                m_size = count;
                addMemory();
                m_items = items;
            }

            MyVector(const MyVector<T> &vector) : MyVector() {
                size_t size = vector.size();
                m_items[0] = vector[0];
                for (int i = 1; i < size; i++) {
                    addItem(vector[i]);
                }
            }

            ~MyVector() {
                delete[] m_items;
            }

            T &operator[](size_t index) const {
                return m_items[index % m_size];
            }

            MyVector<T> &operator+=(const T *item) {
                addItem(item);
                return *this;
            }

            MyVector<T> &operator+=(const T &item) {
                addItem(&item);
                return *this;
            }

            friend std::istream& operator>>(std::istream& in, const MyVector<T> &items) {
                for (int i = 0; i < items.m_size; i++) {
                    in >> items[i];
                }
                return in;
            } 

            iterator begin() const {
                return iterator(&m_items[0]);
            }

            iterator end() const {
                return iterator(&m_items[m_size]);
            }

            size_t size() const {
                return m_size;
            }

            void erase() {
                delete[] m_items;
                initItem();
            }

            MyVector<T> duplicate() {
                return MyVector<T>(*this);
            }

            void addItem(const T *item) {
                if (m_size >= m_capacity) {
                    addMemory();
                }
                m_items[m_size++] = *item;
            }

            void addItem(const T &item) {
                if (m_size >= m_capacity) {
                    addMemory();
                }
                m_items[m_size++] = item;
            }

            void addMemory() {
                m_capacity *= 2;
                T *tmp = m_items;
                m_items = new T[m_capacity];
                for (int i = 0; i < m_size; i++) {
                    m_items[i] = tmp[i];
                }
                delete[] tmp;
            }

        private:
           size_t m_size = 0;
           size_t m_capacity = 1;
           T *m_items{};

           void initItem() {
               m_size = 0;
               m_capacity = 1;
               m_items = new T[m_capacity]{};
           }
    };
}

