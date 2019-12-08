import sys
import re

def func_old(ip, op):
	with open(ip) as f:
	    data = list(f.read())
	f.close()

	delims = ["\t",",",".",";",":","|","\'","\"","{","}","\\","/","`"," ","-"]
	freq = [data.count(c) for c in delims]
	max_freq = max(freq)
	if freq.count(max_freq) > 1:
		print("CONFUSING")
		sys.exit(1)
	new_delim = delims[freq.index(max_freq)]

	out_data = [new_delim if ele in delims else ele for ele in data]

	with open(op,"w") as f:
	    f.write("".join(out_data))
	f.close()
	print("".join(out_data))


def func(ip, op):
	with open(ip) as f:
	    data = re.split('([^a-zA-Z0-9\n]+)',f.read())
	f.close()

	table = {}
	for ele in data:
	    if not re.match('^[a-zA-Z0-9]',ele):
	        if ele in table:
	            table[ele] += 1 
	        else:
	            table[ele] = 1
	#print(table)

	mx_ele = max(table, key=table.get)
	count = table[mx_ele]

	del table[mx_ele]
	if count == table[max(table, key=table.get)]:
	    print("CONFUSING")
	else:
	    out_data = [mx_ele if not re.match('^[a-zA-Z0-9]',ele) else ele for ele in data]
	    with open(op,"w") as f:
	        f.write("".join(out_data))
	    f.close()
	    print("".join(out_data))


if __name__ == "__main__":
	if(len(sys.argv) != 3):
		print("Usage : python3 prog1.py <input> <output>")
		sys.exit(1)
	func(sys.argv[1],sys.argv[2])