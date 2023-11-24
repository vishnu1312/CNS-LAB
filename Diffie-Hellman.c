#include<stdio.h>
#include<math.h>

int main() {
	int q,b,Xa,Xb,Ya,Yb,k1,k2,t1,t2,t3,t4;
	
	printf("Enter value of q:");
	scanf("%d",&q);
	printf("Enter value of alpha:");
	scanf("%d",&b);
	printf("Enter value of Xa and Xb:");
	scanf("%d %d",&Xa,&Xb);
	
	t1 = pow(b,Xa);
	Ya = t1 % q;
	printf("Ya = %d\n",Ya);
	
	t2 = pow(b,Xb);
	Yb = t2 % q;
	printf("Yb = %d\n",Yb);
	
	t3 = pow(Yb,Xa);
	k1 = t3 % q;
	
	t4 = pow(Ya,Xb);
	k2 = t4 % q;
	
	if(k1 == k2) 
	printf("The value of k = %d\n",k1);
	
	return 0;
}
