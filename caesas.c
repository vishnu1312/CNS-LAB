#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() 
{ 
    int k,i;
    char input[100],cipher[100];
	printf("Enter the key value:");
	scanf("%d",&k);
	printf("Enter the input string:");
	scanf("%s",&input);
	
	printf("Encryption:");
	
	for(i=0;i<strlen(input);i++) {
		if(islower(input[i]))
		{
			cipher[i] = ((input[i]  - 'a'+ k) % 26) + 'a';
		}
		else 
		{
			cipher[i] = ((input[i] - 'A'+ k) % 26) + 'A';
		}
		printf("%c",cipher[i]);
	}
	printf("\n Decryption:");
	for (i=0;i<strlen(cipher);i++)
	{
		if(islower(cipher[i]))
		{
			input[i] = ((cipher[i] - 'a'- k) % 26) + 'a' ;
		}
		else
		{
			input[i] = ((cipher[i] - 'A'- k) % 26) + 'A' ;
		}
		printf("%c",input[i]);
	}
	
}
