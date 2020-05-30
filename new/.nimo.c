#include<stdio.h>

typedef struct{
	int day;
	int month;
	int year;
}date;

int main(){
	date d1;
	date d2;
	
	printf("Enter date1 (dd,mm,yyyy) : ");
	scanf("%d %d %d",&d1.day,&d1.month,&d1.year);

	printf("Enter date2 (dd,mm,yyyy)");
	scanf("%d %d %d",&d2.day,&d2.month,&d2.year);
		
	if(d1.day == d2.day){
		if(d1.month == d2.month){
			if(d1.year == d2.year){
				printf("Dates are  equal.");
			}
			else
				printf("Dates are not equal.");
		}
		else
			printf("Dates are not equal.");
	}
	else
		printf("Dates are not equal.");
	return 0;
}
