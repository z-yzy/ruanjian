	#include<stdio.h> 
	#include<string.h>
	#include<stdlib.h>
	typedef struct node {
		int bian;          //���
		char name[50];    //����
		int price;      //����
		int ru;        //�������
		int cun;       //�������
		int chu;       //��������
		char people[50];  //������
		int rtime;       //���ʱ��
		int ctime;      //����ʱ��
		char b[50];    //��ע
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
	
		printf("###############���Ϲ���ϵͳ##############\n");
	
		node* head=creat();
		node* p1=head;
		for(int i=0;;i++)
		{
			printf("�������Ӧ���������:\n1:��Ӽ�¼\n2:��ʾ����ѯ��¼\n3:�޸ļ�¼\n4:������д���ļ�\n");
			int n;
			scanf("%d",&n);
			node* p=head;
			if(n==1)
			{
				printf("������������ϱ�š����ơ����ۡ����������������������������������ˡ�����ʱ�䡢����ʱ��ͱ�ע(���Ϊ0Ϊ�������)\n");
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
				printf("�����������ѯ�ı�ţ���0Ϊ����\n");
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
							printf("��ţ�%d  ���ƣ�%s  ���ۣ�%d  ���������%d  ���������%d  ����������%d  �����ˣ�%s  ����ʱ�䣺%d  ����ʱ�䣺%d  ��ע��%s\n",p->bian,p->name,p->price,p->ru,p->cun,p->chu,p->people,p->rtime,p->ctime,p->b);
							break;
						}

					}
					p=p->next;
				
				}
				if(c==0)
						printf("�����ң�û�иñ��\n");
			}
			if(n==3)
			{
				printf("�������Ӧ���ϵı��:\n");
				int a,cout=0;
				scanf("%d",&a);
			
				p=p->next;
				while(p!=0)
				{
				
					if(p->bian==a)
					{
						printf("�������ҵ�.����������:\n");
						cout++;
						scanf("%d%s%d%d%d%d%s%d%d%s",&p->bian,p->name,&p->price,&p->ru,&p->cun,&p->chu,p->people,&p->rtime,&p->ctime,p->b);
						break;
					}
					p=p->next;
				
				}
				if(cout==0)
						printf("�����ң�û�иñ��\n");
			}
			if(n==4)
			{
				FILE*fp=0;
				fp=fopen("C:\\shiyan3\\shiyan3.txt","w");
				p=p->next;
			
				while(p!=0)
				{
					fprintf(fp,"��ţ�%d  ���ƣ�%s  ���ۣ�%d  ���������%d  ���������%d  ����������%d  �����ˣ�%s  ����ʱ�䣺%d  ����ʱ�䣺%d  ��ע��%s\n",p->bian,p->name,p->price,p->ru,p->cun,p->chu,p->people,p->rtime,p->ctime,p->b);
				
					p=p->next;
				}
				fclose(fp);
				printf("�ѳɹ������ļ�!");
				system("pause");
				return 0;
			}
	   }
						
	}

