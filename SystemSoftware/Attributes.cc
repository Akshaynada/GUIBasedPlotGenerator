#include <iostream>
#include <cstring>
#include <fstream>
#include <memory>
using namespace std;

class Attributes
{
	double xrange0,xrange1,yrange0,yrange1;
	char xlabel[20],ylabel[20],title[30],FilePath[30];
	static int  Type;
public:
	Attributes()	 {
			xrange0=0.0;xrange1=0.0;yrange0=0.0;yrange1=0.0;
			strcpy(xlabel,"Null");
			strcpy(ylabel,"Null");
			strcpy(title,"Null");
			strcpy(FilePath,"Null");
			 }
	int SelectType(int);
	int ShowType();

	bool ReadFile(char*);
	char* ShowFile();

	int ReadTitle(char[]);
	int ReadLabelX(char[]);
	int ReadLabelY(char[]);
	int ShowLabels();

	int ReadX1(double);
	int ReadX2(double);
	int ReadY1(double);
	int ReadY2(double);
	int ShowRanges();

	int Store();
	int CopyFile();
	~Attributes() {}
};
int Attributes::Type=1;

int Attributes::Store()
{
	ofstream fp("Attr.txt");
	if(fp.fail())
	{
	 cout<<"Don't Have File Access"<<endl;
	 return 1;
	}
	fp<<Type<<endl;
	fp<<title<<endl;
	fp<<FilePath<<endl;
	fp<<xlabel<<endl;
	fp<<ylabel<<endl;
	fp<<xrange0<<endl;
	fp<<xrange1<<endl;
	fp<<yrange0<<endl;
	fp<<yrange1<<endl;
	fp.close();
	 return 0;
}

int Attributes::CopyFile()
{
	char ch;
	ifstream fpr(FilePath);
	if(fpr.good())
	{
	 ofstream fpw("Output.txt");
	 while(!fpr.eof())
	 {
	  fpr.get(ch);
	  fpw.put(ch);
	 }
	 fpw.close();
	}
	else
	 cout<<"Can not Open The File!!!"<<endl;
	fpr.close();
	return 0;
}

int Attributes::SelectType(int a)
{
	Type=a;
	return Type;
}

int Attributes::ShowType()
{
	cout<<"Type= "<<Type;
	return Type;
}

bool Attributes::ReadFile(char *FP)
{
	strcpy(FilePath,FP);
	ifstream fp(FilePath);
	if(fp.fail())
	 return false;

	fp.close();
	cout<<"suc";
	return true;
}

char* Attributes::ShowFile()
{
	return FilePath;
}

int Attributes::ReadTitle(char tt[])
{
	strcpy(title,tt);
	return 0;
}

int Attributes::ReadLabelX(char xl[])
{
	strcpy(xlabel,xl); 
	return 0;
}

int Attributes::ReadLabelY(char yl[])
{
	strcpy(ylabel,yl); 
	return 0;
}

int Attributes::ShowLabels()
{	
	cout<<title<<endl;
	cout<<xlabel<<endl;
	cout<<ylabel<<endl;
	return 0;
}

int Attributes::ReadX1(double x1)
{
	xrange0=x1;
	return 0;
}

int Attributes::ReadX2(double x2)
{
	xrange1=x2;
	return 0;
}

int Attributes::ReadY1(double y1)
{
	yrange0=y1;
	return 0;
}

int Attributes::ReadY2(double y2)
{
	yrange1=y2;
	return 0;
}

int Attributes::ShowRanges()
{
	cout<<xrange0<<endl;
	cout<<xrange1<<endl;
	cout<<yrange0<<endl;
	cout<<yrange1<<endl;
	return 0;
}

