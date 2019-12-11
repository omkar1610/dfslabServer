import sys

class Trie:

    def __init__(self):
        self.NUM_SYMBOLS = 10
        self.INIT_SIZE = 20
        self.max_nodes = self.INIT_SIZE
        self.num_nodes = 2
        self.trie = [[0 if i != self.NUM_SYMBOLS else []for i in range(self.NUM_SYMBOLS + 1)] for j in range(self.INIT_SIZE)]
        self.name_to_num = {}
    
    def get_new_node(self) :
        """
        Creates a new trie node and returns the total num of nodes
        """
        if self.num_nodes == self.max_nodes :
            self.trie.extend([[0 if i != self.NUM_SYMBOLS else []for i in range(self.NUM_SYMBOLS + 1)] for j in range(self.INIT_SIZE)])
            self.max_nodes += self.INIT_SIZE
        self.num_nodes += 1
        return self.num_nodes - 1

    def insert_string(self, ph_num, name) :
        """
        Insert the string to the trie
        """
        index = 1
        for c in ph_num.lower() :
            i = ord(c) - ord('0')    # get ASCII value
            if i < 0 or i >= self.NUM_SYMBOLS :
                # print("Unexpected character %c in string %s" % (c, s))
                continue
            if self.trie[index][i] == 0 : # need new node
                new_index = self.get_new_node()
                self.trie[index][i] = new_index
                index = new_index
            else :
                index = self.trie[index][i]
        self.trie[index][self.NUM_SYMBOLS].append(name)
        
    def Insert(self, ph_num, name):
        """
        Insert the Number by each time excluding the first character
        """
        if len(ph_num) > 0:
            if name not in self.name_to_num.keys():
                self.name_to_num[name] = ph_num
            self.insert_string(ph_num, name)
            self.Insert(ph_num[1:], name)
            
    def dfs(self, num, index = 1 , ans = []):
        """ 
        depth first search to print all the names having the given substring
        num = string to be searched
        index = starting index returned by search
        ans = all the distinct names will be stored there
        """
        if index == 0:
            return

        ## Recurssively pass through all the nodes and keep on reducing the string with each call
        for i in range(self.NUM_SYMBOLS):
            if self.trie[index][i] != 0:
                self.dfs(num + str(i), self.trie[index][i], ans)

        ## In the last cell, Add all the names present there
        if len(self.trie[index][self.NUM_SYMBOLS]) != 0:
            for name in self.trie[index][self.NUM_SYMBOLS]:
                if name not in ans:
                    ans.append(name)

    def search(self, ph_num, index = 1):
        if index == 0:
            return 0
        elif len(ph_num) == 0:
            return index
        else:
            c = ph_num[0]
            i = ord(c) - ord('0')    # get ASCII value
            if i < 0 or i >= self.NUM_SYMBOLS :
                return 0
            index = self.trie[index][i]
            return self.search(ph_num[1:], index)
    
    def prog2(self, file, string):
        with open(file) as f:
            for line in f.read().splitlines()[1:]:
                pair = line.rsplit(" ",1)
                self.Insert(pair[1], pair[0])
        
        ans = []
        self.dfs(string, self.search(string, 1), ans)
        for name in sorted(ans):
            print(name, self.name_to_num[name])


if __name__ == '__main__':
    if len(sys.argv) != 3 :
        print('Usage: python3 <file> <string>')
        sys.exit(1) 

    trie = Trie()
    trie.prog2(sys.argv[1],sys.argv[2])
