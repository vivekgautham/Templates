#include "header.h"
#include "trie.h"
int main()
{
	std::string k("hello");
	Trie<char> t;
	t.insert(k.begin(), k.end());

}
