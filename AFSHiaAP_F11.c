#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <pwd.h>
#include <grp.h>

static const char *dirpath = "/home/thalutn5/SoalShift4/AFSHiaAP";

static int xmp_getattr(const char *path, struct stat *stbuf)//ngambil atribut dari filenya enkrip
{
  	int res;
	char fpath[1000];
	
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
	res = lstat(fpath, stbuf);


	if (res == -1)
		return -errno;

	return 0;
}
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
static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
		       off_t offset, struct fuse_file_info *fi)
{
  char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {//open sub folder isi dari ini folder
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
		
	}
	int res = 0;

	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;

		char abjad[256]="qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
    int i, j, panjang;
		char input[strlen(de->d_name)+5];
		strcpy(input, de->d_name);
		
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
		}
		else{
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
					if(res!=0) break;
			}
		}
		
	}

	closedir(dp);
	return 0;
}

static int xmp_read(const char *path, char *buf, size_t size, off_t offset,
		    struct fuse_file_info *fi)
{
  char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {char file[1000];
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
		sprintf(fpath,"%s%s",dirpath,file);}


	int res = 0;
  int fd = 0 ;

	(void) fi;
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		return -errno;

	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);
	return res;
}

static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.read		= xmp_read,
	.unlink	= xmp_unlink,
};

int main(int argc, char *argv[])
{
  umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}

