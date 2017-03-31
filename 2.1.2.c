typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;
};
struct LNode L;
List PtrL;

List MakeEmpty() {
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
	return PtrL;
}

int Find(ElementType X, List PtrL) {
	int i = 0;
	while (i <= PtrL->last && PtrL->Data[i] != X)
		i++;
	if (i > PtrL->Last) // not found
		return -1;
	else				// found
		return 0;
}

void Insert(ElementType X, int i, List PtrL) {
	int j;
	if (PtrL->Last == MAXSIZE-1) {
		printf("table full\n");
		return;
	}
	if (i < 1 || i > PtrL->Last+2) {
		printf("locaton illegall\n");
		return;
	}
	for (j = PtrL->Last; j >= i-1; i--)
		PtrL->Data[j+1] = PtrL->Data[j];
	PtrL->Data[i-1] = X;
	PtrL->Last++;
	return;
}

void Delete(int i, List PtrL) {
	int j;
	if (i < 1 || i > PtrL->Last+1) {
		printf("xxxxx\n");
		return;
	}
	for (j = i; j <= PtrL->last;j++)
		PtrL->Data[j-1] = PtrL->Data[j];
	PtrL->Last--;
	return;
}

typedef struct LNode *List;
struct LNode {
	ElementType Data;
	List Next;
};

struct Lnode L;
List PtrL;

int Length(List PtrL) {
	List p = PtrL;
	int j = 0;
	while (p) {
		p = p->Next;
		j++;
	}
	return i;
}

List FindKth(int K, List PtrL) {
	List p = PtrL;
	int i = 1;
	while (p != NULL && i < K) {
		p = p->Next;
		i++;
	}
	if (i == K) 
		return p;
	else 
		return NULL;
}

List Find(ElementType X, List PtrL) {
	List p = PtrL;
	while (p != NULL && p->Data != X)
		p = p->Next;
	return p;
}

List Insert(Element X, int i, List PtrL) {
	List p, s;
	if (i == 1) {
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = PtrL;
		return s;
	}
	p = FindKth(i-1, PtrL);
	if (p == NULL) {
		printf("para error\n");
		return NULL;
	} else {
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;
		p->Next = s;
		return PtrL;
	}
}	

List Delete(int i, List PtrL) {
	List p, s;
	if (i == 1) {
		s = PtrL;
		if (PtrL != NULL)
			PtrL= PtrL->Next;
		else
			return NULL;
		free(s);
		return PtrL;
	}
	p = FindKth(i-1, PtrL);
	if (p == NULL) {
		printf("xxxxx\n");
		return NULL;
	} else if (p->Next == NULL) {
		printf("xxxxx\n");
	} else {
		s = p->Next;
		p->Next = s->Next;
		free(s);
		return PtrL;
	}
}

// �����
// ���Ա���ƹ�
// ���Ա�n��Ԫ�ض��ǻ����ĵ�Ԫ�أ�
// �����Ԫ�ز��������ǵ�Ԫ�أ�Ҳ��������һ�������
typedef struct GNode *GList;
struct GNode {
	int Tag;
	union {
		ElementType Data;
		GList SubList;
	}URegion;
	GList Next;
};
 ____________________________
|       |   Data      |      |
|  Tag  |-------------| Next |
|       |   SubList   |      |
|_______|_____________|______|


// ��������
// �����еĽڵ����ͬʱ�����ڶ����
// ���������н���ָ������ж������ǰ�����Ӱ�����Next��SubList����
// ָ����
// ����������ָ�����������һ���Ƕ�������������˫�������Ƕ�������

// ���͵Ķ�������--ʮ�������洢ϡ�����
// ֻ�洢�����0Ԫ����
// ����������������Row, ������Col, ��ֵValue
// ÿ�����ͨ������ָ����,��ͬ�С�ͬ�д�������
// ��ָ��(���Ϊ����ָ��)Right
// ��ָ��(���Ϊ����ָ��)Down