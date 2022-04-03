#include <malloc.h>


typedef int elem_type;


typedef struct node_t {

    struct node_t *left;
    struct node_t *right;

    elem_type data;

} node;


struct tree_t {

    struct node_t *head;
    int size;

};


node *create_node(elem_type data)
{
    node* new_elem;
    new_elem = (node*)calloc(1, sizeof(node));

    new_elem->data = data;

    return new_elem;
}
