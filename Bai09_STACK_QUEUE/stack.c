#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int *item;  // mảng lưu trữ giá trị các phần tử
    int size;   // số lượng phần tử tối đa của Stack
    int top;    // chỉ số lấy giá trị ở đỉnh Stack
} Stack;


#define STACK_EMPTY -1

// khởi tạo stack
void init(Stack *stack, int newSize)
{
    stack->size = newSize;
    stack->item = (int*)malloc(newSize * sizeof(int));
    stack->top  = -1;
}

// kiểm tra stack rỗng
bool isEmpty(Stack stack)
{
    return (stack.top == -1 ? true : false);
}

// kiểm tra stack đầy
bool isFull(Stack stack)
{
    return (stack.top == (stack.size - 1) ? true : false);
}

// thêm phần tử vào đỉnh stack
void push(Stack *stack, int data)
{
    if (isFull(*stack))
    {
        printf("Stack đầy! Không thể thêm\n");
    }
    else
    {
        // stack->top++;
        // stack->item[stack->top] = data;

        stack->item[++stack->top] = data;
    }
}

// xóa phần tử ở đỉnh stack
int pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack rỗng!\n");
        return STACK_EMPTY;
    }
    else
    {
        int val = stack->item[stack->top];
        stack->item[stack->top--] = 0;
        return val;
    }
}

// đọc giá trị tại đỉnh stack
int top(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rỗng!\n");
        return STACK_EMPTY;
    }
    else
    {
        return stack.item[stack.top];
    }
}

int main()
{
    Stack stack1;

    init(&stack1, 5);

    printf("Push process\n");
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("\n");
    printf("Display element\n");
    for(int i = 0; i < stack1.size; i++)
    {
        printf("Element: %d -> addr: %p\n", stack1.item[i], &(stack1.item[i]));
    }

    printf("\n");
    printf("Pop process\n");
    for(int i = 0; i < stack1.size; i++)
    {
        printf("Top element: %d -> Addr: %p\n", top(stack1), &(stack1.item[stack1.top]));
        pop(&stack1);
    }
    return 0;
}
