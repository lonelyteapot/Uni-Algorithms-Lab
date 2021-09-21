#ifndef TBITFIELD_H
#define TBITFIELD_H

#include <iostream>

using namespace std;

class TBitField {
private:
    size_t bitLen;
    size_t *array;
    size_t arrLen;

    size_t getArrayIndex(const int bitN) const;
    size_t getArrayMask(const int bitN) const;

public:
    TBitField(size_t length);
    TBitField(const TBitField &bf);
    ~TBitField();

    // Bit functions

    size_t getLength() const;
    void setBit(size_t bitN);
    void clearBit(size_t bitN);
    bool getBit(size_t bitN) const;

    // Binary operations

    bool operator==(const TBitField &other);
    bool operator|(const TBitField &other);
    bool operator&(const TBitField &other);
    bool operator~(void);
    friend istream &operator>>(istream &in, TBitField &bf);
    friend ostream &operator<<(ostream &out, TBitField &bf);
};

#endif
