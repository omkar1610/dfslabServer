import sys

def func(ip, op):
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


if __name__ == "__main__":
	if(len(sys.argv) != 3):
		print("Usage : python3 prog1.py <input> <output>")
		sys.exit(1)
	func(sys.argv[1],sys.argv[2])