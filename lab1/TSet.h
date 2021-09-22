#ifndef TSET_H
#define TSET_H

#include "TBitField.h"

class TSet {
private:
    size_t maxSize;
    TBitField bitField;

public:
    TSet(const size_t maxSize);
    TSet(const TSet &set);
    TSet(const TBitField &bf);
    operator TBitField();

    void insert(const int elem);
    void remove(const int elem);
    bool contains(const int elem) const;

    TSet operator+(const int elem);
    TSet operator-(const int elem);

    bool operator==(const TSet &other);
    TSet operator+(const TSet &other);
    TSet operator*(const TSet &other);
    TSet operator~();

    friend istream &operator>>(istream &in, TSet &set);
    friend ostream &operator<<(ostream &out, const TSet &set);
};


#endif
