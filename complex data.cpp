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

Contact contact[100000];

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

void getString(char* p, char* q){
	int i = 0;
	while(*p != '\0'){
		*q++ = *p++;
		i++;
	}
	*q = '\0';
}
int main(){
	FILE *outfile, *infile;
	int i, a, b;
	int blank[30];
	int num = 30;
	char* name[2];
	outfile = fopen("C:\\46.txt", "w");
	srand( (unsigned)time(NULL));
	for(int i = 0; i < 50000; ++i){
		getRandomName(name);
		getString(name[0], contact[i].first); 
		getString(name[1], contact[i].last);
		getRandomNum(&contact[i].relation);
		getRandomPhone(contact[i].phone);
	}
	for(int i = 0; i < 50000; i++){
		fprintf(outfile, "%d %s %s %s\n", contact[i].relation, contact[i].first, contact[i].last, contact[i].phone);
	}
	fclose(outfile);

	return 0;
}
