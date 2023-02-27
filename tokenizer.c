#include <stdio.h>
#include <locale.h> 

int main() {
	
	setlocale(LC_ALL, "Turkish"); //Türkçe karakterlerin tanýnmasý.
	
	FILE *file; //Dosya pointerinin oluþturulmasý.
	
	char word[100][100], character, code[25];
	int i=0;
	
	printf("Açmak Ýstediðiniz Kaynak Kodu Dosyanýzýn Ýsmini Giriniz: ");
	scanf("%s",&code); //Kullanýcýdan kaynak dosyasýnýn isminin alýnmasý

	//Buradan 30.satýrýn sonuna kadar kod bir IDE'de nasýl yazýldýysa öyle çýktý vermesi için yazýlmýþtýr.
	
	if ((file = fopen(code,"r"))!=NULL){ //Kullanýcýdan alýnan dosyanýn açýlmasý.
		
		printf("KODUNUZ INDENTATION KURALLARINA GÖRE YAZDIRILMASI:\n\n\n");
		
		character = fgetc(file); //Dosyanýn fgetch() komutu ile karakter karakter okunmasý ve character adlý deðiþkene atanmasý.
		while(character!=EOF) { //Dosyayý okuma iþleminin en son karaktere kadar devam etmesi.
			printf("%c",character);
			character = fgetc(file);
		}
		
	}
	
	else {
		printf("Girdiðiniz dosya isminde bir dosya bulunamadý!!!\n");
	}
	
	//Buradan 46.satýra kadar kod dosyasýnýn içindeki kodlarýn kelimeleþtirilmesi için yazýlmýþtýr.
	
	if ((file = fopen(code,"r"))!=NULL){ //Kullanýcýdan alýnan dosyanýn açýlmasý.
		
		printf("\nGÝRDÝÐÝNÝZ KOD DOSYASININ KELÝMELEÞTÝRÝLMÝÞ HALÝ\n\n\n");
		
		while(!feof(file)) { //Dosyayý okuma iþlemi dosyanýn sonuna kadar devam ediyor.
			fscanf(file,"%s,",&word[i]);
			printf("%s,",word[i]);
			i++;
		}
		
	}
	
	else {
		printf("Girdiðiniz dosya isminde bir dosya bulunamadýðý için kelimeleþtirme iþlemi yapýlamadý!!!");
	}
	
	printf("\n\n\n\n\n\n\n");
	
	fclose(file);
}
