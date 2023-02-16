#include <stdio.h>
#include <string.h>

void main() {

	int gun, ay, yil, i, ilk_gun, toplam = 0;
	int ay_uzunluklari[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char dizi[7][10] = { "Pazartesi","Sali","Carsamba","Persembe","Cuma","Cumartesi","Pazar" };

	printf("Lutfen tarihi gun.ay.yil seklinde giriniz : "); scanf_s("%d.%d.%d", &gun, &ay, &yil);

	
	if (yil % 4 == 0 && ay == 2 && gun > 29)
		printf("\nSubat ayi 29 gun oldugu icin ,Yanlis tarih girdiniz.");

	else if (yil % 4 != 0 && ay == 2 && gun > 28)
		printf("\nSubat ayi 28 gun oldugu icin,Yanlis tarih girdiniz.");

	else if (gun >= 1 && gun <= 31 && ay >= 1 && ay <= 12 && yil >= 0) {

		if (yil % 4 != 0) {

			toplam += gun;

			for (i = 0; i < ay - 1; i++) {
				toplam += ay_uzunluklari[i];
			}
			printf("\nYilin %d. gunundesiniz.", toplam);

		}
		else if (yil % 4 == 0 && ay > 2) {
			toplam += gun + 1;

			for (i = 0; i < ay - 1; i++) {
				toplam += ay_uzunluklari[i];
			}
			printf("\nYilin %d. gunundesiniz.\n", toplam);

		}
	
		printf("\n\nYilin ilk gununu belirtiniz.\n\n");
		printf("Pazartesi : 1\nSali      : 2\nCarsamba  : 3\nPersembe  : 4\nCuma      : 5\nCumartesi : 6\nPazar     : 7\n\n"); scanf_s("%d", &ilk_gun);
		toplam += ilk_gun - 1;
		toplam = toplam % 7;

		if (toplam == 0) {
			toplam += 7;
		}

		printf("\nGirdiginiz tarih %s gunudur.", dizi[toplam - 1]);

	}
	else
		printf("\nYanlis tarih girdiniz.");

}