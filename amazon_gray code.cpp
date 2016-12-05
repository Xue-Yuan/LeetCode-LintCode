bool checkGrayCode(uint8_t n1, uint8_t n2) {
    uint8_t x = n1 ^ n2;
    return x && (x & (x-1)) == 0;
}
