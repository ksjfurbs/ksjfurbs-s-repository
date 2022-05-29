#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int cha,word;
	cha=word=0;
	fp=fopen("F:\\桌面\\Desktop\\文件\\暂时文件\\新建文本文档 (2).txt","r");
	
	if(fp==NULL)                            //读取文件失败 
	{
		printf("can not open the file\n");
		exit(0);
	}
	
	printf("===================================================\n");
	printf("文本内容开始\n\n");
	ch=fgetc(fp);                           //显示文本的全部内容 
	while (ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	printf("\n\n\n文本内容结束\n");
	printf("==================================================\n\n\n");
	rewind(fp);

	ch=fgetc(fp);
	while (ch!=EOF)
	{
		if(!(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'))     //cha统计字符数量
			cha++;
		ch=fgetc(fp);     
		
	}
	rewind(fp);
   ch=fgetc(fp);
   if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')          //判断通篇里第一个字符是否为字母，若判断条件为真，直接word+1;
	   word++;
    while (ch!=EOF)
	{
		if(!(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'))         //word统计单词数量
		{	ch=fgetc(fp);
		    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
				word++;
		}
		else ch=fgetc(fp);
	}
	fclose(fp);
	
printf("符号有%d个,单词有%d个",cha,word);   
return 0;
}
