def dist(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x2 - x1) + abs(y2 - y1)


def combination(n, org_arr, new_arr, c):
    global combset
    if len(new_arr) == n:
        combset.append(new_arr)
    for i in range(c, len(org_arr)):
        combination(n, org_arr, new_arr + [org_arr[i]], c+1)


N, M = list(map(int, input().split()))
arr = [list(map(int, input().split())) for _ in range(N)]
lc = []
lh = []
for j in range(N):
    for i in range(N):
        if arr[j][i] == 1:
            lh.append([i, j])
        if arr[j][i] == 2:
            lc.append([i, j])

corr = [[dist(ph, pc) for ph in lh] for pc in lc]

combset = []
combination(M, [i for i in range(len(lc))], [], 0)

mindist = 4*N*N*M
for comb in combset:
    distsum = 0
    for ih in range(len(lh)):
        distsum += min(corr[ic][ih] for ic in comb)
    mindist = min(mindist, distsum)

print(f'{mindist}')