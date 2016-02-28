#include <stdio.h>
#define SIZE_NUMBER 20
//скачено с http://algorithmlib.org/
int read_file_TO_matrix(char *name,int &str,int &stb,double **&mass)//чтение матрицы из файла
{
char buffer;
double number;
double ttt=10;
int i,j;
bool flag=false;
mass=0;
str=stb=i=j=0;
unsigned int code=0;
FILE *fo;
fo=fopen(name,"r");
if(!fo)
return 0;
while(!feof(fo))
{
	if(!fread(&buffer,sizeof(char),1,fo))
	break;
	if(buffer>='0' && buffer<='9') 
	{
			if(!(code>0 && code<=SIZE_NUMBER))
			code=1;
			else code++;
			if(ttt==10)
			number=number*ttt+(buffer-'0');
			else
			{
			number=number+(buffer-'0')*ttt;
			ttt/=10;
			}
			continue;
	}
	else if(buffer=='-')
	{
	flag=true;
	continue ;
	}
	else if(buffer=='.')
	{
		if(ttt==10)
		{
		ttt=0.1;
		continue;
		}
		else
		{
		for(int k=0;k<i;k++)
			delete []mass[k]; 
		if(mass!=0)delete []mass;
		return 0;
		}
	}
	else if(code>0 && code<=SIZE_NUMBER)
	{
		if(flag)
		number=-number;
		if(str==0)
		str=number;
		else if(stb==0)
		stb=number;
		else if(str>0 && stb>0)
		{
			if(i==0 && j==0)
			{
			mass=new double *[str];
			mass[i]=new double [stb];
			}
			else if(j>=stb)
			{
				if(++i>=str){j=-1;break ;}
				mass[i]=new double [stb];
				j=0;
			}
			if(j<stb)
			mass[i][j++]=number;
		}
	}
ttt=10;
flag=false;
number=0;
code=0;
}
if(str-1==i && stb==j)
return 1;

	for(j=i;j>=0;j--)
	delete []mass[j];
	delete []mass;

return 0;
}

void print_matrix(int str,int stb,double **mass)//вывод матрицы в консоль
{
	for(int i=0;i<str;i++)
	{
		for(int j=0;j<stb;j++)
		printf("a[%d][%d]=%f \t",i,j,mass[i][j]);
		printf("\n");
	}
	printf("\n");
}


int LU_fun(int cnt_str,double **mass,double **&LU)
{
int i,j,k;

LU=new double *[cnt_str];//создаём массив под матрицу LU
for(i=0;i<cnt_str;i++)
LU[i]=new double [cnt_str];

for(i=0;i<cnt_str;i++)
{
	for(j=0;j<cnt_str;j++)
	{
	double sum=0;
		if(i<=j)
		{
			for(k=0;k<i;k++)
			sum+=LU[i][k]*LU[k][j];
			LU[i][j]=mass[i][j]-sum;//вычисляем элементы верхней треугольной матрицы
		}
		else
		{
			for(k=0;k<j;k++)
			sum+=LU[i][k]*LU[k][j];
			if(LU[j][j]==0)
			return 0;
			LU[i][j]=(mass[i][j]-sum)/LU[j][j];//вычисляем элементы нижней треугольной матрицы
		}
	}

}
return 1;
}

int main(int args,char *argv[])
{
int str,stb;
str=stb=0;
double **mass;
double **LU;
	if(read_file_TO_matrix(argv[1],str,stb,mass)==1 && str==stb)//чтение матрицы из файла
	{
		if(LU_fun(str,mass,LU)==1)//разложение матрицы на LU
		{
		print_matrix(stb,stb,LU);//вывод результата
		}
		else
		{printf("Error LU_fun matrix\n");}

	for(int i=0;i<str;i++){delete []mass[i];delete []LU[i];}
	delete []mass;
	delete []LU;

	}
	else
	{printf("Error read matrix\n");}
return 0;
}
//скачено с http://algorithmlib.org/
