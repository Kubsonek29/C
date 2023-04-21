typedef struct listNode
{
    int data;
    struct listNode* next;
    struct listNode* prev;
} doublyLinkedListNode;

typedef doublyLinkedListNode* node;

// ZADANIE 10 dla listy dwukierunkowej cyklicznej
void push(node* head, int value); // dodawanie na początek listy
void pushEnd(node* head, int value); // dodawanie na koniec listy
void pop(node* head); // usuwanie pierwszego elementu listy
void popEnd(node* head); // usuwanie ostatniego elementu listy
node find(node head, int value); // odszukaj zadany element
void pushBefore(node *head, node current, int val); // dodaj element przed wskazanym !!!zmieniono definicje funkcji
void pushAfter(node *head, node current, int val); // dodaj za wskazanym elementem !!!zmieniono definicje funkcji
void removeNode(node* head, node current); // usuń wskazany element
node readFromFile(char* fname); // wczytaj zawartość listy z pliku
int saveToFile(node head, char* fname); // zapisz zawartość listy do pliku