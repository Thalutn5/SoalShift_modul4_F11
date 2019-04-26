# SoalShift_modul4_F11
# Soal1
Semua nama file dan folder harus terenkripsi

Enkripsi yang Atta inginkan sangat sederhana, yaitu Caesar cipher. Namun, Kusuma mengatakan enkripsi tersebut sangat mudah dipecahkan. Dia menyarankan untuk character list diekspansi,tidak hanya alfabet, dan diacak. Berikut character list yang dipakai:

```qE1~ YMUR2"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\8s;g<{3.u*W-0```

Misalkan ada file bernama “halo” di dalam folder “INI_FOLDER”, dan key yang dipakai adalah 17, maka:
“INI_FOLDER/halo” saat belum di-mount maka akan bernama “n,nsbZ]wio/QBE#”, saat telah di-mount maka akan otomatis terdekripsi kembali menjadi “INI_FOLDER/halo” .

Perhatian: Karakter ‘/’ adalah karakter ilegal dalam penamaan file atau folder dalam *NIX, maka dari itu dapat diabaikan

Jawab :

- Untuk mengerjakan soal ini saya membuat script decrip dan enkrip
- Untuk script decrip

        char abjad[256]="qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
    	int i, j, panjang;
	  char input[strlen(de->d_name)];
		strcpy(input, de->d_name);

		if(strcmp(input, ".") != 0 && strcmp(input, "..") != 0)
    		{
			panjang = strlen(input); 
			for(i=0;i<panjang;i++)//ngubah perkarakter
			{
				if(input[i]=='/')
				{input[i]='/';}
				else{
				for(j=0;input[i]!=abjad[j];j++)//nyari karakter yang sama di abjad
				{}
				j=j-17;
				if(j<0)
				{j=j+strlen(abjad);}
				input[i]=abjad[j];
				}
			}
			strcpy(de->d_name,input);

			res = (filler(buf, de->d_name, &st, 0));
				if(res!=0) break
			}
		     
- Untuk script encrip

                        char file[1000];
			char abjad[256]="qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int i, j, panjang;
			char input[strlen(path)];
			strcpy(input, path);
			panjang = strlen(input); 
			for(i=0;i<panjang;i++)//ngubah perkarakter
			{
				if(input[i]=='/')
				{input[i]='/';}
				else{
				for(j=0;input[i]!=abjad[j];j++)//nyari karakter yang sama di abjad
				{}
				j=j+17;
				if(j>93)
				{j=j-strlen(abjad);}
				input[i]=abjad[j];
				}
			}
			strcpy(file,input);
		sprintf(fpath,"%s%s",dirpath,file);

- Setelah itu saya mengopaskan template yang ada di modul lalu mengganti dirpathnya menjadi

        /home/thalutn5/SoalShift4/AFSHiaAP

- Dan saya menaruh script encrip saya pada fungsi getatrr agar bisa mengambil atribut dari hasil encripnya
- Saya juga menaruh script encrip saya pada fungsi readdir agar bisa membuka subfolder dari suatu folder
- Serta juga menaruh script encrip di fungsi xmp_read agar file yang dituju bisa diread
- Sementara untuk script decrip saya menaruhnya di fungsi readdir di dalam while agar mecahin ekripsinya agar bisa dibaca



# Soal2
Semua file video yang tersimpan secara terpecah-pecah (splitted) harus secara otomatis tergabung (joined) dan diletakkan dalam folder “Videos”

Urutan operasi dari kebutuhan ini adalah:

a. Tepat saat sebelum file system di-mount

- Secara otomatis folder “Videos” terbuat di root directory file system

- Misal ada sekumpulan file pecahan video bernama “computer.mkv.000”, “computer.mkv.001”, “computer.mkv.002”, dst. Maka secara otomatis file pecahan tersebut akan di-join menjadi file video “computer.mkv” 

- Untuk mempermudah kalian, dipastikan hanya video file saja yang terpecah menjadi beberapa file. File pecahan tersebut dijamin terletak di root folder fuse

- Karena mungkin file video sangat banyak sehingga mungkin saja saat menggabungkan file video, file system akan membutuhkan waktu yang lama untuk sukses ter-mount. Maka pastikan saat akan menggabungkan file pecahan video, file system akan membuat 1 thread/proses(fork) baru yang dikhususkan untuk menggabungkan file video tersebut

- Pindahkan seluruh file video yang sudah ter-join ke dalam folder “Videos”

- Jangan tampilkan file pecahan di direktori manapun

b. Tepat saat file system akan di-unmount

- Hapus semua file video yang berada di folder “Videos”, tapi jangan hapus file pecahan yang terdapat di root directory file system

- Hapus folder “Videos” 

Jawab :

# Soal3
Sebelum diterapkannya file system ini, Atta pernah diserang oleh hacker LAPTOP_RUSAK yang menanamkan user bernama “chipset” dan “ic_controller” serta group “rusak” yang tidak bisa dihapus. Karena paranoid, Atta menerapkan aturan pada file system ini untuk menghapus “file bahaya” yang memiliki spesifikasi:

Owner Name 	: ‘chipset’ atau ‘ic_controller’

Group Name	: ‘rusak’

Tidak dapat dibaca

Jika ditemukan file dengan spesifikasi tersebut ketika membuka direktori, Atta akan menyimpan nama file, group ID, owner ID, dan waktu terakhir diakses dalam file “filemiris.txt” (format waktu bebas, namun harus memiliki jam menit detik dan tanggal) lalu menghapus “file bahaya” tersebut untuk mencegah serangan lanjutan dari LAPTOP_RUSAK.

Jawab :

- Untuk mengerjakan soal ini saya menambah fungs unlink dan didalam fungsi unlink saya tambahkan script encrip

		static int xmp_unlink(const char *path)
		{
    		int res;
		char file[1000];
		char fpath[1000];
			char abjad[256]="qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int i, j, panjang;
			char input[strlen(path)];
			strcpy(input, path);
			panjang = strlen(input); 
			for(i=0;i<panjang;i++)//ngubah perkarakter
			{
				if(input[i]=='/')
				{input[i]='/';}
				else{
				for(j=0;input[i]!=abjad[j];j++)//nyari karakter yang sama di abjad
				{}
				j=j+17;
				if(j>93)
				{j=j-strlen(abjad);}
				input[i]=abjad[j];
				}
			}
			strcpy(file,input);
		sprintf(fpath,"%s%s",dirpath,file);
    		res = unlink(fpath);
    		if(res == -1)
        	return -errno;

   		 return 0;
		}

- Lalu di readdir saya menambahkanscript yang akan menyaring owner chipset dan ic_controller serta group namenya rusak.

		//struct stat info; //mencari informasi
    		struct passwd *pwd ; //karena yang direturn pwd getpwuid sebuah strurt menuju passw ngambil owner
    		struct group *group;		
	 	char folderawal[256];
   	 	//strcpy(folderawal, "/home/thalutn5/SoalShift4/AFSHiaAP");
		//strcat(folderawal, path);
		sprintf(folderawal, "%s/%s", dirpath, de->d_name);
		//strcpy(folderawal+strlen(folderawal), input);
    		char cari[256]="chipset";
    		char cari2[256]="ic_controller";
    		char cari3[256]="rusak";
    		stat(folderawal, &st); //ngambil info dari sebuah file di folder
    		pwd = getpwuid(st.st_uid); //menambil id user lalu disimpan di tempat yg ditunjuk pwd && info = tempat nyimpen info sebuah file
		//printf("%s/n/n/n", pwd->pw_name);
		group =  getgrgid(st.st_gid); //mengambil id grup dari owner lalu disimpan di tempat yang ditunjuk gruop
    		//chmod(folderawal, S_IRWXU | S_IRWXO | S_IRWXG);
    		//chmod(folderawal, 0777);
		
		
- Dan jika nama owner dan group sesuai dengan yang ada di soal maka file tersebut akan didelete dan dicatat di sebuah file 

    		if((strcmp(pwd->pw_name, cari)==0 || strcmp(pwd->pw_name, cari2) ==0) && strcmp(group->gr_name, cari3)==0)
   		 {	 
			remove(folderawal);
			FILE* file;
			char namafile[1000];
			time_t ddd = time(NULL);
			struct tm waktu = *localtime(&ddd);
			file = fopen("/home/thalutn5/SoalShift4/AFSHiaAP/V[EOr[c[Y`HDH","a");
			sprintf(namafile,"%s %d %d %02d:%02d:%04d-%02d:%02d \n", folderawal, group->gr_gid, pwd->pw_uid,waktu.tm_mday,waktu.tm_mon+1,waktu.tm_year+1900,waktu.tm_hour,waktu.tm_min);
			printf("%s\n\n\n\n\n\n\n\n\n", namafile);
			if(fputs(namafile, file)<0)
			printf("erroe \n\n\n");
			fclose(file);
			//remove(folderawal);

        
# Soal4
Pada folder YOUTUBER, setiap membuat folder permission foldernya akan otomatis menjadi 750. Juga ketika membuat file permissionnya akan otomatis menjadi 640 dan ekstensi filenya akan bertambah “.iz1”. File berekstensi “.iz1” tidak bisa diubah permissionnya dan memunculkan error bertuliskan “File ekstensi iz1 tidak boleh diubah permissionnya.”

Jawab :

# Soal5
Pada folder YOUTUBER, setiap membuat folder permission foldernya akan otomatis menjadi 750. Juga ketika membuat file permissionnya akan otomatis menjadi 640 dan ekstensi filenya akan bertambah “.iz1”. File berekstensi “.iz1” tidak bisa diubah permissionnya dan memunculkan error bertuliskan “File ekstensi iz1 tidak boleh diubah permissionnya.”

Jawab :

