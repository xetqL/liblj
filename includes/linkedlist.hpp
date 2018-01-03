struct linkedlist_t {
    float value;
    linkedlist_t* next;
};

void insert_front(float value, linkedlist_t **head);

void push_back(float value, linkedlist_t *head);

void free_linkedlist(linkedlist_t *list);

void print_linkedlist(linkedlist_t *list);

float pop(linkedlist_t **head);
