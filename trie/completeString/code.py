class Node:
    def __init__(self):
        self.flag = False
        self.links = [None] * 26
    
    def contains(self, c):
        return self.links[ord(c) - ord('a')] is not None
    
    def put(self, c):
        self.links[ord(c) - ord('a')] = Node()
    
    def next(self, c):
        return self.links[ord(c) - ord('a')]
    
    def setEnd(self):
        self.flag = True
    
    def isEnd(self):
        return self.flag


class Trie:
    def __init__(self):
        self.root = Node()
    
    def insert(self, s):
        tmp = self.root
        for c in s:
            if not tmp.contains(c):
                tmp.put(c)
            tmp = tmp.next(c)
        tmp.setEnd()
    
    def search(self, s):
        tmp = self.root
        for c in s:
            tmp = tmp.next(c)
            if not tmp.isEnd():
                return False
        return True


def completeString(n, a):
    trie = Trie()
    for s in a:
        trie.insert(s)
    
    ans = ""
    for s in a:
        if trie.search(s):
            if len(s) > len(ans) or (len(s) == len(ans) and s < ans):
                ans = s
    
    if len(ans) == 0:
        return "None"
    return ans
