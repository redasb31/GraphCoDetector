#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct PRODUCT {
	char name[10];
	int num;
	struct PRODUCT* next;
	struct PRODUCT* prev;
};

struct PRODUCT HashTable[6];

void Add(char name[], int num) {
	struct PRODUCT* pos;
	struct PRODUCT* newpro = (struct PRODUCT*)malloc(sizeof(struct PRODUCT));
	strcpy(newpro->name, name);
	newpro->num = num;
	if (HashTable[strlen(name)].next == &HashTable[strlen(name)]) {
		HashTable[strlen(name)].next = newpro;
		HashTable[strlen(name)].prev = newpro;
		newpro->next = &HashTable[strlen(name)];
		newpro->prev = &HashTable[strlen(name)];
		return;
	}
	for (pos = HashTable[strlen(name)].next; pos != &HashTable[strlen(name)]; pos = pos->next) {
		if (!strcmp(name, pos->name)) {
			pos->num += num;
			return;
		}
		else if (strcmp(name, pos->name) < 0) {
			newpro->prev = pos->prev;
			newpro->next = pos;
			pos->prev = newpro;
			newpro->prev->next = newpro;
			return;
		}
	}
	newpro->prev = HashTable[strlen(name)].prev;
	newpro->next = &HashTable[strlen(name)];
	HashTable[strlen(name)].prev = newpro;
	newpro->prev->next = newpro;
	return;
}

int main() {
	int N;
	char s[10];
	int num;
	for (int i = 0; i < 6; i++) {
		HashTable[i].next = &HashTable[i];
		HashTable[i].prev = &HashTable[i];
	}
	//def
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d", s, &num);
		Add(s, num);
	}
	for (int i = 1; i < 6; i++) {
		for (struct PRODUCT* pos = HashTable[i].next; pos != &HashTable[i]; pos = pos->next) {
			printf("%s %d\n", pos->name, pos->num);
		}
	}
	return 0;
}
