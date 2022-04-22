#include <stdio.h>
#include <stdlib.h>

#define NULL 0
//链表结点
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
//边表结点
typedef struct Nodev
{
    int enter;
    int value;
    Node *start;
} Nodev;


//可视化
void draw(int dependencies[][2],int dlen,FILE *fp)
{
    fprintf(fp,"digraph \tmygraph {\n");
    for (int i = 0; i < dlen; ++i)
    {
        fprintf(fp,"%d -> %d;\n",dependencies[i][0],dependencies[i][1]);
    }
    fprintf(fp,"}");
}

void main()
{

    // 定义测试变量
    int n = 4;
    int k = 2;
    int dependencies[][2] = {{2, 1},
                             {3, 1},
                             {1, 4}};
    //定义dependencies的长度
    int dlen = 3;

 /* // 定义测试变量
    int n = 9;
    int k = 3;
    int dependencies[][2] = {{1, 5},
                             {2, 6},
                             {3, 7},
                             {4, 8},
                             {5, 9},
                             {6, 9},
                             {7, 9},
                             {8, 9}
                             };
    //定义dependencies的长度
    int dlen = 8;*/


    //初始化
    Nodev nodevs[n];
    for (int i = 0; i < n; ++i)
    {
        nodevs[i].enter = 0;
        nodevs[i].start = NULL;
        nodevs[i].value = i + 1;
    }

    int from, to;
    Node *temp = NULL;
    // 用dependencies初始化整个邻接表
    for (int i = 0; i < dlen; ++i)
    {
        from = dependencies[i][0];
        to = dependencies[i][1];
        nodevs[to - 1].enter += 1;
        temp = nodevs[from - 1].start;
        // 如果链为空
        if (temp == NULL)
        {
            Node *tempnode = (Node *) malloc(sizeof(Node));
            tempnode->next = NULL;
            tempnode->value = to;
            nodevs[from-1].start = tempnode;
        }
        else
            { //否则放在链后
            while (temp->next != NULL)
                temp = temp->next;
            Node *tempnode = (Node *) malloc(sizeof(Node));
            tempnode->value = to;
            tempnode->next = NULL;
            temp->next = tempnode;
        }
    }
    //printf("finish the init\n");

    //执行计算，用队列实现
    int begin = 0, end = 0;
    int nodeQuen[dlen];
    //首先将入度为0的结点扫入队列
    for (int i = 0; i < dlen; ++i)
    {
        if (nodevs[i].enter == 0)
        {
            nodeQuen[end++] = nodevs[i].value;
        }
    }
/*    for (int i = 0; i < n; ++i)
    {
        printf("%d+%d \t",nodevs[i].value,nodevs[i].enter);
    }
    while (begin<end){
        printf("%d \t",nodeQuen[begin++]);
    }
    return;*/

    //开始拓扑排序
    int count = 0;
    while (begin < end)
    {
        int choosed = k;
        int tempEnd = end;
        printf("the %ds item learned:\n",count+1);
        while (begin < tempEnd && choosed > 0)
        {
            printf("%d\t", nodeQuen[begin]);
            //将该结点连接的结点的入度减一
            struct Node *tem = nodevs[nodeQuen[begin] - 1].start;
            while (tem != NULL)
            {
                nodevs[tem->value - 1].enter -= 1;
                if (nodevs[tem->value - 1].enter == 0)
                    nodeQuen[end++] = tem->value;
                tem = tem->next;
            }
            --choosed;
            ++begin;

        }
        printf("\n");
        ++count;

    }
    printf("so the total numbers of items is: %d\n",count);

    //生成可视化dot文件
    FILE *fp=fopen("./graph.dot","w+");
    draw(dependencies,dlen,fp);
}