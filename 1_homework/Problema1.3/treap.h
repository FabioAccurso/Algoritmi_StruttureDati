#ifndef TREAP_H
#define TREAP_H
#include <iostream>
using namespace std;
template <typename Key, typename Priority> class TREAP;

template<typename Key, typename Priority>
class TREAPNode{
public:
    //Costruttore della classe TREAPNode
    TREAPNode(Key k, Priority v, TREAPNode<Key, Priority> *p = nullptr, TREAPNode<Key, Priority> *l = nullptr, TREAPNode<Key, Priority> *r = nullptr)
    : key(k), priority(v), left(l), right(r), parent(p) {}
    //La classe TREAP è stata dichiarata come classe amica e quindi avrà accesso ai membri privati della classe TREAPNode
    friend class TREAP<Key, Priority>;
private:
    Key key;
    Priority priority;
    TREAPNode<Key, Priority> *left;
    TREAPNode<Key, Priority> *right;
    TREAPNode<Key, Priority> *parent;
};

template<typename Key, typename Priority>
class TREAP{
protected:
    TREAPNode<Key, Priority> *root;
public:
    TREAP(TREAPNode<Key, Priority>* r = NULL): root(r) {}

    //Traverse
    void inorderTreeWalk(TREAPNode<Key, Priority> *x);
    void inorderTreeWalk() {inorderTreeWalk(root);}

    //Accessors
    TREAPNode<Key, Priority>* search(Key key);
    TREAPNode<Key, Priority>* search(TREAPNode<Key, Priority> *x, Key key);

    //Modifiers
    void rotation(TREAPNode<Key, Priority> *z);
    TREAPNode<Key, Priority>* insert(Key key, Priority priority); //if return NULL, the key already exists
};

template<typename Key, typename Priority>
void TREAP<Key, Priority>::inorderTreeWalk(TREAPNode<Key, Priority> *x){
    if(x){
        inorderTreeWalk(x->left);
        if(x==root) cout<<"[Root] ";
        cout<<"Key: "<<x->key<<", Priority: "<<x->priority<<"\n";
        if(x->left) cout << "     | Left Child: " <<"("<< x->left->key <<"," << x->left->priority << ")\n";
        if(x->right) cout << "     | Right Child: "<<"("<<x->right->key<<"," << x->right->priority << ")\n";
        inorderTreeWalk(x->right);
    }
}

template<typename Key, typename Priority>
TREAPNode<Key, Priority>* TREAP<Key, Priority>::search(TREAPNode<Key, Priority> *x, Key key){
    while(x){
        if(x->key == key) break;
        else if (x->key < key) x = x->right;
        else x = x->left;
    }
    return x;
}

template<typename Key, typename Priority>
TREAPNode<Key, Priority>* TREAP<Key, Priority>::search(Key key){
    return search(root, key);
}

template<typename Key, typename Priority>
TREAPNode<Key, Priority>* TREAP<Key, Priority>::insert(Key key, Priority priority){
    if(search(key)) return nullptr;
    TREAPNode<Key, Priority> *x = root;
    TREAPNode<Key, Priority> *y = nullptr;
    TREAPNode<Key, Priority> *z = new TREAPNode<Key, Priority>(key, priority);
    //Ricerca la posizione del nuovo nodo; y punta sempre al padre di x
    //Qui individuiamo "solo" quale sia il padre di z
    while(x){
        y=x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    //L'albero potrebbe essere vuoto
    if(y == nullptr){
        root = z;
    }
    //Inserisce x come figlio destro o sinistro di y in base a key[z]
    //Qui invece specifichiamo se z sarà figlio dx o sx rispetto al padre
    else{
        if(z->key < y->key){
            y->left = z;
        }
        else{
            y->right = z;
        }
        if(z->priority < z->parent->priority) rotation(z);
    }
    return z;
}

template<typename Key, typename Priority>
void TREAP<Key, Priority>::rotation(TREAPNode<Key, Priority> *z){
    TREAPNode<Key, Priority> *y = z->parent;
    //Condizione per verificare se il nodo z è nel lato destro dell'albero
    if(y->key < z->key){
        //Il figlio destro di y non sarà più z, bensì sarà il figlio sinistro di z
        y->right = z->left;
        if(z->left != nullptr){
            //Se z ha figlio sinistro allora il padre di quest'ultimo sarà y e non più z
            z->left->parent = y;
        }
        //Il nuovo figlio sinistro di z è y
        z->left = y;
    }
    //Condizione per verificare se il nodo z è nel lato sinistro dell'albero
    else{
        //Il figlio sinistro di y non sarà più z, bensì sarà il figlio destro di z
        y->left = z->right;
        if(z->right != nullptr){
            //Se z ha figlio destro allora il padre di quest'ultimo sarà y e non più z
            z->right->parent = y;
        }
        //Il nuovo figlio destro di z è y
        z->right = y;
    }
    //Il nuovo padre di z è il padre di y
    z->parent = y->parent;

    if(y->parent != nullptr){
        if(y == y->parent->left) y->parent->left = z; //Se y era figlio sinistro di suo padre allora il nuovo figlio sinistro del padre di y è z
        else y->parent->right = z; //Se invece y era figlio destro di suo padre allora il nuovo figlio destro del padre di y è z
    }

    else{
        root = z;
    }
    //Infine il padre di y diventa effettivamente z
    y->parent = z;

    if (z->parent != nullptr && z->priority < z->parent->priority) {
        rotation(z);
    }
}

#endif

