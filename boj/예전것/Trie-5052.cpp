
#include <cstdio>
#include <algorithm>
using namespace std;

class Trie {
private:
	Trie* sub[10];
	bool ter;
	bool hasChild;
public:

	Trie()
	{
		fill(sub, sub + 10, nullptr);
		ter = hasChild = false;
	}

	~Trie()
	{
		for (int i = 0; i < 10; i++)
		{
			if (sub[i]) delete sub[i];
		}
	}

	void insert(const char* number)
	{
		if (*number == '\0') ter = true;
		else {
			hasChild = true;
			int first = number[0] - '0';
			if (!sub[first]) sub[first] = new Trie();
			sub[first]->insert(number + 1);
		}
	}

	bool consistent()
	{
		if (ter&&hasChild) return false;

		for (int i = 0; i < 10;i++) 
			if (sub[i] && !sub[i]->consistent()) return false;

		return true;
	}
};

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N; scanf("%d", &N);
		Trie* root = new Trie();
		while (N--)
		{
			char pn[11];
			scanf("%s", pn);
			root->insert(pn);
		}
		if (root->consistent())
			printf("YES\n");
		else
			printf("NO\n");

		delete root;
	}
}