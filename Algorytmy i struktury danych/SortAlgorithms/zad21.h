typedef struct dataHolder{
    int data1; //podst
    int data2; //porown
    int indexo;
    struct dataHolder* next;
} dataH;
typedef dataH* dah;

typedef struct sorttype{
    int que; //rodzaj sortowania
    int maxpodst;
    int minpodst;
    int maxporown;
    int minporown;
    struct sorttype* next;
} sortT;
typedef sortT* srt;

void pushEnd(dah *head, int indexo, int data1, int data2);
void srttabadd(srt *head, int que);
void printdane(srt head, dah dhead);
srt sortthesort(srt head, dah dhead, int ctr);
void byebye(dah head);

dah Bubblesort(int *t, int t_size, dah *head);
dah byinsert(int *t, int t_size, dah *head);
dah shellsort(int *t, int t_size, dah *head);
dah quicksort(int *t, int p, int q, dah *head);
int partition_qs(int *t, int p, int q, dah *head);

