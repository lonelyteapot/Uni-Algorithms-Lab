#ifndef TBITFIELD_H
#define TBITFIELD_H

#include <iostream>

using namespace std;

class TBitField {
private:
    size_t bitLen;
    size_t arrLen;
    size_t *array;

    static size_t getArrayIndex(size_t bitN) ;
    static size_t getArrayMask(size_t bitN) ;

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
    TBitField operator|(const TBitField &other);
    TBitField operator&(const TBitField &other);
    TBitField operator~();
    friend istream &operator>>(istream &in, TBitField &bf);
    friend ostream &operator<<(ostream &out, const TBitField &bf);
};

#endif
