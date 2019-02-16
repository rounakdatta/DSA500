OBJECTS = array backtracking binary binary-search-tree binary-tree divide-conquer dynamic-programming greedy heaps matrix puzzles queue sorting stack string trie

$(OBJECTS):
	g++ $@/$(problem).cpp -o $@/$(problem)
	./$@/$(problem)
