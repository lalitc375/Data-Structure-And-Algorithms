
def noOfOnes(n):
	count=0
	while(n>0):
		n=n&(n-1)
		count+=1
	return count
print noOfOnes(100)
print noOfOnes(15)
print noOfOnes(64)