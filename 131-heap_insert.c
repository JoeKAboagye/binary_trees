#include "binary_trees.h"

/**
* heap_insert - inserts a value in Max Binary Heap
* @root: double pointer to the root node of the Heap to insert the value
* @value: value to store in the node to be inserted
* Return: root
*/
heap_t *heap_insert(heap_t **root, int value)
{
	(void) value;
	if (!root || !*root)
		return (NULL);
	return (*root);
}
