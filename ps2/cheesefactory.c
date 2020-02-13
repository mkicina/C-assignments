#include <stdio.h>
#include <math.h>
int main() {
	#define M_PI 3.14159265358979323846
	int holes=0;
	int pieces=0;
	scanf("%d%d",&holes,&pieces);
	double polomer[holes];
	double x[holes];
	double y[holes];
	double z[holes];
	for (int i=0;i<holes;i++){
		scanf("%lf%lf%lf%lf",&polomer[i],&x[i],&y[i],&z[i]);
		polomer[i]=polomer[i]/1000;
		x[i]=x[i]/1000;
		y[i]=y[i]/1000;
		z[i]=z[i]/1000;
	}
	for (int i=0;i<holes;i++){
		printf("%.3lf\n",z[i]);
	}


	double chesse_mass=1000000;
	double hole_mass=0;
	double temp=0;
	for (int i=0;i<holes;i++){
		temp=(double)4/(double)3 * M_PI * ((double)polomer[i]*(double)polomer[i]*(double)polomer[i]);
		hole_mass=hole_mass+temp;
//		printf("%f\n",temp);
//		printf("%lf\n",polomer[i]);
	}
	chesse_mass=chesse_mass-hole_mass;
	double chesse_part = chesse_mass / pieces;
//	int p=0;
	
	double part[pieces];
	int k=0;
	double temp_part=0;
	double air_sum=0;
	double temp_air=0;
	double vyska=0;
	double rozdiel= 0;
//	double polomer_gule=0;
	double special= (100/pieces)* 0.05;
	double plate= 100/pieces;
//	printf("%d\n",special);
	double lol=((double)plate-(double)special);
	double sumik=0;
//	printf("%lf\n",(plate-special));
	for (double i=plate-special;i<=100;i=i+0.0000001){
		lol=lol+0.0000001;
	//	if ((chesse_part-temp_part) < 0.01) {
	//		i=i+0.0000001;
	//		lol=lol+0.0000001;
	//	}
	//	else {
	//	lol=lol+0.01;
	//	i=i+0.1;
	//	}
		air_sum=0;
		if ((k+1)==pieces){
			double sum=0;
			for (int p=0;p<pieces-1;p++){
				sum=sum+part[p];
			}
			double cislo=((double)100)-sum;
			part[k]=cislo;
			break;
		}
		for (int j=0;j<holes;j++) {
			rozdiel=(double)z[j]-(double)polomer[j];
			vyska=i-rozdiel;
//			if (i >23.99999 && i<24.00001 && j==0) {
//				printf("rozdiel: %f -- vyska: %f\n",rozdiel,vyska);
//			}
			double xd = (2*polomer[j]);
			if (vyska>0 && vyska<xd ) {
				temp_air=(M_PI) * ((double)vyska*(double)vyska) * ((double)polomer[j] - ((double)vyska/ (double)3));
				air_sum=air_sum+temp_air;
			}
		}
		temp_part=(10000*lol)-air_sum;
//		if (temp_part > 24 && temp_part < 25) {
//			printf ("TEMP PART: %f -- airsum: %f\n",temp_part,air_sum);
//		}
			if ((chesse_part-temp_part) < 1e-6) {
		//		double haha= (double)plate - (double)special;
				
				part[k]=lol;
				sumik=sumik+lol;
				double hop= (((100-sumik)/(pieces-(k+1)))*0.05);
			//	printf("hop: %.9lf\n",hop);
	//			double dif =(part[k] - (plate-special));
	//			printf("%lf\n",dif);
				k++;
//				printf("SSSS ==%lf==\n",i);
				lol=(part[k-1]-hop);
				i=i+(part[k-1]-hop);
//				printf("toto: %lf a toto: %lf\n",i,part[k-1]);
			//	g++;
//				temp_part=0;
			}

	}	
//	printf("%d\n",p);
	for (int i=0;i<pieces;i++) {
		printf("%.9lf\n",part[i]);
	}
//	printf("%lf\n",part[0]);
//	printf("%lf\n",part[1]);
}
