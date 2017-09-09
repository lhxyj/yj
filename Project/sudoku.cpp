#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;
ofstream outfile("soduku.txt",ios::out);       //�ļ�������� 
class sudo{
	int i , j ;
	int a[9] ;
	int b[9][9];
	public:
		sudo(){
			i = 0 ;
			a[0] = 5 ;
			for(i = 1 ; i < 9 ; i++){
				a[i] = a[0] + 1;
				if(a[i] / 9 == 0) a[i] = 9;
				else 		  a[i] = a[i] % 9;
			}				
		}
		void createsudo();
		void exarray(int a[9]); 
};

void sudo::exarray(int a[9])
{
	int temp = a[0];
	for(i = 1 ; i < 9 ; i++){
		a[i - 1] = a[i];
	}
	a[8] = temp;
}

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp; 
} 
void print(int a[9][9])
{
	int i , j ;
	for(i = 0 ; i < 9 ; i++){
		for(j = 0 ; j < 9 ; j++){
			outfile<<a[i][j]<<' ';
		}		
		outfile<<endl;
	}		
	outfile<<endl;
}

void sudo::createsudo()
{	
	int x , y;           //�������λ�� 
	for(i = 0 ; i < 9 ;i++ )   //��ʼ������
	{
		for(j = 0 ; j < 9 ;i++)
			b[i][j] = a[j];
		exarray(a);	
	} 
	for(i = 0 ; i < 4 ; i++) //���� 
	{
		x = rand() % 9;
		y = rand() % 9;
		for(j = 0 ; j < 9 ;j++)
			swap(b[j][x],b[j][y]);	
	}
	for(i = 0 ; i < 4 ; i++) //����
	{
		x = rand() % 9;
		y = rand() % 9;
		for(j = 0 ; j < 9 ;j++)
			swap(b[x][j],b[y][j]);	
	} 
	
	print(b); 
}

int main(int argc,char** argv)
{
	int i;
	int n;   //��¼��Ҫn���������� 
	srand(time(0));      //����������� 
	if(!outfile){  //�ļ���ʧ������ 
		printf("Open error,please try again!\n");
		exit(1);
	} 
	if(argc == 3 && !strcmp(argv[1],"-c")){   //�жϲ����Ƿ��������ҵ�1�������Ƿ���"-c" 
		for(i = 0 ; argv[2][i] != '\0' ; i++){
			if(argv[2][i] < '0' || argv[2][i] > '9'){
				printf("This parameter is wrong!\n");
				return 0;
			}
		}
		sscanf(argv[2], "%d", &n);  //����ȷ�ĵ�2������ת���������� 
	}
	else{
		printf("This's a wrong format!\n");
		return 0;	
	}
	for(i = 0 ; i < n ; i++){
		sudo a;
		a.createsudo();
	} 
	outfile.close();
	cout<<"finish"<<endl;
	return 0;
}
