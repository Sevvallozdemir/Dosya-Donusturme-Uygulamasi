#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void jsonToCsv(FILE *jsonFile, FILE *csvFile, int addHeader) {
	//eðer baslik eklenecekse, CSV dosyasina baslik satirini yaziyoruz.
    if (addHeader) {
        fprintf(csvFile, "id,name,midterm,final,course\n");
    }

    char buffer[2048];
    while (fgets(buffer, sizeof(buffer), jsonFile) != NULL) {
        // JSON dosyasýndan gerekli verileri çýkarýyoruz
        int id, midterm, final;
        char name[50], course[20];
        
        //id satirini okuyoruz ve deðerini aliyoruz
        if (sscanf(buffer, "        \"id\": %d,", &id) == 1) {
            fgets(buffer, sizeof(buffer), jsonFile); // "name" satýrýný okuma
            sscanf(buffer, "        \"name\": \"%[^\"]\",", name);
            
            fgets(buffer, sizeof(buffer), jsonFile); // "grades" satýrýný okuma
            fgets(buffer, sizeof(buffer), jsonFile); // "midterm" satýrýný okuma
            sscanf(buffer, "            \"midterm\": %d,", &midterm);
            
            fgets(buffer, sizeof(buffer), jsonFile); // "final" satýrýný okuma
            sscanf(buffer, "            \"final\": %d,", &final);

            fgets(buffer, sizeof(buffer), jsonFile); // "course" satýrýný okuma
            sscanf(buffer, "        \"course\": \"%[^\"]\",", course);

            // CSV dosyasýna yazdýralim
            fprintf(csvFile, "%d,%s,%d,%d,%s\n", id, name, midterm, final, course);
        }
    }
}

int main(int argc, char *argv[]) {
	//komut satýrý parametre sayýsýný kontrol ediyoruz
    if (argc != 4) {
        printf("Kullaným: %s <JSON dosyasý> <CSV dosyasý> <header=ON/OFF>\n", argv[0]);
        return 1;
    }

    char *jsonFileName = argv[1];
    char *csvFileName = argv[2];
    //Eðer header=ON ise addHeader deðiþkenine 1 atadik, deðilse 0 atadýk
    int addHeader = strcmp(argv[3], "header=ON") == 0 ? 1 : 0;

    FILE *jsonFile = fopen(jsonFileName, "r");
    FILE *csvFile = fopen(csvFileName, "w");

    if (!jsonFile || !csvFile) {
        printf("Dosya acilamadi\n");
        return 1;
    }
//json dosyasini csv e çeviren fonksiyonu çaðýrýyor.
    jsonToCsv(jsonFile, csvFile, addHeader);

//dosyalarý kapatiyoruz.
    fclose(jsonFile);
    fclose(csvFile);
    printf("Csv dosyasý baþarýlý bir þekilde oluþturulmuþtur.");
    
    return 0;
}
