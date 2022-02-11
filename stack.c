#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MEM_LEN 4194304

struct Stack{
    char top; //char or char array or char pointer
    unsigned capacity;
    char* array; //this then?
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = "";
    /*
     * malloc(all_elements * sizeof_one)
    */
    stack->array = (char*)malloc(stack->capacity * sizeof(char));

    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    char top = stack->top;
    char temp = stack->capacity - 1; //type??
    int result;

    result = strcmp(top, temp);
    //0 -> success && 1 -> unsuccess

    return result;
}
 
// Stack is empty when top is equal to ""
int isEmpty(struct Stack* stack)
{
    char temp = "";
    char top = stack->top;
    int result;

    result = strcmp(top, temp);

    return result;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    
    stack->array[++stack->top] = item;
    printf("%c pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    
    return stack->array[stack->top--];
}

int main()
{
    struct Stack* stack = createStack(MEM_LEN);

    push(stack, "c");
    push(stack, "a");

    printf("%c popped from stack\n", pop(stack));

    return 0;
}
 