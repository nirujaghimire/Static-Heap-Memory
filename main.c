//
// Created by niruja on 9/23/2023.
//
#include <stdio.h>
#include "static_heap.h"

#define MEMORY_SIZE 8
#define NUMBER_OF_ALLOCATIONS 4

HeapMemory memory[MEMORY_SIZE];
HeapMemoryMap map[NUMBER_OF_ALLOCATIONS];
Heap heap;

int main(){
    StaticHeap.init(&heap,map,NUMBER_OF_ALLOCATIONS,memory,MEMORY_SIZE);
    StaticHeap.print(heap);
    void* a0 = StaticHeap.malloc(&heap,2);
    StaticHeap.print(heap);
    void* a1 = StaticHeap.malloc(&heap,3);
    StaticHeap.print(heap);
    void* a2 = StaticHeap.malloc(&heap,1);
    StaticHeap.print(heap);

    StaticHeap.free(&heap,a1);
    StaticHeap.print(heap);

    if(StaticHeap.malloc(&heap,8)==NULL) {
        printf("*****************\n");
        printf("Failed to malloc \n");
        printf("Available Allocations       : %d\n",StaticHeap.getAvailableNumberOfAllocation(heap));
        printf("Available Bytes             : %d\n",StaticHeap.getAvailableBytes(heap));
        printf("Available Allocatable Bytes : %d\n",StaticHeap.getAvailableAllocatableBytes(heap));
        printf("Required Bytes              : %d\n",8);
    }

    if(StaticHeap.malloc(&heap,4)==NULL) {
        printf("*****************\n");
        printf("Failed to malloc \n");
        printf("Available Allocations       : %d\n",StaticHeap.getAvailableNumberOfAllocation(heap));
        printf("Available Bytes             : %d\n",StaticHeap.getAvailableBytes(heap));
        printf("Available Allocatable Bytes : %d\n",StaticHeap.getAvailableAllocatableBytes(heap));
        printf("Required Bytes              : %d\n",4);
    }

    void* a3 = StaticHeap.malloc(&heap,1);
    StaticHeap.print(heap);
    void* a4 = StaticHeap.malloc(&heap,1);
    StaticHeap.print(heap);

    if(StaticHeap.malloc(&heap,1)==NULL) {
        printf("*****************\n");
        printf("Failed to malloc \n");
        printf("Available Allocations       : %d\n",StaticHeap.getAvailableNumberOfAllocation(heap));
        printf("Available Bytes             : %d\n",StaticHeap.getAvailableBytes(heap));
        printf("Available Allocatable Bytes : %d\n",StaticHeap.getAvailableAllocatableBytes(heap));
        printf("Required Bytes              : %d\n",1);
    }

    StaticHeap.free(&heap,a0);
    StaticHeap.print(heap);
    StaticHeap.free(&heap,a2);
    StaticHeap.print(heap);
    StaticHeap.free(&heap,a3);
    StaticHeap.print(heap);
    StaticHeap.free(&heap,a4);
    StaticHeap.print(heap);

    return 0;
}