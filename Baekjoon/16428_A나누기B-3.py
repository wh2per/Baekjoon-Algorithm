a, b = map(int, input().split())
if b > 0:
	p = a//b
else:
	b *= -1             # 양수로 전환
	if a%b == 0:
		p = -a//b
	else:
		p = -a//b + 1
	b *= -1             # 음수로 전환
print(p)
print(a-p*b)