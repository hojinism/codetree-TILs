# 20240409 20:30 -- 22:44 / 20240410 10:15 --


import math
import time


def dist(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x2 - x1) + abs(y2 - y1)


def combination(n, new_arr, c):
    global combarr, combset
    if len(new_arr) == n:
        combset.append(new_arr)
        return
    for i in range(c, len(combarr)):
        combination(n, new_arr + [combarr[i]], i+1)


# start = time.time()

N, M = list(map(int, input().split()))
arr = [list(map(int, input().split())) for _ in range(N)]
lc = []
lh = []
for j in range(N):
    for i in range(N):
        if arr[j][i] == 1:
            lh.append([i, j])
        elif arr[j][i] == 2:
            lc.append([i, j])

corr = [[dist(ph, pc) for ph in lh] for pc in lc]

# end = time.time()
# print(f"{end - start:.5f} sec")

combset = []
combarr = [i for i in range(len(lc))]
combination(M, [], 0)

# end = time.time()
# print(f"{end - start:.5f} sec")

mindist = 4*N*N*M
for comb in combset:
    distsum = 0
    for ih in range(len(lh)):
        distsum += min(corr[ic][ih] for ic in comb)
    mindist = min(mindist, distsum)

# end = time.time()
# print(f"{end - start:.5f} sec")

print(f'{mindist}')