#include<stdio.h>
#include<string.h>
void main(){
	printf("Character Count\n");
	int x[100],y[30],i=0,j=0,count,num,n,total=0;
	printf("enter # of frames :");
	scanf("%d",&num);
	for(int k=0;k<num;k++){
		printf("Enter the frame length: ");
		scanf("%d",&n);
		total+=n+1;
		printf("Enter the input frame: ");
		for(int a=0;a<n;a++){
			scanf("%d",&y[a]);
		}
		x[i++]=n+1;
		for(int a=0;a<n;a++){
			x[i] = y[a];
			i++;
		}
		printf("\n");
	}
	printf("\nAfter Stuffing\n");
	for(int k=0;k<total;k++){
		printf("%d",x[k]);
	}
	printf("\n");
	
}
