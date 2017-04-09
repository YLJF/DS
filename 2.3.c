// 队列顺序存储实现
// 数组
// 一维数组+记录队列头元素位置的变量front+记录队列尾元素位置的变量rear
#define MaxSize 100
struct QNode {
	ElementType Data[MaxSize];
	int rear;
	int front;
};
typedef struct QNode *Queue;

// 入队
void AddQ(Queue PtrQ, ElementType item)
{
	if ((PtrQ->rear+1) % MaxSize == PtrQ->front) {
		printf("Queue full\n");
		return;
	}
	PtrQ->rear = (PtrQ->rear+1) % MaxSize;
	ptrQ->Data[PtrQ->rear] = item;
}

// 出队
ElementType DeleteQ(Queue PtrQ)
{
	if (PtrQ->front == PtrQ->rear) {
		printf("Queue empty\n");
		return ERROR;
	} else {
		PtrQ->front = (PtrQ->front+1) % MaxSize;
		return PtrQ->Data[PtrQ->front];
	}
}

// 队列的链式存储实现
// 单链表
struct Node {
	ElementType Data;
	struct Node *Next;
};

struct QNode {	// 链队列结构
	struct Node *rear; // 指向队尾结点
	struct Node *front; // 指向对头结点
};

typedef struct QNode *Queue;
Queue PtrQ;

// 不带头结点


ElementType DeleteQ(Queue PtrQ)
{
	struct Node *FrontCell;
	ElementType FrontCell;

	if (PtrQ->front == NULL) {
		printf("empty\n");
		return ERROR；
	}
	FrontCell = PtrQ->front;
	if (PtrQ->front == PTrQ->rear) // 若队列只有一个元素
		PtrQ->front = PtrQ->rear = NULL; // 删除后队列置为空
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);  // 释放被删除结点空间
	return FrontElem;
}