include <stdio.h>
#include <stdlib.h>
// Khai báo kiểu cấu trúc struct đặt tên là queue gồm 4 phần tử.
typedef struct
{
    int *items; // mảng lưu trữ giá trị các phần tử
    int size;   // kích thước của hàng đợi
    int front;  // chỉ số phần tử đầu hàng đợi
    int rear;   // chỉ số phần tử cuối hàng đợi
} Queue;

// khởi tạo hàng đợi
void queue_Init(Queue *queue, int size) // Tham số kiểu con trỏ queue và size
{
  // tham thiếu tạo một mảng động dùng malloc với kích thước của biến size
    queue->items = (int*)malloc(size * sizeof(int));
  // khởi tạo size từ tham số truyền vào
    queue->size  = size;
  // khỏi tạo chỉ số đầu và cuối mặc định mức -1 tức là chưa có gì cả , đang rỗng
    queue->front = queue->rear = -1;
}

// kiểm tra hàng đợi rỗng
int queue_IsEmpty(Queue queue)
{
  // kiểu tra về int nhưng return là một dạng so sánh nên sẽ trả về true false tương ứng 0 - 1 nếu điều kiện sai hoặc đúng
    return (queue.front == -1);
}

// kiểm tra hàng đợi đầy
int queue_IsFull(Queue queue)
{  // Khi mà với size là size() thì phần tử cuối cùng của queue ở chỉ số size - 1. 
  // Phần cộng 1 để đảm bảo rằng rear đang ở cuối hàng đợi khi chia dư cho size() mặc khác front phải ở đầu queue
    return (queue.rear + 1) % queue.size == queue.front;
}

// thêm phần tử vào cuối hàng đợi
void enqueue(Queue *queue, int data)
{
  /// trước khi thêm kiểu tra queue full chưa
    if (queue_IsFull(*queue))
    {
        // nếu queue đầy thì không cho thêm phần tử vào
        printf("Hàng đợi đầy!\n");
    }
    else // nếu chưa đầu
    {
      // check chỉ số ở dạng -1 thì check nó có đang rỗng hay không để bắt đầu đưa lên 0.
        if (queue->front == -1)
        {
            queue->front = queue->rear = 0;
        }
        else // tang chỉ số rear rồi thêm phần tử vào
        {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = data;
        printf("Enqueued %d\n", data);
    }
}

#define QUEUE_EMPTY -1

// xóa phần tử từ đầu hàng đợi
int dequeue(Queue *queue)
{
    if (queue_IsEmpty(*queue))
    {
        // nếu queue rỗng thì không cho xóa
        printf("Hàng đợi rỗng\n");
        return QUEUE_EMPTY;
    }
    else
    {
      // khai báo giá trị và trỏ đến front để thực hiện xóa
        int dequeue_value = queue->items[queue->front];
        if (queue->front == queue->rear && (queue->rear ==  queue->size - 1)) // kiểm tra xem queue có đang đầy hay không
        {
            queue->front = queue->rear = -1; // đưa queue về rỗng
        }
        else
        {
            queue->front = (queue->front + 1) % queue->size; //tăng chỉ số front và đảm bảo chỉ số không vươt quá size -1 
        }
        return dequeue_value; // return về giá trị xóa
    }
}

// lấy giá trị của phần tử đứng đầu hàng đợi (front)
int front(Queue queue)
{// check rônghx
    if (queue_IsEmpty(queue))
    {
        printf("Queue is empty\n");
        return QUEUE_EMPTY;
    }
    else // nếu không rỗng thì trả về phần tử có chỉ số front
    {
        return queue.items[queue.front];
    }
}

// lấy giá trị của phần tử đứng cuối hàng đợi (rear)
int rear(Queue queue)
{// check rỗng
    if (queue_IsEmpty(queue))
    {
        printf("Queue is empty\n");
        return QUEUE_EMPTY;
    }
    else // nếu không rỗng trả về phần tử có chỉ số rear trong mảng
    {
        return queue.items[queue.rear];
    }
}

// Hiển thị các phần tử
void display(Queue q)
{
    if (queue_IsEmpty(q))
    {
        printf("Hàng đợi rỗng\n");
        return;
    }
    printf("Hàng đợi: ");
    int i = q.front;
    // khai báo i là chỉ số đầu hàng đợi duyệt từ đầu đến cuối khi gặp  rear thì dừng lại, thực hiện in ra màn hình
    while (1)
    {
        printf("%d ", q.items[i]);
        if (i == q.rear) break;
        i = (i + 1) % q.size;
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    Queue queue;
   
    queue_Init(&queue, 5);

    enqueue(&queue, 10);
    enqueue(&queue, 15);
    enqueue(&queue, 20);
    enqueue(&queue, 25);
    enqueue(&queue, 30);

    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));
    // printf("Dequeued %d\n", dequeue(&queue));

    display(queue);

    enqueue(&queue, 50);
    display(queue);

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    return 0;
}
