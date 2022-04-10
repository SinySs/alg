unsigned mult_mod(unsigned n, unsigned k, unsigned m)
{
    unsigned long long acc, prod;
    assert(m > 1);
    if (k == 0)
        return 1;
    acc = n % m;
    prod = 1;
    for (; k > 0;) {
        if ((k % 2) == 1)
            prod = (prod * acc) % m;
        acc = (acc * acc) % m;
        k = k / 2;
    }
    return prod;
}
