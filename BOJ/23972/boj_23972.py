def sol():
    k, n = map(int, input().split())
    if n == 1 :
        print(-1)
        return 
    ans = int(k*n//(n-1))
    if k*n % (n - 1 ):
        ans += 1
    print(ans)
sol();