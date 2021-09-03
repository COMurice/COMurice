#include "sgx_urts.h"
#include "Enclave_u.h"
#include <wchar.h>
#include<curses.h>
#include<term.h>
#include <sys/uio.h>
#include <execinfo.h>    
#include <pwd.h>
#include<bits/stdc++.h>
#include<sys/vfs.h>
#include<sys/statfs.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/resource.h>
#include<signal.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/utsname.h>
#include<dlfcn.h>
#include<sys/types.h>
#include<dirent.h>
#include <pthread.h> 
#include<ctype.h>
#include <sys/sysinfo.h>
#include<malloc.h>
#include<spawn.h>
#include<sys/wait.h>
#include<string.h>
#include <link.h>
#include<sys/time.h>
#include<poll.h>
#include <map>
#include<errno.h>
#include<sys/ioctl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<fnmatch.h>
#define ubt int
#define _locale_t int
#define nfds_t int
#define wctype_t int
#define _RESTRICT restrict
#define bool int
#define true 1
#define false 0
# define TOKEN_FILENAME   "/home/lab/memory-resident/ld/enclave.token"
# define ENCLAVE_FILENAME "/home/lab/memory-resident/ld/enclave.signed.so"
using namespace std;
sgx_enclave_id_t global_eid = 0;


typedef struct _jmp_buf
{
    int _jp[1];
} jmp_buf1[1];



// struct pollfd {
//         int fd;
//         short events;
//         short revents;
// };
void printf_ocall()
{
	//printf("test this enclave");
}
char all_env[10000000];
char all_argv[10000000];
int SGX_CDECL  main(int argc, char *argv[], char *env[])
{
	int first_arg=123456;
	int seconde_arg=12345;
  	setbuf(stdout, 0);
	sgx_enclave_id_t eid;
	sgx_launch_token_t token = {0};
	sgx_status_t ret = SGX_ERROR_UNEXPECTED;
	
	// void *e_addr = &errno;
	// void *argv_p = (void *)argv;
	// void *env_p = (void *)env;
	int updated = 0;
	// ecall_compile(global_eid,argc,&argv_p,&env_p,&e_addr);
	int length_env[100000],length_argv[100000];
	
	int cnt_env=0,cnt_argv=0;
	memset(all_env,'\0',sizeof(all_env));
	memset(all_argv,'\0',sizeof(all_argv));
	memset(length_argv,0,sizeof(length_argv));
	memset(length_env,0,sizeof(length_env));
	for(char **temp_env=env;*temp_env;temp_env++)
	{
		length_env[cnt_env++]=strlen(*temp_env);
		strncat(all_env,*temp_env,strlen(*temp_env));
		all_env[strlen(all_env)]='0';
	}
	// printf("cnt_env=%d\n",cnt_env);
	// for(char **temp_env=env;*temp_env;temp_env++)
	// {
	// 	printf("%s\n",*temp_env);
	// 	printf("**********\n");
	// }
	for(char **temp_argv=argv;*temp_argv;temp_argv++)
	{
		length_argv[cnt_argv++]=strlen(*temp_argv);
		strncat(all_argv,*temp_argv,strlen(*temp_argv));
		all_argv[strlen(all_argv)]='0';
	}
	printf("%s\n",all_argv);
	// printf("*************************************************\n");
	// int length = 0;
	// for(int i=0;i<cnt_env;i++)
	// {
	// 	for(int j=length;j<length+length_env[i];j++)
	// 	{
	// 		printf("%c",all_env[j]);
	// 	}
	// 	length=length+length_env[i];
	// 	length++;
	// 	printf("\n");
	// }
	// void *shared_memory_first;
	// void *shared_momery_second;
	// int shmid_first=shmget((key_t)123456, 1024*10, 0666|IPC_CREAT|IPC_EXCL);
	// int shmid_second=shmget((key_t)12345, 1024*10, 0666|IPC_CREAT|IPC_EXCL);
	// if(shmid_first == -1) // already create a shared memory
	// {
	// 	shmid_first = shmget((key_t)123456,1024*10,0666);
	// 	shared_memory_first=shmat(shmid_first,NULL,0); //process attached to shared memory segment

	// }
	// else
	// {	

	// }
	
	// if(shmid_second == -1) // already create a shared memory
	// {
	// 	shmid_second = shmget((key_t)12345,1024*10,0666);
	// 	shared_momery_second = shmget(shmid_second,NULL,0);
	// }
	// else
	// {

	// }
	ret = sgx_create_enclave(ENCLAVE_FILENAME, SGX_DEBUG_FLAG,&token , &updated, &global_eid, NULL);
	//cout<<ret<<endl;
	if (ret != SGX_SUCCESS)
	{
		printf("%d\n",ret);
	}
	// printf("exe the program\n");
	ecall_compile(global_eid,cnt_argv,cnt_env,length_argv,length_env,all_argv,all_env);
	//sleep(1000);
	sgx_destroy_enclave(global_eid);
	return 0;

}
void ocall_print_string(const char *str)
{
	printf("%s",str);
}

// //void fstatfs_ocall(int fd, struct statfs *buf)
void fstatfs_ocall(int *preturn, int fd, void *buf)
{
   *preturn = fstatfs(fd, (struct statfs *)buf);
}

void rename_ocall(int *preturn, char *oldname, char *newname)
{
   *preturn = rename(oldname, newname);
}

// // posix_fallocate
// //void posix_fallocate_ocall(int *preturn, int fd, off_t offset, off_t len)
void posix_fallocate_ocall(int *preturn, int fd, int offset, int len)
{
   *preturn = posix_fallocate(fd, (off_t)offset, (off_t)len);
}

// ftruncate
// void ftruncate_ocall(int *preturn, int fd, off_t length)
void ftruncate_ocall(int *preturn, int fd, int length)
{
   *preturn = ftruncate(fd, (off_t)length);
}

// __xstat
// void __xstat_ocall(int *preturn, int __ver, const char *__filename, struct stat *__stat_buf)
void __xstat_ocall(int *preturn, int __ver, const char *__filename, void *__stat_buf)
{
   *preturn = __xstat(__ver, __filename, (struct stat *)__stat_buf);
}

//realpath
void realpath_ocall(int *preturn, const char *path, char *resolved_path)
{
	*preturn = realpath(path,resolved_path) ? 1 : 0;
}

//getcwd
void getcwd_ocall(int *preturn, char *buf, size_t size,int *in_errno)
{
	*preturn = getcwd(buf, size) ? 1 : 0;
	*in_errno = errno;	
}


// lstat
// void lstat_ocall(int *preturn, const char *path, struct stat *buf)
void lstat_ocall(int *preturn, const char *path, void *buf)
{
   *preturn = lstat(path, (struct stat *)buf);
}



// stat
void stat_ocall(int *preturn,const char *path, void *buf,int *in_errno)
{
	*preturn = stat(path,(struct stat *)buf);
	*in_errno = errno;
}

// umask
void umask_ocall(int *preturn,int mask)
{
	*preturn = umask((mode_t) mask);
}

// chmod
void chmod_ocall(int *preturn,const char * path,int mode)
{
	*preturn = chmod(path,(mode_t) mode);
}

//fchmod
void fchmod_ocall(int *preturn,int fildes, int mode)
{
   *preturn = fchmod(fildes, (mode_t) mode);
}


// futimens
void futimens_ocall(int *preturn,int fd, void *times)
{
	*preturn = futimens(fd,(const timespec*) times);
}


// closedir
void closedir_ocall(int *preturn,void ** dir,int *in_errno)
{
	DIR **tmp_p = (DIR **) dir;
	*preturn = closedir(*tmp_p);
	*in_errno = errno;

}


// readdir
//void readdir_ocall(DIR*,struct dirent*);

void readdir_ocall(int *preturn,void **dir, void* readdir_tmp,int *in_errno)
{
	DIR **tmp_p = (DIR **) dir;
	struct dirent *ret = readdir(*tmp_p);

	if(ret)
	{
		memcpy(readdir_tmp,ret,sizeof(struct dirent));
		*preturn = 0;
	}
	else
	{
		*preturn = 1;
	}
	*in_errno=errno;
}
//opendir_ocall

void opendir_ocall(int *preturn,const char *name,void ** ret,int *in_errno)
{

	DIR **tmp_p = (DIR **) ret;
	*tmp_p = opendir(name);
	//printf("opendir ocall return %p\n",*tmp_p);
	if (*tmp_p)
	{
		*preturn = 0;
	}
	else
	{
		*preturn = 1;
	}
	*in_errno=errno;
	//*opendir_tmp=*opendir(name)
	//opendir=NULL;
	// DIR *ret = opendir(name);
	// if(!ret)
	// {
	// 	memcpy(opendir_tmp,ret,sizeof(DIR));
	// 	*preturn = 1;
	// }
	// else
	// {
	// 	*preturn = 0;
	// }
}

void pread_ocall(int *preturn,int fd, void *buf, size_t count, int offset,int *in_errno)
{
   *preturn = pread(fd, buf, count, (off_t)offset);
   *in_errno=errno;
}

// getuid
void getuid_ocall(int *preturn)
{
   *preturn =  getuid();
}

// getpwuid
// void getpwuid(uid_t,struct passwd *)

void getpwuid_ocall(int *preturn,int uid,void * getpwuid_tmp)
{
	// *getpwuid_tmp=*getpwuid(uid);


}

//getpwnam
void getpwnam_ocall(const char *name,void *getpwnam_tmp)
{
	//*getpwnam_tmp=*getpwnam(name);
}

// mallinfo
void mallinfo_ocall(void *mallinfo_tmp)
{
	//*mallinfo_tmp=mallinfo();
}

// getrusage

void getrusage_ocall(int *preturn,int who,void *usage)
{
	*preturn = getrusage(who,(rusage*) usage);
}

// dup2
void dup2_ocall(int *preturn,int odlfd, int newfd)
{
   *preturn = dup2(odlfd,newfd);
}

// sigfillset
void sigfillset_ocall(int *preturn, void *set)
{
   *preturn = sigfillset((sigset_t *) set);
}

// srand

// posix_spawn
// posix_spawn_file_actions_t
// not sure
void posix_spawn_ocall(int * preturn,int * pid,const char *path,const void *file_actions,const void *attrp,void *_argv,void *_envp,int argc,int envc)
{
	char * argv = (char *)_argv;
	char * envp = (char *) _envp;
	//printf("len1 %d,%s\n",argc,argv);
	char *argv_use[100];
	char *env_use[100];
	char *pargv = argv,*penv = envp;
	int argv_idx = 0, env_idx = 0;
	for (int i=0;i<argc;i++)
	{
		if (argv[i] && !pargv)
		    pargv = argv + i;
		else if(argv[i] && pargv)
			continue;
		else if(!argv[i] && !pargv)
			argv_use[argv_idx++] = pargv;
		else if(!argv[i] && pargv)
		{
			//printf("ffff  %s\n",pargv);
			argv_use[argv_idx ++] = pargv;
			pargv = nullptr;
		}
	}
	argv_use[argv_idx] = nullptr;
	
	for (int i=0;i<envc;i++)
	{
		if (envp[i] && !penv)
		    penv = envp + i;
		else if(envp[i] && penv)
			continue;
		else if(!envp[i] && !penv)
			env_use[env_idx ++] = penv;
		else if(!envp[i] && penv)
		{
			env_use[env_idx ++] = penv;
			penv = nullptr;
		}
	}
	env_use[env_idx] = nullptr;
	// printf("path %s,argv env:%p     %p\n",path,argv,envp);
	// char ** arg_p = (char **)malloc(sizeof(void*) * (argc+1));
	// char ** env_p = (char **)malloc(sizeof(void*) * (envc+1));
	// int i;
	// for(i = 0;i<argc;i++)
	// {
	// 	arg_p[i] = (char*)malloc(200);
	// 	void *tmp1 = (void *)arg_p[i];
	// 	void *tmp2 = (void *)argv[i];

	// 	printf("arg%d:%s\n",i,arg_p[i]);
	// }
		
	// arg_p[i] = nullptr;
	// for(i = 0;i<envc;i++)
	// {
	// 	env_p[i] = (char*)malloc(200);
	// 	void *tmp1 = (void *)env_p[i];
	// 	void *tmp2 = (void *)envp[i];

	// 	printf("arg%d:%s\n",i,env_p[i]);
	// }
		
	// env_p[i] = nullptr;
	// int l=strlen(path);
	// if(!(path[l-1]=='d'&&path[l-2]=='l'))
	// {
	// 	int shmid_second=shmget((key_t)12345, 1024*10, 0666|IPC_CREAT);
	// 	void *shared_memory;
	// 	shared_memory=shmat(shmid_second,NULL,0);
	// }
	// char file[32];
        // char buf[64];
        // pid_t pid = getpid();
        // sprintf(file,"/proc/%i/cmdline",pid);
        // FILE *f = fopen(file,"r");
        // fgets(buf,64,f);
        // fclose(f);
	// if(strcmp(buf,path)==0)
	// {
	// 	int shmid_second=shmget((key_t)12345, 1024*10, 0666|IPC_CREAT);
	// 	void *shared_memory;
	// 	shared_memory=shmat(shmid_second,NULL,0);
	// }
   	*preturn = posix_spawn(pid,path,(const posix_spawn_file_actions_t *)file_actions,(const posix_spawnattr_t *)attrp,argv_use,env_use);
}

// waitpid
void waitpid_ocall(int *preturn,int pid, int *status_pid, int options,int *in_errno)
{
	*preturn = waitpid((pid_t)pid, status_pid, options);
	*in_errno = errno;
}

// alarm
void alarm_ocall(int *preturn,unsigned int seconds)
{
   *preturn = alarm(seconds);
}

// strsignal

void strsignal_ocall(int sig,char *strsignal_tmp)
{
	char *p=strsignal(sig);
	int n=strlen(p);
	for(int i=0;i<n;i++)
	{
		strsignal_tmp[i]=p[i];
	}
}

// kill
void kill_ocall(int *preturn,int pid, int sig)
{
   *preturn = kill(pid, sig);
}

// wait
void wait_ocall (int *preturn,int * status_pid)
{
    *preturn = wait(status_pid);
}

// sysconf
void sysconf_ocall(int *preturn,int name)
{
   *preturn = sysconf(name);
}

// fork
void fork_ocall(int *preturn)
{
   *preturn = fork();
}

// execve   xxxxxxxxx

void execve_ocall(int *preturn,const char * filename, char * const argv[], char * const envp[])  // array of const pointer to char
{
	*preturn = execve(filename,argv,envp);
}

// execv  xxxxxxxxxx
//not sure
void execv_ocall(int *preturn,const char * path, char * const argv[])
{
	*preturn = execv(path,argv);
}

// _Unwind_GetIP


// sigaltstack

void sigaltstack_ocall(int *preturn,const void *ss, void *old_ss)
{
	// *preturn = sigaltstack((stack_t*)ss,(stack_t*)old_ss);
}

// unlink
void unlink_ocall(int *preturn ,const char * pathname)
{
   *preturn = unlink(pathname);
}

// dl_iterate_phdr
// not sure
/*
int dl_iterate_phdr_ocall(int (*callback) (struct dl_phdr_info *info, size_t size, void *data), void *data)
{
   return dl_iterate_phdr(callback, data);
}
*/
// backtrace
void backtrace_ocall(int *preturn,void **buffer, int size)
{
   *preturn = backtrace(buffer,size);
}

// sched_getaffinity
void sched_getaffinity_ocall(int *preturn ,int pid, unsigned int cpusetsize, void *mask){

	*preturn = sched_getaffinity(pid,cpusetsize,(cpu_set_t*)mask);

}

// __sched_cpucount
void __sched_cpucount_ocall(int *preturn ,size_t setsize, const void *setp){

	*preturn = __sched_cpucount(setsize,(const cpu_set_t *) setp);

}

// pthread_setschedparam 
void pthread_setschedparam_ocall(int *preturn , int target_thread, int policy, const void *param){

	// *preturn = pthread_setschedparam((pthread_t) target_thread,policy,(const struct sched_param *) param);
}

// pthread_attr_init
void pthread_attr_init_ocall(int *preturn, int*attr){

	// *preturn = pthread_attr_init((pthread_attr_t *)attr);
}

// pthread_attr_destroy
void pthread_attr_destroy_ocall(int *preturn,int *attr){

	// *preturn = pthread_attr_destroy((pthread_attr_t *)attr);
}

// __printf_chk
void __printf_chk_ocall(int *preturn,int flag, const char * format){
    //*preturn = __printf_chk(flag,format);
    *preturn = 1;
}

//localtime
void localtime_ocall(const void *timer, void *localtime_tmp){

	struct tm* ret = localtime((const time_t *)timer);
	memcpy(localtime_tmp,ret,sizeof(struct tm));

}

// gettimeofday
void gettimeofday_ocall(int *preturn,void * tv, void *tz,int *in_errno){
	*preturn = gettimeofday((struct timeval *)tv,(struct timezone *) tz);
	*in_errno = errno;
}

//don't know how to write
// aligned_alloc
void aligned_alloc_ocall(void *preturn,size_t alignment, size_t size){
	preturn = (void *) aligned_alloc(32,10);
}


// fwrite
void fwrite_ocall(int *preturn,const void *ptr, size_t size, size_t nmemb, void *stream,int *in_errno){

	*preturn =fwrite(ptr,size,nmemb,(FILE *)stream);
	*in_errno=errno;
}

// fputs
void fputs_ocall(int *preturn,const char *str, void *stream){
	*preturn =  fputs(str,(FILE *)stream);
}

void fputc_ocall(int *preturn,int c,void *stream)
{
	*preturn = fputc(c,(FILE *)stream);
}

// write
void write_ocall (int *preturn ,int fd, const void * buf, size_t count,int *in_errno){
	*preturn = write(fd,buf,count);
	*in_errno = errno;
}

//dont't know how to write
// syscall
//not sure
int syscall(int number, ...){
	
}

// __tls_get_addr
void* __tls_get_addr(size_t m, size_t offset){
	
}


// __strtof_l
void _strtof_l_ocall(
   float *preturn,
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	//*preturn = _strtof_l(strSource,endptr,locale);
	*preturn = 1;
}

// __strtod_l
void _strtod_l_ocall(
   double *preturn,
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	//*preturn = _strtod_l(strSource,endptr,locale);
	*preturn = 1;
}

// strtold_l
void _strtold_l_ocall(
    long double *preturn,
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	//*preturn = _strtold_l(strSource,endptr,locale);
	*preturn = 1;
}

// __newlocale
void __newlocale_ocall (int *preturn,int category_mask, const char *locale, int base){
	//*preturn = __newlocale(category_mask,locale,(locale_t)base);
	*preturn = 1;
}


//don't know how to wirte
// __dso_handle

// __cxa_atexit
// int __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle){

// }

// strdup
void strdup_ocall(const char *s,char * strdup_tmp){
	// char *p=strdup(s);
	// int n=strlen(p);
	// for(int i=0;i<n;i++) strdup_tmp[i]=p[i];
}

// bind_textdomain_codeset
void bind_textdomain_codeset_ocall (const char * domainname, const char * codeset,char *bind_textdomain_codeset_tmp){
	char *p=bind_textdomain_codeset(domainname,codeset);
	strcpy(bind_textdomain_codeset_tmp,p);
}

//don't know how to wirte
// dgettext
char * gettext (const char * msgid);char * dgettext (const char * domainname, const char * msgid);


void  dcgettext_ocall(const char * domainname, const char *msgid, int category,char *dcgettext_tmp)
{
	dcgettext_tmp = dcgettext(domainname,msgid,category);
}

// getenv
void getenv_ocall(int* preturn, const char* name,void **ret){
	char ** tmp_p = (char **)ret;
	*tmp_p = getenv(name);
	if (*tmp_p==NULL)
	{
		printf("******\n");
		*preturn = 0;
	}
	else
	{
		*preturn = 1;
	}
	
		
}

// __strcoll_l
void _strcoll_l_ocall(
   int *preturn,
   const char *string1,
   const char *string2,
   _locale_t locale
){
	//*preturn = _strcoll_l(string1,string2,locale);
	*preturn = 1;
}

// __strxfrm_l
void _strxfrm_l_ocall(
   int *preturn,
   char *strDest,
   const char *strSource,
   size_t count,
   _locale_t locale
){
	//*preturn = _strxfrm_l(strDest,strSource,count,locale);
	*preturn = 1;
}

// __wcscoll_l
void __wcscoll_l_ocall(
   int *preturn,
   const wchar_t *string1,
   const wchar_t *string2,
   _locale_t locale
){
	//*preturn = __wcscoll_l(string1,string2,locale);
	*preturn = 1;
}

// __wcsxfrm_l
void __wcsxfrm_l_ocall(
   int *preturn,
   wchar_t *strDest,
   const wchar_t *strSource,
   size_t count,
   _locale_t locale
){
	//*preturn = __wcsxfrm_l(strDest,strSource,count,locale);
	*preturn=1;
}

// __ctype_get_mb_cur_max
void __ctype_get_mb_cur_max_ocall(int *preturn){
	*preturn = __ctype_get_mb_cur_max();
}

// __errno_location
void __errno_location_ocall(int *preturn){
	printf("__errno_loacation********out %p\n",(int *)preturn);	
	//preturn=__errno_location();
}

// fflush
void fflush_ocall(int *preturn,void *stream,int *in_errno){
	*preturn = fflush((FILE *)stream);
	*in_errno = errno;
}

// fdopen
void fdopen_ocall(int fildes,const char * mode,void *fdopen_tmp){

	//fdopen_tmp=fdopen(fildes,mode);
}


// setvbuf
void setvbuf_ocall(int *preturn,void *stream, char *buffer, int mode, size_t size){
	*preturn = setvbuf((FILE *)stream,buffer,mode,size);
}


// fopen64
void fopen64_ocall(char *Path, char *Type,void *fopen64_tmp){
	//fopen64_tmp = fopen64(Path,Type);
}

// fileno
void fileno_ocall(int *preturn,void* stream){
	*preturn = fileno((FILE *)stream);
}

// fclose
void fclose_ocall(int *preturn,void **fp,int *in_errno){
	*preturn = fclose(*(FILE **)fp);
	*in_errno = errno;
}

// read
void read_ocall(int *preturn,int fd, void * buf, size_t count){
	*preturn = read(fd,buf,count);
}

// writev
void writev_ocall(int *preturn,int filedes,void  *iov, int iovcnt){
	*preturn = writev(filedes, (const struct iovec *) iov,iovcnt);
}

// lseek64
void lseek64_ocall(long long *preturn,int fd, long long offset, int whence,int *in_errno){
	*preturn = lseek64(fd,offset,whence);
	*in_errno = errno;
}

// poll in poll.h
void poll_ocall(int *preturn,void *fd, int nfds, int timeout){
	nfds=nfds/8;
	*preturn = poll((struct pollfd *)fd,nfds,timeout);
	// *preturn = 1;
}

// __fxstat64
void __fxstat64_ocall(int *preturn,int ver, int fildes, void *stat_buf){

	*preturn = __fxstat64(ver,fildes,(struct stat64 *)stat_buf);
	// *preturn = 1;
}

// setlocale
void setlocale_ocall(int category, const char *locale,char *setlocale_tmp){
	setlocale_tmp = setlocale(category,locale);
}

// __strftime_l
void __strftime_l_ocall(
   int *preturn,
   char *strDest,
   size_t maxsize,
   const char *format,
   const void *timeptr,
   _locale_t locale
){
	//*preturn = __strftime_l(strDest,maxsize,format,timeptr,locale);
	*preturn = 1;
}

// __wcsftime_l
void __wcsftime_l_ocall(
   int *preturn,
   wchar_t *strDest,
   size_t maxsize,
   const wchar_t *format,
   const void *timeptr,
   _locale_t locale
){
	//*preturn = __wcsftime_l(strDest, maxsize,format,timeptr,locale);
	*preturn =1;
}


// __towupper_l
void __towupper_l_ocall(
   int *preturn,
   wint_t c ,
   _locale_t locale
){
	//*preturn = __towupper_l(c,locale);
	*preturn = 1;
}

// __towlower_l
void __towlower_l_ocall(
   int *preturn,
   wint_t c,
   _locale_t locale
){
	//*preturn = __towlower_l(c,locale);
	*preturn = 1;
}

// __iswctype_l
void __iswctype_l_ocall(
   int *preturn,
   wint_t c,
   wctype_t desc,
   _locale_t locale
){
	//*preturn = __iswctype_l(c,desc,locale);
	*preturn = 1;
}

// bindtextdomain
void bindtextdomain_ocall (int *preturn,const char * domainname, const char * dirname,char *bindtextdomain_tmp){
	bindtextdomain_tmp = bindtextdomain(domainname,dirname);
	if(errno == ENOMEM)
	{
		*preturn = 0;
	}
	else *preturn = 1;
}

// textdomain
void textdomain_ocall(int *preturn,const char *domainname,char *textdomain_tmp)
{
	textdomain_tmp = textdomain(domainname);
	if(errno == ENOMEM)
	{
		*preturn = 0;
	}
	else *preturn = 1;
}
// fnmatch
void fnmatch_ocall(int *preturn,const char *pattern,const char *string,int flags)
{
	*preturn = fnmatch(pattern,string,flags);
}
// get_nprocs
void get_nprocs_ocall(int *preturn){
	*preturn = get_nprocs();
}

// nanosleep
void nanosleep_ocall(int *preturn,const  void *req, void *rem){
	*preturn = nanosleep((struct timespec *)req,(struct timespec*) rem);
}

// pthread_detach
void pthread_detach_ocall(int *preturn,int tid){
	*preturn = pthread_detach((pthread_t)tid);
}

// clock_gettime
void clock_gettime_ocall(int *preturn,int clk_id,void *tp){
	*preturn = clock_gettime((clockid_t)clk_id,(struct timespec *)tp);
}


// fopen
void fopen_ocall(const char *filename, const char *mode,void **ret,int *in_errno){
	FILE ** tmp_p = (FILE**)ret;
	*tmp_p = fopen(filename,mode);
	*in_errno = errno;
	//fopen_tmp=fopen(filename,mode);
}

// __fprintf_chk
void __fprintf_chk_ocall(int *preturn,void * stream, int flag, const char * format){
	//*preturn = __fprintf_chk(stream,flag,format);
	*preturn = 1;
}

// // sprintf
// // not sure
// int sprintf(char *str, const char *format, ...){
// }


// getc
void getc_ocall(int *preturn,void *stream){
	*preturn = getc((FILE *)stream);
}

// ungetc
void ungetc_ocall(int *preturn,int chr, void *stream){
	*preturn = ungetc(chr,(FILE *)stream);
}

// putc
void putc_ocall(int *preturn,int chr, void *stream){
	*preturn = putc(chr,(FILE *)stream);
}

// fseeko64
void fseeko64_ocall(int *preturn,void *stream,int offset, int fromwhere){
	*preturn = fseeko64((FILE *)stream,offset,fromwhere);
}

// ftello64
void ftello64_ocall(int *preturn,void *stream){
	*preturn = ftello64((FILE *)stream);
}

// getwc
void getwc_ocall(int *preturn,void* stream){
	*preturn = getwc((FILE* )stream);
}

// ungetwc
void ungetwc_ocall(int *preturn,wint_t ch, void * stream){
	*preturn = ungetwc(ch,(FILE *)stream);
}

// putwc
void putwc_ocall(int *preturn,wchar_t ch, void * stream){
	*preturn = putwc(ch,(FILE *)stream);
}

// fread
void fread_ocall(int *preturn,void *buffer, size_t size, size_t count, void **stream,int *in_errno){

	*preturn = fread(buffer,size,count,*(FILE **)stream);
	*in_errno = errno;
}

// getrlimit
void getrlimit_ocall(int *preturn,int resource, void *rlim){
	*preturn = getrlimit(resource,(struct rlimit *)rlim);
}

//setrlimit
void setrlimit_ocall(int *preturn,int resource, const void *rlim){
	*preturn = setrlimit(resource,(struct rlimit *)rlim);
}

//strcpy
void strcpy_ocall(char *dest, const char *src,char *strcpy_tmp){
	// strcpy_tmp = strcpy(dest,src);
}

void exit_ocall(int status_pid)
{
	exit(status_pid);
}

//time
void time_ocall(int *preturn,void *seconds){

	*preturn = time((time_t *)seconds);
}

//localtime_r
void localtime_r_ocall( const void *timer,void *buf ,void *localtime_r_tmp){

	struct tm * ret = localtime_r(( time_t *)timer,(struct tm*)buf);
	memcpy(localtime_r_tmp,ret,sizeof(struct tm));
}

//getpid
void getpid_ocall(int *preturn){
	*preturn = getpid();
}

//sigemptyset
void sigemptyset_ocall(int *preturn,void *set){
	*preturn = (int)sigemptyset((sigset_t *)set);
}

//sigaddset
void sigaddset_ocall(int *preturn,void *set, int signo){
	*preturn = sigaddset((sigset_t *)set,signo);
}

//sigprocmask
void sigprocmask_ocall(int *preturn,int how,const void*set,void *oldset){
	*preturn = sigprocmask((ubt)how,(const sigset_t *)set,(sigset_t *)oldset);
}

// raise
void raise_ocall(int *preturn,int sig){
	*preturn = raise(sig);
}

//_setjmp
// void _setjmp_ocall(int *preturn, int env){
// 	*preturn = _setjmp((jmp_buf)env);
// }

//gethostname
void gethostname_ocall(int *preturn,char *name, size_t len){
	*preturn = gethostname(name,len);
}

//getsid
void getsid_ocall(int *preturn,int pid){
	*preturn = getsid((pid_t)pid);
}

//open
void open_ocall(int *preturn,const char * pathname, int flags, int mode,int *in_errno){
	*preturn = open(pathname,flags,(mode_t)mode);
	*in_errno=errno;
}

// close
void close_ocall(int *preturn,int fildes,int *in_errno){
	*preturn = close(fildes);
	*in_errno = errno;
}

//isatty
void isatty_ocall(int *preturn,int fd,int *in_errno){
	*preturn = isatty(fd);
	*in_errno = errno;
}

//lseek
void lseek_ocall(int *preturn,int fd, int offset, int whence,int *in_errno){
	*preturn = lseek(fd,(off_t) offset,whence);
	*in_errno = errno;
}

//dlclose
void dlclose_ocall(int *preturn,void *handle){
 	//*preturn = dlclose(handle);
	//  *preturn = 1;
}

//uname
void uname_ocall(int *preturn,void *buf){
	// *preturn = uname((utsname *)buf);
}

//munmap
void munmap_ocall(int *preturn,void **start, size_t length,int *in_errno){
	*preturn = munmap(*start,length);
	*in_errno = errno;
}

//mproteck
void mprotect_ocall(int *preturn,void *addr, size_t len, int prot){
	//*preturn = mprotect(addr,len,prot);
	*preturn = 1;
}


//mmap
void mmap_ocall(void *preturn, void *addr, size_t length, int prot, int flags, int fd, int offset,int *in_errno){
	*(void **)preturn = mmap(addr, length, prot, flags, fd, (off_t)offset);
	*in_errno = errno;
}

//readlink
//not sure
void readlink_ocall(int *preturn ,char * path, char *buf, int bufsize,int *in_errno)
{
       	*preturn = readlink(path,buf, bufsize);
	*in_errno = errno;
}

//__realpath_chk
void __realpath_chk_ocall(const char *buf, char *resolved, size_t resolvedlen,char *__realpath_chk_tmp){
	//__realpath_chk_tmp=__realpath_chk(buf,resolved,resolvedlen);
	__realpath_chk_tmp="123";
}

//access
void access_ocall(int *preturn,const char *path, int amode,int *in_errno){
	*preturn = access(path,amode);
	*in_errno = errno; 
}

//chdir
void chdir_ocall(int *preturn,const char * path){
	*preturn = chdir(path);
}

//mkdir
void mkdir_ocall(int *preturn,const char *path, int mode){
	*preturn = mkdir(path,(mode_t)mode);
}

 //symlink
void symlink_ocall(int *preturn,const char *path1, const char *path2){
	*preturn = symlink(path1,path2);
}

//link
void link_ocall (int *preturn,const char * oldpath, const char * newpath){
	*preturn=link(oldpath,newpath);
}

//_lxstat
void __lxstat_ocall (int *preturn,int vers, const char *name, void *buf){
	*preturn = __lxstat(vers,name,(struct stat *)buf);
	// *preturn = 1;
}

void uselocale_ocall(void *preturn, int newloc) {
	*(locale_t *)preturn = uselocale((locale_t) newloc);
}
void remove_ocall(int *preturn,const char *filename,int *in_errno)
{
	*preturn = remove(filename);
	*in_errno = errno;
}

void fstat_ocall(int *preturn,int fd,void *buf,int *in_errno)
{
	// printf("%s\n","test this enclave");
	*preturn = fstat(fd,(struct stat *)buf);
	// *preturn = 1;
	*in_errno=errno;
}
void pthread_mutex_destroy_ocall(int *preturn,void * mutex)
{
	*preturn = pthread_mutex_destroy((pthread_mutex_t *)mutex);
}
void pthread_mutexattr_init_ocall(int *preturn,void *attr)
{
	*preturn = pthread_mutexattr_init((pthread_mutexattr_t *)attr);
}
void pthread_mutexattr_destroy_ocall(int *preturn,void *attr)
{
	*preturn = pthread_mutexattr_destroy((pthread_mutexattr_t *)attr);
}
void pthread_mutexattr_settype_ocall(int *preturn,void *attr,int type)
{
	*preturn = pthread_mutexattr_settype((pthread_mutexattr_t *)attr,type);
}
void pthread_mutexattr_setpshared_ocall(int *preturn,void *attr,int pshared)
{
	*preturn =pthread_mutexattr_setpshared((pthread_mutexattr_t *)attr,pshared);
}
void ioctl_ocall(int *preturn,int fd,unsigned long request,void *arguments,int *in_errno)
{
	if(arguments!=NULL)
	{
		*preturn = ioctl(fd,request);
	}
	else *preturn = ioctl(fd,request,arguments);
	*in_errno = errno;
}
void tigetnum_ocall(int *preturn,char *capname,int *in_errno)
{
	//*preturn = tigetnum(capname);
	*in_errno = errno;
}
void setupterm_ocall(int *preturn,char *term,int fd,int *errret)
{
	*preturn = setupterm(term,fd,errret);
}