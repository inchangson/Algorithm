N = int(input())

count = 0

cur = N
while True:
    tmp = ((cur // 10)+ (cur % 10))
    cur = (cur % 10)*10 + tmp%10
    count += 1
    if cur == N :
        break

print(count)