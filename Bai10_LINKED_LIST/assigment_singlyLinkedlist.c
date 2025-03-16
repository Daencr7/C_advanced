#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    struct node* next;
}node;

node *createNode(int value); 
void push_back(node** array, int value); 
void push_front(node **array, int value); // them 1 node vao phia truoc
void pop_back(node **array); 
void pop_front(node **array); // xoa node dau tien
int front(node *array); // lay gia tri cua node dau tien
int back(node *array); // lay gia tri cua node cuoi cung
void insert(node **array, int value, int pos); // them 1 node vao mot vi tri bat ky
void erase(node **array, int pos); // xoa 1 node tai mot vi tri bat ky
int size(node *array); // lay kich thuoc cua list
int get(node *array, int pos); 
int empty(node *array); // kiem tra list co rong hay khong
void clear(node **head); // xóa toàn bộ node

node* createNode(int value){
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
int len(node *array){
    int dem = 0;
    while(array != NULL){
        ++dem;
        array = array->next; // cho head chuyen sang node ke tiep
    }
    return dem;
}
void push_front(node** array, int value){
    node* newNode = createNode(value);
    newNode->value = value;
    newNode->next = NULL;
    newNode->next = (*array);
    (*array) = newNode;
}
void push_back(node** array, int value){
    node* temp;
    temp = createNode(value); // khoi tao node

    if (*array == NULL){
        *array = temp;
    }
    else {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL){
            p = p->next;    // check next node until it a last node
        }
        p->next = temp;     // change it next member point to address of new node have just create
    }
}

void pop_back(node** array){
    node* p, * temp;
    p = *array;
    int i = 0; // to 

    while (p->next->next != NULL){
        p = p->next;
        i++;
    }
    temp = p->next;
    p->next = NULL;
    free(temp);
}
void pop_front (node **array){
    if(*array == NULL) return;
    node *delete = *array;
    *array = (*array)->next;
    free(delete);
}
int front (node* array){
    if(array == NULL) return -1;
    return (*array).value;
}
int back (node* array){
    if(array == NULL) return -1;
    node* run = array;
    for(;run->next!=NULL;run = run->next){}
    return run->value;
}
void insert(node **array, int value, int pos){
    int n = len(*array);
    if(pos < 1 || pos > n + 1){
        printf("ERROR POSITION!\n");
        return;
    }
    node *newNode = createNode(value);
    if(pos == 1){
        push_front(array, pos); return;
    }
    else{
        node *tmp = *array;
        for(int i = 1; i < pos - 1; i++){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}
void erase (node **array, int pos){
    if(pos < 1 || pos > len(*array)) return;
    if(pos==1){
        pop_front(array);
    }
    else{
        node* tmp = (*array);
        for(int i = 1; i <=pos-2; i++){
            tmp = tmp->next;
        }
        node* p = tmp->next;
        tmp->next = p->next;
        free(p);
    }
}
int size(node *array){
    if(array == NULL) return 0;
    node* run = array;
    int cnt = 0;
    for(;run->next!=NULL;run = run->next){++cnt;}
}
int get(node* array, int pos){
    int i = 0;
 
    while (array->next != NULL && pos != i){
        array = array->next;
        i++;
    }
    if (pos != i){
        printf("Error: List has less element\n");
        return 0;
    }

    int value = array->value;
    return value;
}

int empty(node* array){
    if(array==NULL) return 1;
    return 0;
}


// void clear(node** head){

// }


int main(){
    node* arr = NULL;
    // push_back(&arr, 2);
    // push_back(&arr, 7);
    // push_back(&arr, 4);
    // push_back(&arr, 5);
    // push_back(&arr, 3);
    // push_back(&arr, 10);

    // printf("Value test: %d\n", get(arr, 2));
    // printf("Value test: %d\n", get(arr, 0));
    // printf("Value test: %d\n", get(arr, 5));
	return 0;
}
