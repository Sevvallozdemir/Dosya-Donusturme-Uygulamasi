#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void jsonToCsv(FILE *jsonFile, FILE *csvFile, int addHeader) {
	//e�er baslik eklenecekse, CSV dosyasina baslik satirini yaziyoruz.
    if (addHeader) {
        fprintf(csvFile, "id,name,midterm,final,course\n");
    }

    char buffer[2048];
    while (fgets(buffer, sizeof(buffer), jsonFile) != NULL) {
        // JSON dosyas�ndan gerekli verileri ��kar�yoruz
        int id, midterm, final;
        char name[50], course[20];
        
        //id satirini okuyoruz ve de�erini aliyoruz
        if (sscanf(buffer, "        \"id\": %d,", &id) == 1) {
            fgets(buffer, sizeof(buffer), jsonFile); // "name" sat�r�n� okuma
            sscanf(buffer, "        \"name\": \"%[^\"]\",", name);
            
            fgets(buffer, sizeof(buffer), jsonFile); // "grades" sat�r�n� okuma
            fgets(buffer, sizeof(buffer), jsonFile); // "midterm" sat�r�n� okuma
            sscanf(buffer, "            \"midterm\": %d,", &midterm);
            
            fgets(buffer, sizeof(buffer), jsonFile); // "final" sat�r�n� okuma
            sscanf(buffer, "            \"final\": %d,", &final);

            fgets(buffer, sizeof(buffer), jsonFile); // "course" sat�r�n� okuma
            sscanf(buffer, "        \"course\": \"%[^\"]\",", course);

            // CSV dosyas�na yazd�ralim
            fprintf(csvFile, "%d,%s,%d,%d,%s\n", id, name, midterm, final, course);
        }
    }
}

int main(int argc, char *argv[]) {
	//komut sat�r� parametre say�s�n� kontrol ediyoruz
    if (argc != 4) {
        printf("Kullan�m: %s <JSON dosyas�> <CSV dosyas�> <header=ON/OFF>\n", argv[0]);
        return 1;
    }

    char *jsonFileName = argv[1];
    char *csvFileName = argv[2];
    //E�er header=ON ise addHeader de�i�kenine 1 atadik, de�ilse 0 atad�k
    int addHeader = strcmp(argv[3], "header=ON") == 0 ? 1 : 0;

    FILE *jsonFile = fopen(jsonFileName, "r");
    FILE *csvFile = fopen(csvFileName, "w");

    if (!jsonFile || !csvFile) {
        printf("Dosya acilamadi\n");
        return 1;
    }
//json dosyasini csv e �eviren fonksiyonu �a��r�yor.
    jsonToCsv(jsonFile, csvFile, addHeader);

//dosyalar� kapatiyoruz.
    fclose(jsonFile);
    fclose(csvFile);
    printf("Csv dosyas� ba�ar�l� bir �ekilde olu�turulmu�tur.");
    
    return 0;
}
