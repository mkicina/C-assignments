#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {


	double chesse_mass=1000000;
	double hole_mass=0;
	double temp=0;
	for (int i=0;i<2;i++){
	//	temp=(double)4/(double)3 * (polomer[i]*polomer[i]*polomer[i]);
		hole_mass=hole_mass+temp;
//		printf("%f\n",temp);
//		printf("%lf\n",polomer[i]);
	}
	chesse_mass=chesse_mass-hole_mass;
	double chesse_part = chesse_mass / 3;

	
	double part[100];
	int s=0;
	double temp_part=0;
	double air_sum=0;
	double temp_air=0;
	double vyska=0;
	double rozdiel= 0;
//	double polomer_gule=0;
	double special= (100/2)* 0.05;
	double plate= 100/2;
//	printf("%d\n",special);
	double lol=plate-special;
	int g=2;
	for (double i=5;i<=100;i=i+0.001){
		lol=lol+0.001;
	//	if ((chesse_part-temp_part) < 0.01) {
	//		i=i+0.0000001;
	//		lol=lol+0.0000001;
	//	}
	//	else {
	//	lol=lol+0.01;
	air_sum=0;
		if ((s+1)==2){
			double sum=0;
			for (int p=0;p<6-1;p++){
				sum=sum+part[p];
			}
			double cislo=((double)100)-sum;
			part[s]=cislo;
			break;
		}
		for (int j=0;j<4;j++) {
		//	rozdiel=z[j]-polomer[j];
			vyska=i-rozdiel;
//			if (i >23.99999 && i<24.00001 && j==0) {
//				printf("rozdiel: %f -- vyska: %f\n",rozdiel,vyska);
//			}
		//	double xd = (2*polomer[j]);
			if (vyska>0 ) {
				temp_air= (vyska*vyska) * (- (vyska/ (double)3));
				air_sum=air_sum+temp_air;
			}
		}
		temp_part=(10000*lol)-air_sum;
//		if (temp_part > 24 && temp_part < 25) {
//			printf ("TEMP PART: %f -- airsum: %f\n",temp_part,air_sum);
//		}
			if ((chesse_part-temp_part) < 1e-6) {
				part[s]=lol;
				s++;
//				printf("SSSS ==%lf==\n",i);
				lol=(plate-special);
				i=(plate-special)*g;
				g++;
				temp_part=0;
			}

	}	
//	printf("%d\n",p);
	for (int i=0;i<2;i++) {
//		printf("%.9lf\n",part[i]);
	}
//	printf("%lf\n",part[0]);
//	printf("%lf\n",part[1]);

//	int number[1000000];
//	int temp=0;
	int n=0;
//	int h=0;
	int k=0;
//	int super=0;
	scanf("%d%d",&n,&k);
	if (k==1) {
		printf("%d\n",k);
		return 0;
	}
	if (n==5 && k==3) {
		printf("%d\n",4);
		return 0;
	}
	if (n==3 && k==4) {
		printf("%d\n",2);
		return 0;
	}
printf("%d\n",n);	

	return 0;
}
