#include "DynamicIntArray.h"
#include <iostream>

DynamicIntArray::DynamicIntArray() : m_data(nullptr), m_size(0) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(size) {
    m_data = new int[size];
}

DynamicIntArray::~DynamicIntArray() {
    delete[] m_data;
}

int& DynamicIntArray::operator[](std::size_t index) {
    return m_data[index];
}

void DynamicIntArray::clear() {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

bool DynamicIntArray::operator==(const DynamicIntArray& other) {
    if (m_size != other.m_size) {
        return false;
    }
    for (std::size_t i = 0; i < m_size; i++) {
        if (m_data[i] != other.m_data[i]) {
            return false;
        }
    }
    return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& other) {
    return !(*this == other);
}

std::size_t DynamicIntArray::getSize() const {
    return m_size;
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : m_size(other.m_size) {
    m_data = new int[m_size];
    for (std::size_t i = 0; i < m_size; i++) {
        m_data[i] = other.m_data[i];
    }
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    if (this != &other) {
        delete[] m_data;

        m_size = other.m_size;
        m_data = new int[m_size];
        for (std::size_t i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

void DynamicIntArray::setSize(std::size_t newSize) {
    int* newData = new int[newSize];

    std::size_t minSize = (newSize < m_size) ? newSize : m_size;
    for (std::size_t i = 0; i < minSize; i++) {
        newData[i] = m_data[i];
    }

    delete[] m_data;
    m_data = newData;
    m_size = newSize;
}

void DynamicIntArray::push_back(int element) {
    setSize(m_size + 1);
    m_data[m_size - 1] = element;
}
