#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define INVALID_POSITION -5

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct TLinkedList TLinkedList;

TLinkedList *list_create(); //Done
int list_free(TLinkedList *list); //Done

int list_push_front(TLinkedList *list, struct aluno al); //Done
int list_push_back(TLinkedList *list, struct aluno al); //Done

int list_insert(TLinkedList *list, int pos, struct aluno al); //Done
int list_insert_sorted(TLinkedList *list, struct aluno al); //Done
int list_size(TLinkedList *list); //Done


int list_pop_front(TLinkedList *list); //Done
int list_pop_back(TLinkedList *list); //Done
int list_erase_data(TLinkedList *list, int mat); //Done
int list_erase_pos(TLinkedList *list, int pos); //Not Done

int list_find_pos(TLinkedList *list, int pos, struct aluno *al); //Done
int list_find_mat(TLinkedList *list, int nmat, struct aluno *al);
int list_front(TLinkedList *list, struct aluno **al); //Done
int list_back(TLinkedList *list, struct aluno **al); //Done
int list_front(TLinkedList *list, struct aluno *al);
int list_get_pos(TLinkedList *list, int nmat, int *pos);
int list_print(TLinkedList *list); //Done
void node_print(struct aluno *al); //Done
void print_menu();
