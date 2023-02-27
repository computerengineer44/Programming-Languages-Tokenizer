#include <stdio.h>
#include <locale.h> 

int main() {
	
	setlocale(LC_ALL, "Turkish"); //T�rk�e karakterlerin tan�nmas�.
	
	FILE *file; //Dosya pointerinin olu�turulmas�.
	
	char word[100][100], character, code[25];
	int i=0;
	
	printf("A�mak �stedi�iniz Kaynak Kodu Dosyan�z�n �smini Giriniz: ");
	scanf("%s",&code); //Kullan�c�dan kaynak dosyas�n�n isminin al�nmas�

	//Buradan 30.sat�r�n sonuna kadar kod bir IDE'de nas�l yaz�ld�ysa �yle ��kt� vermesi i�in yaz�lm��t�r.
	
	if ((file = fopen(code,"r"))!=NULL){ //Kullan�c�dan al�nan dosyan�n a��lmas�.
		
		printf("KODUNUZ INDENTATION KURALLARINA G�RE YAZDIRILMASI:\n\n\n");
		
		character = fgetc(file); //Dosyan�n fgetch() komutu ile karakter karakter okunmas� ve character adl� de�i�kene atanmas�.
		while(character!=EOF) { //Dosyay� okuma i�leminin en son karaktere kadar devam etmesi.
			printf("%c",character);
			character = fgetc(file);
		}
		
	}
	
	else {
		printf("Girdi�iniz dosya isminde bir dosya bulunamad�!!!\n");
	}
	
	//Buradan 46.sat�ra kadar kod dosyas�n�n i�indeki kodlar�n kelimele�tirilmesi i�in yaz�lm��t�r.
	
	if ((file = fopen(code,"r"))!=NULL){ //Kullan�c�dan al�nan dosyan�n a��lmas�.
		
		printf("\nG�RD���N�Z KOD DOSYASININ KEL�MELE�T�R�LM�� HAL�\n\n\n");
		
		while(!feof(file)) { //Dosyay� okuma i�lemi dosyan�n sonuna kadar devam ediyor.
			fscanf(file,"%s,",&word[i]);
			printf("%s,",word[i]);
			i++;
		}
		
	}
	
	else {
		printf("Girdi�iniz dosya isminde bir dosya bulunamad��� i�in kelimele�tirme i�lemi yap�lamad�!!!");
	}
	
	printf("\n\n\n\n\n\n\n");
	
	fclose(file);
}
