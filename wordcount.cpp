#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int cha,word;
	cha=word=0;
	fp=fopen("F:\\����\\Desktop\\�ļ�\\��ʱ�ļ�\\�½��ı��ĵ� (2).txt","r");
	
	if(fp==NULL)                            //��ȡ�ļ�ʧ�� 
	{
		printf("can not open the file\n");
		exit(0);
	}
	
	printf("===================================================\n");
	printf("�ı����ݿ�ʼ\n\n");
	ch=fgetc(fp);                           //��ʾ�ı���ȫ������ 
	while (ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	printf("\n\n\n�ı����ݽ���\n");
	printf("==================================================\n\n\n");
	rewind(fp);

	ch=fgetc(fp);
	while (ch!=EOF)
	{
		if(!(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'))     //chaͳ���ַ�����
			cha++;
		ch=fgetc(fp);     
		
	}
	rewind(fp);
   ch=fgetc(fp);
   if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')          //�ж�ͨƪ���һ���ַ��Ƿ�Ϊ��ĸ�����ж�����Ϊ�棬ֱ��word+1;
	   word++;
    while (ch!=EOF)
	{
		if(!(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'))         //wordͳ�Ƶ�������
		{	ch=fgetc(fp);
		    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
				word++;
		}
		else ch=fgetc(fp);
	}
	fclose(fp);
	
printf("������%d��,������%d��",cha,word);   
return 0;
}
