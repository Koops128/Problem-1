#include <stdbool.h>
#include <string.h>
#include <stdbool.h>

#include "PriorityQueue.h"
#include "Fifo.h"
#include "Pcb.h"


int main() {
    PQPtr pQ = pqConstructor();

    //test isEmpty
    if (pqIsEmpty(pQ) == false) {
        printf("pqIsEmpty returns false on a newly constructed priority queue");
    }

    //create 100 pcbs with a random priority, and assigns them an ids from 1-100.
    //after 10 pcbs have been created and enqueued, pause the program to print the results.
    //after each group of 10, dequeue from 4 to 6 PCBs, print out the contents of the dequeued PCBs, then reprint the PQ so far.

    //enqueue each pcb, print as they are enqueued
    srand( time(NULL) );
    PcbPtr pcb;
    int id = 1;
    int i;
    for (i = 0; i < 10; i++) {
        int j;
        for (j = 0; j < 10; j++) {
            pcb = newPCB();
            setPriority(pcb, rand() % 16);
            setID(pcb, id++);
            pqEnqueue(pQ, pcb);
        }
        //print out the priority queue so far
        printf("After enqueueing 10 PCBs:\n%s\n", pqToString(pQ));
        //pause the program to take a screencap

        //dequeue 4 to 6 PCBs:
        int dequeue = (rand() % 3) + 4;
        int k;
        for (k = 0; k < dequeue; k++) {
            //Test the Peek method
            PcbPtr peekedPCB = pqPeek(pQ);
            PcbPtr dpcb = pqDequeue(pQ);

            if (peekedPCB != dpcb) {
                printf("Peek does not return the same value as dequeued.  Peeked PCB: %d, dequeued PCB: %d\n", peekedPCB, dpcb);
            }

            printf("A dequeued PCB: %s\n", toString(dpcb));
        }
        printf("After dequeueing %d PCBs:\n%s\n\n", dequeue, pqToString(pQ));
    }
    
    pqDestructor(pQ);
    
    return 0;
}


