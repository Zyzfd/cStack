#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stack>
#include <ctime>
#define RAND_MAX 100

using namespace std;

int * Stack;
int head = -1;

bool stack_is_empty() {
    return head == -1;
}

void push_stack(int el, int kolvo) {
    head++;
    if (head == sizeof(int) * kolvo / sizeof(int)) {
        printf("Overflow\n");
        head--;
        return;
    }
    Stack[head] = el;
}

void print_stack() {
    printf("\n");
    for (int i = 0; i <= head; i++) {
        printf("%4d", Stack[i]);
    }
}

int pop_stack() {
    if (stack_is_empty()) {
        printf("Underflow");
        return 0;
    }
    head--;
    int temp = Stack[head + 1];
    Stack[head + 1] = 0;
    return temp;
}

void empty_stack() {
    if (stack_is_empty()) {
        return;
    }
    while (head != -1) {
        pop_stack();
    }
}

int main() {
    for (int kolvo = 0; kolvo < 10000000; kolvo += 100000) {
        stack <int> steck;
        //Stack = (int*)malloc(kolvo * sizeof(int));

        int* mass_values = (int*)malloc(kolvo * sizeof(int));
        for (int i = 0; i < kolvo; i++) {
            mass_values[i] = rand();
        }

        for (int i = 0; i < kolvo; i++) {
            steck.push(mass_values[i]);
            //push_stack(mass_values[i], kolvo);
        }

        unsigned int start_time = clock();
        unsigned int start_mem = sizeof(steck);
        for (int i = 0; i < kolvo; i++) {
            steck.pop();
            //pop_stack();
        }
        unsigned int end_mem = sizeof(steck);
        unsigned int end_time = clock();
        unsigned int search_mem = end_mem - start_mem;
        unsigned int search_time = end_time - start_time;
        //printf("%d\n", search_time);
        printf("%d\n", search_mem);

        //free(Stack);
        head = -1;
        free(mass_values);
    }
}