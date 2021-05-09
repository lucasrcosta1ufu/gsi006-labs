#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLinkedList.h"

typedef struct list_node list_node;

struct list_node
{
    struct aluno data;
    list_node *next;
};

struct TLinkedList
{
    list_node *head;
};

TLinkedList *list_create()
{
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL)
    {
        list->head = NULL;
    }
    return list;
}

int list_free(TLinkedList *list)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *aux;

        aux = list->head;
        while (aux != NULL)
        {
            list->head = aux->next;
            free(aux);
            aux = list->head;
        }

        // segunda forma
        // while (list->head != NULL)
        // {
        //     aux = list->head;
        //     list->head = list->head->next;
        //     free(aux);
        // }
        free(list);
        return SUCCESS;
    }
}

int list_push_front(TLinkedList *list, struct aluno al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = list->head;
        list->head = node;

        return SUCCESS;
    }
}

int list_push_back(TLinkedList *list, struct aluno al)
{
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
            return OUT_OF_MEMORY;
        node->data = al;
        node->next = NULL;
        if (list->head == NULL)
        { // a lista está vazia
            list->head = node;
        }
        else
        { // a lista tem pelo menos um nó
            list_node *aux;
            aux = list->head;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = node;
        }
        return SUCCESS;
    }
}

int list_insert(TLinkedList *list, int pos, struct aluno al){
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }
    int tamanho;
    tamanho = list_size(list);
    if(pos < 1 || pos > tamanho+1){
        return INVALID_POSITION;
    }

    list_node *node;
    node = malloc(sizeof(list_node));
    if(node == NULL)
        return OUT_OF_MEMORY;
    else{
        node->data = al;
        node->next = NULL;
    }
        
    int cont = 1;
    list_node *currentNode,*previousNode;
    currentNode = list->head;
    previousNode = list->head;
    while(cont < pos){
        previousNode = currentNode;
        currentNode = currentNode->next;
        cont++;
    }
    if(previousNode == currentNode){// mesma coisa pos == 1;
        list->head = node;
        node->next = currentNode;
    }else{
        previousNode->next = node;
        node->next = currentNode;
    }

    return SUCCESS;
}

int list_insert_sorted(TLinkedList *list, struct aluno al){
    if(list == NULL){
        return INVALID_NULL_POINTER;
    }

    list_node *node;
    node = malloc(sizeof(list_node));
    if(node == NULL)
        return OUT_OF_MEMORY;
    else{
        node->data = al;
        node->next = NULL;
    }
    
    list_node *previousNode,*currentNode;
    previousNode = NULL;
    currentNode = list->head;
    if(list->head == NULL){
        list->head = node;
        node->next = NULL;
    }else{
        while(currentNode != NULL && currentNode->data.matricula < node->data.matricula){
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        if(currentNode == list->head){// se esta na primeira posicao da lista
            node->next = currentNode;
            list->head = node;
        }else{
            previousNode->next = node;
            node->next = currentNode;
        }
    }
    return SUCCESS;
    
}

int list_pop_front(TLinkedList *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else{
        list_node *previousNode = NULL,*currentNode = list->head;

        previousNode = currentNode;
        currentNode = currentNode->next;
        free(previousNode);
        list->head = currentNode;

        return SUCCESS;
    }
}

int list_pop_back(TLinkedList *list){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    else{
        list_node *previousNode = NULL,*currentNode = list->head;
        if(currentNode->next == NULL){
            free(currentNode);
            list->head = NULL;
        }else{
            while(currentNode->next != NULL){
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            free(currentNode);
            previousNode->next = NULL;
        }
        

        return SUCCESS;
    }
}

int list_erase_data(TLinkedList *list, int mat){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    int size = list_size(list);
    if(size == 0){
        return OUT_OF_RANGE;
    }else{
        list_node *previousNode = list->head,*aluno = list->head;
        while(aluno->next != NULL && aluno->data.matricula != mat){
            previousNode = aluno;
            aluno = aluno->next;
        }
        if(aluno == NULL){
            return ELEM_NOT_FOUND;
        }else{
            if(size == 1){
                list->head = NULL;
                free(aluno);
            }else{
                previousNode->next = aluno->next;
                free(aluno);
            }
        }
    }
    return SUCCESS;
}

int list_erase_pos(TLinkedList *list, int pos){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    if(pos < 1)
        return INVALID_POSITION;
    int size = list_size(list);
    if(pos > size+1 || size == 0)
        return OUT_OF_RANGE;
    else{
        list_node *tmp = list->head,*previousNode = list->head,*currentNode = list->head;
        int cont = 1;
        while(currentNode->next != NULL && cont < pos){
            previousNode = currentNode;
            currentNode = currentNode->next;
            cont++;
        }
        if(size == 1){
            list->head = NULL;
            free(currentNode);
        }else{
            if(cont == pos){
                previousNode->next = currentNode->next;
                free(currentNode);
            }
        }
        return SUCCESS;
    }
}

int list_find_pos(TLinkedList *list, int pos, struct aluno *al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    if(pos < 1)
        return INVALID_POSITION;
    int size = list_size(list);
    if(pos > size+1)
        return OUT_OF_RANGE;
  
    if(size == 0){
        return ELEM_NOT_FOUND;
    }else{
        int cont = 1;
        list_node *previousNode = list->head,*currentNode = list->head;
        while(cont < pos){
            previousNode = currentNode;
            currentNode = currentNode->next;
            cont++;
            
        }
        if(cont == pos){
           al = &previousNode->data;
        }
        return SUCCESS;
    }
}



int list_front(TLinkedList *list, struct aluno **al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    if(list->head == NULL) // Lista vazia
        return ELEM_NOT_FOUND;
    else{
        *al = &list->head->data;
        return SUCCESS;
    }
    
}

int list_back(TLinkedList *list, struct aluno **al){
    if(list == NULL)
        return INVALID_NULL_POINTER;
    if(list->head == NULL) // Lista vazia
        return ELEM_NOT_FOUND;
    else{
        list_node *temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(temp->next == NULL){
            *al = &temp->data;
        }
        return SUCCESS;
    }
}

void node_print(struct aluno *al){
    printf("\nImprimindo a lista\n");

    printf("\n------------------\n");
    printf("Matricula: %d\n", al->matricula);
    printf("Nome: %s\n", al->nome);
    printf("Notas: %f; %f; %f;\n", al->n1, al->n2, al->n3);

    printf("\nFim da lista \n");
}

int list_print(TLinkedList *list)
{
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    int size = list_size(list);
    if(size == 0)
        return ELEM_NOT_FOUND;
    else
    {
        list_node *aux;
        aux = list->head;
        printf("\nImprimindo a lista\n");

        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da lista \n");
    }
    return SUCCESS;
}

int list_size(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        int contador = 0;
        list_node *aux;
        aux = list->head;
        while (aux != NULL)
        {
            aux = aux->next;
            contador = contador + 1;
        }
        return contador;
    }
}

void print_menu(){
    printf("\n<<< LINKED LIST >>>\n");
    printf("1 - Create List\n");
    printf("2 - Free List\n");
    printf("3 - Push List Front\n");
    printf("4 - Push List Back\n");
    printf("5 - Insert List\n");
    printf("6 - Insert List Sorted\n");
    printf("7 - Size List\n");
    printf("8 - Pop Node Front\n");
    printf("9 - Pop Node Back\n");
    printf("10 - Erase Node by Enrollment Number\n");
    printf("11 - Erase Node by Position\n");
    printf("12 - Find Node by Position\n");
    printf("13 - Find Node by Enrollment Number\n");
    printf("14 - List Front\n");
    printf("15 - List Back\n");
    printf("16 - Get Position by the Enrollment Number\n");
    printf("17 - Print List\n");
    printf("18 - Print Node\n");
    printf("19 - Quit Menu\n");
    printf("\nSelect an option: ");
}

