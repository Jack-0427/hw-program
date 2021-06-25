#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <time.h> 
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

int compare(Contact* p1, Contact* p2)
{
	int d = compare_relation(p1->relation, p2->relation);
	int e = compare_string(p1->first, p2->first);
	int f = compare_string(p1->last, p2->last);
	int g = compare_phone(p1->phone, p2->phone);
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

int getStringlen(char* p, char* q){
	int i = 0;
	while(*p++ != '\0')
		i++;
	while(*q++ != '\0')
		i++;
	return i;
}

void insertion_sort(Contact* base, int n, size_t size, int (*compar)(Contact*, Contact*)){
	int i = 0, j, a;
	Contact* tmp[n];
	Contact* temp;
	Contact p[n];
	for(int i = 0; i < n; i++){
		tmp[i] = (Contact*)malloc(sizeof(Contact));
		tmp[i] = base+i; 
	}
	for(i = 0; i < n; i++){
		j = i;
		if(!temp)	temp = (Contact*)malloc(sizeof(Contact));
		while(j > 0 && compare(tmp[j], tmp[j-1]) == -1){
			temp = tmp[j];
			tmp[j] = tmp[j-1];
			tmp[j-1] = temp;
			j--;
		}
	}
	for(i = 0; i < n; i++){
		strcpy(p[i].first, tmp[i]->first);
		strcpy(p[i].last, tmp[i]->last);
		strcpy(p[i].phone, tmp[i]->phone);
		p[i].relation = tmp[i]->relation;
	}
	for(i = 0; i < n; i++){
		strcpy(base[i].first, p[i].first);
		strcpy(base[i].last, p[i].last);
		strcpy(base[i].phone, p[i].phone);
		base[i].relation = p[i].relation;
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
	cout << endl << "程式執行所花費：" << (double)clock()/CLOCKS_PER_SEC << " S";
	cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	fclose(infile);
}

