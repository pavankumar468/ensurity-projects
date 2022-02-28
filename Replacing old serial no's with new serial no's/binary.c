#include<stdio.h>
#include<string.h>
#include<dir.h>
#include<dirent.h>
#include <sys/stat.h>
#include<stdlib.h>

int main(){
	char a[] = {0x4e,0x45,0x28,0x00,0x45,0x54,0x56,0x34,0x42,0x30,0x30,0x30,0x51,0x4f,0x00,0x00,0x00,0x00,0x00,0x00,0x54,0x43,0x45,0x37,0x4e,0x43,0x45,0x46,0x54,0x4d,0x4d,0x52,0x34,0x00, 0x00, 0x00 ,0x53 ,0x48 ,0x00 ,0x31, 0x39 ,0x31, 0x32 ,0x00};
	int i;
	FILE *fp;
	 char buffer[12];
	 char buffer1[12], temp[12];	
	 char file_name[30] = "./";
	 char total[50];
	 char dir_name[30] = "generate_bin_files";
	int check = mkdir(dir_name);

	strcat(file_name,dir_name);
	strcat(file_name,"/");

	fp = fopen("serial.txt","r");
	
	while(fscanf(fp,"%s",buffer)!= EOF)
	{
		
		memcpy(total,file_name,strlen(file_name)+1);
		strcat(total,buffer);
		strcat(total,".bin");
		
		
		memcpy(a+4,buffer,12); 
		
		printf("%s\n",buffer);
		
	
	
		FILE *create;
		create = fopen(total ,"wb+");
			
		fwrite(a,44,1,create);	
		
		fclose(create);	

	}
	
printf("\nfilename = %s",__FILE__);
	fclose(fp);	

	
}

