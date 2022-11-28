#include "include/vector.h"
#include <iostream>

int main()
{
    m_vector<int> a(40);
    m_vector<int> c;
    for (int i = 0; i < 50; ++i)
        a.push_back(i);

    m_vector<int> b = a;

    for (int i = 0; i < 10; ++i)
        a.pop_back();

    c = a;
    c.clear();
    std::cout << (a == c) << std::endl;
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << c.empty() << std::endl;
}
