# [Static-Heap-Memory](https://nirujaghimire.super.site/static-heap-memory)
Using this library static memory can be defined and use as dynamic memory instead of using heap in C.
### Advantages :
* We can define number of static heaps independent to each other.  
* Static memory usage is shown during compilation so better memory management.  
* Predictable behavior. (Dynamic heap has unpredictable behavior)
### Disadvantages :
* We should define memory reason at the first by ourselves. If defined large region of memory for small use, large memory get unused. So user should have idea of how much memory is needed approximately.  
* Many more allocation in one heap slows down the allocation and deallocation process as it searches and shifts elements behind the scene.  
## Test Code : 
```c
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
```
## Output :
```c
******************
0x0 : -
0x1 : -
0x2 : -
0x3 : -
0x4 : -
0x5 : -
0x6 : -
0x7 : -
0 : 0, 8, 0
******************
0x0 : x
0x1 : x
0x2 : -
0x3 : -
0x4 : -
0x5 : -
0x6 : -
0x7 : -
0 : 0, 2, 1
1 : 2, 6, 0
******************
0x0 : x
0x1 : x
0x2 : x
0x3 : x
0x4 : x
0x5 : -
0x6 : -
0x7 : -
0 : 0, 2, 1
1 : 2, 3, 1
2 : 5, 3, 0
******************
0x0 : x
0x1 : x
0x2 : x
0x3 : x
0x4 : x
0x5 : x
0x6 : -
0x7 : -
0 : 0, 2, 1
1 : 2, 3, 1
2 : 5, 1, 1
3 : 6, 2, 0
******************
0x0 : x
0x1 : x
0x2 : -
0x3 : -
0x4 : -
0x5 : x
0x6 : -
0x7 : -
0 : 0, 2, 1
1 : 2, 3, 0
2 : 5, 1, 1
3 : 6, 2, 0
*****************
Failed to malloc
Available Allocations       : 2
Available Bytes             : 5
Available Allocatable Bytes : 3
Required Bytes              : 8
*****************
Failed to malloc
Available Allocations       : 2
Available Bytes             : 5
Available Allocatable Bytes : 3
Required Bytes              : 4
******************
0x0 : x
0x1 : x
0x2 : x
0x3 : x
0x4 : x
0x5 : x
0x6 : -
0x7 : -
0 : 0, 2, 1
1 : 2, 3, 1
2 : 5, 1, 1
3 : 6, 2, 0
******************
0x0 : x
0x1 : x
0x2 : x
0x3 : x
0x4 : x
0x5 : x
0x6 : x
0x7 : x
0 : 0, 2, 1
1 : 2, 3, 1
2 : 5, 1, 1
3 : 6, 2, 1
*****************
Failed to malloc
Available Allocations       : 0
Available Bytes             : 0
Available Allocatable Bytes : 0
Required Bytes              : 1
******************
0x0 : -
0x1 : -
0x2 : x
0x3 : x
0x4 : x
0x5 : x
0x6 : x
0x7 : x
0 : 0, 2, 0
1 : 2, 3, 1
2 : 5, 1, 1
3 : 6, 2, 1
******************
0x0 : -
0x1 : -
0x2 : x
0x3 : x
0x4 : x
0x5 : -
0x6 : x
0x7 : x
0 : 0, 2, 0
1 : 2, 3, 1
2 : 5, 1, 0
3 : 6, 2, 1
******************
0x0 : -
0x1 : -
0x2 : -
0x3 : -
0x4 : -
0x5 : -
0x6 : x
0x7 : x
0 : 0, 6, 0
1 : 6, 2, 1
******************
0x0 : -
0x1 : -
0x2 : -
0x3 : -
0x4 : -
0x5 : -
0x6 : -
0x7 : -
0 : 0, 8, 0

Process finished with exit code 0
```