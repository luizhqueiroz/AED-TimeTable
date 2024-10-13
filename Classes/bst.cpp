#include "bst.h"

Bst::Bst() {
    root = nullptr;
    size = 0;
}

void Bst::insert (const Estudante &est) {
    bstree_node *node = new struct bstree_node;

    node->est = est;
    node->left = node->right = node->parent = nullptr;

    if(isEmpty()) {
        root = node;
    } else {
        insert(node, root);
    }
    size++;
}

void Bst::insert(struct bstree_node *new_node, struct bstree_node *node) {

    if(new_node->est.getName() < node->est.getName()) {
        if(!node->left) {
            node->left = new_node;
            new_node->parent = node;
        } else {
            insert(new_node, node->left);
        }


    } else if(new_node->est.getName() > node->est.getName()) {
        if(!node->right) {
            node->right = new_node;
            new_node->parent = node;
        } else {
            insert(new_node, node->right);
        }
    }
}

struct bstree_node* Bst::searchName (const string &name) {
    return searchName(name, root);
}

struct bstree_node* Bst::searchName(const string &name, struct bstree_node *node) {

    if (!node || name == node->est.getName()) {
        return node;
    }

    else if(name < node->est.getName()) {
        return searchName(name, node->left);
    }

    else return searchName(name, node->right);
}

struct bstree_node* Bst::minimum(struct bstree_node *tree_root) {
    struct bstree_node *node = (!tree_root) ? root : tree_root;

    while (node->left != nullptr)
        node = node->left;

    return node;
}

struct bstree_node* Bst::maximum(struct bstree_node *tree_root) {
    struct bstree_node *node = (!tree_root) ? root : tree_root;

    while (node->right != nullptr)
        node = node->right;

    return node;
}

void Bst::splice(struct bstree_node *source, struct bstree_node *target) {
    if(!source->parent){
        root = target;
    }

    else if(source->parent->left == source) {
        source->parent->left = target;
    }

    else {
        source->parent->right = target;
    }

    if(target != nullptr) {
        target->parent = source->parent;
    }
}

bool Bst::remove(const string &name) {
    struct bstree_node *node = searchName(name, root);

    if(!node) return false;

    if(!node->left) {
        splice(node, node->right);
    }

    else if(!node->right) {
        splice(node, node->left);
    }

    else {
        struct bstree_node *min = minimum(node->right);
        if(min->parent != node) {
            splice(min, min->right);
            min->right = node->right;
            min->right->parent = min;
        }

        splice(node, min);
        min->left = node->left;
        min->left->parent = min;
    }

    size--;
    return true;
}

bool Bst::isEmpty() const{
    return (size <= 0);
}

int Bst::sizeTree() const{
    return size;
}

struct bstree_node* Bst::rootTree(){
    return root;
}

void Bst::inOrder(bstree_node *node) {
    if(!node) return;

    inOrder(node->left);
    cout << "Nome: ";
    cout << setiosflags(ios::left) << setw( 25 ) << node->est.getName();
    cout << "\tCódigo: " << setw( 12 )  << node->est.getStudentCode() << endl;
    inOrder(node->right);
}

void Bst::preOrder(bstree_node *node) {
    if(!node) return;

    cout << node->est.getName() << endl;
    preOrder(node->left);
    preOrder(node->right);
}

void Bst::postOrder(bstree_node *node) {
    if(!node) return;

    postOrder(node->left);
    postOrder(node->right);
    cout << node->est.getName() << endl;
}


Bst::~Bst(){
    destroy(root);
}

void Bst::destroy(struct bstree_node *node) {
    if(!node) return;

    destroy(node->left);

    if(!node->left && !node->right) {
        if(node->parent->left == node) {
            node->parent->left = nullptr;
        } else {
            node->parent->right = nullptr;
        }
        free(node);

    } else destroy(node->right);
}

void Bst::estudMaisNAlf(bstree_node* node,int n) {
    if (!node) return;

    estudMaisNAlf(node->left, n);

    unsigned nuc = node->est.getHorario().getAulas().size();
    if (nuc > n) cout << "Nome: " << setiosflags(ios::left) << setw( 25 ) << node->est.getName()
    << "\tCódigo: " << setw( 8 )  << node->est.getStudentCode() << "\tNúmero de UCs: " << nuc << endl;

    estudMaisNAlf(node->right,n);
}

void Bst::estudMaisNUCs(bstree_node* node, int n, list<pair<Estudante,int>> &estds) {
    if (!node) return;

    unsigned nuc;
    if (node->left) estudMaisNUCs(node->left, n, estds);

    nuc = node->est.getHorario().getAulas().size();
    if (nuc > n) {
        if (estds.empty()) estds.emplace_back(node->est,nuc);
        else {
            auto it = estds.begin();
            for (; it != estds.end(); it++) {
                if (nuc > it->second) {
                    estds.insert(it,make_pair(node->est,nuc));
                    break;
                }
                else if (nuc == it->second) {
                    auto iter = it;
                    while (nuc == iter->second) {
                        iter++;
                    }
                    estds.insert(iter, make_pair(node->est, nuc));
                    break;
                }
            }
            if (it == estds.end()) estds.emplace_back(node->est,nuc);
        }
    }

    if (node->right) estudMaisNUCs(node->right, n, estds);
}

