#include "TBitField.h"

using namespace std;

// Private methods

size_t TBitField::getArrayIndex(const size_t bitN) {
    return bitN / (sizeof(size_t) * CHAR_BIT);
}

size_t TBitField::getArrayMask(const size_t bitN) {
    const size_t localBitN = bitN % (sizeof(size_t) * CHAR_BIT);
    return 1U << localBitN;
}

// Constructors

TBitField::TBitField(size_t length) {
    if (length <= 0)
        throw runtime_error("TBitField cannot be of length 0");
    bitLen = length;
    arrLen = getArrayIndex(bitLen-1) + 1;
    array = new size_t[arrLen];
}

TBitField::TBitField(const TBitField &bf) {
    bitLen = bf.bitLen;
    arrLen = bf.arrLen;
    array = new size_t[arrLen];
    for (size_t i = 0; i < arrLen; ++i)
        array[i] = bf.array[i];
}

TBitField::~TBitField() {
    delete[] array;
}

// Bit functions

size_t TBitField::getLength() const {
    return bitLen;
}

void TBitField::setBit(size_t bitN) {
    array[getArrayIndex(bitN)] |= getArrayMask(bitN);
}

void TBitField::clearBit(size_t bitN) {
    array[getArrayIndex(bitN)] &= ~getArrayMask(bitN);
}

bool TBitField::getBit(size_t bitN) const {
    return (array[getArrayIndex(bitN)] & getArrayMask(bitN)) != 0;
}

// Binary operations

bool TBitField::operator==(const TBitField &other) {
    if (bitLen != other.bitLen)
        return false;
    for (size_t i = 0; i < arrLen; ++i) {
        if (array[i] != other.array[i])
            return false;
    }
    return true;
}

TBitField TBitField::operator|(const TBitField &other) {
    TBitField ret = TBitField(max(bitLen, other.bitLen));
    for (size_t i = 0; i < arrLen; ++i)
        ret.array[i] = array[i];
    for (size_t i = 0; i < other.arrLen; ++i)
        ret.array[i] |= other.array[i];
    return ret;
}

TBitField TBitField::operator&(const TBitField &other) {
    TBitField ret = TBitField(max(bitLen, other.bitLen));
    for (size_t i = 0; i < arrLen; ++i)
        ret.array[i] = array[i];
    for (size_t i = 0; i < other.arrLen; ++i)
        ret.array[i] &= other.array[i];
    return ret;
}

TBitField TBitField::operator~() {
    TBitField ret = TBitField(this->bitLen);
    for (size_t i = 0; i < arrLen; ++i) {
        ret.array[i] = ~array[i];
    }
    return ret;
}

istream &operator>>(istream &in, TBitField &bf) {
    string str;
    in >> str;
    bf.bitLen = str.length();
    bf.arrLen = bf.getArrayIndex(bf.bitLen-1) + 1;
    for (size_t i = 0; i < bf.bitLen; ++i) {
        if (str[i] == '1') {
            bf.setBit(i);
        } else if (str[i] == '0') {
            bf.clearBit(i);
        } else {
            throw runtime_error("Wrong 'bit' character: " + str.substr(i, 1));
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const TBitField &bf) {
    for (size_t i = 0; i < bf.bitLen; ++i) {
        out << "01"[bf.getBit(i)];
    }
    return out;
}
