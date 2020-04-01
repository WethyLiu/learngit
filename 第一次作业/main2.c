#include"duLinkedList.h"
#include"linkedList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define NUL '\0'


LNode*head1=NULL;  //单链表a 
LNode*head2=NULL;   //单链表b 
DuLNode*head3=NULL; //双向链表a
DuLNode*head4=NULL; //双向链表b
static int n;         //操作数 

/*函数声明*/
void welcome();    //主菜单 
void Create();  //创建链表菜单 
void Single(int link);  //创建单链表 
void Double(int link);   //创建双向链表 
void Circular(int link);  //创建循环链表 
void Destroy();   //销毁链表菜单 


/*主函数*/ 
void main()
{
	system("title 链表练习  —— 刘欣羽制作");//设置标题 
	welcome();
	system("pause");
}

/*菜单*/
void welcome()
{
	int choice;  
  A:system("cls");
    printf("                                 菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---创建链表                   2---销毁链表\n");
	printf("\n");
	printf("             3---输入数据                   4---清空链表 \n");
	printf("\n");
	printf("             5---其他操作                   6---退出菜单\n");
	printf("\n");		
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("n=%d",n);
	int  f=n;
    if(n==0)
        printf("提示：你一共可以创建两条链表   链表1：未创建    链表2：未创建\n");
    else if(n<10)
	        printf("提示：你一共可以创建两条链表   链表1：未创建    链表2：已创建\n");
	    else if(n==f/10*10)
	        printf("提示：你一共可以创建两条链表   链表1：已创建    链表2：未创建\n");
			else
                printf("提示：你一共可以创建两条链表   链表1：已创建    链表2：已创建\n");			
	printf("\n");		        
	printf("请输入序号：\n");
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

/*创建链表*/
void Create()
{
	int choice;
	int link; 
  A:system("cls");
    printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---单链表                 2---双向链表 \n");
	printf("\n");
	printf("             3---循环链表               4---退出 \n");
	printf("\n");	
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");	
	printf("请输入序号：\n");
    fflush(stdin);
    scanf("%d",&choice);
	printf("请输入需要生成链表代号 1/2:\n");
	fflush(stdin);
	scanf("%d",&link);
	if (link!=1&&link!=2)
	{
		printf("代号有误\n");system("pause");return;
	}	
	if((n>=10&&link==1)||(n>0&&n<10&&link==2))
	{
		printf("无法新增链表\n");
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

/*创建单链表*/
void Single(int link)
{   
	int i;
	LNode*head,*p,*q;
  A:printf("请输入链表长度\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("请输入大于零整数！\n");
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
			printf("生成新节点过程出错\n");  //不足：已生成结点需要删掉 引用删除函数
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
	
	printf("成功创建链表！\n");
} 
/*创建双向链表*/
void Double(int link)
{
    	int i;
	DuLNode*head,*p,*q;
  A:printf("请输入链表长度\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("请输入大于零整数！\n");
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
			printf("生成新节点过程出错\n");  //不足：已生成结点需要删掉 引用删除函数
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
	
	printf("成功创建链表！\n");
} 
/*创建循环链表*/
void Circular(int link)
{   
	int i;
	LNode*head,*p,*q;
  A:printf("请输入链表长度\n");
	fflush(stdin);
	scanf("%d",&i);
	if(i<=0)
	{
		printf("请输入大于零整数！\n");
		goto A;
	}
	int x;
  B:printf("请输入链表尾部连接至第几个结点（输入数据请小于链表长度）\n");
	fflush(stdin);
	scanf("%d",&x);
	if(x>=i||x<=0)
	{
		printf("输入数据有误！");
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
			printf("生成新节点过程出错\n");  //不足：已生成结点需要删掉 引用删除函数
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










