#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

using namespace std;

struct Contact{
	char first[10];
	char last[10];
	int relation;
	char phone[10];
};

	char* firstname[20] = 
	{"James", "John", "Robert", "Jacob", "Oliver",
	 "Michael", "William", "Daniel", "Lucas", "Matthew",
	 "Mary", "Patricia", "Linda", "Barbara", "Elizabeth",
	 "Ella", "Grace", "Chloe", "Amelia", "Sofia"};
	char* lastname[20] = 
	{"Smith", "Jones" , "Williams", "Brown", "Davis",
 	 "Evans" , "Wilson", "Thomas", "Roberts", "Jackson",
     "Taylor", "Walker", "White", "Green", "Lewis",
	 "Harris", "Johnson", "Hughes", "Robinson", "Patel"};

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


int getRandomNum(int* relation){
	*relation = rand() % 5 + 1;
}

void getRandomPhone(char* phone){
	int i;
	phone[0] = '0';
	phone[1] = '9';
	for(i = 2; i < 10; i++){
		phone[i] = '0' + rand() % 10;
	}
}

void getRandomName(char* name[]){
	int i, j;
	i = rand() % 20;
	j = rand() % 20;
	name[0] = firstname[i];
	name[1] = lastname[j];
}

void getString(char* p, char* q){
	int i = 0;
	while(*p != '\0'){
		*q++ = *p++;
		i++;
	}
	*q = '\0';
}

int getStringlen(char* p, char* q){
	int i = 0;
	while(*p++ != '\0')
		i++;
	while(*q++ != '\0')
		i++;
	return i;
}

Contact contact[30];

int main(){
	FILE *outfile, *infile;
	int i, a, b;
	int blank[30];
	int num = 30;
	char* name[2];
	outfile = fopen("C:\\45.txt", "w");
	infile = fopen("C:\\45.txt", "r");
	srand( (unsigned)time(NULL));
	for(int i = 0; i < 30; ++i){
		getRandomName(name);
		getString(name[0], contact[i].first); 
		getString(name[1], contact[i].last);
		getRandomNum(&contact[i].relation);
		getRandomPhone(contact[i].phone);
	}
	
		if(outfile == NULL || infile == NULL){
			printf("Files DOES NOT EXISTS\n");
		}
	
		else{
			for(int i = 0; i < 30; i++){
				fprintf(outfile, "%d %s %s %s\n", contact[i].relation, contact[i].first, contact[i].last, contact[i].phone);
				fscanf(infile,  "%d %s %s %s\n", contact[i].relation, contact[i].first, contact[i].last, contact[i].phone);
			}
		}
		
	qsort (contact, 30, sizeof(Contact), compare);
		
	for(int i = 0; i < 30; i++){
		printf("%d %s %s", contact[i].relation, contact[i].first, contact[i].last);
		blank[i] = getStringlen(contact[i].first, contact[i].last);
		for(int j = 1; j <= 18-blank[i]; j++){
			printf(" ");
		}
		printf("%s\n", contact[i].phone);
		printf("\n");
	}
	fclose(outfile);
	fclose(infile);

	return 0;
}
