#include <iostream>
#include "heap.h"
#include <stdlib.h>
#include <time.h>


int main () 
{
    Heap<int> heap(4);
    srand (time(NULL));
    for(int i = 0; i < 10; i++) {
        int num = rand()%100;
        heap.push(num);
        // std::cout << num << " ";

    }

    std::cout <<"\n";
	
    for(int i = 0; i < 10;i++) {
        // std::cout << heap.top() << " ";
        heap.pop();
    }
}