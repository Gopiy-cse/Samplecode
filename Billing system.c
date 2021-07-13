#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
typedef struct med{
	char cusn[50];
	char cusm[50];
	char medn[50];
	int qunt,price;
	float tot;	
}med;
void bill();
void main()
{
	int n,i,x;
	FILE *fp=fopen("med.txt","a+");
	med *md;
	printf("Enter how many customer do you want to bill....");
	scanf("\n%d",&n);
	md=(med*)calloc(n,sizeof(med));
	printf ("\n ******Welcome to Med plus****** \n");
	for(i=0;i<n;i++)
	{
		printf("\n Enter customer name:");
		scanf("%s",md[i].cusn);
		printf("\n Enter mobile number:");
		scanf("%s",md[i].cusm);
		printf("\n Enter the medicine name:");
		scanf("%s",md[i].medn);
		printf("\n Enter the Quantity:");
		scanf("%d",&md[i].qunt);
		printf("\n Enter Price:");
		scanf("%d",&md[i].price);
		md[i].tot=md[i].price*md[i].qunt;
		fwrite(&md[i],sizeof(med),1,fp);
	}
		fclose(fp);
		printf("Press any key to go back....");
		getch();
		system("cls");
		printf("\n Enter any key to Add more or\n Enter 1 to make bill:");
		scanf("%d",&x);
		if(x==1)
		{
			bill();
		}
		else{
			main();
		}
	printf("\n Thank you visit again");	
}
void bill(){
	FILE *fp;
	med md1;
	fp=fopen("med.txt","r");
	while(fread(&md1,sizeof(med),1,fp)){
		printf("\n*******************Medicine Bill*********************");
		printf("\n \t Med plus Pharmacy");
		printf("\n  ----------------------------------------------------------------------------");
		printf("\n Customer name \t Customer mobile no \t\t Medicine \t Qty \t rate ");
		printf("\n  ----------------------------------------------------------------------------");
		printf("\n%s",md1.cusn);
		printf("\t\t%s",md1.cusm);
		printf("\t\t%s",md1.medn);
		printf("\t\t%d",md1.qunt);
		printf("\t%d",md1.price);
		printf("\nTotal bill...      :%f only",md1.tot);
		}
		fclose(fp);
		getch();
}
