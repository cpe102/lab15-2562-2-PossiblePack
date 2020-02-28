#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *data,int x,int y){
	for(int i = 0; i<(x*y); i++){
		*(data+i) = (rand()%101)/100.00;
	}
}

void findRowSum(const double *data,double *result,int N,int M){
	double sum = 0;
	int z = 0;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			sum += *(data+z);
			z++;
		}
		*(result+i) = sum;
		sum = 0;
	}
}

void showData(double *data,int N,int M){
	int o = 0;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			cout << *(data+o) << "\t";
			o++;
		}cout << "\n";
	}
}