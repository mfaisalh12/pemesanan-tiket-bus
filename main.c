#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int bus,kelas,i,n;
//Deklarasi untuk Outpus Pesan
char Nama[100][100],Jenis[100][100],Bus[100][100],Jalur[100][100];
int NoKursi[100],Nik[100];
//Deklarasi Login/Registrasi
struct akun{
    char nama[100], username[100], password[100];
    int umur;
};struct akun asliAkun, tempAkun[100]; //pendeklarasian struct akun
//Deklarasi Data PenumpNG
struct DataPenumpang{
    int harga,total,nokursi,NIK;
    char nama[100];
    char jalur[100];
    char jenis[100],bus[100];
};struct DataPenumpang penumpang, temppenumpang[100]; //deklarasi data penumpang

void registrasiAkun() //operasifile registrasi akun
{
    system("cls");
    TampilanAwal();
    FILE *user;
    user = fopen("User.txt", "a+");
    printf("    Masukkan Username   : "); fflush(stdin);
    gets(asliAkun.username);
    printf("    Masukkan Password   : ");
    gets(asliAkun.password);
    printf("    Masukkan Nama Anda  : ");
    gets(asliAkun.nama);
    printf("    Masukkan Umur Anda  : ");
    scanf("%d", &asliAkun.umur);

    i = 0;
    n = 0;
    int kondisi=0;
    while(!feof(user))
    {
        fscanf(user, "%[^#]#%[^#]#%[^#]#%d\n", &tempAkun[i].username, &tempAkun[i].password, &tempAkun[i].nama, &tempAkun[i].umur);
        n++;
        i++;
    }
    for(i=0;i<n;i++){
        if (strcmp(asliAkun.username,tempAkun[i].username)==0){
            kondisi=0;
        } else
            kondisi=1;
    }
    if (kondisi==0){
        printf("   Maaf username yang anda masukkan sudah ada\n");
        printf("   Silahkan menggunakan username lain\n");
        system("pause");
        registrasiAkun();}
    else{
        fprintf(user, "%s#%s#%s#%d\n", asliAkun.username, asliAkun.password, asliAkun.nama, asliAkun.umur);}
    fclose(user);

    //Back to menu
    menuUtama();
}

void loginAkun() //login akun
{
    system("cls");
    TampilanAwal();
    int i, n;
    FILE *user;
    user = fopen("User.txt", "r");

    /*Pembacaan File User.txt*/
    i = 0;
    n = 0;
    if (!user){
        printf("Tidak ada File (Silahkan Registrasi dulu)\n");
        system("pause");
        menuUtama();
    }else{
        while(!feof(user)) {
            fscanf(user, "%[^#]#%[^#]#%[^#]#%d\n", &tempAkun[i].username, &tempAkun[i].password, &tempAkun[i].nama, &tempAkun[i].umur);
            n++;
            i++;
        }
        fclose(user);
        /*End of read File User.txt*/

        char usernameLogin[100], passwordLogin[100];
        printf("      Masukkan Username: ");
        gets(usernameLogin);
        printf("      Masukkan Passord: ");
        gets(passwordLogin);

        /*Pencarian username dan password*/
        int kondisi = 0; //variabel sementara untuk kondisi perulangan

        for(i=0; i<n; i++)
        {
            if(strcmp(usernameLogin, tempAkun[i].username) == 0 && strcmp(passwordLogin, tempAkun[i].password) == 0)
            {
                //Aksi Selanjutnya jika berhasil
                printf("===================================================\n");
                printf("  ~ SELAMAT DATANG %s ~\n", tempAkun[i].nama);
                printf("===================================================\n");
                system("pause");

                kondisi = 0;
                break; //Jangan lupa untuk break, karena kalau tidak dia akan kembali pada perulangan ini
            }
            else{
                kondisi = 1; //kondisi jika gagal login
            }
        }
        /*Akhir dari pencarian username dan password */
        if(kondisi != 0)//JIka data tidak ada
        {
            printf("\n---------------------------------------------------------------------------\n");
            printf("Username atau Password tidak terdaftar silahkan Registrasi Terlebih dahulu!\n\n");
            system("pause");
            menuUtama(); //kembali ke MenuUtama
        }

    }
}

void menuUtama() //Pemilihan menu untuk registrasi & login
{
    system("cls");
    TampilanAwal();
    int pilihanMenuUtama;
    printf(
           "   Silahkan Login/Registrasi Terlebih Dahulu\n\n"
           " 1. Registrasi\n"
           " 2. Login\n"
           " 3. Keluar\n"
           );
    printf("------------------------------------------\n");
    printf("\n Masukkan menu yang anda inginkan: ");
    scanf("%d", &pilihanMenuUtama);

    fflush(stdin);

    switch(pilihanMenuUtama)
    {
        case 1: registrasiAkun();break;
        case 2: loginAkun();break;
        default : exit(0);
    }
}

void PemilihanData() //Pemilihan setelah berhasil login
{
    system("cls");
    int pilihan;
    TampilanAwal();
    printf("\n   1. Pemesanan Tiket\n");
    printf("   2. Data Penumpang\n");
    printf("   3. Keluar        \n\n");
    printf("-------------------------------------------\n");
    printf("   Pilih Fitur Yang Ingin Digunakan: ");
    scanf("%d",&pilihan);
    if (pilihan==1) Pemesanan();
    else if(pilihan==2){
        OutputData();
    }
    else exit(0);
}

void DaftarBus1() //Data bus Bandung - Jakart
{
    system("cls");
    TampilanAwal();
    printf("\t-----------------------------------------\n");
    printf("\tDaftar Harga Bus Bandung - Jakarta\n");
    printf("\t-----------------------------------------\n");
    printf("\t\t|1.Eksekutif\t| Rp 100.000\n\t1.Bus A\t|2.Bisnis\t| Rp 89.900\n\t\t|3.Ekonomi\t| Rp 76.000\n");
    printf("\t-----------------------------------------\n");
    printf("\t\t|1.Eksekutif\t| Rp 99.000\n\t2.Bus B\t|2.Bisnis\t| Rp 88.900\n\t\t|3.Ekonomi\t| Rp 75.500\n");
    printf("\t-----------------------------------------\n");
    printf("\t\t|1.Eksekutif\t| Rp 95.000\n\t3.Bus C\t|2.Bisnis\t| Rp 80.000\n\t\t|3.Ekonomi\t| Rp 70.000\n");
    printf("\t-----------------------------------------\n");
    printf("\tNB: Pembelian Lebih Dari 5 Tiket Akan Mendapat Bonus Sebesar 10 persen\n\n");
    printf("\tPilihan Bus    : ");scanf("%d",&bus); //Pemilihan Bus
    printf("\tTentukan Kelas : ");scanf("%d",&kelas); //Pemilihan Kelas
    printf("  Masukkan Banyak Penumpang : ");scanf("%d",&n); //Input banyak penumpang
    if (bus==1){
        strcpy(penumpang.bus,"Bus A");
        switch(kelas){
            case 1 :
                penumpang.harga=100000;
                strcpy(penumpang.jenis,"Eksekutif");
                if (n>=5) //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else //Jika kurang dari 5 tidak mendapat diskon
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;
            case 2 :
                penumpang.harga=89900;
                strcpy(penumpang.jenis,"Bisnis");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;
            case 3 :
                penumpang.harga=76000;
                strcpy(penumpang.jenis,"Ekonomi");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);
        }
    }else if (bus==2){
        strcpy(penumpang.bus,"Bus B");
        switch(kelas){
            case 1 :
                penumpang.harga=99000;
                strcpy(penumpang.jenis,"Eksekutif");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;
            case 2 :
                penumpang.harga=88900;
                strcpy(penumpang.jenis,"Bisnis");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;
            case 3 :
                penumpang.harga=75500;
                strcpy(penumpang.jenis,"Ekonomi");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);
        }
    }else if (bus==3){
        strcpy(penumpang.bus,"Bus C");
        switch(kelas){
            case 1 :{
                penumpang.harga=95000;
                strcpy(penumpang.jenis,"Eksekutif");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;}
            case 2 :{
                penumpang.harga=80000;
                strcpy(penumpang.jenis,"Bisnis");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;}
            case 3 :{
                penumpang.harga=70000;
                strcpy(penumpang.jenis,"Ekonomi");
                if (n>=5)
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);}
        }
    }
}

void DaftarBus2() //Data bus Bandung-Surabaya
{
    system("cls");
    TampilanAwal();
    printf("\t-----------------------------------------\n");
    printf("\tDaftar Harga Bus Bandung - Surabaya\n");
    printf("\t-----------------------------------------\n");
    printf("\t1.Bus A\t|Eksekutif\t| Rp 260.000\t|\n");
    printf("\t-----------------------------------------\n");
    printf("\t2.Bus B\t|Eksekutif\t| Rp 270.000\t|\n");
    printf("\t-----------------------------------------\n");
    printf("\tNB: Pembelian Lebih Dari 5 Tiket Akan Mendapat Bonus Sebesar 10 persen\n\n");
    printf("\tTentukan Pilihan Anda : "); scanf("%d",&bus); //pemilihan Bus
    printf("  Masukkan Banyak Penumpang : ");scanf("%d",&n);//Input banyak penumpang
        if (bus==1) {
            strcpy(penumpang.bus,"Bus A");
            penumpang.harga=260000;
            strcpy(penumpang.jenis,"Eksekutif");
            if (n>=5){ //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                penumpang.total=HargaDiskon(penumpang.harga,n);}
            else{
                HargaTotal(&penumpang.total,penumpang.harga,n);}
        }else if(bus==2){
            strcpy(penumpang.bus,"Bus B");
            penumpang.harga=270000;
            strcpy(penumpang.jenis,"Eksekutif");
            if (n>=5){ //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                penumpang.total=HargaDiskon(penumpang.harga,n);}
            else{
                HargaTotal(&penumpang.total,penumpang.harga,n);}
        }
}

void DaftarBus3() //Data Bus Bandung-Yogyakarta
{
    system("cls");
    TampilanAwal();
    printf("\t-----------------------------------------\n");
    printf("\tDaftar Harga Bus Bandung - Yogyakarta\n\n");
    printf("\t-----------------------------------------\n");
    printf("\t\t|1.Eksekutif\t| Rp 200.000\n\t1.Bus A\t|2.Bisnis\t| Rp 180.000\n\t\t|\n");
    printf("\t-----------------------------------------\n");
    printf("\t\t|1.Eksekutif\t| Rp 160.000\n\t2.Bus B\t|2.Bisnis\t| Rp 152.000\n\t\t|3.Ekonomi\t| Rp 135.000\n");
    printf("\t-----------------------------------------\n");
    printf("\t\t|1.Eksekutif\t| Rp 159.000\n\t3.Bus C\t|2.Bisnis\t| Rp 148.000\n\t\t|3.Ekonomi\t| Rp 126.000\n");
    printf("\t-----------------------------------------\n");
    printf("\tNB: Pembelian Lebih Dari 5 Tiket Akan Mendapat Bonus Sebesar 10 persen\n\n");
    printf("\tPilihan Bus    : ");scanf("%d",&bus);
    printf("\tTentukan Kelas : ");scanf("%d",&kelas);
    printf("  Masukkan Banyak Penumpang : ");scanf("%d",&n);
    if (bus==1){
        strcpy(penumpang.bus,"Bus A");
        switch(kelas){
            case 1 : {
                penumpang.harga=200000;
                strcpy(penumpang.jenis,"Eksekutif");
                if (n>=5){ //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);}
                else{
                    HargaTotal(&penumpang.total,penumpang.harga,n);}break;}
            case 2 :{
                penumpang.harga=180000;
                strcpy(penumpang.jenis,"Bisnis");
                if (n>=5){ //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);}
                else{
                    HargaTotal(&penumpang.total,penumpang.harga,n);}}
        }
    }else if (bus==2){
        strcpy(penumpang.bus,"Bus B");
        switch(kelas){
            case 1 :{
                penumpang.harga=160000;
                strcpy(penumpang.jenis,"Eksekutif");
                if (n>=5){ //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);}
                else{
                    HargaTotal(&penumpang.total,penumpang.harga,n);}break;}
            case 2 :{
                penumpang.harga=152000;
                strcpy(penumpang.jenis,"Bisnis");
                if (n>=5){ //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);}
                else{
                    HargaTotal(&penumpang.total,penumpang.harga,n);}break;}
            case 3 :{
                penumpang.harga=135000;
                strcpy(penumpang.jenis,"Ekonomi");
                if (n>=5){ //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);}
                else{
                    HargaTotal(&penumpang.total,penumpang.harga,n);}}
        }
    }else if (bus==3){
        strcpy(penumpang.bus,"Bus C");
        switch(kelas){
            case 1 :{
                penumpang.harga=159000;
                strcpy(penumpang.jenis,"Eksekutif");
                if (n>=5) //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;}
            case 2 :{
                penumpang.harga=148000;
                strcpy(penumpang.jenis,"Bisnis");
                if (n>=5) //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);break;}
            case 3 :{
                penumpang.harga=126000;
                strcpy(penumpang.jenis,"Ekonomi");
                if (n>=5) //Jika Penumpang lebih dari 5 maka akan mendapat diskon
                    penumpang.total=HargaDiskon(penumpang.harga,n);
                else
                    HargaTotal(&penumpang.total,penumpang.harga,n);}
        }
    }
}

void Pemesanan() //Pemilihan Rute Bus
{
    system("cls");
    int rute;
    TampilanAwal();
    printf("-------------------------------\n");
    printf("|           Rute Bus          |\n");
    printf("-------------------------------\n");
    printf("|  1.  Bandung - Jakarta      |\n");
    printf("|  2.  Bandung - Surabaya     |\n");
    printf("|  3.  Bandung - Yogyakarta   |\n");
    printf("-------------------------------\n\n");
    printf("\nSilahkan Pilih Rute Anda: ");
    scanf("%d",&rute);
    switch(rute){
        case 1 : strcpy(penumpang.jalur,"Bandung-Jakarta");DaftarBus1();break;
        case 2 : strcpy(penumpang.jalur,"Bandung-Jakarta");DaftarBus2();break;
        case 3 : strcpy(penumpang.jalur,"Bandung-Yogyakarta");DaftarBus3();
    }
}

// Perhitungan Harga Total Tiket
int HargaTotal(int *hasil,int harga, int banyak)
{
    *hasil=harga*banyak;
    return *hasil;
}

//Perhitungan Harga Total Tiket dengan Diskon 10%
int HargaDiskon(int Harga, int Banyak)
{
    int Total;
    Harga=Harga*Banyak;
    Total=Harga-(Harga*10/100);
    return Total;
}

void InputData() //Perintah input data penumpang pada file penumpang
{
    system("cls");
    TampilanAwal();
    printf("\n------------------------------------------------------\n");
    for(i=0;i<n;i++){
        FILE *Penumpang;
        Penumpang = fopen("Penumpang.txt", "a");
        printf("%d\tMasukkan Nama        : ",i+1);fflush(stdin);
        gets(penumpang.nama);
        printf("\tMasukkan Nomor Kursi : ",i+1);
        scanf("%d",&penumpang.nokursi);
        printf("\tMasukkan NIK         : ",i+1);
        scanf("%d",&penumpang.NIK);
        printf("----------------------------------------------------\n");

        fprintf(Penumpang, "%s#%s#%s#%s#%d#%d\n",penumpang.nama,penumpang.jalur,penumpang.bus,penumpang.jenis,penumpang.NIK,penumpang.nokursi);
        //Pengisian data pada variabel sementara untuk OutputPesan
        strcpy(Nama[i],penumpang.nama);
        strcpy(Jenis[i],penumpang.jenis);
        strcpy(Bus[i],penumpang.bus);
        strcpy(Jalur[i],penumpang.jalur);
        NoKursi[i]=penumpang.nokursi;
        Nik[i]=penumpang.NIK;
        fclose(Penumpang);
    }
}

void OutputData() //Output data pada PemilihanData Data Penumpang
{
    system("cls");
    TampilanAwal();
    int i, n;
    FILE *Penumpang;
    Penumpang = fopen("Penumpang.txt", "r");

    if (!Penumpang){
        printf("  File data penumpang tidak ada\n");
        printf("  Silahkan lakukan pemesanan terlebih dahulu\n\n");
        system("pause");
        PemilihanData();
    }
    else{
        /*Pembacaan File Penumpang.txt*/
        i = 0;
        n = 0;
        while(!feof(Penumpang))
        {
            fscanf(Penumpang, "%[^#]#%[^#]#%[^#]#%[^#]#%d#%d\n",&temppenumpang[i].nama,&temppenumpang[i].jalur,&temppenumpang[i].bus,&temppenumpang[i].jenis,&temppenumpang[i].NIK,&temppenumpang[i].nokursi);
            n++;
            i++;
        }
        fclose(Penumpang); /*End of read File Penumpang.txt*/
        for(i=0;i<n;i++){
            printf("%d\tNo Kursi        : %d\n",i+1,temppenumpang[i].nokursi);
            printf("\tNama            : %s\n",temppenumpang[i].nama);
            printf("\tNIK             : %d\n",temppenumpang[i].NIK);
            printf("\tJalur           : %s\n",temppenumpang[i].jalur);
            printf("\tJenis Kereta    : %s %s\n",temppenumpang[i].bus,temppenumpang[i].jenis);
        }
        system("pause");
        system("cls");
        TampilanAwal();
        int cari,pass;
        printf("---------------------------------------\n");
        printf("| 1. Urutkan Berdasarkan Nomor Kursi  |\n");
        printf("| 2. Cari Data Berdasarkan NIK        |\n");
        printf("---------------------------------------\n");
        printf(" Pilih Fitur: ");
        scanf("%d",&cari);
        //Proses Sorting
        if (cari==1){
            system("cls");
            TampilanAwal();
            //selection sort
            for (pass = 0; pass < n; ++pass){
                for (i = pass + 1; i < n; ++i){
                    if (temppenumpang[pass].nokursi > temppenumpang[i].nokursi){
                        penumpang = temppenumpang[ pass ];
                        temppenumpang[pass] = temppenumpang[i];
                        temppenumpang[i] = penumpang;
                    }
                }
            }
            printf("\n   Data Diurutkan Berdasarkan Nomor Kursi :\n");
            printf("---------------------------------------------\n");
            for (i= 0; i < n; ++i){
                printf("%d\tNo Kursi        : %d\n",i+1,temppenumpang[i].nokursi);
                printf("\tNama            : %s\n",temppenumpang[i].nama);
                printf("\tNIK             : %d\n",temppenumpang[i].NIK);
                printf("\tJalur           : %s\n",temppenumpang[i].jalur);
                printf("\tJenis Kereta    : %s %s\n",temppenumpang[i].bus,temppenumpang[i].jenis);
            }
        system("pause");
        PemilihanData();}
        //Proses Searching binary
        else if (cari==2){
            system("cls");
            TampilanAwal();
            int idx,low,high,mid;
            //selection sort
            for (pass = 0; pass < n; ++pass){
                for (i = pass + 1; i < n; ++i){
                    if (temppenumpang[pass].NIK > temppenumpang[i].NIK){
                        penumpang = temppenumpang[ pass ];
                        temppenumpang[pass] = temppenumpang[i];
                        temppenumpang[i] = penumpang;}
            }}

            printf("           Data diurutkan berdasarkan NIK         \n");
            printf("--------------------------------------------------\n");
            for (i= 0; i < n; ++i){
                printf("%d\tNo Kursi        : %d\n",i+1,temppenumpang[i].nokursi);
                printf("\tNama            : %s\n",temppenumpang[i].nama);
                printf("\tNIK             : %d\n",temppenumpang[i].NIK);
                printf("\tJalur           : %s\n",temppenumpang[i].jalur);
                printf("\tJenis Kereta    : %s %s\n",temppenumpang[i].bus,temppenumpang[i].jenis);}
            printf("--------------------------------------------------\n");
            printf(" Cari data dengan NIK : ");
            scanf("%d",&cari);
            printf("-----------------------------\n");
            low=1; high=n; idx=0;
            while((low<=high)&&(idx==0)){
                mid=(low+high)/2;
                if (temppenumpang[mid].NIK==cari)
                    idx=mid;
                else if (temppenumpang[mid].NIK<cari)
                    low=mid+1;
                else high=mid-1;}
            if (idx>=0) printf("\n Data ditemukan pada Nomor :%2d\n\n",idx+1);
            else printf("\n Data tidak ditemukan"); system("pause");
            PemilihanData();
            }
    }
}

void OutputPesan() //Output Data pada PemilihanData Pemesanan
{
    system("cls");
    TampilanAwal();
    printf("------------------------------------------------\n");
    for (i=0;i<n;i++){
        printf("%d\tNo Kursi        : %d\n",i+1,NoKursi[i]);
        printf("\tNama            : %s\n",Nama[i]);
        printf("\tNIK             : %d\n",Nik[i]);
        printf("\tJalur           : %s\n",Jalur[i]);
        printf("\tJenis Kereta    : %s %s\n",Bus[i],Jenis[i]);
    }
    printf("------------------------------------------------\n");
    //Output jika mendapatkan diskon 10%
    if(n>=5) printf("\tSelamat Anda Mendapat Diskon 10 persen\n");
    printf("\tHarga Total Tiket : Rp %d\n\n\n",penumpang.total);
    system("pause");
    PemilihanData();
}
//Program Utama
int main()
{
    TampilanAwal();
    printf("               SELAMAT DATANG DI\n");
    printf("     APLIKASI MANAJEMEN PEMESANAN TIKET BUS\n\n");
    printf("       \t             Oleh:\n");
    printf("    \t  Muhammad Faisal Hidayatullah\n\t    Taufiq Salman Sya'bani\n\n");
    printf("    \t    Teknik Komputer 43-03\n\n");
    system("pause");
    menuUtama();
    PemilihanData();
    InputData();
    OutputPesan();
    return 0;
}

//Header pada aplikasi
void TampilanAwal()
{
    printf("             ======================= \n");
    printf("      ====================================\n");
    printf("      ||  PEMESANAN TIKET BUS INDONESIA ||\n");
    printf("      ====================================\n\n");
}
