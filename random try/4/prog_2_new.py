import sys
import re

NUM_SYMBOLS = 10
INIT_SIZE = 10
max_nodes = INIT_SIZE
num_nodes = 2

def get_new_node(trie) :
    global num_nodes, max_nodes
    if num_nodes == max_nodes :
        #trie.extend([ [ 0 ] * (NUM_SYMBOLS+1) for i in range(INIT_SIZE) ])
        trie.extend([[0 if i != NUM_SYMBOLS else []for i in range(NUM_SYMBOLS + 1)] for j in range(INIT_SIZE)])
        max_nodes += INIT_SIZE
    num_nodes += 1
    return num_nodes - 1

def insert_string(trie, ph_num, name) :
    index = 1
    for c in ph_num.lower() :
        i = ord(c) - ord('0')    # get ASCII value
        if i < 0 or i >= NUM_SYMBOLS :
            # print("Unexpected character %c in string %s" % (c, s))
            continue
        if trie[index][i] == 0 : # need new node
            new_index = get_new_node(trie)
            trie[index][i] = new_index
            index = new_index
        else :
            index = trie[index][i]
    #trie[index][NUM_SYMBOLS] = name
    trie[index][NUM_SYMBOLS].append(name)
    
def dfs(trie, name_to_num, num, index = 1 ):
    if index == 0:
        return
    #print("called", num, index)
    for i in range(NUM_SYMBOLS):
        if trie[index][i] != 0:
            #num += str(i)
            dfs(trie, name_to_num, num + str(i), trie[index][i])
    if len(trie[index][NUM_SYMBOLS]) != 0:
        #print(trie[index][NUM_SYMBOLS], num)
        for name in trie[index][NUM_SYMBOLS]:
            print(name, name_to_num[name])
        
        
def search(trie, ph_num, index = 1):
    if index == 0:
        return 0
    elif len(ph_num) == 0:
        return index
    else:
        c = ph_num[0]
        i = ord(c) - ord('0')    # get ASCII value
        if i < 0 or i >= NUM_SYMBOLS :
            return 0
        index = trie[index][i]
        return search(trie, ph_num[1:], index)
    
#trie = [ [ 0 ] * (NUM_SYMBOLS+1) for i in range(INIT_SIZE) ]
trie = [[0 if i != NUM_SYMBOLS else []for i in range(NUM_SYMBOLS + 1)] for j in range(INIT_SIZE)]
def Insert(trie, name_to_num, ph_num, name):
    if len(ph_num) > 0:
        if name not in name_to_num.keys():
            name_to_num[name] = ph_num
        insert_string(trie, ph_num, name)
        Insert(trie, name_to_num, ph_num[1:], name)



trie = [[0 if i != NUM_SYMBOLS else []for i in range(NUM_SYMBOLS + 1)] for j in range(INIT_SIZE)]
name_to_num = {}

if __name__ == '__main__': # can use code in this file via import (?)
    if len(sys.argv) != 3 : # == argc
        print('Usage: python3 <file> <string>')
        sys.exit(1) 
    with open(sys.argv[1]) as f:
        for line in f:
            loc = re.search(r"\d", line).start()
            Insert(trie, name_to_num, line[loc:], line[:loc-1])
    dfs(trie, name_to_num, sys.argv[2], search(trie, sys.argv[2], 1))