// Challenge 4 Union-Find
//
// Author: Tian(Maxwell) Yang
//
// Implement a forest data structure for Union-Find problem. The description
// in the book is too vague for me to fully understand it so my code could
// be totally wrong

#include <stdio.h>
#include <stdlib.h>

size_t parent[1024];

void Initialize() {
	for (size_t i=0; i < sizeof(parent)/sizeof(size_t); ++i) {
		parent[i] = i;
	}
}

size_t Find(size_t index) {
	return parent[index];
}

void FindReplace(size_t root, size_t value) {
	for (size_t i=0; i < sizeof(parent)/sizeof(size_t); ++i) {
		if (parent[i] == root)
			parent[i] = value;
	}
}

void FindCompress(size_t index) {
	size_t old_root = parent[index];
	for (size_t i=0; i < sizeof(parent)/sizeof(size_t); ++i) {
		if (parent[i] == old_root)
			parent[i] = index;
	}
}

void Union(size_t elem_a, size_t elem_b) {
	FindCompress(elem_a);
	FindReplace(parent[elem_b], elem_a);
}

int main() {
	return EXIT_SUCCESS;
}
