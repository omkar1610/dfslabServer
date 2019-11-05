class Queue():
    
    __queue = []
    
    def __init__(self):
        return
    
    def push(self,x):
        self.__queue.append(x)
    
    def pop(self):
        if(len(self.__queue)>0):
            self.__queue.pop(0)
        else:
            print("Underflow")
    
    def display(self):
        if(len(self.__queue)>0):
            print(self.__queue)
        else:
            print("Empty")
    
    def isPresent(self, x):
        if(x in self.__queue):
            return True
        else:
            return False

class Stack():
    
    __stack = []
    
    def __init__(self):
        return
    
    def push(self,x):
        self.__stack.append(x)
    
    def pop(self):
        if(len(self.__stack)>0):
            self.__stack.pop()
        else:
            print("Underflow")
    
    def display(self):
        if(len(self.__stack)>0):
            print(self.__stack)
        else:
            print("Empty")
    
    def isPresent(self, x):
        if(x in self.__stack):
            return True
        else:
            return False
        
class Trie():
    
    trie = {}
    
    def insert_string(self, s) :
        current_node = self.trie
        for c in s.lower() :
            if c not in current_node : # c is not a key in this dictionary
                new_node = {}
                current_node[c] = new_node
                current_node = new_node
            else :
                current_node = current_node[c]
        current_node['flag'] = True


    def search(self, s) :
        current_node = self.trie
        for c in s.lower() :
            if c not in current_node :
                return False
            else :
                current_node = current_node[c]
        return ('flag' in current_node) and current_node['flag'] # guard condition

    
    def display(self):
        print(self.trie)