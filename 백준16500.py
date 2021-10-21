s = input()
n = int(input())
a = [input() for x in range(n)]

ssize = len(s)
dp = [x == (ssize) for x in range(ssize + 1)]
for x in reversed(range(ssize)):
	t = s[x:]
	remain_len = ssize - x
	# print(remain_len, s[x:])
	for ts in a:
		if (len(ts) <= remain_len) & (t[:len(ts)] == ts):
			if dp[x + len(ts)] == 1:
				dp[x] = 1
print(~~dp[0])