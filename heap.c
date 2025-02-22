#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct heap{
	int *arr;
	int heapsize;
	int totsize;
}hh;

hh *createHeap(int size){
	hh *h = (hh*)malloc(sizeof(hh));
	h->arr = (int*)malloc(size*sizeof(int));
	h->heapsize = 0;
	h->totsize = size;
	return h;
}

void heapify(hh *h,int indx){
	int largest = indx;
	int l = 2*indx+1;
	int r = 2*indx+2;
	if(l < h->heapsize && h->arr[l] > h->arr[largest]){
		largest = l;
	}
	if(r < h->heapsize && h->arr[r] > h->arr[largest]){
		largest = r;
	}
	if(largest != indx){
		int temp = h->arr[indx];
		h->arr[indx] = h->arr[largest];
		h->arr[largest] = temp;
		heapify(h,largest);
	}
}
void insertHeap(hh *h,int val){
	if(h->heapsize >= h->totsize){
		return;
	}
	h->arr[h->heapsize++] = val;
	int indx = h->heapsize-1;
	while(indx > 0){
		int par = (indx-1)/2;
		if(h->arr[par] < h->arr[indx]){
			int temp = h->arr[par];
			h->arr[par] = h->arr[indx];
			h->arr[indx] = temp;
		}
		indx = par;
	}
}

int extractMin(hh *h){
	if(h->heapsize == 0){
		printf("heap is empty\n");
		return -1;
	}
	int min = h->arr[0];
	h->arr[0] = h->arr[--h->heapsize];
	int indx = 0;
	if(h->heapsize == 0) return -1;
	heapify(h,indx);
}


void print(hh *h){
	for(int i = 0;i < h->heapsize;i++){
		printf("%d\n",h->arr[i]);
	}
}

int main(){
	hh *h = createHeap(6);
	insertHeap(h,4);
	insertHeap(h,10);
	insertHeap(h,122);
	insertHeap(h,16);
	insertHeap(h,33);
	insertHeap(h,12);
	insertHeap(h,9);
	print(h);
	extractMin(h);
	print(h);
}
