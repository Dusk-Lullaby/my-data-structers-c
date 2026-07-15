#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Element_t;

typedef struct {
	Element_t* data;
	int pos;
	int capacity;
} SEQTable_t;

SEQTable_t* creatSeqTable(int n);

void showSeqTable(const SEQTable_t* table);

int pushbcakSeqTable(SEQTable_t* table, Element_t value);

int enlargeSeqTable(SEQTable_t* table);

int findIndexOfSeqTable(const SEQTable_t* table, Element_t value);

int deleteSeqTable(SEQTable_t* table, Element_t value);

void releaseSeqTable(SEQTable_t* table);

int insertSeqTable(SEQTable_t* table, int index, int value);

int setSeqTable(SEQTable_t* table, Element_t old, Element_t value);

//测试main函数
int main() {
	SEQTable_t* table = creatSeqTable(5);
	showSeqTable(table);
	printf("------------\n");
	for (int i = 0; i < 5; i++) {
		pushbcakSeqTable(table, i + 100);
	}
	showSeqTable(table);
	printf("--------------\n");
	pushbcakSeqTable(table, 82);
	showSeqTable(table);
	printf("-------------\n");
	deleteSeqTable(table, 103);
	showSeqTable(table);
	printf("------------\n");
	insertSeqTable(table, 3, 802);
	showSeqTable(table);
	printf("-------------\n");
	setSeqTable(table, 101, 802);
	showSeqTable(table);

	releaseSeqTable(table);
	return 0;
}

/*
	功能： 创建顺序表，并且进行初始化
	参数： 需要的元素个数
	返回值： 创建完成的顺序表指针, 如果失败则返回空
		1. 开辟顺序表空间
		2. 判断是否开辟成功
		3. 开辟成功对顺序表进行初始化
*/
SEQTable_t* creatSeqTable(int n) {
	SEQTable_t* table = malloc(sizeof(SEQTable_t));
	//如果空间开辟失败
	if (table == NULL) {
		printf("table malloc failed\n");
		free(table);
		return NULL;
	}

	//开辟成功进行初始化
	table->data = malloc(sizeof(Element_t) * n);
	if (table->data == NULL) {
		printf("data malloc failed\n");
		return NULL;
	}
	table->pos = 0;
	table->capacity = n;

	return table;
}

/*
	功能： 打印顺序表中的信息
	参数： 需要打印的顺序表的指针
	返回值： 无
			1. 判断该顺序表中是否有元素，没有元素则进行提示
			2. 遍历打印
*/
void showSeqTable(const SEQTable_t* table) {
	if (table->pos == 0) {
		printf("data is null\n");
		return;
	}
	printf("pos is %d and capacity is %d\n", table->pos, table->capacity);
	for (int i = 0; i < table->pos; i++) {
		printf("%d ", table->data[i]);
	}
	printf("\n");
	return;
}

/*
	功能： 尾插法添加元素
	参数： 需要进行操作的顺序表指针 ， 需要添加的元素
	返回值： 成功0 失败-1
		1. 判断空间是否存在，防止小人
		2. 判断是否需要进行扩容操作
		3. 尾插
*/
int pushbcakSeqTable(SEQTable_t* table, Element_t value) {
	//判断空间是否存在
	if (table == NULL || table->data == NULL) {
		printf("table is null\n");
		return -1;
	}
	//判断扩容
	if (table->pos == table->capacity && enlargeSeqTable(table)) {
		return -1;
	}
	//尾插
	table->data[table->pos++] = value;

	return 0;
}

/*
	功能： 顺序表扩容
	参数： 需要扩容的顺序表指针
	返回值： 成功0 失败-1
		1. 开辟新的空间
		2. 将老空间中的元素拷贝到新空间
		3. free
		4. data指针指向新空间

*/
int enlargeSeqTable(SEQTable_t* table) {
	//开辟新空间
	Element_t* tmp = malloc(sizeof(Element_t) * table->capacity * 2);
	if (tmp == NULL) {
		printf("enlargeSeqTable malloc failed\n");
		return -1;
	}
	//拷贝
	memcpy(tmp, table->data, sizeof(Element_t) * table->pos);
	table->capacity *= 2;
	//释放空间，让data指向新空间
	free(table->data);
	table->data = tmp;

	return 0;
}

/*
	功能： 查找对应元素的索引
	参数： 需要进行操作的顺序表指针 需要查找的元素
	返回值： 如果查找成功返回对应的索引 ，查找失败则返回-1
		1. 遍历
*/
int findIndexOfSeqTable(const SEQTable_t* table, Element_t value) {
	int index = -1;
	for (int i = 0; i < table->pos; i++) {
		if (table->data[i] == value) {
			index = i;
			return index;
		}
	}
	printf("not found index\n");

	return -1;
}

/*
	功能： 顺序表的删除
	参数： 需要进行操作的顺序表指针 删除的元素
	返回值： 成功0 失败-1
		1. 查找索引，失败返回-1
		2. 删除
*/
int deleteSeqTable(SEQTable_t* table, Element_t value) {
	//获得索引
	int index = findIndexOfSeqTable(table, value);
	if (index == -1) return -1;
	for (int i = index + 1; i < table->pos; i++) {
		table->data[i - 1] = table->data[i];
	}
	table->pos--;

	return 0;
}

/*
	功能： 释放顺序表
	参数： 需要释放的顺序表指针
	返回值： 无
*/
void releaseSeqTable(SEQTable_t* table) {
	if (table && table->data != NULL) {
		free(table->data);
	}
	free(table);
}

/*
	功能： 任意位置插入元素
	参数： 需要进行操作的顺序表指针 需要插入位置的索引 需要插入的元素
	返回值： 成功0 失败-1
		1. 判断顺序表是否存在
		2. 索引是否合法 
		3. 判断是否需要扩容
		4. 将索引上的空间和之后的空间都后移一位，为新元素腾空间
*/
int insertSeqTable(SEQTable_t* table, int index, int value) {
	// 判断空间有效性
	if (table == NULL || table->data == NULL) {
		printf("table is null\n");
		return -1;
	}
	// 判断索引合法
	if (index < 0 || index > table->pos) {
		printf("index invalid\n");
		return -1;
	}
	//是否扩容
	if (table->pos == table->capacity && enlargeSeqTable(table)) {
		printf("enlarge malloc failed\n");
		return -1;
	}
	//插入
	for (int i = table->pos - 1; i >= index; i--) {
		table->data[i + 1] = table->data[i];
	}
	table->data[index] = value;
	table->pos++;

	return 0;
}

/*
	功能： 修改顺序表元素
	参数： 需要修改的顺序表指针 旧元素 新元素
	返回值： 成功0 失败-1
		1. 找到旧元素的索引，失败返回-1
		2. 重新赋值
*/
int setSeqTable(SEQTable_t* table, Element_t old, Element_t value) {
	int index = findIndexOfSeqTable(table, old);
	if (index == -1) {
		return -1;
	}
	table->data[index] = value;

	return 0;
}