/***********************************************************************************************
* Fifo.h
*
* Programming Team:
* Sean Markus
* Wing-Sea Poon
* Abigail Smith
* Tabi Stein
*
* Date: 1/22/16
*
* Description:
* This header file defines the class and methods for the FIFO Queue implementation.
*
************************************************************************************************/

#ifndef FIFO_H_
#define FIFO_H_
#include "Pcb.h"

/**
 * The Node ADT
 * This holds a PCB as content,
 * and contains a next pointer to the next node.
 */
typedef struct node {
	PcbStr * content;
	struct node * next;
} Node;

/**
 * Allocates a space in memory for a node and returns a pointer to the newly constructed node.
 */
Node * nodeConstructor();

/**
 * Destroys this Node.
 */
Node * nodeDeconstructor(Node * node);

/**
 * Sets the "next" pointer in node to nextNode
 */
void nodeSetNext(Node * node, Node * nextNode);

/**
 * The queue ADT.
 * Holds node pointers for the head and back of the queue.
 */
typedef struct queue {
	Node * head;
	Node * back;
	int size;
}fifoQueue;

/**
 * Returns pointer to a new empty Queue
 */
fifoQueue * fifoQueueConstructor();

/**
 * Destroys Queue
 */
void fifoQueueDestructor(fifoQueue * queue);

/**
 * Pass in the queue and a pointer of the PcbStr to enqueue
 */
void fifoQueueEnqueue(fifoQueue *queue, PcbStr * pcb);

/**
 * Pass in a queue. Returns and dequeues the head PcbStr.
 */
PcbStr *fifoQueueDequeue(fifoQueue *queue);

/**
 * Returns a pointer to the head PcbStr
 */
PcbStr *fifoQueuePeek(fifoQueue * queue);

/**
 * Is it Empty?
 */
int fifoQueueIsEmpty(fifoQueue * queue);

/**
 * sizeof(fifoQueue)
 */
int fifoQueueSize();

/**
 * Returns a formatted string of all PcbStrs and their content
 */
char * fifoQueueToString(fifoQueue * queue);

#endif /* FIFO_H_ */

