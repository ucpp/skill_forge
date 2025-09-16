#ifndef _LEETCODE_UTILS_H_
#define _LEETCODE_UTILS_H_

#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "{";

    auto it = v.begin();
    auto end = v.end();

    if (it != end)
    {
        os << *it;
        while (++it != end)
        {
            os << ", " << *it;
        }
    }

    os << "}";
    return os;
}

#endif // _LEETCODE_UTILS_H_