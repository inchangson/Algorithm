#2217
import sys
input = sys.stdin.readline

N = int(input())
ropes = [int(input()) for _ in range(N)]

ropes.sort(reverse=True)

ans = 0
for idx in range(N):
    tmp = (idx+1)*ropes[idx]
    ans = max(ans, tmp)
print(ans)
