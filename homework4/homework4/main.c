#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
	int*arr;
	int N;
}data_info;

void print(double*sort_time);
void input_Random(int*arr,int N);
void input_Reverse(int*arr,int N);
void BubbleSort(int*arr,int N);
void SelectionSort(int*arr,int N);
void InsertionSort(int*arr,int N);
void MergeSort(int*cpy,int p,int r);
void Merge(int*cpy,int p,int q,int r);
void QuickSort(int*cpy,int p,int r,int select);
//int Partition(int*cpy,int p,int r);
int Partition_middle(int*cpy,int p,int r);
int Partition_random(int*cpy,int p,int r);
void HeapSort(int*arr,int N);
void Build_Max_Heap(int*cpy,int N);
void Max_Heapify(int*cpy,int i,int N);
int compare(const void*first,const void*second);

int main(void)
{
	data_info Arr[6];
	int N=1000,i=0,j,m,k=0;
	int*cpy;
	double sort_time[54];
	clock_t start,end;

	srand((unsigned)time(NULL));
	while(i<6){
		if(i==2||i==3)
			N=10000;
		else if(i==4||i==5)
			N=100000;
		Arr[i].N=10,Arr[i].arr=(int*)malloc(sizeof(int)*10);
		input_Random(Arr[i++].arr,N);
		Arr[i].N=N,Arr[i].arr=(int*)malloc(sizeof(int)*N);
		input_Reverse(Arr[i++].arr,N);
	}
	printf("Bubble------------------------------------ \n");
	for(i=0;i<6;i++){
		start=clock();
		BubbleSort(Arr[i].arr,Arr[i].N);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Selection--------------------------------- \n");
	for(i=0;i<6;i++){
		start=clock();
		SelectionSort(Arr[i].arr,Arr[i].N);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Insertion--------------------------------- \n");
	for(i=0;i<6;i++){
		start=clock();
		InsertionSort(Arr[i].arr,Arr[i].N);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Merge------------------------------------- \n");
	for(i=0;i<6;i++){
		start=clock();
		cpy=(int*)malloc(sizeof(int)*Arr[i].N);
		for(j=0;j<Arr[i].N;j++)
			cpy[j]=Arr[i].arr[j];
		MergeSort(cpy,0,Arr[i].N-1);
		for(m=0;m<10;m++)
			printf("%d ",cpy[m]);
		printf("\n");
		free(cpy);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Quick1-------------------------------------- \n");
	
	for(i=0;i<6;i++){
	/*	start=clock();
		cpy=(int*)malloc(sizeof(int)*Arr[i].N);
		for(j=0;j<Arr[i].N;j++)
			cpy[j]=Arr[i].arr[j];
		QuickSort(cpy,0,Arr[i].N-1,1);
		for(m=0;m<10;m++)
			printf("%d ",cpy[m]);
		printf("\n");
		free(cpy);
		end=clock();*/
		sort_time[k++]=0;//(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Quick2-------------------------------------- \n");
	for(i=0;i<6;i++){
		start=clock();
		cpy=(int*)malloc(sizeof(int)*Arr[i].N);
		for(j=0;j<Arr[i].N;j++)
			cpy[j]=Arr[i].arr[j];
		QuickSort(cpy,0,Arr[i].N-1,2);
		for(m=0;m<10;m++)
			printf("%d ",cpy[m]);
		printf("\n");
		free(cpy);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Quick3-------------------------------------- \n");
	for(i=0;i<6;i++){
		start=clock();
		cpy=(int*)malloc(sizeof(int)*Arr[i].N);
		for(j=0;j<Arr[i].N;j++)
			cpy[j]=Arr[i].arr[j];
		QuickSort(cpy,0,Arr[i].N-1,3);
		for(m=0;m<10;m++)
			printf("%d ",cpy[m]);
		printf("\n");
		free(cpy);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Heap--------------------------------- \n");
	for(i=0;i<6;i++){
		start=clock();
		HeapSort(Arr[i].arr,Arr[i].N);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	printf("Library--------------------------------- \n");
	for(i=0;i<6;i++){
		start=clock();
		cpy=(int*)malloc(sizeof(int)*Arr[i].N);
		for(j=0;j<Arr[i].N;j++)
			cpy[j]=Arr[i].arr[j];
		qsort((int*)cpy,Arr[i].N,sizeof(int),compare);
		for(m=0;m<10;m++)
			printf("%d ",cpy[m]);
		printf("\n");
		free(cpy);
		end=clock();
		sort_time[k++]=(end-start)/(double)CLOCKS_PER_SEC;
	}
	print(sort_time);
	return 0;
}

void print(double*sort_time)
{
	int i;

	printf("\n%16s %10s %10s %10s %10s %10s \n","Random1000","Reverse1000","Random10000","Reverse10000","Random100000","Reverse100000");
	printf("Bubble    ");
	for(i=0;i<6;i++)
		printf(" %f   ",sort_time[i]);
	printf("\nSelection  ");
	for(;i<12;i++)
		printf("%f    ",sort_time[i]);
	printf("\nInsertion  ");
	for(;i<18;i++)
		printf("%f    ",sort_time[i]);
	printf("\nMerge     ");
	for(;i<24;i++)
		printf(" %f   ",sort_time[i]);
	printf("\nQuick1    ");
	for(;i<30;i++)
		printf("     -      ",sort_time[i]);
	printf("\nQuick2    ");
	for(;i<36;i++)
		printf(" %f   ",sort_time[i]);
	printf("\nQuick3    ");
	for(;i<42;i++)
		printf(" %f   ",sort_time[i]);
	printf("\nHeap      ");
	for(;i<48;i++)
		printf(" %f   ",sort_time[i]);
	printf("\nLibrary   ");
	for(;i<54;i++)
		printf(" %f   ",sort_time[i]);
	printf("\n");
}

void input_Random(int*arr,int N)
{
	int j;

	for(j=0;j<10;j++)
		arr[j]=rand()%N+1;
}

void input_Reverse(int*arr,int N)
{
	int j,value=N;

	for(j=0;j<N;j++){
		arr[j]=value;
		value--;
	}
}

void BubbleSort(int*arr,int N)
{
	int i,last,temp;
	int*cpy;
	cpy=(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
		cpy[i]=arr[i];
	for(last=N-1;last>0;last--){
		for(i=0;i<last;i++)
			if(cpy[i]>cpy[i+1]){
				temp=cpy[i];
				cpy[i]=cpy[i+1];
				cpy[i+1]=temp;
			}			
	}
	for(i=0;i<10;i++)
		printf("%d ",cpy[i]);
	printf("\n");
	free(cpy);
}

void SelectionSort(int*arr,int N)
{
	int i,last,max,index,temp;
	int*cpy;
	cpy=(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
		cpy[i]=arr[i];
	for(last=N-1;last>0;last--){
		max=cpy[last],index=last;
		for(i=0;i<=last;i++)
			if(max<cpy[i])
				max=cpy[i],index=i;
		temp=cpy[last];
		cpy[last]=cpy[index];
		cpy[index]=temp;
	}
	for(i=0;i<10;i++)
		printf("%d ",cpy[i]);
	printf("\n");
	free(cpy);
}

void InsertionSort(int*arr,int N)
{
	int i,j,temp;
	int*cpy;
	cpy=(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
		cpy[i]=arr[i];
	for(i=1;i<N;i++){
		temp=cpy[i];
		j=i-1;
		while(j>=0&&temp<cpy[j]){
			cpy[j+1]=cpy[j];
			j-=1;
		}
		cpy[j+1]=temp;
	}
	for(i=0;i<10;i++)
		printf("%d ",cpy[i]);
	printf("\n");
	free(cpy);
}

void MergeSort(int*cpy,int p,int r)
{
	int q;
	if(p<r){
		q=(p+r)/2;
		MergeSort(cpy,p,q);
		MergeSort(cpy,q+1,r);
		Merge(cpy,p,q,r);
	}
}
void Merge(int*cpy,int p,int q,int r)
{
	int i=p,j=q+1,k=p;
	int tmp[100000];
	while(i<=q&&j<=r){
		if(cpy[i]<=cpy[j])
			tmp[k++]=cpy[i++];
		else
			tmp[k++]=cpy[j++];
	}
	while(i<=q)
		tmp[k++]=cpy[i++];
	while(j<=r)
		tmp[k++]=cpy[j++];
	for(i=p;i<=r;i++)
		cpy[i]=tmp[i];
}

void QuickSort(int*cpy,int p,int r,int select)
{
	int q;
	if(p<r){
	/*	if(select==1)
			q=Partition(cpy,p,r);*/
		if(select==2)
			q=Partition_middle(cpy,p,r);
		if(select==3)
			q=Partition_random(cpy,p,r);
		QuickSort(cpy,p,q-1,select);
		QuickSort(cpy,q+1,r,select);
	}
}
/*
int Partition(int*cpy,int p,int r)
{
	int x,i,j,temp;
	x=cpy[r];//마지막값을 피봇
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(cpy[j]<=x){
			i+=1;
			temp=cpy[i];
			cpy[i]=cpy[j];
			cpy[j]=temp;
		}
	}
	temp=cpy[i+1];
	cpy[i+1]=cpy[r];
	cpy[r]=temp;
	return i+1;
}*/

int Partition_middle(int*cpy,int p,int r)
{
	int mid=(p+r)/2;
	int x,i,j,temp,index=0;
	//중간값을 피봇
	if((cpy[p]>=cpy[mid]&&cpy[p]<=cpy[r])||(cpy[p]>=cpy[r]&&cpy[p]<=cpy[mid]))
		x=cpy[p],cpy[p]=cpy[r],cpy[r]=x;
	else if((cpy[mid]>=cpy[p]&&cpy[mid]<=cpy[r])||(cpy[mid]>=cpy[r]&&cpy[mid]<=cpy[p]))
		x=cpy[mid],cpy[mid]=cpy[r],cpy[r]=x;
	else
		x=cpy[r];

	i=p-1;
	for(j=p;j<r;j++)
	{
		if(cpy[j]<=x){
			i+=1;
			temp=cpy[i];
			cpy[i]=cpy[j];
			cpy[j]=temp;
		}
	}
	temp=cpy[i+1];
	cpy[i+1]=cpy[r];
	cpy[r]=temp;
	return i+1;
}

int Partition_random(int*cpy,int p,int r)
{
	int index;
	int x,i,j,temp;

	index=rand()%(r-p+1)+p;
	x=cpy[index],cpy[index]=cpy[r],cpy[r]=x;//랜덤한값을 피봇
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(cpy[j]<=x){
			i+=1;
			temp=cpy[i];
			cpy[i]=cpy[j];
			cpy[j]=temp;
		}
	}
	temp=cpy[i+1];
	cpy[i+1]=cpy[r];
	cpy[r]=temp;
	return i+1;
}

void HeapSort(int*arr,int N)
{
	int i,temp;
	int*cpy;

	cpy=(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
		cpy[i]=arr[i];
	N--;
	Build_Max_Heap(cpy,N);
	for(i=N;i>0;i--){
		temp=cpy[0];
		cpy[0]=cpy[i];
		cpy[i]=temp;
		N--;
		Max_Heapify(cpy,0,N);
	}
	for(i=0;i<10;i++)
		printf("%d ",cpy[i]);
	printf("\n");
	free(cpy);
}

void Build_Max_Heap(int*cpy,int N)
{
	int i;

	for(i=N/2;i>=0;i--)
		Max_Heapify(cpy,i,N);
}

void Max_Heapify(int*cpy,int i,int N)
{
	int k,temp;

	if(2*i+1>N)
		return;//자식노드없으면 리턴
	if(cpy[2*i+1]>cpy[2*i+2]||2*i+2>N)
		k=2*i+1;
	else 
		k=2*i+2;
	if(cpy[i]>=cpy[k])
		return;
	temp=cpy[i];
	cpy[i]=cpy[k];
	cpy[k]=temp;
	Max_Heapify(cpy,k,N);
}

int compare(const void*first,const void*second)
{
	if(*(int*)first>*(int*)second)
		return 1;
	else if(*(int*)first<*(int*)second)
		return -1;
	else
		return 0;
}