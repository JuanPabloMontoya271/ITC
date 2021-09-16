#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <bits/stdc++.h>

class Find
{
    public:
        Find(std::shared_ptr<std::vector<float>>, float num);
        // O(N) y O(1)
        int sequential();
        // O(logn) y O(1)
        int binary();
        
    private:
        std::vector<float> array_;
        float num_;
        
};