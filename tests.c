/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u)
{
    union {
        unsigned u;
        float f;
    } a;
    a.u = u;
    return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f)
{
    union {
        unsigned u;
        float f;
    } a;
    a.f = f;
    return a.u;
}

int test_absVal(int x)
{
    return (x < 0) ? -x : x;
}

int test_addOK(int x, int y)
{
    long long lsum = (long long) x + y;
    return lsum == (int) lsum;
}

int test_allEvenBits(int x)
{
    int i;
    for (i = 0; i < 32; i += 2)
        if ((x & (1 << i)) == 0)
            return 0;
    return 1;
}

int test_allOddBits(int x)
{
    int i;
    for (i = 1; i < 32; i += 2)
        if ((x & (1 << i)) == 0)
            return 0;
    return 1;
}

int test_anyEvenBit(int x)
{
    int i;
    for (i = 0; i < 32; i += 2)
        if (x & (1 << i))
            return 1;
    return 0;
}

int test_anyOddBit(int x)
{
    int i;
    for (i = 1; i < 32; i += 2)
        if (x & (1 << i))
            return 1;
    return 0;
}

int test_bang(int x)
{
    return !x;
}

int test_bitAnd(int x, int y)
{
    return x & y;
}

int test_bitCount(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i++)
        result += ((unsigned) x >> i) & 0x1;
    return result;
}

int test_bitMask(int highbit, int lowbit)
{
    int result = 0;
    int i;
    for (i = lowbit; i <= highbit; i++)
        result |= 1 << i;
    return result;
}

int test_bitMatch(int x, int y)
{
    int i;
    int result = 0;
    for (i = 0; i < 32; i++) {
        int mask = 1u << i;
        int bit = (x & mask) == (y & mask);
        result |= (unsigned) bit << i;
    }
    return result;
}

int test_bitNor(int x, int y)
{
    return ~(x | y);
}

int test_bitOr(int x, int y)
{
    return x | y;
}

int test_bitParity(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i++)
        result ^= ((unsigned) x >> i) & 0x1;
    return result;
}

int test_bitReverse(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i++) {
        int bit = ((unsigned) x >> i) & 0x1;
        int pos = 31 - i;
        result |= bit << pos;
    }
    return result;
}

int test_bitXor(int x, int y)
{
    return x ^ y;
}

int test_byteSwap(int x, int n, int m)
{
    /* FIXME: only valid to little endian machine */
    /* least significant byte stored first */
    unsigned int nmask, mmask;
    switch (n) {
    case 0:
        nmask = x & 0xFF;
        x &= 0xFFFFFF00;
        break;
    case 1:
        nmask = (x & 0xFF00) >> 8;
        x &= 0xFFFF00FF;
        break;
    case 2:
        nmask = (x & 0xFF0000) >> 16;
        x &= 0xFF00FFFF;
        break;
    default:
        nmask = ((unsigned int) (x & 0xFF000000)) >> 24;
        x &= 0x00FFFFFF;
        break;
    }
    switch (m) {
    case 0:
        mmask = x & 0xFF;
        x &= 0xFFFFFF00;
        break;
    case 1:
        mmask = (x & 0xFF00) >> 8;
        x &= 0xFFFF00FF;
        break;
    case 2:
        mmask = (x & 0xFF0000) >> 16;
        x &= 0xFF00FFFF;
        break;
    default:
        mmask = ((unsigned int) (x & 0xFF000000)) >> 24;
        x &= 0x00FFFFFF;
        break;
    }
    nmask <<= 8 * m;
    mmask <<= 8 * n;
    return x | nmask | mmask;
}

int test_conditional(int x, int y, int z)
{
    return x ? y : z;
}

int test_countLeadingZero(int x)
{
    if (x == 0)
        return 32;
    unsigned int y = x;
    int n = 0;
    if (y <= 0x0000FFFF) {
        n += 16;
        y <<= 16;
    }
    if (y <= 0x00FFFFFF) {
        n += 8;
        y <<= 8;
    }
    if (y <= 0x0FFFFFFF) {
        n += 4;
        y <<= 4;
    }
    if (y <= 0x3FFFFFFF) {
        n += 2;
        y <<= 2;
    }
    if (y <= 0x7FFFFFFF) {
        n += 1;
        y <<= 1;
    }
    return n;
}

int test_copyLSB(int x)
{
    return (x & 0x1) ? -1 : 0;
}

int test_distinctNegation(int x)
{
    return x != -x;
}

int test_dividePower2(int x, int n)
{
    int p2n = 1 << n;
    return x / p2n;
}

int test_evenBits(void)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i += 2)
        result |= 1 << i;
    return result;
}

int test_ezThreeFourths(int x)
{
    return (x * 3) / 4;
}

int test_fitsBits(int x, int n)
{
    int TMin_n = -(1 << (n - 1));
    /* This convoluted way of generating TMax avoids overflow */
    int TMax_n = (int) ((1u << (n - 1)) - 1u);
    return x >= TMin_n && x <= TMax_n;
}

int test_fitsShort(int x)
{
    short int sx = (short int) x;
    return x == sx;
}

unsigned test_floatAbsVal(unsigned uf)
{
    float f = u2f(uf);
    unsigned unf = f2u(-f);
    if (isnan(f))
        return uf;
    /* An unfortunate hack to get around a limitation of the BDD Checker */
    if ((int) uf < 0)
        return unf;
    else
        return uf;
}

int test_floatFloat2Int(unsigned uf)
{
    float f = u2f(uf);
    int x = (int) f;
    return x;
}

unsigned test_floatInt2Float(int x)
{
    float f = (float) x;
    return f2u(f);
}

int test_floatIsEqual(unsigned uf, unsigned ug)
{
    float f = u2f(uf);
    float g = u2f(ug);
    return f == g;
}

int test_floatIsLess(unsigned uf, unsigned ug)
{
    float f = u2f(uf);
    float g = u2f(ug);
    return f < g;
}

unsigned test_floatNegate(unsigned uf)
{
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
        return uf;
    else
        return f2u(nf);
}

unsigned test_floatPower2(int x)
{
    float result = 1.0;
    float p2 = 2.0;
    int recip = (x < 0);
    /* treat tmin specially */
    if ((unsigned) x == 0x80000000) {
        return 0;
    }
    if (recip) {
        x = -x;
        p2 = 0.5;
    }
    while (x > 0) {
        if (x & 0x1)
            result = result * p2;
        p2 = p2 * p2;
        x >>= 1;
    }
    return f2u(result);
}

unsigned test_floatScale1d2(unsigned uf)
{
    float f = u2f(uf);
    float hf = 0.5 * f;
    if (isnan(f))
        return uf;
    else
        return f2u(hf);
}

unsigned test_floatScale2(unsigned uf)
{
    float f = u2f(uf);
    float tf = 2 * f;
    if (isnan(f))
        return uf;
    else
        return f2u(tf);
}

unsigned test_floatScale64(unsigned uf)
{
    float f = u2f(uf);
    float tenf = 64 * f;
    if (isnan(f))
        return uf;
    else
        return f2u(tenf);
}

unsigned test_floatUnsigned2Float(unsigned u)
{
    float f = (float) u;
    return f2u(f);
}

int test_getByte(int x, int n)
{
    unsigned char byte;
    switch (n) {
    case 0:
        byte = x;
        break;
    case 1:
        byte = x >> 8;
        break;
    case 2:
        byte = x >> 16;
        break;
    default:
        byte = x >> 24;
        break;
    }
    return (int) (unsigned) byte;
}

int test_greatestBitPos(int x)
{
    unsigned mask = 1u << 31;
    if (x == 0)
        return 0;
    while (!(mask & x)) {
        mask = mask >> 1;
    }
    return mask;
}

int test_howManyBits(int x)
{
    unsigned int a, cnt;
    x = x < 0 ? -x - 1 : x;
    a = (unsigned int) x;
    for (cnt = 0; a; a >>= 1, cnt++)
        ;
    return (int) (cnt + 1);
}

int test_implication(int x, int y)
{
    return !(x & (!y));
}

int test_intLog2(int x)
{
    int mask, result;
    /* find the leftmost bit */
    result = 31;
    mask = 1u << result;
    while (!(x & mask)) {
        result--;
        mask = 1 << result;
    }
    return result;
}

int test_isAsciiDigit(int x)
{
    return (0x30 <= x) && (x <= 0x39);
}

int test_isEqual(int x, int y)
{
    return x == y;
}

int test_isGreater(int x, int y)
{
    return x > y;
}

int test_isLess(int x, int y)
{
    return x < y;
}

int test_isLessOrEqual(int x, int y)
{
    return x <= y;
}

int test_isNegative(int x)
{
    return x < 0;
}

int test_isNonNegative(int x)
{
    return x >= 0;
}

int test_isNonZero(int x)
{
    return x != 0;
}

int test_isNotEqual(int x, int y)
{
    return x != y;
}

int test_isPallindrome(int x)
{
    int result = 1;
    int i;
    int mask = 0xFFFF;
    int xlo = x & mask;
    int xhi = (x >> 16) & mask;
    for (i = 0; i < 16; i++) {
        int flipi = 15 - i;
        int bhigh = (xhi >> i) & 0x1;
        int blow = (xlo >> flipi) & 0x1;
        result = result && (bhigh == blow);
    }
    return result;
}

int test_isPositive(int x)
{
    return x > 0;
}

int test_isPower2(int x)
{
    int i;
    for (i = 0; i < 31; i++) {
        if (x == 1 << i)
            return 1;
    }
    return 0;
}

int test_isTmax(int x)
{
    return x == 0x7FFFFFFF;
}

int test_isTmin(int x)
{
    return x == 0x80000000;
}

int test_isZero(int x)
{
    return x == 0;
}

int test_leastBitPos(int x)
{
    int mask = 1;
    if (x == 0)
        return 0;
    while (!(mask & x)) {
        mask = mask << 1;
    }
    return mask;
}

int test_leftBitCount(int x)
{
    int result = 0;
    int i;
    for (i = 31; i >= 0; i--) {
        int bit = ((unsigned) x >> i) & 0x1;
        if (!bit)
            break;
        result++;
    }
    return result;
}

int test_logicalNeg(int x)
{
    return !x;
}

int test_logicalShift(int x, int n)
{
    unsigned u = (unsigned) x;
    unsigned shifted = u >> n;
    return (int) shifted;
}

int test_maximumOfTwo(int x, int y)
{
    return (x > y) ? x : y;
}

int test_minimumOfTwo(int x, int y)
{
    return (x < y) ? x : y;
}

int test_minusOne(void)
{
    return -1;
}

int test_multFiveEighths(int x)
{
    return (x * 5) / 8;
}

int test_negate(int x)
{
    return -x;
}

int test_oddBits(void)
{
    int result = 0;
    int i;
    for (i = 1; i < 32; i += 2)
        result |= 1 << i;
    return result;
}

int test_remainderPower2(int x, int n)
{
    int p2n = 1 << n;
    return x % p2n;
}

int test_replaceByte(int x, int n, int c)
{
    switch (n) {
    case 0:
        x = (x & 0xFFFFFF00) | c;
        break;
    case 1:
        x = (x & 0xFFFF00FF) | (c << 8);
        break;
    case 2:
        x = (x & 0xFF00FFFF) | (c << 16);
        break;
    default:
        x = (x & 0x00FFFFFF) | (c << 24);
        break;
    }
    return x;
}

int test_rotateLeft(int x, int n)
{
    unsigned u = (unsigned) x;
    int i;
    for (i = 0; i < n; i++) {
        unsigned msb = u >> 31;
        unsigned rest = u << 1;
        u = rest | msb;
    }
    return (int) u;
}

int test_rotateRight(int x, int n)
{
    unsigned u = (unsigned) x;
    int i;
    for (i = 0; i < n; i++) {
        unsigned lsb = (u & 1) << 31;
        unsigned rest = u >> 1;
        u = lsb | rest;
    }
    return (int) u;
}

int test_satAdd(int x, int y)
{
    if (x > 0 && y > 0 && x + y < 0)
        return (0x7FFFFFFF);
    if (x < 0 && y < 0 && x + y >= 0)
        return (0x80000000);
    return x + y;
}

int test_satMul2(int x)
{
    if ((x + x) / 2 != x)
        return x < 0 ? 0x80000000 : 0x7FFFFFFF;
    else
        return 2 * x;
}

int test_satMul3(int x)
{
    if ((x + x + x) / 3 != x)
        return x < 0 ? 0x80000000 : 0x7FFFFFFF;
    else
        return 3 * x;
}

int test_sign(int x)
{
    if (!x)
        return 0;
    return (x < 0) ? -1 : 1;
}

int test_signMag2TwosComp(int x)
{
    int sign = x < 0;
    int mag = x & 0x7FFFFFFF;
    return sign ? -mag : mag;
}

int test_specialBits(void)
{
    return 0xffca3fff;
}

int test_subtractionOK(int x, int y)
{
    long long ldiff = (long long) x - y;
    return ldiff == (int) ldiff;
}

int test_thirdBits(void)
{
    int result = 0;
    int i;
    for (i = 0; i < 32; i += 3)
        result |= 1 << i;
    return result;
}

int test_tmax(void)
{
    return 0x7FFFFFFF;
}

int test_tmin(void)
{
    return 0x80000000;
}

int test_trueFiveEighths(int x)
{
    return (int) (((long long int) x * 5) / 8);
}

int test_trueThreeFourths(int x)
{
    return (int) (((long long int) x * 3) / 4);
}

int test_twosComp2SignMag(int x)
{
    int sign = x < 0;
    int mag = x < 0 ? -x : x;
    return ((unsigned) sign << 31) | mag;
}

int test_upperBits(int x)
{
    int result = 0;
    int i;
    for (i = 0; i < x; i++)
        result |= (1 << (31 - i));
    return result;
}
