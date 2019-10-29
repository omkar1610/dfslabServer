num_ele = 0
# data = [(0, i+1, -1) for i in range(max_ele)]
data = []

root = -1

def insert(data, value):
	if(len(data) == 0):
		root = 0
		data.append((value, -1, -1))


insert(data, 5)
for t in data:
	print(t)