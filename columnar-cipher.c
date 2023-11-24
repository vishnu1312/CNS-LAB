#include<stdio.h>
#include<conio.h>

void encrypt(char message[],int key) {
	int len = strlen(message),row = (len + key - 1) / key;
	int i,j,m = 0;
	char encryption[100][100];
	int index = 0;
	for(i=0;i<row;i++) {
		for(j=0;j<key;j++) {
			if(m < len) {
				encryption[i][j] = message[m];
				m++;
			}
			else {
				encryption[i][j] = 'X';
			}
		}
	}
	for(j=0;j<key;j++) {
		for(i=0;i<row;i++) {
			if(encryption[i][j] != 'X') {
				printf("%c",encryption[i][j]);
			}
		}
	}
}

int main() {
	char message[100];
	int key;
	printf("Plain Text:");
	scanf("%s",&message);
	printf("Key:");
	scanf("%d",&key);
	printf("Encrypted Message:\n ");
	encrypt(message,key);
}
