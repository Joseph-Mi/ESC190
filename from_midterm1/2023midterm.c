#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
int data;
struct node *next;
} node;
typedef struct LL{
node *head;
int size;
} LL;
// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_elem)
{
    node *last = malloc(sizeof(node));
    node *current = malloc(sizeof(node));

    last->data = new_elem;
    last->next = NULL;

    if (my_list->size == 0){
        my_list->head = last;
        my_list->size++;
        return;
    }

    current = my_list->head;
    
    while (current->next != NULL){
        current = current->next;
    }
    my_list->size++;
    current->next = last;
}

char *strcat_rec(char *dest, const char *src)
{
    if (src[0] == '\0'){
        return dest;
    } else{
        //dest[strlen(src)] = src[0];
        //dest[strlen(src) + 1] = '\0'
        if (dest[0] != '\0'){
            return strcat_rec(dest + 1, src);
        }
        else{
            dest[0] = src[0];
            dest[1] = '\0';
            return strcat_rec(dest + 1, src + 1);
        }
    }

}

typedef struct daylight{
    int hours;
    int minutes;
} daylight;

void create_daylight_pt_block(daylight ***block , int *data, int n)
{
    *block = (daylight**)malloc(sizeof(daylight *) * n/2);

    for (int i = 0; i < n/2; i++){
        (*block)[i] = (daylight*)malloc(sizeof(daylight));
        (*block)[i]->hours = data[i * 2];
        (*block)[i]->minutes = data[i * 2 + 1];
    }
}

int main(){
    // char one[100] = "12345";
    // char *two = "678";
    // strcat_rec(one, two);

    // printf("%s", one);

    int data[4] = {11, 29, 12, 9};
    daylight **block1;
    create_daylight_pt_block(&block1, data, 4);
    printf("%d\t%d\n", (block1)[0]->hours, (block1)[0]->minutes);
    printf("%d\t%d\n", (block1)[1]->hours, (block1)[1]->minutes);
}