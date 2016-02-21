def powerOf2(n):
	return  not(n & (n-1))

print powerOf2(100)
print powerOf2(64)