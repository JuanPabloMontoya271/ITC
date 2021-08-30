R, C = map(int, input().split())
matrix = []
E = []


def check_nbs(matrix, E, coords):
    if matrix[coords[0]][coords[1]] == "E":
        return 0
    if matrix[coords[0]][coords[1]] == ".":
        return (coords[0] - E[0]) ** 2 + (coords[1] - E[0]) ** 2
    forbidden = {"#", "X"}
    if matrix[coords[0]][coords[1]] in forbidden:
        return -1


def get_result(value, min_dist, solitario):
    result = ""
    if value == 0:
        result = "E"
    elif value > 0:
        min_dist = min(value, min_dist)
        print("Min dist", min_dist)
    solitario = solitario and value == -1
    return min_dist, solitario, result


for i in range(R):
    line = input()
    row = []
    for idx, c in enumerate(line):
        row.append(c)
        if "E" == c:
            E = [i, idx]

    matrix.append(row)


Q = int(input())
result = ""
min_dist = float("inf")
solitario = 1
for _ in range(Q):
    x, y = map(int, input().split())
    x, y = x - 1, y - 1

    if y - 1 >= 0:
        top = check_nbs(matrix, E, [y - 1, x])
        min_dist, solitario, result = get_result(top, min_dist, solitario)

    if y + 1 < len(matrix):
        bottom = check_nbs(matrix, E, [y + 1, x])
        min_dist, solitario, result = get_result(bottom, min_dist, solitario)
    if x + 1 < len(matrix[0]):
        right = check_nbs(matrix, E, [y, x + 1])
        min_dist, solitario, result = get_result(right, min_dist, solitario)
    if x - 1 > len(matrix[0]):
        left = check_nbs(matrix, E, [y, x - 1])
        min_dist, solitario, result = get_result(left, min_dist, solitario)

    print(result, min_dist, solitario)
print(matrix)
