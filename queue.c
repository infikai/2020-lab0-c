#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) {
        printf("Error! Allocation was failed. \n");
        return q;
    } else {
        q->head = NULL;
        q->tail = NULL;  // Add for the q_insert_tail
        q->size = 0;
        return q;
    }
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (q != NULL) {
        list_ele_t *next;
        while (q->head != NULL) {
            next = q->head->next;
            free(q->head->value);
            free(q->head);
            q->head = next;
        }
        free(q);
    }
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (q != NULL) {
        list_ele_t *newh;
        newh = malloc(sizeof(list_ele_t));
        if (newh != NULL) {
            int length;
            length = strlen(s) + 1;
            newh->value = malloc(length * sizeof(char));
            if (newh->value != NULL) {
                memcpy(newh->value, s, length);
                newh->next = q->head;
                if (q->size == 0) {
                    q->tail = newh;
                }
                q->head = newh;
                q->size++;
                return true;
            } else {
                free(newh);
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    if (q != NULL) {
        list_ele_t *newt;
        newt = malloc(sizeof(list_ele_t));
        if (newt != NULL) {
            int length;
            length = strlen(s) + 1;
            newt->value = malloc(length * sizeof(char));
            if (newt->value != NULL) {
                memcpy(newt->value, s, length);
                if (q->size == 0) {
                    q->head = newt;
                } else {
                    q->tail->next = newt;
                }
                q->tail = newt;
                newt->next = NULL;
                q->size++;
                return true;
            } else {
                free(newt);
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (q->size != 0) {
        if (sp != NULL) {
            memcpy(sp, q->head->value, bufsize - 1);
            sp[bufsize - 1] = '\0';
        }
        list_ele_t *next;
        next = q->head->next;
        free(q->head->value);
        free(q->head);
        q->head = next;
        if (q->size == 1) {
            q->tail = NULL;
        }
        q->size--;
        return true;
    } else {
        return false;
    }
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    return (q == NULL) ? 0 : q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
