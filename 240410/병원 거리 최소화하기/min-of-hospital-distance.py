N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]

chickens = []
houses = []
for j in range(N):
    for i in range(N):
        if arr[j][i] == 2:
            chickens.append((i, j))
        elif arr[j][i] == 1:
            houses.append((i, j))


def dist(chicken, house):
    cx, cy = chicken
    hx, hy = house
    return abs(cx - hx) + abs(cy - hy)


# 각 house마다 가장 가까운 chicken집을 sort하여 시간을 줄일 수 있음!
corr = [sorted(list(enumerate(dist(chicken, house) for chicken in chickens)), key=lambda x: x[1]) for house in houses]

selected = [False for _ in range(len(chickens))] # 선택되었는지 확인용
mindist = 250000 # 적당히 큰 수

def comb(cn, ci):
    global mindist, selected
    if cn == M:
        tmp = 0
        for D in corr:
            for idx, dst in D:
                if selected[idx]:
                    tmp += dst
                    break
        mindist = min(mindist, tmp)
        return
    for i in range(ci, len(chickens)):
        selected[i] = True
        comb(cn + 1, i + 1)
        selected[i] = False


comb(0, 0)


print(mindist)