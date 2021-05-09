#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TLinkedList.h"

int main(){

  TLinkedList *list = NULL;
  struct aluno temp,*retorno;
  int ret,pos = 1,mat = 4;

  while(1){
    int option;
    print_menu();
    scanf("%d",&option);
    getchar();
    switch(option){
      case 1:
        printf("\n<< CREATE LIST >>\n");
        list = list_create();
        if (list == NULL){
          printf("ERROR!");
          return 0;
        }else{
          printf("List Created with Success!\n");
        }
        break;
      case 2:
        printf("\n<< FREE LIST >>\n");
        ret = list_free(list);
        if (ret == INVALID_NULL_POINTER){
          printf("ERROR!");
          return 0;
        }else{
          if(ret == SUCCESS){
            printf("List Freed with Success!\n");
            list = NULL;
          }
        }
        break;
      case 3:
        printf("\n<< PUSH LIST FRONT >>\n");
        printf("Type Student's Enrolment Number: ");
        scanf("%d",&temp.matricula);
        getchar();
        printf("Type Student's Name: ");
        fgets(temp.nome,30,stdin);
        temp.nome[strcspn(temp.nome, "\n")]='\0';
        printf("Type Student's Grade 1: ");
        scanf("%f",&temp.n1);
        getchar();
        printf("Type Student's Grade 2: ");
        scanf("%f",&temp.n2);
        getchar();
        printf("Type Student's Grade 3: ");
        scanf("%f",&temp.n3);
        getchar();
        ret = list_push_front(list, temp);
        if (ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro");
        else if (ret == OUT_OF_MEMORY)
          printf("Memoria insuficiente");
        else if (ret == SUCCESS)
          printf("Aluno inserido na frente.");
        break;
      case 4:
        printf("\n<< PUSH LIST BACK >>\n");
        printf("Type Student's Enrolment Number: ");
        scanf("%d",&temp.matricula);
        getchar();
        printf("Type Student's Name: ");
        fgets(temp.nome,30,stdin);
        temp.nome[strcspn(temp.nome, "\n")]='\0';
        printf("Type Student's Grade 1: ");
        scanf("%f",&temp.n1);
        getchar();
        printf("Type Student's Grade 2: ");
        scanf("%f",&temp.n2);
        getchar();
        printf("Type Student's Grade 3: ");
        scanf("%f",&temp.n3);
        getchar();
        ret = list_push_back(list, temp);
        if (ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro");
        else if (ret == OUT_OF_MEMORY)
          printf("Memoria insuficiente");
        else if (ret == SUCCESS)
          printf("Aluno inserido no final.");
        break;
      case 5:
        printf("\n<< INSERT LIST >>\n");
        printf("Type Student's Enrolment Number: ");
        scanf("%d",&temp.matricula);
        getchar();
        printf("Type Student's Name: ");
        fgets(temp.nome,30,stdin);
        temp.nome[strcspn(temp.nome, "\n")]='\0';
        printf("Type Student's Grade 1: ");
        scanf("%f",&temp.n1);
        getchar();
        printf("Type Student's Grade 2: ");
        scanf("%f",&temp.n2);
        getchar();
        printf("Type Student's Grade 3: ");
        scanf("%f",&temp.n3);
        getchar();
        ret = list_insert(list,pos,temp);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == OUT_OF_MEMORY)
          printf("Memoria insuficiente\n");
        else if (ret == OUT_OF_RANGE)
          printf("Posicao nao encontrada\n");
        else if (ret == INVALID_POSITION)
          printf("Posicao menor que 1 ou maior que o tamanho\n");
        else if (ret == SUCCESS)
          printf("Aluno inserido na posicao %d\n",pos);
        break;
      case 6:
        printf("\n<< INSERT LIST SORTED >>\n");
        printf("Type Student's Enrolment Number: ");
        scanf("%d",&temp.matricula);
        getchar();
        printf("Type Student's Name: ");
        fgets(temp.nome,30,stdin);
        temp.nome[strcspn(temp.nome, "\n")]='\0';
        printf("Type Student's Grade 1: ");
        scanf("%f",&temp.n1);
        getchar();
        printf("Type Student's Grade 2: ");
        scanf("%f",&temp.n2);
        getchar();
        printf("Type Student's Grade 3: ");
        scanf("%f",&temp.n3);
        getchar();
        ret = list_insert_sorted(list,temp);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == OUT_OF_MEMORY)
          printf("Memoria insuficiente\n");
        else if (ret == SUCCESS)
          printf("Aluno inserido ordenado\n");
        break;
      case 7:
        printf("\n<< SIZE LIST >>\n");
        int tam = list_size(list);
        printf("Tamanho da lista: %d\n", tam);
        break;
      case 8:
        printf("\n<< LIST NODE FRONT >>\n");
        ret = list_pop_front(list);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == SUCCESS)
          printf("Aluno removido da frente\n");
        break;
      case 9:
        printf("\n<< POP NODE BACK >>\n");
        ret = list_pop_back(list);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == SUCCESS)
          printf("Aluno removido do final\n");
        break;
      case 10:
        printf("\n<< ERASE NODE BY ENROLLMENT NUMBER >>\n");
        ret = list_erase_data(list,mat);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == OUT_OF_RANGE)
          printf("Posicao nao encontrada\n");
        else if (ret == INVALID_POSITION)
          printf("Posicao menor que 1\n");
        else if (ret == SUCCESS)
          printf("Matricula %d foi removida com sucesso\n",mat);
        break;
      case 11:
        printf("\n<< ERASE NODE BY POSITION >>\n");
        ret = list_erase_pos(list,pos);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == OUT_OF_RANGE)
          printf("Posicao nao encontrada\n");
        else if (ret == INVALID_POSITION)
          printf("Posicao menor que 1\n");
        else if (ret == SUCCESS)
          printf("Posicao %d foi removida com sucesso\n",pos);
        break;
      case 12:
        printf("\n<< FIND NODE BY POSITION >>\n");
        ret = list_find_pos(list,pos,retorno);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == INVALID_POSITION)
          printf("Posicao menor que 1\n");
        else if (ret == ELEM_NOT_FOUND)
          printf("Lista vazia\n");
        else if (ret == OUT_OF_RANGE)
          printf("Posicao nao encontrada\n");
        else if (ret == SUCCESS)
          printf("O no foi encontrado na posicao %d\n",pos);
        break;
      case 13:
        printf("\n<< FIND NODE BY ENROLLMENT NUMBER >>\n");

        break;
      case 14:
        printf("\n<< LIST FRONT >>\n");
        ret = list_front(list,&retorno);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == ELEM_NOT_FOUND)
          printf("Lista vazia\n");
        else if (ret == SUCCESS)
          printf("Aluno da frente encontrado com sucesso\n");
        break;
      case 15:
        printf("\n<< LIST BACK >>\n");
        ret = list_back(list,&retorno);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == ELEM_NOT_FOUND)
          printf("Lista vazia\n");
        else if (ret == SUCCESS)
          printf("Aluno do final encontrado com sucesso\n");
        break;
      case 16:
        printf("\n<< GET POSITION BY THE ENROLLMENT NUMBER >>\n");

        break;
      case 17:
        printf("\n<< PRINT LIST >>\n");
        ret = list_print(list);
        if(ret == INVALID_NULL_POINTER)
          printf("Erro de ponteiro\n");
        else if (ret == ELEM_NOT_FOUND)
          printf("Lista vazia\n");
        else if (ret == SUCCESS)
          printf("Aluno do final encontrado com sucesso\n");
        break;
      case 18:
        printf("\n<< PRINT NODE >>\n");
        node_print(retorno);
        break;
      case 19:
        printf("\n<<< QUITTING MENU >>>\n");
        printf("          .       \n");
        printf("          .       \n");
        printf("          .       \n");
        if(list != NULL){
          list_free(list);
          list = NULL;
        }
        return 0;
      default:
        printf("\n<< Select an Valid Option >>\nNumber Not Identified\n");
        break;    
          }    
      }
    
    return 0;
}
