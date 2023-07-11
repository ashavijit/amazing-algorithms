type Node struct {
	flag  bool
	links [26]*Node
}

func (n *Node) contains(c byte) bool {
	return n.links[c-'a'] != nil
}

func (n *Node) put(c byte) {
	n.links[c-'a'] = &Node{}
}

func (n *Node) next(c byte) *Node {
	return n.links[c-'a']
}

func (n *Node) setEnd() {
	n.flag = true
}

func (n *Node) isEnd() bool {
	return n.flag
}

type Trie struct {
	root *Node
}

func NewTrie() *Trie {
	return &Trie{
		root: &Node{},
	}
}

func (t *Trie) insert(s string) {
	tmp := t.root
	for i := 0; i < len(s); i++ {
		c := s[i]
		if !tmp.contains(c) {
			tmp.put(c)
		}
		tmp = tmp.next(c)
	}
	tmp.setEnd()
}

func (t *Trie) search(s string) bool {
	tmp := t.root
	for i := 0; i < len(s); i++ {
		c := s[i]
		tmp = tmp.next(c)
		if !tmp.isEnd() {
			return false
		}
	}
	return true
}

func completeString(n int, a []string) string {
	trie := NewTrie()
	for _, s := range a {
		trie.insert(s)
	}

	var ans string
	for _, s := range a {
		if trie.search(s) {
			if len(s) > len(ans) || (len(s) == len(ans) && s < ans) {
				ans = s
			}
		}
	}

	if len(ans) == 0 {
		return "None"
	}
	return ans
}
