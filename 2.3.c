// ����˳��洢ʵ��
// ����
// һά����+��¼����ͷԪ��λ�õı���front+��¼����βԪ��λ�õı���rear
#define MaxSize 100
struct QNode {
	ElementType Data[MaxSize];
	int rear;
	int front;
};
typedef struct QNode *Queue;

// ���
void AddQ(Queue PtrQ, ElementType item)
{
	if ((PtrQ->rear+1) % MaxSize == PtrQ->front) {
		printf("Queue full\n");
		return;
	}
	PtrQ->rear = (PtrQ->rear+1) % MaxSize;
	ptrQ->Data[PtrQ->rear] = item;
}

// ����
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

// ���е���ʽ�洢ʵ��
// ������
struct Node {
	ElementType Data;
	struct Node *Next;
};

struct QNode {	// �����нṹ
	struct Node *rear; // ָ���β���
	struct Node *front; // ָ���ͷ���
};

typedef struct QNode *Queue;
Queue PtrQ;

// ����ͷ���


ElementType DeleteQ(Queue PtrQ)
{
	struct Node *FrontCell;
	ElementType FrontCell;

	if (PtrQ->front == NULL) {
		printf("empty\n");
		return ERROR��
	}
	FrontCell = PtrQ->front;
	if (PtrQ->front == PTrQ->rear) // ������ֻ��һ��Ԫ��
		PtrQ->front = PtrQ->rear = NULL; // ɾ���������Ϊ��
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);  // �ͷű�ɾ�����ռ�
	return FrontElem;
}