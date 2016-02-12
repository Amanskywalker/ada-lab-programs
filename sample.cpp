/*
 * This is a sample program 
 * It just for template to how to write program  
 * */

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define SWAP(x,y,temp) (temp=x,x=y,y=temp)

int main(int argc,char *argv[])
{									// n value will be passed from the commandline as argv[]
		int n;
		n=atoi(argv[1]);			// changing the string to its equivalent int
		int temp,a[n];				// creating the array
		float s,e,t;		
		for(int i=0;i<n;++i)		//generating the random value for the test
			a[i]=rand()%10000;
		s=clock();					// code for algorithm
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if (a[i]<a[j])
					SWAP(a[i],a[j],temp);
			}
		}
		e=clock();
		t=(e-s)/CLOCKS_PER_SEC;
		cout<<"\n "<<n<<"\t"<<t<<"\n";	//outputing the size and the time taken for that size
		return 0;
}
