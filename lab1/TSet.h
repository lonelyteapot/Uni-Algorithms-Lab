#ifndef TSET_H
#define TSET_H

#include "TBitField.h"

class TSet {
private:
    size_t maxSize;
    TBitField bitField;

public:
    TSet(size_t maxSize);
    TSet(const TSet &set);
    TSet(const TBitField &bf);
    operator TBitField();

    void insert(const size_t elem);
    void remove(const size_t elem);
    bool contains(const size_t elem) const;

    TSet operator+(const size_t elem);
    TSet operator-(const size_t elem);

    bool operator==(const TSet &other);
    TSet operator+(const TSet &other);
    TSet operator*(const TSet &other);
    TSet operator~();

    friend istream &operator>>(istream &in, TSet &set);
    friend ostream &operator<<(ostream &out, const TSet &set);
};

#endif
