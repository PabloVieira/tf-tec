/*
 * =====================================================================================
 *
 *       Filename:  swap.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/30/2014 04:48:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include"sort.h"
#include<string.h>
#include<stdlib.h>

void selection_sort(int *array, int size){
    int i, j, min, aux;
      for (i = 0; i < (size-1); i++){
        min = i;
        for (j = (i+1); j < size; j++) {
            if(array[j] < array[min]){
                min = j;
              }
        }
        if (i != min){
            aux = array[i];
              array[i] = array[min];
              array[min] = aux;
        }
    }
}


void insertion_sort(int *array, int size) {
   int i, j, selected;
   for (i = 1; i < size; i++){
      selected = array[i];
      j = i - 1;
      while ((j >= 0) && (selected < array[j])) {
         array[j+1] = array[j];
         j--;
      }
      array[j+1] = selected;
   }
}

void shell_sort(int *array, int size) {
    int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while (gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = array[i];
            j = i - gap;
            while (j >= 0 && value < array[j]) {
                array [j + gap] = array[j];
                j -= gap;
            }
            array [j + gap] = value;
        }
    }
}

void quick_sort(int array[], int left, int right) {
    int i, j, pivot, y;
    i = left;
    j = right;

    pivot = array[(i+j) / 2];

    while(i <= j) {
        while(array[i] < pivot && i < right){
            i++;
        }
        while(array[j] > pivot && j > left){
            j--;
        }
        if(i <= j){
            y = array[i];
            array[i] = array[j];
            array[j] = y;
            i++;
            j--;
        }
    }
    /** Recursive call for the function to the left part of the array */
    if(j > left){
        quick_sort(array, left, j);
    }

    /** Recursive call for the function to the right part of the array */
    if(i < right){
        quick_sort(array, i, right);
    }
}

void heap_sort(int array[], int n){
    int i = n/2, father, child, t;

    for(;;) {
        if (i > 0) {
            i--;
            t = array[i];
        }
        else {
            n--;
            if (n <= 0)
               return;
            t = array[n];
            array[n] = array[0];
        }

        father = i;

        //Compare with the left child
        child = i*2+1;

        while (child < n){
            if ((child + 1 < n)  &&  (array[child + 1] > array[child])){
              	child++;
            }
          	if (array[child] > t){
             	array[father] = array[child];
             	father = child;
             	child = father*2 + 1;
          	} else break;
      	}
     	 array[father] = t;
   	}
}

void top_down_merge(int* a,int begin,int end,int* b){
    int middle = (end+begin)/2;
    int i0 = begin;
    int i1 = middle;
    int index;
    int n = end-begin;

    if(n < 2){
        return;
    }

    top_down_merge(a, begin, middle, b);
    top_down_merge(a, middle, end, b);

    for (index = begin; index < end; index++) {
        if (i0 < middle && (i1 >= end || a[i0] <= a[i1])){
            b[index] = a[i0];
            i0++;
        }else{
            b[index] = a[i1];
            i1++;
        }
    }

    memcpy((a+begin),(b+begin),sizeof(int)*(n));
}

void merge_sort(int* a,int n){
    int* b = (int*)malloc(sizeof(int)*n);
    top_down_merge(a, 0, n, b);
    free(b);
}

/**
 * Method that receives a pointer to an array that will be sorted,
 * his size and the constant of the method that will be used
 * @param  array  Array to be sorted
 * @param  size   Size of the array
 * @param  method Sorting algorithm constant
 * @return        Pointer to the sorted array
 */
int* sort_array(int *array, int size, int method){

    switch(method){
        case SELECTION:
            selection_sort(array, size);
        break;

        case INSERTION:
            insertion_sort(array, size);
        break;

        case SHELL:
            shell_sort(array, size);
        break;

        case QUICK:
            quick_sort(array, 0, size - 1);
        break;

        case HEAP:
            heap_sort(array, size);
        break;

        case MERGE:
            merge_sort(array, size);
        break;       
    }
    return array;
}