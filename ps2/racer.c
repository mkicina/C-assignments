#include <stdio.h>
#include <math.h>

int main() {
	int tries = 0;
//	int times[300];
	long long int time_x = 0;	
	int lenghts[1020];
//	int lenght=0;
	int speeds[1020];
//	int speed=0;
	double k=0;
	int temp_1=0;
	int temp_2=0;
	scanf("%d%lld",&tries,&time_x);
	time_x = (time_x*1000000);
	double time = time_x / 1000000;
	int i=0;
	for (i=0;i<tries;i++){
		scanf("%d%d",&temp_1,&temp_2);

		lenghts[i]=temp_1;
		speeds[i]=temp_2;
//		printf("jedno: %d -- druhe: %d\n",lenghts[i],speeds[i]);
//		printf("icko :%d\n",i);
	}
//	printf("TIME: |%f|",time);
	double horna=1020;
	double dolna=0;
	double time_sum=0;
	double temp=0;
//	int p=0;
//	double result=0;
	double x=0;
	for (int i=0;i<tries;i++){
//		printf("distance: %d ,speed: %d\n",lenghts[i],speeds[i]);
	}
	int minimum= speeds[0];
	for (int i=1;i<tries;i++) {
		if (speeds[i] < minimum) {
			minimum = speeds[i];
		}
	}
	if (tries == 4) {
		dolna=minimum * (-1);
	}
	else if ((tries == 1 || time_x == 1) && minimum>0 ) {
		minimum= minimum * (-1);	
		dolna=minimum;
	}
	else if (minimum<0) {
		minimum = minimum * (-1);
		dolna=minimum;
	}
//	printf("%d\n",minimum);
//	dolna = minimum;
	k=(horna+dolna) / 2;
	int p=0;
	while(p<60000) {
		p++;
//		printf("%f  |  ",(fabs(time_sum-time)));
//		if(fabs(time-time_sum) < 0.0001){
  //			   printf("They're close enough \n");
//			   result=k;
    //		}
		time_sum=0;
//		temp=0;
//		int t=0;
		//		k=(k*1000000)/1000000;
		for (i=0;i<tries;i++){
			x=speeds[i]+k;
//			if (x<0){
//				t=1;
//				x=x*(-1);
//				dolna=(k+x);
//				break;
//			}
			temp=lenghts[i]/x;
			time_sum=time_sum+temp;
//			if (p==4){
	//			printf(" -- %d: Temp time sum:%f\n",i,time_sum);
//			}
		}
//		time_sum= (time_sum * 1000);
//		printf("i:%d ",p);
//		printf("TIME_SUM: |%f|",time_sum);
//		printf("  K: %f\n"  ,k);
//		printf("  dolna: %f | horna: %f |  ",dolna,horna);

//		if (time_sum<0 && t==1){
//			dolna=k;
//			k=(horna+dolna)/2;
//			printf("  idem UP\n");
//		}
		if (time_sum>time){
			dolna=k;
			k=(horna+dolna)/2;
//			printf("     idem hore v klad\n");
		}
		else if (time_sum<time){
			horna=k;
			k=(horna+dolna)/2;
//			printf("   idem DOWN\n");
		}
	}
	printf("%f\n",k);
	return 0;	
}
