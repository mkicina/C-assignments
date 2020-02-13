#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sum_digits(const long int number){
    int x=number,sum = 0,zvys;
    if (number<0) {
        return 0;
    }
    while (1)  {
        zvys = x % 10;
        sum = sum + zvys;
        x = x / 10;
        if (x == 0){
            break;
        }
    }
    return sum;
}

int main() {
	int i=0;
	char number_string[100000]={'\0'};
	int number[100000];
	scanf("%s",number_string);;
    	int size=strlen(number_string);
    	for(i=0; i<size; i++){
        	number[i]=(((int)number_string[i])-48);
      //  	printf("%d",number[i]);
    	}
	
	int sum=0;
	int count=0;
	for (int i=0;i<size;i++) {
		sum=sum+number[i];
		count++;
	}	
	while(sum>9){
		sum=sum_digits(sum);
	}

	printf("%d\n",sum);
	return  0;
}
