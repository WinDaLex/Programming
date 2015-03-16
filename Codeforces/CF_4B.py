d, sum_time = map(int, input().split())
min_time = [0] * d
max_time = [0] * d
for i in range(d):
    min_time[i], max_time[i] = map(int, input().split())

if sum(min_time) <= sum_time <= sum(max_time):
    print('YES')
    left_max_time = sum(max_time)
    ans = []
    for i in range(d):
        left_max_time -= max_time[i]
        today_time = max(min_time[i], sum_time - left_max_time)
        ans.append(today_time)
        sum_time -= today_time
    print(' '.join(map(str, ans)))
else:
    print('NO')
