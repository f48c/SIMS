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
        printf("���ܴ��ļ�");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d",std1[i].name,std1[i].pass,&std1[i].f);
        if(strcmp(n,std1[i].name)==0&&std1[i].f==f)
        {
            printf("�T�T�T�T�T�T�T�����Ѵ��ڣ�����������T�T�T�T�T�T�T\n");
            getchar();
            printf("��������������:");
            gets(ch);
            printf("��������������:");
            gets(pass);
            printf("���������뼶��:");
            scanf("%d",&f);
            if(cf(f,ch)==0)
            {	
                if((fp=fopen("usdatal.txt","a"))==NULL)
                {
                    printf("���ܴ���Ϣ�ļ�");
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
        printf("���ܴ��ļ�\n");
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
        printf("���ܴ���Ϣ�ļ�\n");
        exit(0);
    }
    printf("����������:");
    gets(ch);
    printf("����������:");
    gets(pass);
    printf("�����뼶��:");
    scanf("%d",&f);
    if(cf(f,ch)==0)
        fprintf(fp,"%s %s %d\n",ch,pass,f);
    fclose(fp);
    printf("�T�T�T�T�T�T�T�T�T�û����������T�T�T�T�T�T�T�T�T\n");
    printf("������������\n");
    printf("\n%20s%5s\n","�û���","����");
    print();
    return;
}




void del(char name[])
{
    FILE *fp;
    int i=0,n;
    if((fp=fopen("usdatal.txt","r"))==NULL)
    {  
        printf("���ܴ��ļ�\n");
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
        printf("���ܴ��ļ�\n");
        exit(0);
    }
    for(n=0;n<i-1;n++)
        fprintf(fp,"%s %s %d\n",std1[n].name,std1[n].pass,std1[n].f);
    fclose(fp);
    printf("ɾ����������\n");
    printf("\n%20s%5s\n","�û���","����");
    print();
    return;
}

void edits(char nam[])
{
    FILE *fp;
    int i=0,n,lb;
    char yhm[20],pw[10];
    printf("�������޸ĺ��û�������:");
    gets(yhm);
    printf("�������޸ĺ������:");
    gets(pw);
    printf("�������޸ĺ�����:");
    scanf("%d",&lb);
    if((fp=fopen("usdatal.txt","r"))==NULL)
    {   printf("���ܴ��ļ�\n");
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
        printf("���ܴ��ļ�");
        exit(0);
    }
    for(n=0;n<i-1;n++)
        fprintf(fp,"%s %s %d\n",std1[n].name,std1[n].pass,std1[n].f);
    fclose(fp);
    printf("�޸ĺ�������\n");
    printf("\n%20s%5s\n","�û���","����");
    print();
    return;
}







void yhgl()
{int sele;
    char username[20];   
    do
    {  printf("              �q�T�T�T�T�T�T�T�T�T�T�r              \n");  
        printf("�q�T�T�T�T�T�T�g   ��  ��  ��  ��   �d�T�T�T�T�T�T�r\n");  
        printf("�U            �t�T�T�T�T�T�T�T�T�T�T�s            �U\n");  
        printf("�U     ��1�������û�            ��2��ɾ���û�     �U\n");  
        printf("�U                                                �U\n");  
        printf("�U     ��3���޸��û�            ��0���˳�ϵͳ     �U\n");  
        printf("�U                                                �U\n");  
        printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");  
        printf("�T�T�T�T�T�T�T������0-3  ѡ����Ӧ���ܨT�T�T�T�T�T�T\n");
        scanf("%d",&sele);getchar();
        switch(sele)
        {case 1:printf("�����봴�����û���Ϣ\n");add();break;
        case 2:printf("�����û���Ϣ����\n");printf("\n%20s%5s\n","�û���","����");print();printf("������Ҫɾ���û�������\n");gets(username);del(username);break;
        case 3:printf("�����û���Ϣ����\n");printf("\n%20s%5s\n","�û���","����");print();printf("������Ҫ�޸��û�������\n");gets(username);edits(username);break;
        case 0:exit(0);
        default: yhgl();
        }
    }while(1);
}







int cft(int i,char n[])
{  FILE *fp;
    char ch[20];
    int j=0,k=0;
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {
        printf("���ܴ���Ϣ�ļ�");
        exit(0);
    }
    do{
        fread(stu[j].name,sizeof(struct student),1,fp);
        if(strcmp(n,stu[j].name)==0)
        {
            printf("�T�T�T�T�T�T�T�����Ѵ��ڣ�����������T�T�T�T�T�T�T\n");
            printf("��������������:");
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
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {
        printf("���ܴ���Ϣ�ļ�\n");
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
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","ab"))==NULL)
    {
        printf("���ܴ���Ϣ�ļ�");
        exit(0);
    }
    i=0;
    printf("����������:");
    gets(ch);
    if(cft(i,ch)==0)strcpy(stu[i].name,ch);
    printf("������ѧ��:");
    gets(stu[i].num);
    printf("���������Һ�:");
    gets(stu[i].ssnum);
    printf("������QQ��:");
    gets(stu[i].qqnum);
    printf("������绰��:");
    gets(stu[i].telnum);
    fwrite(&stu[i],sizeof(struct student),1,fp);
    fclose(fp);
    printf("�T�T�T�T�T�T�T�T�T��Ϣ¼������T�T�T�T�T�T�T�T�T\n");
    printf("¼���������\n");
    printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
    printt();
    return;
}





void delt(char name[])
{
    FILE *fp;
    int i=0,n;
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {   printf("���ܴ���Ϣ�ļ�\n");
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(name,stu[i].name)!=0||feof(fp))i++;
    }
    fclose(fp);
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","wb"))==NULL)
    {   printf("���ܴ���Ϣ�ļ�\n");
        exit(0);
    }
    for(n=0;n<i-1;n++)
        fwrite(&stu[n],sizeof(struct student),1,fp);
    fclose(fp);
    printf("ɾ����������\n");
    printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
    printt();
    return;
}





void editst(char nam[])
{
    FILE *fp;
    int i=0,n;
    char ch[20];
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {   printf("���ܴ���Ϣ�ļ�\n");
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
            printf("�������޸ĺ��ѧ��:");
            gets(stu[i].num);
            printf("�������޸ĺ�����Һ�:");
            gets(stu[i].ssnum);
            printf("�������޸ĺ��QQ��:");
            gets(stu[i].qqnum);
            printf("�������޸ĺ�ĵ绰��:");
            gets(stu[i].telnum);
        }
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","wb"))==NULL)
    {   printf("���ܴ���Ϣ�ļ�\n");
        exit(0);
    }
    for(i=0;i<n-1;i++)
        fwrite(&stu[i],sizeof(struct student),1,fp);
    fclose(fp);
    printf("�޸ĺ�������\n");
    printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
    printt();
    return;
}





void xxgl()
{int sel;
    char ch[20];
    do
    {   printf("              �q�T�T�T�T�T�T�T�T�T�T�r              \n");  
        printf("�q�T�T�T�T�T�T�g   ��  Ϣ  ��  ��   �d�T�T�T�T�T�T�r\n");  
        printf("�U            �t�T�T�T�T�T�T�T�T�T�T�s            �U\n");  
        printf("�U     ��1��¼����Ϣ          ��2��ɾ����Ϣ       �U\n");  
        printf("�U                                                �U\n");  
        printf("�U     ��3���޸���Ϣ          ��0�������ϸ�����   �U\n");  
        printf("�U                                                �U\n");  
        printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");  
        printf("�T�T�T�T�T�T�T������0-3  ѡ����Ӧ���ܨT�T�T�T�T�T�T\n");
        scanf("%d",&sel);getchar();
        switch(sel)
        {case 1:addsc();break;
        case 2:printf("����ѧ����Ϣ����\n");printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");printt();printf("������Ҫɾ����Ϣ������");gets(ch);delt(ch);break;
        case 3:printf("����ѧ����Ϣ����\n");printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");printt();printf("������Ҫ�޸���Ϣ������");gets(ch);editst(ch);break;
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
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
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
    printf("�����������:\n");
    printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
    for(i=0;i<m-1;i++)
        printf("%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    if((fp1=fopen("��������������.txt","w"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
        exit(0);
    }
    if(k==1)
    {
        fprintf(fp1,"\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
        for(i=0;i<m-1;i++)
            fprintf(fp1,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp1);
    if((fp2=fopen("��������������.txt","w"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
        exit(0);
    }
    if(k==-1)
    {
        fprintf(fp2,"\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
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
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
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
    printf("�����������:\n");
    printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
    for(i=0;i<m-1;i++)
        printf("%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    if((fp1=fopen("��ѧ����������.txt","w"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
        exit(0);
    }
    if(k==1)
    {
        fprintf(fp1,"\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
        for(i=0;i<m-1;i++)
            fprintf(fp1,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp1);
    if((fp2=fopen("��ѧ�Ž�������.txt","w"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
        exit(0);
    }
    if(k==-1)
    {
        fprintf(fp2,"\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
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
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
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
    printf("�����������:\n");
    printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
    for(i=0;i<m-1;i++)
        printf("%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    if((fp1=fopen("�����Һ���������.txt","w"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
        exit(0);
    }
    if(k==1)
    {
        fprintf(fp1,"\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
        for(i=0;i<m-1;i++)
            fprintf(fp1,"%20s%15s%8s%15s%15s\n",stu[i].name,stu[i].num,stu[i].ssnum,stu[i].qqnum,stu[i].telnum);
    }
    fclose(fp1);
    if((fp2=fopen("�����ҺŽ�������.txt","w"))==NULL)
    {   
        printf("���ܴ���Ϣ�ļ�\n");   
        exit(0);
    }
    if(k==-1)
    {
        fprintf(fp2,"\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");
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
    {   printf("              �q�T�T�T�T�T�T�T�T�T�T�r              \n");  
        printf("�q�T�T�T�T�T�T�g   ��  Ϣ  ��  ��   �d�T�T�T�T�T�T�r\n");  
        printf("�U            �t�T�T�T�T�T�T�T�T�T�T�s            �U\n");  
        printf("�U     ��1������������        ��2����ѧ������     �U\n");  
        printf("�U                                                �U\n");  
        printf("�U     ��3������������        ��0�������ϸ�����   �U\n");  
        printf("�U                                                �U\n");  
        printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");  
        printf("�T�T�T�T�T�T�T������0-3  ѡ����Ӧ���ܨT�T�T�T�T�T�T\n");
        scanf("%d",&sel);getchar();
        switch(sel)
        {case 1:printf("����ѧ����Ϣ����\n");printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");printt();printf("������s/j������/����:");gets(k);pxname(k);break;
        case 2:printf("����ѧ����Ϣ����\n");printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");printt();printf("������s/j������/����:");gets(k);pxnum(k);break;
        case 3:printf("����ѧ����Ϣ����\n");printf("\n%20s%15s%8s%15s%15s\n","����","ѧ��","���Һ�","QQ��","�绰��");printt();printf("������s/j������/����:");gets(k);pxssnum(k);break;
        case 0:return;
        default: xxpx();
        }
    }while(1);
}



void xianshi()
{FILE *fp;
    int i=0,n;
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {printf("���ܴ���Ϣ�ļ�");
        exit(0);
    }
    while(!feof(fp))
    {fread(&stu[i],sizeof(struct student),1,fp);i++;}
    n=i;
    printf("���� ѧ�� ���Һ� QQ�� �绰��\n");
    for(i=0;i<n-1;i++)
        printf("%s %s %s %s %s\n",stu[i].name,stu[i].num,stu[i].qqnum,stu[i].ssnum,stu[i].telnum);
    fclose(fp);
    return;
}





void teacher()
{int sel;
    char ch[20];
    do
    {   printf("              �q�T�T�T�T�T�T�T�T�T�T�r              \n");  
        printf("�q�T�T�T�T�T�T�g   ��  ʦ  ��  ��   �d�T�T�T�T�T�T�r\n");  
        printf("�U            �t�T�T�T�T�T�T�T�T�T�T�s            �U\n");  
        printf("�U     ��1����Ϣ����            ��2����Ϣ����     �U\n");  
        printf("�U                                                �U\n");  
        printf("�U     ��3����ʾ������Ϣ        ��0���˳�ϵͳ     �U\n");  
        printf("�U                                                �U\n");  
        printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");  
        printf("�T�T�T�T�T�T�T������0-3  ѡ����Ӧ���ܨT�T�T�T�T�T�T\n");
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
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {printf(" ���ܴ���Ϣ�ļ�");
        exit(0);
    }
    i=0;
    do{
        fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(nam,stu[i].name)==0)
        {printf("������������");puts(stu[i].name);	
            printf("������ѧ�ţ�");puts(stu[i].num);	
            printf("���������ң�");puts(stu[i].ssnum);
            printf("������QQ�ţ�");puts(stu[i].qqnum);	
            printf("�����ĵ绰��");puts(stu[i].telnum);
            break;
        }
    }while(!feof(fp));
    if(feof(fp)) printf("���޴���\n");
}



void xuehao(char nnum[])
{FILE*fp;
    int i;
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {printf(" ���ܴ���Ϣ�ļ�");
        exit(0);
    }
    i=0;
    do{
        fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(nnum,stu[i].num)==0)
        {printf("������������");puts(stu[i].name);	
            printf("������ѧ�ţ�");puts(stu[i].num);	
            printf("���������ң�");puts(stu[i].ssnum);
            printf("������QQ�ţ�");puts(stu[i].qqnum);	
            printf("�����ĵ绰��");puts(stu[i].telnum);
            break;
        }
    }while(!feof(fp));
    if(feof(fp)) printf("���޴���\n");
}


void qinshi(char qssnum[])
{FILE*fp;
    int i;
    if((fp=fopen("ѧ����Ϣ�ļ�.dat","rb"))==NULL)
    {printf(" ���ܴ���Ϣ�ļ�");
        exit(0);
    }
    i=0;
    do{
        fread(&stu[i],sizeof(struct student),1,fp);
        if(strcmp(qssnum,stu[i].ssnum)==0)
        {printf("������������");puts(stu[i].name);	
            printf("������ѧ�ţ�");puts(stu[i].num);	
            printf("���������ң�");puts(stu[i].ssnum);
            printf("������QQ�ţ�");puts(stu[i].qqnum);	
            printf("�����ĵ绰��");puts(stu[i].telnum);
            break;
        }
    }while(!feof(fp));
    if(feof(fp)) printf("���޴���\n");
}



void students()
{
    int sel,k;
    char name[20],num[15],ssnum[5];
    do
    {
        printf("              �q�T�T�T�T�T�T�T�T�T�T�r              \n");  
        printf("�q�T�T�T�T�T�T�g   ѧ  ��  ��  ��   �d�T�T�T�T�T�T�r\n");  
        printf("�U            �t�T�T�T�T�T�T�T�T�T�T�s            �U\n");  
        printf("�U     ��1����������ѯ          ��2����ѧ�Ų�ѯ   �U\n");  
        printf("�U                                                �U\n");  
        printf("�U     ��3�������Ҳ�ѯ          ��0���˳�ϵͳ     �U\n");  
        printf("�U                                                �U\n");  
        printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");  
        printf("�T�T�T�T�T�T�T������0-3  ѡ���ѯ���T�T�T�T�T�T�T\n");
        scanf("%d",&sel);
        getchar();
        switch(sel)
        {
        case 1:printf("������ѧ������");gets(name);xingming(name);break;
        case 2:printf("������ѧ��ѧ��");gets(num);xuehao(num);break;
        case 3:printf("������ѧ������");gets(ssnum);qinshi(ssnum);break;
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
        printf("���ܴ��ļ�\n");
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
    printf("              �q�T�T�T�T�T�T�T�T�T�T�r              \n");  
    printf("�q�T�T�T�T�T�T�gѧ����Ϣ����ϵͳV1.0�d�T�T�T�T�T�T�r\n");  
    printf("�U            �t�T�T�T�T�T�T�T�T�T�T�s            �U\n");  
    printf("�U     ��1���� �� Ա            ��2�� ��  ʦ      �U\n");  
    printf("�U                                                �U\n");  
    printf("�U     ��3�� ѧ  ��             ��0���˳�ϵͳ     �U\n");  
    printf("�U                                                �U\n");  
    printf("�t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�s\n");  
    
    
    while(1)
    { printf("�T�T�T�T�T�T�T������0-3  ѡ���û����T�T�T�T�T�T�T\n");
        scanf("%d",&sel);getchar();
        if(sel!=0)
        {
            printf("�������û���");
            gets(username);
            printf("����������");
            gets(password);
            if(check(username,password,sel)==0)
                printf("�û������������𲻶�\n");
            else 
                switch(sel)
                {
                case 1:printf("�T�T�T�T�T�T�T�T�T����ӭ%s����Ա���T�T�T�T�T�T�T�T�T\n",username);yhgl();break;
                case 2:printf("�T�T�T�T�T�T�T�T�T����ӭ%s��ʦ���T�T�T�T�T�T�T�T�T\n",username);teacher();break;
                case 3:printf("�T�T�T�T�T�T�T�T�T����ӭ%sͬѧ���T�T�T�T�T�T�T�T�T\n",username);students();break;
                }
        }
        else
            exit(0);
    }
}