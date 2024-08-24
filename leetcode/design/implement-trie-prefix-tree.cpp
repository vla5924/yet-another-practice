// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <set>
#include <string>
#include <string_view>
#include <unordered_set>

using namespace std;

class Trie {
    struct Node {
        Node *children[26] = {0};
        bool terminal = false;
    };
    Node *root;

  public:
    Trie() { root = new Node; }

    void insert(string word) {
        Node *curr = root;
        for (char c : word) {
            Node *&next = curr->children[c - 'a'];
            if (next == nullptr)
                next = new Node;
            curr = next;
        }
        curr->terminal = true;
    }

    bool search(string word) {
        Node *curr = root;
        for (char c : word) {
            Node *next = curr->children[c - 'a'];
            if (next == nullptr)
                return false;
            curr = next;
        }
        return curr->terminal;
    }

    bool startsWith(string prefix) {
        Node *curr = root;
        for (char c : prefix) {
            Node *next = curr->children[c - 'a'];
            if (next == nullptr)
                return false;
            curr = next;
        }
        return true;
    }
};

namespace lazy {
class Trie {
    set<string> prefixes;
    unordered_set<string_view> words;

  public:
    Trie() {}

    void insert(string word) {
        if (search(word))
            return;
        auto hint = prefixes.insert(word).first;
        string_view wview(*hint);
        auto wbegin = word.begin();
        for (int i = word.size() - 1; i > 0; i--) {
            hint = prefixes.emplace_hint(hint, wbegin, wbegin + i);
        }
        words.insert(wview);
    }

    bool search(string word) { return words.contains(string_view(word)); }

    bool startsWith(string prefix) { return prefixes.contains(prefix); }
};
} // namespace lazy

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() { return 0; }
