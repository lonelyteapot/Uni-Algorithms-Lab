#include "TSet.h"

TSet::TSet(size_t maxSize):
        maxSize {maxSize},
        bitField {maxSize} {
}

TSet::TSet(const TSet &set):
        maxSize {set.maxSize},
        bitField {set.bitField} {
}

TSet::TSet(const TBitField &bf):
        maxSize {bf.getLength()},
        bitField {bf} {
}

TSet::operator TBitField() {
    return bitField;
}

void TSet::insert(const size_t elem) {
    // TODO Assert elem < maxSize
    bitField.setBit(elem);
}

void TSet::remove(const size_t elem) {
    // TODO Assert elem < maxSize
    bitField.clearBit(elem);
}

bool TSet::contains(const size_t elem) const {
    // TODO Assert elem < maxSize
    return bitField.getBit(elem);
}

TSet TSet::operator+(const size_t elem) {
    TSet ret = TSet(*this);
    ret.insert(elem);
    return ret;
}

TSet TSet::operator-(const size_t elem) {
    TSet ret = TSet(*this);
    ret.remove(elem);
    return ret;
}

bool TSet::operator==(const TSet &other) {
    return bitField == other.bitField;
}

TSet TSet::operator+(const TSet &other) {
    return {bitField | other.bitField};
}

TSet TSet::operator*(const TSet &other) {
    return {bitField & other.bitField};
}

TSet TSet::operator~() {
    return {~bitField};
}

// TODO Implement operator>>

ostream &operator<<(ostream &out, const TSet &set) {
    out << "{";
    for (size_t i = 0; i < set.maxSize; ++i) {
        if (set.contains(i)) {
            out << i << ", ";
        }
    }
    out << "}";
    return out;
}
