Çalıştırmak için komut istemine yazılan bir örnek:

C:\Users\se_vv>cd C:\Users\se_vv\OneDrive\Masaüstü\VERİTABANİ2DOSYALAR\210601040_Sevval_Ozdemir_Odev1

C:\Users\se_vv\OneDrive\Masaüstü\VERİTABANİ2DOSYALAR\210601040_Sevval_Ozdemir_Odev1>gcc -o jsontocsv jsontocsv.c

C:\Users\se_vv\OneDrive\Masaüstü\VERİTABANİ2DOSYALAR\210601040_Sevval_Ozdemir_Odev1>jsontocsv test.json output.csv
Kullan²m: jsontocsv <JSON dosyas²> <CSV dosyas²> <header=ON/OFF>

C:\Users\se_vv\OneDrive\Masaüstü\VERİTABANİ2DOSYALAR\210601040_Sevval_Ozdemir_Odev1>jsontocsv test.json output1.csv header=ON
Csv dosyas² ba■ar²l² bir ■ekilde olu■turulmu■tur.

C:\Users\se_vv\OneDrive\Masaüstü\VERİTABANİ2DOSYALAR\210601040_Sevval_Ozdemir_Odev1>jsontocsv test.json output2.csv header=OFF
Csv dosyas² ba■ar²l² bir ■ekilde olu■turulmu■tur.

Benim bilgisayarımdan cmd yi açtığımda yukarıdaki komutları girerek output1(başlıklı hali) ve output2(başlıksız hali) dosyalarını açtım. Siz de dosya konumunu değiştirerek aynı komutları girip csv dosyalarını açabilirsiniz 
Başlıklar olsun istiyorsak -->> C:\Users\se_vv\OneDrive\Masaüstü\VERİTABANİ2DOSYALAR\210601040_Sevval_Ozdemir_Odev1>jsontocsv test.json output1.csv header=ON  //jsontocsv dediğimiz dosya exe dosyamız oluyor. output dediğimiz dosya oluşturulacak csv dosyamızın adı. 

Başlıklar olmasın istiyorsak -->> C:\Users\se_vv\OneDrive\Masaüstü\VERİTABANİ2DOSYALAR\210601040_Sevval_Ozdemir_Odev1>jsontocsv test.json output2.csv header=OFF

