#include <stdio.h>
#include "binarTree.h"

node work;

int main() {
    insert(&work,"siema");
    insert(&work,"aiema");
    insert(&work,"ziema");
    insert(&work,"yiema");
    insert(&work,"niema");
    removeNode(&work,"yiema");
    printf("%s\n", ancestor(work));
    printf("%s\n\n", descendant(work));
    printTree(work);
}
