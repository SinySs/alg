def Eratosthenes_sieve(N):
    mask = [1] * (N-1)
    numbers = []
    
    for i in range(2, N // 2):
        t = 2 * i

        while(t <= N):
            mask[t - 2] = 0
            t += i

    for i in range(len(mask)):
        if(mask[i] != 0):
            numbers.append(i + 2)

    return numbers
        

print(Eratosthenes_sieve(10))
