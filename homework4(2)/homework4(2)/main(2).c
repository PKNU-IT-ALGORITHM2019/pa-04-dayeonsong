#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char*IP;
	char*Time;
	char*URL;
	char*Status;
}CSV;

void read_file();
void sort();
int compare_t(const void*first,const void*second);
int compare_ip(const void*first,const void*second);
void print();

CSV item[50000];
int count;
int sign;

int main(void)
{
	char str[10];
	
	while(1)
	{
		printf("$ ");
		scanf("%s",str);
		if(strcmp(str,"read")==0){
			printf("input filename: ");
			read_file();
		}
		else if(strcmp(str,"sort")==0)
			sort();
		else if(strcmp(str,"print")==0)
			print();
		else if(strcmp(str,"exit")==0)
			break;
		else
			printf("Please re-enter. \n");
	}
	return 0;
}

void read_file()
{
	char filename[100];
	char str[1000];
	FILE*fp;
	
	scanf("%s",filename);
	fp=fopen(filename,"rt");
	if(fp==NULL){
		puts("Failed to open file!");
		return;
	}
	fgets(str,sizeof(str),fp);
	while(fgets(str,sizeof(str),fp)!=NULL){
		item[count].IP=strdup(strtok(str,","));
		item[count].Time=strdup(strtok(NULL,","));
		item[count].URL=strdup(strtok(NULL,","));
		item[count].Status=strdup(strtok(NULL,"\n"));
		count++;
	}
	fclose(fp);
	puts("Success read file!");
	return;
}

void sort()
{
	char str[5];

	scanf("%s",str);
	if(strcmp(str,"-t")==0)
		qsort((CSV*)item,count,sizeof(CSV),compare_t),sign=1;
	else if(strcmp(str,"-ip")==0)
		qsort((CSV*)item,count,sizeof(CSV),compare_ip),sign=2;
	else
		printf("failed! \n");
}


int compare_t(const void*first,const void*second)
{
	return strcmp(((CSV*)first)->Time,((CSV*)second)->Time);
}

int compare_ip(const void*first,const void*second)
{
	if(strcmp(((CSV*)first)->IP,((CSV*)second)->IP)==0)
		return strcmp(((CSV*)first)->Time,((CSV*)second)->Time);
	else
		return strcmp(((CSV*)first)->IP,((CSV*)second)->IP);
}

void print()
{
	int i;

	if(sign==1)
		for(i=0;i<count;i++)
			printf("%s \n   %s \n   %s \n   %s \n",item[i].Time,item[i].IP,item[i].URL,item[i].Status);
	else if(sign==2)
		for(i=0;i<count;i++)
			printf("%s \n   %s \n   %s \n   %s \n",item[i].IP,item[i].Time,item[i].URL,item[i].Status);
	else
		for(i=0;i<count;i++)
			printf("%s \n%s \n%s \n%s \n",item[i].IP,item[i].Time,item[i].URL,item[i].Status);
}

