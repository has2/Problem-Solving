#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie {
	struct Node {
		bool valid;
		int child[26];
		Node() {
			for (int i = 0; i < 26; i++) child[i] = -1;
		}
	};
	vector<Node> trie;
	int root;
	int init() {
		puts("333");
		Node a;
		puts("3.5");
		printf("size1:%d\n", trie.size());
		trie.push_back(a);
		printf("size2:%d\n", trie.size());
		return (int)trie.size() - 1;
	}
	Trie() {
		root = init();
	}

	void insert(int node, int idx, string s) {
		printf("node:%d\n", node);
		if (idx == s.size()) {
			trie[node].valid = true;
			return;
		}

		int i = s[idx] - 'a';
		puts("111");
		int& next = trie[node].child[i];
		printf("next1:%d\n", next);
		if (next == -1) {
			printf("next2:%d\n", next);
			int k = init();
			printf("k:%d\n", k);
			next = k;
		}
		printf("next:%d\n", next);
		insert(next, idx + 1, s);
	}
	// if(trie[node].child[i]==-1) {
	//     int next = init();
	//     trie[node].child[i] = next;
	// }
	// insert(trie[node].child[i],idx+1,s);
	bool find(int node, int idx, string s) {
		if (node == -1) return false;
		if (idx == s.size()) {
			return trie[node].valid;
		}
		int i = s[idx] - 'a';
		int& next = trie[node].child[i];

		return find(next, idx + 1, s);
	}
};
int N, M;
struct nd {
	bool valid;
	int child[26];
	nd() {
		for (int i = 0; i < 26; i++) child[i] = -1;
	}
};
int main() {
	cin >> N >> M;
	Trie trie;
	//cout << "N : " << N << ", M : " << M << '\n';
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		//cout << "a : " << a << '\n';
		trie.insert(0, 0, a);
	}
	cout << trie.find(0, 0, "asdf");
}