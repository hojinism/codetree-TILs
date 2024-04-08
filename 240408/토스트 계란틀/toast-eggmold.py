dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def unite(basket, lst):
    global arr, marked, hasmoved
    while lst:
        x, y = lst.pop(0)
        for ds in range(4):
            nx = x + dx[ds]
            ny = y + dy[ds]
            if not marked[ny][nx] and L <= abs(arr[ny][nx] - arr[y][x]) <= R:  # simply chained cmp!
                marked[ny][nx] = 1
                lst.append([nx, ny])
                basket.append([nx, ny])
                hasmoved = True
    return basket


def rewrite(basket):
    global arr
    tmpsum = 0
    for x, y in basket:
        tmpsum += arr[y][x]
    tmpavg = int(tmpsum / len(basket))
    for x, y in basket:
        arr[y][x] = tmpavg


N, L, R = list(map(int, input().split()))
arr = [[-500 for _ in range(N + 2)]] + \
      [([-500] + list(map(int, input().split())) + [-500]) for _ in range(N)] + \
      [[-500 for _ in range(N + 2)]]
marked = [[1 for _ in range(N + 2)] for _ in range(N + 2)]

n_move = 0
while 1:
    # init
    for j in range(1, N + 1):
        for i in range(1, N + 1):
            marked[j][i] = 0
    hasmoved = False

    for j in range(1, N + 1):
        for i in range(1, N + 1):
            if not marked[j][i]:
                marked[j][i] = 1
                basket = [[i, j]]
                lst = [[i, j]]
                basket = unite(basket, lst)
                rewrite(basket)

    if not hasmoved:
        break
    else:
        n_move += 1

print(f'{n_move}')