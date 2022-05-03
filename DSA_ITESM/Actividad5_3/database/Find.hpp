#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "../date_parser/element.hpp"
#include "Sort.hpp"
class Find
{
public:
    Find(std::vector<Element>, int num);
    // O(N) y O(1)
    int sequential();
    // O(logn) y O(1)
    int binary();

private:
    std::vector<Element> array_;
    int num_;

};