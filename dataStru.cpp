#include "dataStru.h"

// origin:https://github.com/xyandy/DataStructure-And-Algorithms/tree/master/BitMap

class BitMap{
    public:
        BitMap(size_t num) {
            _v.resize((num >> 5) + 1); 
        }

        void set(size_t num) {
            size_t index = num >> 5; 
            size_t pos = num % 32;
            _v[index] |= (1 << pos);
        }

        void reSet(size_t num) {
            size_t index = num >> 5; 
            size_t pos = num % 32;
            _v[index] &= ~(1 << pos);
        }

        bool hasExisted(size_t num) {
            size_t index = num >> 5;
            size_t pos = num % 32;
            bool flag = false;
            if (_v[index] & (1 << pos))
                flag = true;
            return flag;
        }

    private:
        vector<size_t> _v;
};
