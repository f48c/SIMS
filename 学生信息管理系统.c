#include "stdio.h"
#include "string.h"

struct yh
{
    char name[20];
    char pass[10];
    int f;
}std1[1000];

struct student
{
    char name[20];
    char num[15];
    char ssnum[5];
    char qqnum[15];
    char telnum[15];
}stu[1000];




int cf(int f,char n[])
{
    FILE *fp;
    char ch[20],pass[10];
    int i=0,k=0;
    if((fp=fopen("usdatal.txt","r"))==NULL)
    {
        printf("不能打开文件");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d",std1[i].name,std1[i].pass,&std1[i].f);
        if(strcmp(n,std1[i].name)==0&&std1[i].f==f)
        {
            printf("═══════此人已存在，请重新输入═══════\n");
            getchar();
            printf("请重新输入姓名:");
            gets(ch);
            printf("请重新输入密码:");
            gets(pass);
            printf("请重新输入级别:");
            scanf("%d",&f);
            if(cf(f,ch)==0)
            {	
                if((fp=fopen("usdatal.txt","a"))==NULL)
                {
                    printf("不能打开信息文件");
                    exit(0);
                }
                fprintf(fp,"%s %s %d\n",ch,pass,f);
                fclose(fp);
                k=1;
                return k;
            }
            k=1;
        }
        i++;
    }
    fclose(fp);
    return k;
    
}




void print()
{
    FILE *fp;
    int j=0,n;
    if((fp=fopen("usdatal.txt","r"))==NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d",std1[j].name,std1[j].pass,&std1[j].f);
        j++;
    }
    fclose(fp);
    n=j;
    for(j=0;j<n-1;j++)
        printf("%20s%5d\n",std1[j].name,std1[j].f);
    return;
}





void add()
{
    FILE *fp;
    int f;
    char ch[20],pass[10];
    if((fp=fopen("usdatal.txt","a"))==NULL)
    {
        printf("不能打开信息文件\n");
        exit(0);
    }
    printf("请输入姓名:");
    gets(ch);
    printf("请输入密码:");
    gets(pass);
    printf("请输入级别:");
    scanf("%d",&f);
    if(cf(f,ch)==0)
        fprintf(fp,"%s %s %d\n",ch,pass,f);
    fclose(fp);
    printf("═════════用户创建结束═════════\n");
    printf("创建后结果如下\n");
    printf("\n%20s%5s\n","用户名","级别");
    print();
    return;
}




void del(char name[])
{
    FILE *fp;
    int i=0,n;
    if((fp=fopen("usdatal.txt","r"))==NULL)
    {  
        printf("不能打开文件\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d",std1[i].name,std1[i].pass,&std1[i].f);
        if(strcmp(name,std1[i].name)!=0||feof(fp)!=0)
            i++;
    }
    fclose(fp);
    if((fp=fopen("usdatal.txt","w"))==NULL)
    {   
        printf("不能打开文件\n");
        exit(0);
    }
    for(n=0;n<i-1;n++)
        fprintf(fp,"%s %s %d\n",std1[n].name,std1[n].pass,std1[n].f);
    fclose(fp);
    printf("删除后结果如下\n");
    printf("\n%20s%5s\n","用户名","级别");
    print();
    return;
}

void edits(char nam[])
{
    FILE *fp;
    int i=0,n,lb;
    char yhm[20],pw[10];
    printf("请输入修改后用户的姓名:");
    gets(yhm);
    printf("请输入修改后的密码:");
    gets(pw);
    printf("请输入修改后的类别:");
    scanf("%d",&lb);
    if((fp=fopen("usdatal.txt","r"))==NULL)
    {   printf("不能打开文件\n");
        exit(0);
    }
    while(!feof(fp))
    { fscanf(fp,"%s %s %d",std1[i].name,std1[i].pass,&std1[i].f);
        if(strcmp(nam,std1[i].name)==0)
        {strcpy(std1[i].name,yhm);strcpy(std1[i].pass,pw);std1[i].f=lb;}
        i++;
    }
    fclose(fp);
    if((fp=fopen("usdatal.txt","w"))==NULL)
    {
        printf("不能打开文件");
        exit(0);
    }
    for(n=0;n<i-1;n++)
        fprintf(fp,"%s %s %d\n",std1[n].name,std1[n].pass,std1[n].f);
    fclose(fp);
    printf("修改后结果如下\n");
    printf("\n%20s%5s\n","用户名","级别");
    print();
    return;
}







void yhgl()
{int sele;
    char username[20];   
    do
    {  printf("              ╭══════════╮              \n");  
        printf("╭══════╣   用  户  管  理   ╠══════╮\n");  
        printf("║            ╰══════════╯            ║\n");  
        printf("║     【1】创建用户            【2】删除用户     ║\n");  
        printf("║                                                ║\n");  
        printf("║     【3】修改用户            【0】退出系统     ║\n");  
        printf("║                                                ║\n");  
        printf("╰════════════════════════╯\n");  
        printf("═══════请输入0-3  选择相应功能═══════\n");
        scanf("%d",&sele);getchar();
        switch(sele)
        {case 1:printf("请输入创建的用户信息\n");add();break;
        case 2:printf("已有用户信息如下\n");printf("\n%20s%5s\n","用户名","级别");print();printf("请输入要删除用户的姓名\n");gets(username);del(username);break;
        case 3:printf("已有用户信息如下\n");printf("\n%20s%5s\n","用户名","级别");print();printf("请输入要修改用户的姓名\n");gets(username);edits(username);break;
        case 0:exit(0);
        default: yhgl();
        }
    }while(1);
}







int cft(int i,char n[])
{  FILE *fp;
    char ch[20];
    int j=0,k=0;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {
        printf("不能打开信息文件");
        exit(0);
    }
    do{
        fread(stu[j].name,sizeof(struct student),1,fp);
        if(strcmp(n,stu[j].name)==0)
        {
            printf("═══════此人已存在，请重新输入═══════\n");
            printf("请重新输入姓名:");
            gets(ch);
            if(cft(i,ch)==0)strcpy(stu[i].name,ch);
            k=1;
        }
        j++;
    }while(!feof(fp));
    fclose(fp);
    return k;
    
}






void printt()
{
    FILE *fp;
    int j=0,n;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {
        printf("不能打开信息文件\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fread(&stu[j],sizeof(struct student),1,fp);
        j++;
    }
    fclose(fp);
    n=j;
    for(j=0;j<n-1;j++)
        printf("%20s%15s%8s%15s%15s\n",stu[j].name,stu[j].num,stu[j].ssnum,stu[j].qqnum,stu[j].telnum);
    return;
}





void addsc()
{
    FILE *fp;
    int i;
    char ch[20];
    if((fp=fopen("学生信息文件.dat","ab"))==NULL)
    {
        printf("不能打开信息文件");
        exit(0);
    }
    i=0;
    printf("请输入姓名:");
    gets(ch);
    if(cft(i,ch)==0)strcpy(stu[i].name,ch);
    printf("请输入学号:");
    gets(stu[i].num);
    printf("请输入寝室号:");
    gets(stu[i].ssnum);
    printf("请输入QQ号:");
    gets(stu[i].qqnum);
    printf("请输入电话号:");
    gets(stu[i].telnum);
    fwrite(&stu[i],sizeof(struct student),1,fp);
    fclose(fp);
    printf("═════════信息录入结束═════════\n");
    printf("录入后结果如下\n");
    printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
    printt();
    return;
}





void delt(char name[])
{
    FILE *fp;
    int i=0,n;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {   printf("不能打开信息文件\n");
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(name,stu[i].name)!=0||feof(fp))i++;
    }
    fclose(fp);
    if((fp=fopen("学生信息文件.dat","wb"))==NULL)
    {   printf("不能打开信息文件\n");
        exit(0);
    }
    for(n=0;n<i-1;n++)
        fwrite(&stu[n],sizeof(struct student),1,fp);
    fclose(fp);
    printf("删除后结果如下\n");
    printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
    printt();
    return;
}





void editst(char nam[])
{
    FILE *fp;
    int i=0,n;
    char ch[20];
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {   printf("不能打开信息文件\n");
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[i],sizeof(struct student),1,fp);
        i++;
    }
    fclose(fp);
    n=i;
    for(i=0;i<n-1;i++)
        if(strcmp(nam,stu[i].name)==0)
        {
            printf("请输入修改后的学号:");
            gets(stu[i].num);
            printf("请输入修改后的寝室号:");
            gets(stu[i].ssnum);
            printf("请输入修改后的QQ号:");
            gets(stu[i].qqnum);
            printf("请输入修改后的电话号:");
            gets(stu[i].telnum);
        }
    if((fp=fopen("学生信息文件.dat","wb"))==NULL)
    {   printf("不能打开信息文件\n");
        exit(0);
    }
    for(i=0;i<n-1;i++)
        fwrite(&stu[i],sizeof(struct student),1,fp);
    fclose(fp);
    printf("修改后结果如下\n");
    printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
    printt();
    return;
}





void xxgl()
{int sel;
    char ch[20];
    do
    {   printf("              ╭══════════╮              \n");  
        printf("╭══════╣   信  息  管  理   ╠══════╮\n");  
        printf("║            ╰══════════╯            ║\n");  
        printf("║     【1】录入信息          【2】删除信息       ║\n");  
        printf("║                                                ║\n");  
        printf("║     【3】修改信息          【0】返回上个界面   ║\n");  
        printf("║                                                ║\n");  
        printf("╰════════════════════════╯\n");  
        printf("═══════请输入0-3  选择相应功能═══════\n");
        scanf("%d",&sel);getchar();
        switch(sel)
        {case 1:addsc();break;
        case 2:printf("已有学生信息如下\n");printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");printt();printf("请输入要删除信息的姓名");gets(ch);delt(ch);break;
        case 3:printf("已有学生信息如下\n");printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");printt();printf("请输入要修改信息的姓名");gets(ch);editst(ch);break;
        case 0:return;
        default: xxgl();
        }
    }while(1);
}





void pxname(char n[])
{
    FILE *fp,*fp1,*fp2;
    int m=0,i,j,k;
    char ch[20];
    if(n[0]=='s'||n[0]=='S')k=1;
    else if(n[0]=='j'||n[0]=='J')k=-1;
    else return;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[m],sizeof(struct student),1,fp);
        m++;
    }
    fclose(fp);
    for(i=0;i<m-2;i++)
        for(j=i;j<m-1;j++)
            if(strcmp(stu[i].name,stu[j].name)==k)
            {
                stu[m+1]=stu[j];
                stu[j]=stu[i];
                stu[i]=stu[m+1];
                
            }
    printf("排序后结果如下:\n");
    printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
    for(i=0;i<m-1;i++)
        printf("%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    if((fp1=fopen("按姓名升序排序.txt","w"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    if(k==1)
    {
        fprintf(fp1,"\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
        for(i=0;i<m-1;i++)
            fprintf(fp1,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp1);
    if((fp2=fopen("按姓名降序排序.txt","w"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    if(k==-1)
    {
        fprintf(fp2,"\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
        for(i=0;i<m-1;i++)
            fprintf(fp2,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp2);
    return;
}





void pxnum(char n[])
{
    FILE *fp,*fp1,*fp2;
    int m=0,i,j,k;
    char ch[20];
    if(n[0]=='s'||n[0]=='S')k=1;
    else if(n[0]=='j'||n[0]=='J')k=-1;
    else return;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[m],sizeof(struct student),1,fp);
        m++;
    }
    fclose(fp);
    for(i=0;i<m-2;i++)
        for(j=i;j<m-1;j++)
            if(strcmp(stu[i].num,stu[j].num)==k)
            {
                stu[m+1]=stu[j];
                stu[j]=stu[i];
                stu[i]=stu[m+1];
                
            }
    printf("排序后结果如下:\n");
    printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
    for(i=0;i<m-1;i++)
        printf("%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    if((fp1=fopen("按学号升序排序.txt","w"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    if(k==1)
    {
        fprintf(fp1,"\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
        for(i=0;i<m-1;i++)
            fprintf(fp1,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp1);
    if((fp2=fopen("按学号降序排序.txt","w"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    if(k==-1)
    {
        fprintf(fp2,"\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
        for(i=0;i<m-1;i++)
            fprintf(fp2,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp2);
    return;
}




void pxssnum(char n[])
{
    FILE *fp,*fp1,*fp2;
    int m=0,i,j,k;
    char ch[20];
    if(n[0]=='s'||n[0]=='S')k=1;
    else if(n[0]=='j'||n[0]=='J')k=-1;
    else return;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[m],sizeof(struct student),1,fp);
        m++;
    }
    fclose(fp);
    for(i=0;i<m-2;i++)
        for(j=i;j<m-1;j++)
            if(strcmp(stu[i].ssnum,stu[j].ssnum)==k)
            {
                stu[m+1]=stu[j];
                stu[j]=stu[i];
                stu[i]=stu[m+1];
                
            }
    printf("排序后结果如下:\n");
    printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
    for(i=0;i<m-1;i++)
        printf("%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    if((fp1=fopen("按寝室号升序排序.txt","w"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    if(k==1)
    {
        fprintf(fp1,"\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
        for(i=0;i<m-1;i++)
            fprintf(fp1,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp1);
    if((fp2=fopen("按寝室号降序排序.txt","w"))==NULL)
    {   
        printf("不能打开信息文件\n");   
        exit(0);
    }
    if(k==-1)
    {
        fprintf(fp2,"\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");
        for(i=0;i<m-1;i++)
            fprintf(fp2,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp2);
    return;
}






void xxpx()
{int sel;
    char k[20];
    do
    {   printf("              ╭══════════╮              \n");  
        printf("╭══════╣   信  息  排  序   ╠══════╮\n");  
        printf("║            ╰══════════╯            ║\n");  
        printf("║     【1】按姓名排序        【2】按学号排序     ║\n");  
        printf("║                                                ║\n");  
        printf("║     【3】按寝室排序        【0】返回上个界面   ║\n");  
        printf("║                                                ║\n");  
        printf("╰════════════════════════╯\n");  
        printf("═══════请输入0-3  选择相应功能═══════\n");
        scanf("%d",&sel);getchar();
        switch(sel)
        {case 1:printf("已有学生信息如下\n");printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");printt();printf("请输入s/j按升序/降序:");gets(k);pxname(k);break;
        case 2:printf("已有学生信息如下\n");printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");printt();printf("请输入s/j按升序/降序:");gets(k);pxnum(k);break;
        case 3:printf("已有学生信息如下\n");printf("\n%20s%15s%8s%15s%15s\n","姓名","学号","寝室号","QQ号","电话号");printt();printf("请输入s/j按升序/降序:");gets(k);pxssnum(k);break;
        case 0:return;
        default: xxpx();
        }
    }while(1);
}



void xianshi()
{FILE *fp;
    int i=0,n;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {printf("不能打开信息文件");
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[i],sizeof(struct student),1,fp);i++;}
    n=i;
    printf("姓名 学号 寝室号 QQ号 电话号\n");
    for(i=0;i<n-1;i++)
        printf("%s %s %s %s %s\n",stu[i].name,stu[i].num,stu[i].qqnum,stu[i].ssnum,stu[i].telnum);
    fclose(fp);
    return;
}





void teacher()
{int sel;
    char ch[20];
    do
    {   printf("              ╭══════════╮              \n");  
        printf("╭══════╣   老  师  界  面   ╠══════╮\n");  
        printf("║            ╰══════════╯            ║\n");  
        printf("║     【1】信息管理            【2】信息排序     ║\n");  
        printf("║                                                ║\n");  
        printf("║     【3】显示所有信息        【0】退出系统     ║\n");  
        printf("║                                                ║\n");  
        printf("╰════════════════════════╯\n");  
        printf("═══════请输入0-3  选择相应功能═══════\n");
        scanf("%d",&sel);getchar();
        switch(sel)
        {case 1:xxgl();break;
        case 2:xxpx();break;
        case 3:xianshi();break;
        case 0:exit(0);
        default: teacher();
        }
    }while(1);
}






void xingming(char nam[])
{FILE*fp;
    int i;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {printf(" 不能打开信息文件");
        exit(0);
    }
    i=0;
    do{
        fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(nam,stu[i].name)==0)
        {printf("该生的姓名：");puts(stu[i].name);	
            printf("该生的学号：");puts(stu[i].num);	
            printf("该生的寝室：");puts(stu[i].ssnum);
            printf("该生的QQ号：");puts(stu[i].qqnum);	
            printf("该生的电话：");puts(stu[i].telnum);
            break;
        }
    }while(!feof(fp));
    if(feof(fp)) printf("查无此人\n");
}



void xuehao(char nnum[])
{FILE*fp;
    int i;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {printf(" 不能打开信息文件");
        exit(0);
    }
    i=0;
    do{
        fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(nnum,stu[i].num)==0)
        {printf("该生的姓名：");puts(stu[i].name);	
            printf("该生的学号：");puts(stu[i].num);	
            printf("该生的寝室：");puts(stu[i].ssnum);
            printf("该生的QQ号：");puts(stu[i].qqnum);	
            printf("该生的电话：");puts(stu[i].telnum);
            break;
        }
    }while(!feof(fp));
    if(feof(fp)) printf("查无此人\n");
}


void qinshi(char qssnum[])
{FILE*fp;
    int i;
    if((fp=fopen("学生信息文件.dat","rb"))==NULL)
    {printf(" 不能打开信息文件");
        exit(0);
    }
    i=0;
    do{
        fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(qssnum,stu[i].ssnum)==0)
        {printf("该生的姓名：");puts(stu[i].name);	
            printf("该生的学号：");puts(stu[i].num);	
            printf("该生的寝室：");puts(stu[i].ssnum);
            printf("该生的QQ号：");puts(stu[i].qqnum);	
            printf("该生的电话：");puts(stu[i].telnum);
            break;
        }
    }while(!feof(fp));
    if(feof(fp)) printf("查无此人\n");
}



void students()
{
    int sel,k;
    char name[20],num[15],ssnum[5];
    do
    {
        printf("              ╭══════════╮              \n");  
        printf("╭══════╣   学  生  管  理   ╠══════╮\n");  
        printf("║            ╰══════════╯            ║\n");  
        printf("║     【1】按姓名查询          【2】按学号查询   ║\n");  
        printf("║                                                ║\n");  
        printf("║     【3】按寝室查询          【0】退出系统     ║\n");  
        printf("║                                                ║\n");  
        printf("╰════════════════════════╯\n");  
        printf("═══════请输入0-3  选择查询类别═══════\n");
        scanf("%d",&sel);
        getchar();
        switch(sel)
        {
        case 1:printf("请输入学生姓名");gets(name);xingming(name);break;
        case 2:printf("请输入学生学号");gets(num);xuehao(num);break;
        case 3:printf("请输入学生寝室");gets(ssnum);qinshi(ssnum);break;
        case 0:exit(0);
        default: students();
        }
    }while(1);
}





int check(char na[],char pa[],int cl)
{
    char fname[20];
    char fpass[10];
    FILE *fp;
    int found=0,fclas;
    if((fp=fopen("usdatal.txt","r"))==NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d",fname,fpass,&fclas);
        if(strcmp(fname,na)==0&&strcmp(fpass,pa)==0&&fclas==cl)
        {found=1;break;}
    }
    fclose(fp);
    return found;
}



int main()
{int sel;
    char username[20],password[10];
    printf("              ╭══════════╮              \n");  
    printf("╭══════╣学生信息管理系统V1.0╠══════╮\n");  
    printf("║            ╰══════════╯            ║\n");  
    printf("║     【1】管 理 员            【2】 老  师      ║\n");  
    printf("║                                                ║\n");  
    printf("║     【3】 学  生             【0】退出系统     ║\n");  
    printf("║                                                ║\n");  
    printf("╰════════════════════════╯\n");  
    
    
    while(1)
    { printf("═══════请输入0-3  选择用户类别═══════\n");
        scanf("%d",&sel);getchar();
        if(sel!=0)
        {
            printf("请输入用户名");
            gets(username);
            printf("请输入密码");
            gets(password);
            if(check(username,password,sel)==0)
                printf("用户名或密码或类别不对\n");
            else 
                switch(sel)
                {
                case 1:printf("═════════【欢迎%s管理员】═════════\n",username);yhgl();break;
                case 2:printf("═════════【欢迎%s老师】═════════\n",username);teacher();break;
                case 3:printf("═════════【欢迎%s同学】═════════\n",username);students();break;
                }
        }
        else
            exit(0);
    }
}