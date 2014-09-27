n = int(input())
m = [list(map(int, input().split("-"))) for _ in range(n)]
 
for x in range(n):
		m[x][0] -= m[x][0] % 5
 
		m[x][1] += (5 - (m[x][1] % 5)) % 5
		if m[x][1] % 100 == 60:
			m[x][1] += 40
 
lis = [0] * 2401
 
for x in range(n):
	lis[m[x][0]:m[x][1]] = '1' * (m[x][1] - m[x][0])
		
x = 0
while x < 2400:
	if lis[x] == '1':
		print("%04d-" % x, end="")
		while lis[x] != 0:
			x+=1
		print("%04d" % x)
	else:
		x += 1

