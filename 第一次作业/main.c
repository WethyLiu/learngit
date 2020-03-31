#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define NUL '\0'

/*结点结构体*/ 
typedef struct node{
	struct node*front;
	long int a;
	struct node*next;
}Node; 

Node*head1=NULL;  //链表a 
Node*head2=NULL;   //链表b 
static int n;         //操作数 

/*函数声明*/
void welcome();    //主菜单 
void Create();  //创建链表菜单 
void Single();  //创建单链表 
void Double();   //创建双向链表 
void Circular();  //创建循环链表 
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
    if(n==0)
        printf("提示：你一共可以创建两条链表   a链表：未创建    b链表：未创建\n");
    else if(n<10)
	        printf("提示：你一共可以创建两条链表   a链表：已创建    b链表：未创建\n");
	    else
	        printf("提示：你一共可以创建两条链表   a链表：已创建    b链表：已创建\n");
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
    switch(choice)
    {
        case 1:Single(n);break;
        case 2:Double(n);break;
        case 3:Circular(n);break;
        case 4:break;
        default:printf("error\n");goto A;
    } 
    return; 	
}

/*创建单链表*/
void Single()
{  
	if(n>10) 
	{
		printf("无法新增链表\n");
		system("pause"); 
    	return;	
	}   
    else
    {
        printf("新增链表成功\n");	
        n=n*10+1;
        system("pause");
	}
   Node*head; //创建链表操作    
    if(n==1)
	    head1=head;
    else
        head2=head;  
	printf("n=%d",n); 
} 
/*创建双向链表*/
void Double()
{
	if(n>10) 
	{
		printf("无法新增链表\n");
		system("pause");
    	return;	
	}   
    else
    {
        printf("新增链表成功\n");	
        n=n*10+2;
        system("pause");
	}
   Node*head;   //创建链表操作     
    if(n==2)
	    head1=head;
    else
        head2=head; 
	printf("n=%d",n);  	
} 
/*创建循环链表*/
void Circular()
{
	if(n>10) 
	{
		printf("无法新增链表\n");
		system("pause");
		return;
    }
    else
    {
        printf("新增链表成功\n");	
        n=n*10+3;
        system("pause");
	}
   Node*head;  //创建链表操作      
    if(n==3)
	    head1=head;
    else
        head2=head;
	printf("n=%d",n);   
} 










 