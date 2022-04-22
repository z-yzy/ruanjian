	#include<stdio.h> 
	#include<string.h>
	#include<stdlib.h>
	typedef struct node {
		int bian;          //编号
		char name[50];    //名称
		int price;      //单价
		int ru;        //入库数量
		int cun;       //库存数量
		int chu;       //出库数量
		char people[50];  //保管人
		int rtime;       //入库时间
		int ctime;      //出库时间
		char b[50];    //备注
		struct node* next;
	}node;
	node* creat()
	{
		node* p=(node*)malloc(sizeof(node));
		p->next=0;
		return p;
	}
	int main()
	{
	
		printf("###############材料管理系统##############\n");
	
		node* head=creat();
		node* p1=head;
		for(int i=0;;i++)
		{
			printf("请输入对应操作的序号:\n1:添加记录\n2:显示、查询记录\n3:修改记录\n4:结束并写入文件\n");
			int n;
			scanf("%d",&n);
			node* p=head;
			if(n==1)
			{
				printf("请依次输入材料编号、名称、单价、入库数量、库存数量、出库数量、保管人、进货时间、出货时间和备注(编号为0为输入结束)\n");
				for(int i=0;;i++)
				{
					int s;
					scanf("%d",&s);
				
					if(s==0)
							break;
				
					else
					{
						node* pnew=(node*)malloc(sizeof(node));
						pnew->bian=s;
						scanf("%s%d%d%d%d%s%d%d%s",pnew->name,&pnew->price,&pnew->ru,&pnew->cun,&pnew->chu,pnew->people,&pnew->rtime,&pnew->ctime,pnew->b);
						pnew->next=0;
						p1->next=pnew;
						p1=p1->next;
					}
				}
			}
			if(n==2)
			{
				printf("请输入你想查询的编号，以0为结束\n");
				int a[50],sum = 0,c=0;
				for(int i=0;;i++)
				{
					scanf("%d",&a[i]);
					if(a[i]==0)
						break;
					sum++;
				}
				p=p->next;
			
				while(p!=0)
				{				
					for(int i=0;i<sum;i++)
					{  
					
						if (a[i]==p->bian)
						{c++;
							printf("编号：%d  名称：%s  单价：%d  入库数量：%d  库存数量：%d  出库数量：%d  保管人：%s  进货时间：%d  出货时间：%d  备注：%s\n",p->bian,p->name,p->price,p->ru,p->cun,p->chu,p->people,p->rtime,p->ctime,p->b);
							break;
						}

					}
					p=p->next;
				
				}
				if(c==0)
						printf("经查找，没有该编号\n");
			}
			if(n==3)
			{
				printf("请输入对应材料的编号:\n");
				int a,cout=0;
				scanf("%d",&a);
			
				p=p->next;
				while(p!=0)
				{
				
					if(p->bian==a)
					{
						printf("材料已找到.请重新输入:\n");
						cout++;
						scanf("%d%s%d%d%d%d%s%d%d%s",&p->bian,p->name,&p->price,&p->ru,&p->cun,&p->chu,p->people,&p->rtime,&p->ctime,p->b);
						break;
					}
					p=p->next;
				
				}
				if(cout==0)
						printf("经查找，没有该编号\n");
			}
			if(n==4)
			{
				FILE*fp=0;
				fp=fopen("C:\\shiyan3\\shiyan3.txt","w");
				p=p->next;
			
				while(p!=0)
				{
					fprintf(fp,"编号：%d  名称：%s  单价：%d  入库数量：%d  库存数量：%d  出库数量：%d  保管人：%s  进货时间：%d  出货时间：%d  备注：%s\n",p->bian,p->name,p->price,p->ru,p->cun,p->chu,p->people,p->rtime,p->ctime,p->b);
				
					p=p->next;
				}
				fclose(fp);
				printf("已成功存入文件!");
				system("pause");
				return 0;
			}
	   }
						
	}

