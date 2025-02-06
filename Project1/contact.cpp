#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void menu(void) {
	printf("***** 1.Add     2.Delete *****\n");
	printf("***** 3.Modify  4.Search *****\n");
	printf("***** 5.Show    6.Clear  *****\n");
	printf("***** 7.Sort    0.Exit   *****\n"); 
}

void check_capacity(Contact* pc) {
	if (pc->sz == pc->capacity) {
		PerInfo* pf = (PerInfo*)realloc(pc->data, (pc->capacity * 2) * sizeof(PerInfo));
		if (pf != NULL) {
			pc->data = pf;
			pc->capacity *= 2;
			printf("扩容成功.\n");
		}
	}
}

void destory_contact(Contact* pc) {
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


void loading_contact(Contact* pc) {
	PerInfo tmp = { 0 };
	int i = 0;
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL) {
		perror("loading_contact::fopen");
		return;
	}
	while (fread(&tmp, sizeof(PerInfo), 1, pf)) {
		check_capacity(pc);
		pc->data[i] = tmp;
		pc->sz++;
		i++;
	}
	fclose(pf);
	pf = NULL;
}

void Init_contact(Contact* pc) {
	assert(pc);
	PerInfo* ptr = (PerInfo*)calloc(DEFAULT_SIZE, sizeof(PerInfo));
	if (ptr == NULL) {
		printf("%s", strerror(errno));
		return;
	}
	else {
		pc->data = ptr;
		pc->sz = 0;
		pc->capacity = DEFAULT_SIZE;
	}
}

void save_contact(Contact* pc) {
	FILE* pfw = fopen("contact.txt", "wb");
	if (pfw == NULL) {
		perror("save_contact::fopen");
		return;
	}
	for (int i = 0; i < pc->sz; i++) {
		fwrite(pc->data + i, sizeof(PerInfo), 1, pfw);
	}
	fclose(pfw);
	pfw = NULL;
}

void Add_contact(Contact* pc) {
	assert(pc);
	check_capacity(pc);
	printf("请输入新添联系人的姓名:");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入新添联系人的年龄:");
	scanf("%hu", &pc->data[pc->sz].age);
	printf("请输入新添联系人的性别:");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入新添联系人的电话:");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入新添联系人的住址:");
	scanf("%s", pc->data[pc->sz].address);
	pc->sz++;
	printf("增加成功.\n");
}

void Show_contact(const Contact* pc) {
	assert(pc);
	printf("%-20s %-5s %-5s %-12s %-20s\n", "姓名", "年龄", "性别", "电话", "住址");
	for (int i = 0;i < pc->sz;i++) {
		printf("%-20s %-5hd %-5s %-12s %-20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].address);
	}
}

static int find_name(const Contact* pc, char* name) {
	assert(pc);
	for (int i = 0;i < pc->sz;i++) {
		if (strcmp(name, pc->data[i].name) == 0)
			return i;
	}
	return -1;
}

void Delete_contact(Contact* pc) {
	assert(pc);
	char name[name_max];
	if (pc->sz != 0) {
		printf("请输入要删除的联系人:");
		scanf("%s", name);
		int d = find_name(pc, name);
		if (d + 1) {
			for (int i = d;i < pc->sz;i++) {
				pc->data[i] = pc->data[i + 1];
			}
			pc->sz--;
			printf("删除成功.\n");
		}
		else {
			printf("该联系人不存在通讯录中.\n");
			return;
		}
	}
	else {
		printf("通讯录为空，无法删除.\n");
		return;
	}
	
}

void Modify_contact(Contact* pc) {
	char name[name_max];
	printf("请输入要修改的联系人:");
	scanf("%s", name);
	int m=find_name(pc, name);
	if (m + 1) {
		printf("请输入新的名字:");
		scanf("%s", pc->data[m].name);
		printf("请输入新的年龄:");
		scanf("%hd", &pc->data[m].age);
		printf("请输入新的性别:");
		scanf("%s", pc->data[m].sex);
		printf("请输入新的电话:");
		scanf("%s", pc->data[m].tele);
		printf("请输入新的住址:");
		scanf("%s", pc->data[m].address);
	}
	else {
		printf("该联系人不存在通讯录中.\n");
		return;
	}
	printf("修改成功.\n");
}

void Search_contact(Contact* pc) {
	assert(pc);
	char name[name_max];
	printf("请输入要查找的联系人:");
	scanf("%s", name);
	int pos = find_name(pc, name);
	if (pos + 1) {
		printf("已找到该联系人.\n");
		printf("%-20s %-5s %-5s %-12s %-20s\n", "姓名", "年龄", "性别", "电话", "住址");
		printf("%-20s %-5hd %-5s %-12s %-20s\n", pc->data[pos].name, pc->data[pos].age, pc->data[pos].sex, pc->data[pos].tele, pc->data[pos].address);
	}
	else {
		printf("该联系人不存在通讯录中.\n");
		return;
	}
}

void Clear_contact(Contact* pc) {
	Init_contact(pc);
}

int cmp_name(const void* con_name1, const void* con_name2) {
	return strcmp(((PerInfo*)con_name1)->name, ((PerInfo*)con_name2)->name);
}

void Sort_name(Contact* pc) {
	qsort(pc->data, pc->sz, sizeof(PerInfo), cmp_name);
	Show_contact(pc);
}






