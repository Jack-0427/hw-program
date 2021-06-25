#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <time.h> 
#include "insertion.h"
using namespace std; 

struct Contact{
	char first[10];
	char last[10];
	int relation;
	char phone[10];
};

int compare_relation(int n, int m){
	if(n == m)
		return 0;	
	else if(n < m)
		return -1;
	else if(n > m)
		return 1;
}

int compare_string(char* ch1, char* ch2){
	if(*ch1 == *ch2 && *ch1 != '\0')
		return compare_string(ch1+1, ch2+1);
	else if(*ch1 == *ch2)
		return 0;
	else if(*ch1 < *ch2)
		return -1;
	else if(*ch1 > *ch2)
		return 1;
}

int compare_phone(char* p, char* q){
int i = 0;
while(*p++ == *q++ && i++ < 10)
	if(i == 10)
		return 0;
	else if(*p < *q)
		return -1;
	else if(*p > *q)
		return 1;
}

int compare(const void* p1, const void* p2)
{

	struct Contact* pt1 = (Contact*) p1;
	struct Contact* pt2 = (Contact*) p2;
	int d = compare_relation(pt1->relation, pt2->relation);
	int e = compare_string(pt1->first, pt2->first);
	int f = compare_string(pt1->last, pt2->last);
	int g = compare_phone(pt1->phone, pt2->phone);
	if(d == -1)
		return -1;
	else if(d == 1)
		return 1;
	else{
		if(e == -1)
			return -1;
		else if(e == 1)
			return 1;
		else{
			if(f == -1)
				return -1;
			else if(f == 1)
				return 1;
			else{
				if(g == -1)
					return -1;
				else if(g == 1)
					return 1;
				else
					return 0;
			}
}
}
}

Contact contact[50000];

int main(){
	double START,END;
	START = clock();
	FILE *infile;
	int blank[1000];
	infile = fopen("C:\\46.txt", "r");
	for(int i = 0; i < 10000; i++){
		fscanf(infile, "%d %s %s %s\n", &contact[i].relation, contact[i].first, contact[i].last, contact[i].phone);
	}
	insertion_sort(contact, 10000, sizeof(Contact), compare);
//	for(int i = 0; i < 10000; i++){
//		printf("%d %s %s %s\n", contact[i].relation, contact[i].first, contact[i].last, contact[i].phone);
//	}
	END = clock();
	cout << endl << "�{������Ҫ�O�G" << (double)clock()/CLOCKS_PER_SEC << " S";
	cout << endl << "�i��B��Ҫ�O���ɶ��G" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	fclose(infile);
}
