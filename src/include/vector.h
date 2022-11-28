#ifndef _VECTOR_H_
#define _VECTOR_H_

template <typename T>
class m_vector
{
public: // ctor
    m_vector();
    m_vector(unsigned int);
    m_vector(const m_vector &);
    m_vector(m_vector &&);
    ~m_vector();

public:
    m_vector &operator=(const m_vector &);
    m_vector &operator=(m_vector &&);
    bool operator==(const m_vector &);
    T &operator[](const unsigned int);
    const T &operator[](const unsigned int) const;

public:
    void push_back(const T &);
    void pop_back();
    unsigned int size();
    unsigned int capacity();
    bool empty();
    void clear();

private:
    unsigned int m_size;
    unsigned int m_capacity;
    T *m_arr_v;
};

template <typename T>
m_vector<T>::m_vector() : m_size{0}, m_capacity{0}, m_arr_v{nullptr} {}

template <typename T>
m_vector<T>::m_vector(unsigned int size) : m_size{0}, m_capacity{size}
{
    m_arr_v = new T[m_capacity];
}
template <typename T>
m_vector<T>::m_vector(const m_vector &other) : m_size{other.m_size}, m_capacity{other.m_capacity}
{
    m_arr_v = new T[m_capacity];
    for (unsigned int i = 0; i < m_size; ++i)
        m_arr_v[i] = other.m_arr_v[i];
}
template <typename T>
m_vector<T>::m_vector(m_vector &&other) : m_size{other.m_size}, m_capacity{other.m_capacity}
{
    m_arr_v = other.m_arr_v;
    other.m_arr_v = nullptr;
}

template <typename T>
m_vector<T>::~m_vector()
{
    delete[] m_arr_v;
    m_arr_v = nullptr;
}

template <typename T>
m_vector<T> &m_vector<T>::operator=(const m_vector &other)
{
    if (this != &other)
    {
        delete[] m_arr_v;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_arr_v = new T[m_capacity];
        for (unsigned int i = 0; i < m_size; ++i)
            m_arr_v[i] = other.m_arr_v[i];
    }
    return *this;
}
template <typename T>
m_vector<T> &m_vector<T>::operator=(m_vector &&other)
{
    if (this != &other)
    {
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_arr_v = other.m_arr_v;
        other.m_arr_v = nullptr;
    }
    return *this;
}

template <typename T>
bool m_vector<T>::operator==(const m_vector &other)
{
    if (this == &other)
        return true;
    if (m_size != other.m_size)
        return false;
    for (unsigned int i = 0; i < m_size; ++i)
        if (m_arr_v[i] != other.m_arr_v[i])
            return false;
    return true;
}

template <typename T>
T &m_vector<T>::operator[](const unsigned int index)
{
    return m_arr_v[index];
}
template <typename T>
const T &m_vector<T>::operator[](const unsigned int index) const
{
    return m_arr_v[index];
}

template <typename T>
void m_vector<T>::push_back(const T &item)
{
    if (m_size == m_capacity)
    {
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
        T *temp = new T[m_capacity];
        for (unsigned int i = 0; i < m_size; ++i)
            temp[i] = m_arr_v[i];
        delete[] m_arr_v;
        m_arr_v = temp;
    }
    m_arr_v[m_size] = item;
    ++m_size;
}
template <typename T>
void m_vector<T>::pop_back()
{
    if (m_size != 0)
        --m_size;
}

template <typename T>
unsigned int m_vector<T>::size()
{
    return m_size;
}

template <typename T>
unsigned int m_vector<T>::capacity()
{
    return m_capacity;
}

template <typename T>
bool m_vector<T>::empty()
{
    return m_size == 0 ? true : false;
}

template <typename T>
void m_vector<T>::clear()
{
    m_size = 0;
}

#endif //_VECTOR_H_