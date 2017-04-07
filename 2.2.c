// ջ��˳��洢�ṹ
// һά�����һ����¼ջ��Ԫ��λ�õı������
#define MAXSIZE 100
typedef struct SNode *Stack;
struct SNode {
	ElementType Data[MAXSIZE];
	int Top;
};

// ��ջ
void Push(Stack PtrS, ElementType item) {
	if (PtrS->Top == MAXSIZE-1) {
		printf("stack full\n");
		return;
	} else {
		PtrS->Data[++(PtrS->Top)] = item;
	}
}

// ��ջ
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
	int Top1;  // ջ1��ջ��ָ��
	int Top2;  // ջ2��ջ��ָ��
} S;
S.Top1 = -1;
S.Top2 = MaxSize;

void Push(Struct DStack *PtrS, ElementType item, int Tag) {
	if (PtrS->Top2 - PtrS->Top1 == 1) { // ջ��
		printf("stack full\n");
		return;
	}
	if (Tag == 1) // �Ե�һ��ջ����
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

// ջ����ʽ�洢
// ��������ջ
// �����ɾ������ֻ������ջ��ջ������
typedef struct SNode *Stack;
struct SNode {
	ElementType Data;
	struct SNode *Next;
};

Stack CreateStack() 
{	// ����һ����ջ��ͷ��㣬����ָ��
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