#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <list>
#include <cassert>
using namespace std;

#define ll long long
#define pb push_back
#define loop(a) for(int i = 0; i < a; i++)
#define loopv(i,a) for (int i = 0; i < a; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

class BST {
    struct node {
        int bf;
        int value;
        int children;
        int height;
        node* left;
        node* right;
    };

    node* root;
    int node_count;

    node* new_node(int value) {
        node* t = new node;

        t->bf = 0;
        t->value = value;
        t->children = 0;
        t->height = 0;
        t->left = NULL;
        t->right = NULL;

        return t;
    }

    node* insert(node* t, int value) {
        if (t == NULL) {
            return new_node(value);
        }

        if (value < t->value) {
            t->left = insert(t->left, value);
            t->children++;
        } else if (value > t->value) {
            t->right = insert(t->right, value);
            t->children++;
        }

        update(t);

        return balance(t);
    }

    void update(node* t) {
        int lh = t->left == NULL ? -1 : t->left->height;
        int rh = t->right == NULL ? -1 : t->right->height;

        int lc = t->left == NULL ? 0 : 1 + t->left->children;
        int rc = t->right == NULL ? 0 : 1 + t->right->children;

        t->height = 1 + max(lh, rh);
        t->bf = rh - lh;
        t->children = rc + lc;
    }

    node* balance(node* t) {
        if (t->bf == -2) {
            if (t->left->bf <= 0) {
                return left_left_case(t);
            } else {
                return left_right_case(t);
            }
        } else if (t->bf == 2) {
            if (t->right->bf >= 0) {
                return right_right_case(t);
            } else {
                return right_left_case(t);
            }
        }

        return t;
    }

    node* left_left_case(node* t) {
        return right_rotation(t);
    }

    node* left_right_case(node* t) {
        t->left = left_rotation(t->left);
        return left_left_case(t);
    }

    node* right_right_case(node* t) {
        return left_rotation(t);
    }

    node* right_left_case(node* t) {
        t->right = right_rotation(t->right);
        return right_right_case(t);
    }

    node* left_rotation(node* t) {
        node* parent = t->right;

        int rc = t->right == NULL ? 0 : t->right->children;
        int pc = parent->left == NULL ? 0 : parent->left->children;

        t->children -= rc;
        t->right = parent->left;
        t->children += pc;
        parent->children -= pc;
        parent->left = t;
        parent->children += t->children;

        update(t);
        update(parent);

        return parent;
    }

    node* right_rotation(node* t) {
        node* parent = t->left;

        int lc = t->left == NULL ? 0 : t->left->children;
        int pc = parent->right == NULL ? 0 : parent->right->children;

        t->children -= lc;
        t->left = parent->right;
        t->children += pc;
        parent->children -= pc;
        parent->right = t;
        parent->children += t->children;

        update(t);
        update(parent);

        return parent;
    }

    node* remove(node* t, int value) {
        if (t == NULL) {
            return NULL;
        }

        if (value < t->value) {
            t->left = remove(t->left, value);
            t->children--;
        } else if (value > t->value) {
            t->right = remove(t->right, value);
            t->children--;
        } else {
            if (t->left == NULL) {
                return t->right;
            } else if (t->right == NULL) {
                return t->left;
            } else {
                if (t->left->height > t->right->height) {
                    int m = find_max(t->left);
                    t->value = m;
                    t->left = remove(t->left, m);
                    t->children--;
                } else {
                    int m = find_min(t->right);
                    t->value = m;
                    t->right = remove(t->right, m);
                    t->children--;
                }
            }
        }

        update(t);

        return balance(t);
    }

    int find_min(node* t) {
        while (t->left != NULL) t = t->left;
        return t->value;
    }

    int find_max(node* t) {
        while (t->right != NULL) t = t->right;
        return t->value;
    }

    int find_by_order(node* t, int pos) {
        int lc = t->left == NULL ? 0 : 1 + t->left->children;

        if (pos < lc) {
            return find_by_order(t->left, pos);
        }

        if (pos > lc) {
            return find_by_order(t->right, pos - lc - 1);
        }

        return t->value;
    }

    void print(string prefix, node* t, bool is_left) {
        if (t == NULL) return;

        cout << prefix;
        cout << (is_left ? "├──" : "└──" );
        cout << t->value << "(" << t->children << ")" << endl;

        print(prefix + (is_left ? "│   " : "    "), t->left, true);
        print(prefix + (is_left ? "│   " : "    "), t->right, false);
    }

public:
    BST() {
        root = NULL;
        node_count = 0;
    }

    int size() {
        return node_count;
    }

    bool empty() {
        return node_count == 0;
    }

    void insert(int value) {
        root = insert(root, value);
        node_count++;
    }

    void remove(int value) {
        root = remove(root, value);
        node_count--;
    }

    int find_by_order(int pos) {
        return find_by_order(root, pos);
    }

    void print() {
        cout << "-----------------" << endl;
        print("", root, false);
        cout << "-----------------" << endl;
    }
};

int main(void) {
    ll n, k;
    cin >> n >> k;

    auto tree = new BST();

    for (int i = 1; i <= n; i++) {
        tree->insert(i);
    }

    //tree->print();

    ll pos = 0;
    while (!tree->empty()) {
        pos = (pos + k) % tree->size();
        int x = tree->find_by_order(pos);
        cout << x << " ";
        tree->remove(x);
        //tree->print();
    }

    cout << endl;

    return 0;
}
