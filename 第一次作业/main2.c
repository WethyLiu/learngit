#include"duLinkedList.h"
#include"linkedList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define NUL '\0'


LNode*head1=NULL;  //������a 
LNode*head2=NULL;   //������b 
DuLNode*head3=NULL; //˫������a
DuLNode*head4=NULL; //˫������b
static int n;         //������ 

/*��������*/
void welcome();    //���˵� 
void Create();  //��������˵� 
void Single(int link);  //���������� 
void Double(int link);   //����˫������ 
void Circular(int link);  //����ѭ������ 
void Destroy();   //��������˵� 


/*������*/ 
void main()
{
	system("title ������ϰ  ���� ����������");//���ñ��� 
	welcome();
	system("pause");
}

/*�˵�*/
void welcome()
{
	int choice;  
  A:system("cls");
    printf("                                 �˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---��������                   2---��������\n");
	printf("\n");
	printf("             3---��������                   4---������� \n");
	printf("\n");
	printf("             5---��������                   6---�˳��˵�\n");
	printf("\n");		
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("n=%d",n);
	int  f=n;
    if(n==0)
        printf("��ʾ����һ�����Դ�����������   ����1��δ����    ����2��δ����\n");
    else if(n<10)
	        printf("��ʾ����һ�����Դ�����������   ����1��δ����    ����2���Ѵ���\n");
	    else if(n==f/10*10)
	        printf("��ʾ����һ�����Դ�����������   ����1���Ѵ���    ����2��δ����\n");
			else
                printf("��ʾ����һ�����Դ�����������   ����1���Ѵ���    ����2���Ѵ���\n");			
	printf("\n");		        
	printf("��������ţ�\n");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:Create();goto A;
        case 2:goto A;
        case 3:goto A;
        case 4:goto A;
        case 5:goto A;
        case 6:free(head1);free(head2);break;
        default:printf("error\n");goto A;
    } 
    return; 
} 

/*��������*/
void Create()
{
	int choice;
	int link; 
  A:system("cls");
    printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---������                 2---˫������ \n");
	printf("\n");
	printf("             3---ѭ������               4---�˳� \n");
	printf("\n");	
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");	
	printf("��������ţ�\n");
    fflush(stdin);
    scanf("%d",&choice);
	printf("��������Ҫ����������� 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("��������\n");system("pause");return;
	}	
	if((n>=10&&link==1)||(n>0&&n<10&&link==2))
	{
		printf("�޷���������\n");
		system("pause"); 
        return;	
	}   
    switch(choice)
    {
        case 1:Single(link);break;
        case 2:Double(link);break;
        case 3:Circular(link);break;
        case 4:break;
        default:printf("error\n");system("pause");goto A;
    } 
    return; 	
}

/*����������*/
void Single(int link)
{   
	int i;
	LNode*head,*p,*q;
  A:printf("������������\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("�����������������\n");
		goto A;
	}
    head=(LinkedList)malloc(sizeof(LNode));
	q=head;
	for (int j=1;j<=i;j++)
	{
		if(InitList(&p)==1)
		{
            q->next=p;
			q=q->next;
		}
        else
		{
			printf("�����½ڵ���̳���\n");  //���㣺�����ɽ����Ҫɾ�� ����ɾ������
			return;
		}
	}
	if (link==1)
	{
		n=n+10;
		head1=head;
	}
	else 
	{
		n=n+1;
		head2=head;
	}
	
	printf("�ɹ���������\n");
} 
/*����˫������*/
void Double(int link)
{
    	int i;
	DuLNode*head,*p,*q;
  A:printf("������������\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("�����������������\n");
		goto A;
	}
    head=(DuLinkedList)malloc(sizeof(DuLNode));
	q=head;
	head->prior=NULL;
    for (int j=1;j<=i;j++)
	{
		if(InitList_DuL(&p)==1)
		{
            q->next=p;
			p->prior=q;
			q=q->next;
		}
        else
		{
			printf("�����½ڵ���̳���\n");  //���㣺�����ɽ����Ҫɾ�� ����ɾ������
			return;
		}
	}
	if (link==1)
	{
		n=n+20;
		head3=head;
	}
	else 
	{
		n=n+2;
		head4=head;
	}
	
	printf("�ɹ���������\n");
} 
/*����ѭ������*/
void Circular(int link)
{   
	int i;
	LNode*head,*p,*q;
  A:printf("������������\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("�����������������\n");
		goto A;
	}
	int x;
  B:printf("����������β���������ڼ�����㣨����������С�������ȣ�\n");
	fflush(stdin);
	scanf("%d",&x);
	if(x>=i||x<=0)
	{
		printf("������������");
		goto B;
	}
    head=(LinkedList)malloc(sizeof(LNode));
	q=head;
	int j;
	for (j=1;j<=i;j++)
	{
		if(InitList(&p)==1)
		{
            q->next=p;
			q=q->next;
		}
        else
		{
			printf("�����½ڵ���̳���\n");  //���㣺�����ɽ����Ҫɾ�� ����ɾ������
			return;
		}
	}
	for (j=1,p=head;j>x;j++,p=p->next)
	{
		q->next=p;
	}
	if (link==1)
	{
		n=n+30;
		head1=head;
	}
	else 
	{
		n=n+3;
		head2=head;
	} 
}










