#include<stdio.h>
#include<stdlib.h>

struct node {
  void* payload;
  struct node *previous;
  struct node *next;
};

struct list {
  struct node *first;
  struct node *last;
};

struct node* create_new_node(void* payload, struct node* previous, struct node* next) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->payload = payload;
  new_node->previous = previous;
  new_node->next = next;
  return new_node;
}

void add_first_node(void* payload, struct list* list) {
  struct node* new_node = create_new_node(payload, NULL, NULL);
  list->first = new_node;
  list->last = new_node;
}

void add_to_front(void* payload, struct list* list) {
  if(list->first == NULL && list->last == NULL) {
    add_first_node(payload, list);
    return;
  }
  struct node* current_first_node = list->first;
  struct node* new_node = create_new_node(payload, NULL, current_first_node);
  current_first_node->previous = new_node;
  list->first = new_node;
}

void add_to_back(void* payload, struct list* list) {
  if(list->first == NULL && list->last == NULL) {
    add_first_node(payload, list);
    return;
  }
  struct node* current_last_node = list->last;
  struct node* new_node = create_new_node(payload, current_last_node, NULL);
  current_last_node->next = new_node;
  list->last = new_node;
}

void* remove_from_front(struct list* list) {
  struct node* node_to_remove = list->first;
  void* payload = node_to_remove->payload;
  list->first = node_to_remove->next;
  free(node_to_remove);
  return payload;
}

void* remove_from_back(struct list* list) {
  struct node* node_to_remove = list->last;
  void* payload = node_to_remove->payload;
  list->last = node_to_remove->previous;
  free(node_to_remove);
  return payload;
}

void transfer(int input[], int length, void (*insert)(void*, struct list*), void* (*remove)(struct list*), int output[]) {
  struct list* list = (struct list*)malloc(sizeof(struct list));
  list->first = NULL;
  list->last = NULL;
  int i;
  for(i=0; i<length; i++) {
    (*insert)((void *) input[i], list);
  }
  for(i=0; i<length; i++) {
    output[i] = (int)(*remove)(list);
  }
  free(list);
}

int main() {
  printf("Starting Test 1 (add_to_front, remove_from_front):\n");
  int input_array[]={1,2,3,4,5,6,7,8,9};
  int output_array[9];

  transfer(input_array, 9, add_to_front, remove_from_front, output_array);

  int i;
  for(i=0; i<9; i++) {
    printf("%i", output_array[i]);
  }

  printf("\nStarting Test 2 (add_to_back, remove_from_front):\n");
  transfer(input_array, 9, add_to_back, remove_from_front, output_array);

  for(i=0; i<9; i++) {
    printf("%i", output_array[i]);
  }

  printf("\nStarting Test 3 (add_to_front, remove_from_back):\n");
  transfer(input_array, 9, add_to_front, remove_from_back, output_array);

  for(i=0; i<9; i++) {
    printf("%i", output_array[i]);
  }

  printf("\nStarting Test 4 (add_to_back, remove_from_back):\n");
  transfer(input_array, 9, add_to_back, remove_from_back, output_array);

  for(i=0; i<9; i++) {
    printf("%i", output_array[i]);
  }

  printf("\n");

  return 0;
}
