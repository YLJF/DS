// 栈的顺序存储结构
// 一维数组和一个记录栈顶元素位置的变量组成
#define MAXSIZE 100
typedef struct SNode *Stack;
struct SNode {
	ElementType Data[MAXSIZE];
	int Top;
};

// 入栈
void Push(Stack PtrS, ElementType item) {
	if (PtrS->Top == MAXSIZE-1) {
		printf("stack full\n");
		return;
	} else {
		PtrS->Data[++(PtrS->Top)] = item;
	}
}

// 出栈
ElementType Pop(Stack PtrS) {
	if (PtrS->Top == -1) {
		printf("stack empty\n");
		return ERROR;
	} else {
		return (PtrS->Data[(PtrS->Top)--]);
	}
}

#define MaxSize 100
struct DStack {
	ElementType Data[MaxSize];
	int Top1;  // 栈1的栈顶指针
	int Top2;  // 栈2的栈顶指针
} S;
S.Top1 = -1;
S.Top2 = MaxSize;

void Push(Struct DStack *PtrS, ElementType item, int Tag) {
	if (PtrS->Top2 - PtrS->Top1 == 1) { // 栈满
		printf("stack full\n");
		return;
	}
	if (Tag == 1) // 对第一个栈操作
		PtrS->Data[++(PtrS->Top1)] = item;
	else
		PtrS->Data[--(PtrS->Top2)] = item;
}

ElementType Pop(struct DStack *PtrS, int Tag) {
	if (Tag == 1) {
		if (PtrS->Top1 == -1) {
			printf("Stack 1 empty\n");
			return NULL;
		} else {
			return PtrS->Data[(PtrS->Top1)--];
		}
	} else {
		if (PtrS->Top2 == MaxSize) {
			printf("Stack 2 empty\n");
			return NULL;
		} else {
			return PtrS->Data[(PtrS->Top2)++];
		}
	}
}

// 栈的链式存储
// 单链表，链栈
// 插入和删除操作只能在链栈的栈顶进行
typedef struct SNode *Stack;
struct SNode {
	ElementType Data;
	struct SNode *Next;
};

Stack CreateStack() 
{	// 构建一个堆栈的头结点，返回指针
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	s->Next = NULL;
	return S;
}

int IsEmpty(Stack S) {
	return (S->Next == NULL);
}

void Push(ElementType item, Stack S) 
{
	struct SNode *TmpCell;
	TmpCell = (struct SNode *)malloc(sizeof(struct SNode));
	TmpCell->Element = item;
	TmpCell->Next = S->Next;
	s->Next = TmpCell;
}

ElementType Pop(Stack S) 
{
	struct SNode *FirstCell;
	ElementType TopElem;
	if (IsEmpty(S)) {
		printf("stack empty\n");
		return NULL;
	} else {
		FirstCell = S->Next;
		S->Next = FirstCell->Next;
		TopElem = FirstCell->Element;
		free(FirstCell);
		return TopElem;
	}
}