#include "treap.h"
#include <iostream>

int main(){
    TREAP<string, int> T;
    T.insert("A",10);
    T.insert("E",23);
    T.insert("B",7);
    T.insert("I",73);
    T.insert("K",65);
    T.insert("H",5);
    T.insert("G",4);

    T.insert("C",25);
    T.insert("D",9);
    T.insert("F",2);
    
    T.inorderTreeWalk();
}