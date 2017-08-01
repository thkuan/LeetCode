typedef unsigned int uint32_t;

int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n != 0) {
        ret += n & 0x1;
        n >>= 1;
    }

    return ret;
}
