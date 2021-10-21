log2 = lambda x:0 if x<=1 else 1+log2(x//2)

def Swap_row(i, j, arr):
	if i==j:
		return 0
	arr[i], arr[j] = arr[j], arr[i]
	return 1

def Reduce_pivot(pivot_row, RREF, pcol, rows):
	cnt = 0
	for row in range(rows):
		if row == pivot_row:
			continue
		if (RREF[row]>>pcol)&1:
			RREF[row] ^= RREF[pivot_row]
			cnt +=1
	return cnt

def Max_Xor(sorted_list, num_el):
	if num_el == 0:
		return 0
	#Max_Xor = Sum of standard basis of list in F^n_2
	cols = log2(sorted_list[0])+1
	rows = num_el


	#init
	rank = 0
	RREF = sorted_list[:]

	for pcol in reversed(range(cols)):
		#find pivot
		for row in range(rank, rows):
			# is_pivot?
			if (RREF[row]>>pcol)&1:
				Swap_row(rank, row, RREF)
				Reduce_pivot(rank, RREF, pcol, rows)
				rank+=1
				break
		if (rank == rows):
			break

	out = 0
	for x in range(rank):
		out ^= RREF[x]
	return out
	

N=int(input())
My_list = [int(input()) for x in range(N)]
My_list = list(set(My_list))

#Maximal subarray(length : even) of a1, ... , aN  == Maximal subarray of a1^a2, a1^a3, ... ,a1^aN
for x in range(1,len(My_list)):
	My_list[x] ^= My_list[0]

del(My_list[0])

N = len(My_list)

My_list.sort()
My_list.reverse()

Max = Max_Xor(My_list,N)
print(Max)