long long iabs(long long x)
{
    if (x < 0) {

        return -x;

    }

    return x;
}

long long eu_mod(long long x, long long y)
{
    int r;
    r = x % y;

    if (r < 0) {
        r += iabs(y);
    }

    return r;
}

long long gcd(long long x, long long y)
{
    long long q;
    assert(y != 0);

    q = eu_mod(x, y);

    while(q != 0) {
        x = y;
        y = q;
        q = eu_mod(x, y);
    }

    return y;
}
