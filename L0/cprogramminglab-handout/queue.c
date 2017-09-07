/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if(q==NULL)
        return NULL;
    q->tail = NULL;
    q->head = q->tail;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements? */
    /* Free queue structure */
    
    list_ele_t *temp;
    list_ele_t *temp1;
    if(q==NULL)
        exit(0);
    temp=q->head;
    if(temp)
    temp1=temp->next;
    free(q);

    while(temp)
    {
        free(temp);
        if(temp1)
            temp=temp1;
        else
            break;
        temp1=temp->next;
    }
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if(q==NULL)
        return false;
    newh = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if(newh==NULL)
        return false;
    newh->value = v;
    if(q->size!=0)
    {
        newh->next = q->head;
        q->head = newh;
        q->size++;
    }
    else
    {
        newh->next=NULL;
        q->head = newh;
        q->tail = newh;
        q->size++;
    }
    
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *newt;
    /* What should you do if the q is NULL? */
    if(q==NULL)
        return false;
    newt = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if(!newt)
        return false;
    newt->value = v;
    newt->next = NULL;
    if(q->size!=0)
    {
        q->tail->next = newt;
        q->tail = newt;
        q->size++;    
    }
    else
    {
        q->head = newt;
        q->tail = newt;
        q->size++;
    }
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* You need to fix up this code. */
    if(!q||q->size==0||vp==NULL)
        return false;
    list_ele_t *temp = q->head;
    *vp = temp->value;
    q->head = q->head->next;
    free(temp);
    q->size--;
    if(q->size==0)
        q->tail=NULL;
    return true;
}

int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->size;
}

/*
  Reverse elements in queue
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    list_ele_t *temp;
    list_ele_t *temp1;
    list_ele_t *tail=q->head;
    temp=q->head;
    q->head=NULL;
    while(temp)
    {
        temp1=temp->next;
        temp->next=q->head;
        q->head=temp;
        temp=temp1;
    }
    q->tail=tail;
}

