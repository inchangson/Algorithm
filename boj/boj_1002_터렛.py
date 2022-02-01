def get_num_node(x1, y1, r1, x2, y2, r2):
    dist_2 = (x1 - x2)**2 + (y1 - y2)**2
    if dist_2 == 0 and r1 == r2:
        return -1

    sum_r_2 = (r1 + r2)**2
    if sum_r_2 == dist_2:
        return 1
    if sum_r_2 < dist_2:
        return 0

    gap_2 = (r1 - r2)**2

    if gap_2 == dist_2:
        return 1
    elif gap_2 < dist_2:
        return 2
    else:
        return 0


T = int(input())
for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    ans = get_num_node(x1, y1, r1, x2, y2, r2)
    print(ans)
