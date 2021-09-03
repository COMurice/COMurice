#define off_t int
#define size_t int
#define mode_t int
#define uid_t int
#define pid_t int
#define _Unwind_Ptr void*
#define cpu_set_t int
#define pthread_t int
#define pthread_attr_t int
#define time_t int
#define FILE void
#define ssize_t int
#define _locale_t int
#define locale_t int 
#define wchar_t int
#define off64_t int
#define nfds_t int
#define wint_t int
#define wctype_t int
#define clockid_t int
#define _RESTRICT restrict
#define sigset_t int
#define ubt int
#define int32_t int
#define bool int
#define true 1
#define false 0


typedef struct _jmp_buf
{
    int _jp[1];
} jmp_buf[1];
struct timespec {
               time_t   tv_sec;        /* seconds */
               long     tv_nsec;       /* nanoseconds */
           };

struct pollfd {
        int fd;
        short events;
        short revents;
};

// fstatfs
int fstatfs(int fd, struct statfs *buf)
{
   int *preturn = (int *)malloc(sizeof(int));
   fstatfs_ocall(preturn, fd, (void *)buf);
   return *px;
}

// rename
int rename(char * oldname, char * newname)
{
   int *preturn = (int *)malloc(sizeof(int));
   rename_ocall(preturn, oldname, newname);
}

// posix_fallocate
int posix_fallocate(int fd, off_t offset, off_t len)
{
   int *preturn = (int *)malloc(sizeof(int));
   posix_fallocate_ocall(preturn, fd, (int)offset, (int)len);
   return *preturn;
}

// ftruncate
int ftruncate(int fd, off_t length)
{
   int *preturn = (int *)malloc(sizeof(int));
   ftruncate_ocall(preturn, fd, (int)length);
   return *preturn;
}

// __xstat
int __xstat(int __ver, const char *__filename, struct stat *__stat_buf)
{
   int *preturn = (int *)malloc(sizeof(int));
   __xstat_ocall(preturn, __ver, __filename, (void *)__stat_buf);
   return *preturn;
}

// realpath
char *realpath(const char *path, char *resolved_path)
{
   int *preturn = (int *)malloc(sizeof(int));
   realpath_ocall(preturn, path, resolved_path);
   if (*preturn > 0) return resolved_path;
   else return nullptr;
}

// getcwd
char *getcwd(char *buf, size_t size)
{
   int *preturn = (int *)malloc(sizeof(int));
   getcwd_ocall(preturn, buf, size);
   if(*preturn > 0) return buf;
   else return nullptr;
}

// lstat
int lstat(const char *path, struct stat *buf)
{
   int *preturn = (int *)malloc(sizeof(int));
   lstat_ocall(preturn, path, (void *)buf);
   return *preturn;
}




// this is cyp's work
// stat
int stat(const char *path, struct stat *buf)
{
   int *preturn = (int *)malloc(sizeof(int));
   stat_ocall(preturn,path,(void *)buf);
   return *preturn;
}

// umask
int umask(int mask)
{
	int *preturn = (int *)malloc(sizeof(int));
	umask_ocall(preturn,mask);
	return *preturn;
}

// chmod
int chmod(const char * path, mode_t mode)
{
   int *preturn = (int *)malloc(sizeof(int));
   chmod_ocall(preturn,path,mode);
   return *preturn;
}

// fchmod
int fchmod(int fildes, mode_t mode)
{
	int *preturn = (int *)malloc(sizeof(int));
	fchmod_ocall(preturn,fildes,mode);
	return *preturn;
}

// futimens
int futimens(int fd, const struct timespec *times)
{
	int *preturn = (int *)malloc(sizeof(int));
    futimens_ocall(*preturn,fd,(void *)times);
    return *preturn;
}

// closedir
int closedir(void * dir)
{
	int *preturn = (int *)malloc(sizeof(int));
    *preturn = closedir_ocall(preturn,dir);
    return *preturn;
}

// readdir
//void readdir_ocall(DIR*,struct dirent*);
struct dirent readdir_tmp;
struct dirent* readdir(void * dir)
{
   readdir_ocall(dir,&readdir_tmp);
   return &readdir_tmp;
}


// opendir
//void opendir_ocall(char*,DIR*);
//not sure
void *opendir(const char * name)
{
   void *opendir_tmp;
   opendir_ocall(name,opendir_tmp);
   return (void *)opendir_tmp; 
}

// pread
size_t pread(int fd, void *buf, size_t count, off_t offset)
{
   int *preturn = (int *)malloc(sizeof(int));
   pread_ocall(preturn,fd, buf, count, offset);
   return *preturn;
}

// getuid
uid_t getuid()
{
   int *preturn = (int *)malloc(sizeof(int));
   getuid_ocall(preturn);
   return *preturn;
}

// getpwuid
// void getpwuid(uid_t,struct passwd *)
struct passwd getpwuid_tmp;
struct passwd *getpwuid(uid_t uid)
{
   getpwuid_ocall(uid, &getpwuid_tmp);
   return &getpwuid_tmp;
}


// getpwnam
// void getpwnam(char*,struct passwd*)
struct passwd getpwnam_tmp;
struct passwd * getpwnam(const char * name)
{
   getpwnam(name,&getpwnam_tmp);
   return &getpwnam_tmp;
}

// mallinfo
// void mallinfo(struct mallinfo *)
struct mallinfo mallinfo_tmp;
struct mallinfo * mallinfo(void)
{
   mallinfo_ocall(&mallinfo_tmp);
   return &mallinfo_tmp;
}

// getrusage
int getrusage(int who, struct rusage *usage)
{
   int *preturn = (int *)malloc(sizeof(int));
   getrusage_ocall(preturn,who,usage);
   return *preturn;
} 

// dup2
int dup2(int odlfd, int newfd)
{
   int *preturn = (int *)malloc(sizeof(int));
   dup2_ocall(preturn,odlfd,newfd);
   return *preturn;
}

// sigfillset
int sigfillset(sigset_t * set)
{
   int *preturn = (int *)malloc(sizeof(int));
   sigfillset_ocall(preturn,set);
   return *preturn;
}

// rand
int rand(void)
{
   uint8_t tmp[4];
   int* ret = (int*)tmp;
   sgx_read_rand(tmp,4);
   return *ret;
}

// srand
void srand(unsigned int seed){
}

// posix_spawn
// posix_spawn_file_actions_t
//not sure
int posix_spawn(void *restrict pid, const char *restrict path, const void *file_actions, const void *restrict attrp, char *const argv[restrict], char *const envp[restrict])
{
   return posix_spawn_ocall(pid,path,file_actions,attrp,argv,envp);
}

// waitpid
pid_t waitpid(pid_t pid, int *status, int options)
{
   int *preturn = (int *)malloc(sizeof(int));
   *preturn = waitpid_ocall(preturn,pid, status, options);
   return *preturn;
}

// alarm
unsigned int alarm(unsigned int seconds)
{
	int *preturn = (int *)malloc(sizeof(int));
	*preturn = alarm_ocall(preturn,seconds);
	return *preturn;
}

// strsignal
char strsignal_tmp[100];
char *strsignal(int sig)
{
   strsignal_ocall(sig,strsignal_tmp);
   return strsignal_tmp;
}

// kill
int kill(pid_t pid, int sig)
{
   int *preturn = (int *)malloc(sizeof(int));
   kill_ocall(preturn,pid, sig);
   return *preturn;
}

// wait
pid_t wait (int * status)
{
   int *preturn = (int *)malloc(sizeof(int));
   waitpid_ocall(preturn,status);
   return *preturn;
} 

// sysconf
long sysconf(int *preturn,int name)
{
	int *preturn = (int *)malloc(sizeof(int));
   sysconf_ocall(preturn,name);
   return *preturn;
} 
 
// fork
pid_t fork(void)
{
   int *preturn = (int *)malloc(sizeof(int));
   fork_ocall(preturn);
   return *preturn;
} 

// execve   xxxxxxxxx
int execve(const char * filename, char * const argv[], char * const envp[])
{
	int *preturn = (int *)malloc(sizeof(int));
	execve_ocall(preturn,filename,argv,envp);
	return *preturn;
} 

// environ
extern char ** environ;

// execv  xxxxxxxxxx
int execv (const char * path, char * const argv[])
{
	int *preturn = (int *)malloc(sizeof(int));
	execv_ocall(preturn,path,argv);
	return *preturn;
} 

// _Unwind_GetIP
// not sure
_Unwind_Ptr _Unwind_GetIP(struct _Unwind_Context *context)
{

} 

// sigaltstack
// not sure
int sigaltstack(const void *ss, void *old_ss)
{
	int *preturn = (int *)malloc(sizeof(int));
	sigaltstack_ocall(preturn,ss,old_ss);
	return *preturn;
} 

// unlink
int unlink(const char * pathname)
{
   int *preturn = (int *)malloc(sizeof(int));
   unlink_ocall(preturn,pathname);
   return *preturn;
} 

// dl_iterate_phdr
// not sure
int dl_iterate_phdr(int (*callback) (struct dl_phdr_info *info, size_t size, void *data), void *data)
{
   return dl_iterate_phdr_ocall(callback, data);
} 

// backtrace
int backtrace(void **buffer, int size)
{
	int *preturn = (int *)malloc(sizeof(int));
    backtrace_ocall(preturn,buffer,size);
    return *preturn;
} 

// backtrace_symbols_fd
void backtrace_symbols_fd(void *const *buffer, int size, int fd){} 

// sched_getaffinity
int sched_getaffinity(pid_t pid, unsigned int cpusetsize, cpu_set_t *mask){
	int *preturn = (int *)malloc(sizeof(int));
	sched_getaffinity_ocall(preturn,pid,cpusetsize,mask);
	return *preturn;
}

// __sched_cpucount
int __sched_cpucount(int *preturn,size_t setsize, const cpu_set_t *setp){
	int *preturn = (int *)malloc(sizeof(int));
	__sched_cpucount_ocall(preturn,setsize,setp);
	return *preturn;
}

// pthread_setschedparam
int pthread_setschedparam(pthread_t target_thread, int policy, const struct sched_param *param){
	int *preturn = (int *)malloc(sizeof(int));
	pthread_setschedparam_ocall(preturn,target_thread,policy,param);
	return *preturn;
}


// pthread_attr_init
int pthread_attr_init(pthread_attr_t *attr){
	int *preturn = (int *)malloc(sizeof(int));
	pthread_attr_init_ocall(preturn,attr);
	return *preturn;
}
// pthread_attr_destroy
int pthread_attr_destroy(pthread_attr_t *attr){
	int *preturn = (int *)malloc(sizeof(int));
	pthread_attr_destroy_ocall(preturn,attr);
	return *preturn;
}

// __printf_chk
int __printf_chk(int flag, const char * format){
	int *preturn = (int *)malloc(sizeof(int));
	__printf_chk_ocall(preturn,flag,format);
	return *preturn;
}

// localtime
struct tm localtime_tmp;
struct tm *localtime(const time_t *timer){
	localtime_ocall(time_t,&localtime_tmp);
	return &localtime_tmp;
}

// gettimeofday
int gettimeofday (struct timeval * tv, struct timezone * tz){
	int *preturn = (int *)malloc(sizeof(int));
	gettimeofday_ocall(preturn,tv,tz);
	return *preturn;
}

// aligned_alloc
void * aligned_alloc(size_t alignment, size_t size){
	void *preturn  = (void *) malloc(10);
	return preturn;
	
}

// fwrite
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream){
	int *preturn = (int *)malloc(sizeof(int));
	fwrite_ocall(preturn,pre,size,nmemb,stream);
	return *preturn;
}

// fputs
int fputs(const char *str, FILE *stream){
	int *preturn = (int *)malloc(sizeof(int));
	fputs_ocall(preturn,str,stream);
	return *preturn;
}


// fputc
int fputc(int c, FILE * stream){
	int *preturn = (int *)malloc(sizeof(int));
	fputc_ocall(preturn,c,stream);
	return *preturn;
}
// write
ssize_t write (int fd, const void * buf, size_t count){
	int *preturn = (int *)malloc(sizeof(int));
	write_ocall(preturn,fd,buf,count);
	return *preturn;
}

// syscall
// not sure
int syscall(int number, ...){
	
}
// __tls_get_addr
// not sure
void* __tls_get_addr(size_t m, size_t offset){
	void *preturn = (void *)malloc(10);
	return preturn;
}
// __cxa_thread_atexit_impl
// not sure
typedef void (*dtor_func) (void *){}
int __cxa_thread_atexit_impl (dtor_func func, void *obj, void *dso_symbol){
}


// __strtof_l
float _strtof_l(
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	float *preturn = (float *)malloc(sizeof(float));
	_strtof_l_ocall(preturn,strSource,endptr,locale);
	return *preturn;
}

// __strtod_l
double _strtod_l(
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	double *prturn = (double *)malloc(sizeof(double));
	_strtod_l_ocall(preturn,strSource,endptr,locale);
	return *preturn;
}

// strtold_l
long double _strtold_l(
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	long double *preturn = (long double *)malloc(sizeof(long double));
	_strtold_l_ocall(preturn,strSource,endptr,locale);
	return *preturn;
}
// __newlocale
locale_t __newlocale (int category_mask, const char *locale, locale_t base){
	int *preturn = (int *)malloc(sizeof(int));
	__newlocale_ocall(preturn,category_mask,locale,base);
	return *preturn;
}
// __dso_handle
void *__dso_handle;

// __cxa_atexit
// not sure
int __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle){
	
}

// strdup
char strdup_tmp[10];
char * strdup(const char *s){
	strdup_ocall(s,strdup_tmp);
	return strdup_tmp;
}
// bind_textdomain_codeset
char bind_textdomain_codeset_tmp[10];
char * bind_textdomain_codeset (const char * domainname, const char * codeset){
	bind_textdomain_codeset_ocall(domainname,codeset,bind_textdomain_codeset_tmp);
	return bind_textdomain_codeset_tmp;
}
// dgettext
char * gettext (const char * msgid);char * dgettext (const char * domainname, const char * msgid);char * dcgettext (const char * domainname, const char *msgid, int category){
	
}
// getenv
char getenv_tmp[10];
char *getenv(const char* name){
	getenv_ocall(name,getenv_tmp);
	return getenv_tmp;
}
// __strcoll_l
int _strcoll_l(
   const char *string1,
   const char *string2,
   _locale_t locale 
){
	int *preturn = (int *)malloc(sizeof(int));
	_strcoll_l_ocall(preturn,string1,string2,locale);
	return *preturn;
}

// __strxfrm_l
size_t _strxfrm_l(
   char *strDest,
   const char *strSource,
   size_t count,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	_strxfrm_l_ocall(preturn,strDest,strSource,count,locale);
	return *preturn,
}

// __wcscoll_l
int __wcscoll_l(
   const wchar_t *string1,
   const wchar_t *string2,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	__wcscoll_l_ocall(preturn,string1,string2,locale);
	return *preturn;
}

// __wcsxfrm_l
size_t __wcsxfrm_l(
   wchar_t *strDest,
   const wchar_t *strSource,
   size_t count,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	__wcsxfrm_l_ocall(preturn,strDest,strSource,count,locale);
	return *preturn;
}

// __ctype_get_mb_cur_max
size_t __ctype_get_mb_cur_max(){
	int *preturn = (int *)malloc(sizeof(int));
	__ctype_get_mb_cur_max_ocall(preturn);
	return *preturn;
}


// __errno_location
int __errno_location_tmp[100];
int *__errno_location(void){
	__errno_location_ocall(__errno_location_tmp);
	return __errno_location_tmp;
}




// fflush
int fflush(FILE *stream){
	int *preturn = (int *)malloc(sizeof(int));
	fflush_ocall(preturn,stream);
	return *preturn;
}
// fdopen
FILE fdopen_tmp;
FILE * fdopen(int fildes,const char * mode){
	fdopen_ocall(fildes,mode,&fdopen_tmp);
	return &fdopen_tmp;
}

// setvbuf
int setvbuf(FILE *stream, char *buffer, int mode, size_t size){
	int *preturn = (int *)malloc(sizeof(int));
	setvbuf_ocall(preturn,stream,buffer,mode,size);
	return *preturn;
}

// fopen64
FILE fopen64_tmp;
FILE  *fopen64 (char *Path, char *Type){
	fopen64_ocall(Path,Type,&fopen64_tmp);
	return &fopen64_tmp;
}

// fileno
int fileno(FILE * stream){
	int *preturn = (int *)malloc(sizeof(int)); 
	fileno_ocall(preturn,stream);
	return *preturn;
}

// fclose
int fclose( FILE *fp ){
	int *preturn = (int *)malloc(sizeof(int));
	fclose_ocall(preturn,fp);
	return *preturn;
}
// read
ssize_t read(int fd, void * buf, size_t count){
	int *preturn = (int *)malloc(sizeof(int));
	read_ocall(preturn,fd,buf,count);
	return *preturn;
}
// writev
ssize_t writev(int filedes, const struct iovec *iov, int iovcnt){
	int *preturn = (int *)malloc(sizeof(int));
	writev_ocall(preturn,filedes,iov,iovcnt);
	return *preturn;
}
// lseek64
off64_t lseek64(int fd, off64_t offset, int whence){
	int *preturn = (int *)malloc(sizeof(int));
	lseek64_ocall(preturn,fd,offset,whence);
	return *preturn;
}
//don't know how to write yet
// ioctl
int ioctl(int d,int request,...){
	
}
// poll in poll.h
int poll(struct pollfd fd[], nfds_t nfds, int timeout){
	int *preturn = (int *)malloc(sizeof(int));
	poll_ocall(preturn,fd,nfds,timeout);
	return *preturn;
}
// __fxstat64
int __fxstat64(int ver, int fildes, struct stat64 * stat_buf){
	int *preturn = (int *)malloc(sizeof(int));
	__fxstat64_ocall(preturn,ver,fildes,stat_buf);
	return *preturn;
}
// setlocale
char setlocale_tmp[10];
char *setlocale(int category, const char *locale){
	setlocale_ocall(category,locale,setlocale_tmp);
	return setlocale_tmp;
}
// __strftime_l
size_t __strftime_l(
   char *strDest,
   size_t maxsize,
   const char *format,
   const struct tm *timeptr,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	__strftime_l_ocall(preturn,strDest,maxsize,format,timeptr,locale);
	return *preturn;
}

// __wcsftime_l
size_t __wcsftime_l(
   wchar_t *strDest,
   size_t maxsize,
   const wchar_t *format,
   const struct tm *timeptr,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	__wcsftime_l_ocall(preturn,strDest, maxsize,format,timeptr,locale);
	return *preturn;
}

// __towupper_l
int __towupper_l(
   wint_t c ,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	__towupper_l_ocall(preturn,c,locale);
	return *preturn;
}

// __towlower_l
int __towlower_l(
   wint_t c,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	__towlower_l_ocall(preturn,c,locale);
	return *preturn;
}

// __iswctype_l
int __iswctype_l(
   wint_t c,
   wctype_t desc,
   _locale_t locale
){
	int *preturn = (int *)malloc(sizeof(int));
	__iswctype_l_ocall(preturn,c,desc,locale);
	return *preturn;
}

// bindtextdomain
char bindtextdomain_tmp[10];
char * bindtextdomain (const char * domainname, const char * dirname){
	bindtextdomain_ocall(domainname,dirname,bindtextdomain_tmp);
	return bindtextdomain_tmp;
}
// get_nprocs
int get_nprocs(void){
	int *preturn = (int *)malloc(sizeof(int));
	get_nprocs_ocall(preturn);
	return *preturn; 
}
// nanosleep
int nanosleep(const struct timespec *req, struct timespec *rem){
	int *preturn = (int *)malloc(sizeof(int));
	nanosleep_ocall(pretutn,req,rem);
	return *preturn;
}
// pthread_detach
int pthread_detach(pthread_t tid){
	int *preturn = (int *) malloc(sizeof(int)); 
	pthread_detach_ocall(preturn,tid);
	return *preturn;
}

// clock_gettime
int clock_gettime(clockid_t clk_id,struct timespec *tp){
	int *preturn = (int *) malloc(sizeof(int)); 
	clock_gettime_ocall(preturn,clk_id,tp);
	return *preturn;
} 
 
// fopen
FILE fopen_tmp;
FILE *fopen(const char *filename, const char *mode){
	fopen_ocall(filename,mode,&fopen_tmp);
	return &fopen_tmp;
} 

// __fprintf_chk
int __fprintf_chk(FILE * stream, int flag, const char * format){
	int *preturn = (int *)malloc(sizeof(int));
	__fprintf_chk_ocall(preturn,stream,flag,format);
	return *preturn;
} 

// sprintf
// not sure
int sprintf(char *str, const char *format, ...){
}

// __assert_fail
void __assert_fail(const char * assertion, const char * file, unsigned int line, const char * function){
}

// getc
int getc(FILE *stream){
	int *preturn = (int *) malloc(sizeof(int));
	getc_ocall(preturn,stream);
	return *preturn; 
}

// ungetc
int ungetc(int chr, FILE *stream){
	int *preturn = (int *) malloc(sizeof(int));
	ungetc_ocall(preturn,chr,stream);
	return *preturn; 
}

// putc
int putc(int chr, FILE *stream){
	int *preturn = (int *) malloc(sizeof(int));
	putc_ocall(preturn,chr,stream);
	return *preturn;
}

// fseeko64
int fseeko64(FILE *stream, off64_t offset, int fromwhere){
	int *preturn = (int *) malloc(sizeof(int));
	fseeko64_ocall(preturn,stream,offset,fromwhere);
	return *preturn;
}

// ftello64
off64_t ftello64(FILE *stream){
	int *preturn = (int *) malloc(sizeof(int));
	ftello64_ocall(preturn,stream);
	 return *preturn;
}


// getwc
wint_t getwc (FILE* stream){
	int *preturn = (int *) malloc(sizeof(int));
	getwc(preturn,stream);
	return *preturn;
}


// ungetwc
wint_t ungetwc(wint_t ch, FILE * stream){
	int *preturn = (int *) malloc(sizeof(int));
	ungetwc_ocall(preturn,ch,stream);
	return *preturn;
}

// putwc
wint_t putwc(wchar_t ch, FILE * stream){
	int *preturn = (int *) malloc(sizeof(int));
	putwc_ocall(preturn,ch,stream);
	return *preturn;
}

// fread
size_t fread( void *buffer, size_t size, size_t count, FILE *stream ){
	int *preturn = (int *) malloc(sizeof(int));
	fread_ocall(preturn,buffer,size,count,stream);
	return *preturn;
}

// getrlimit
int getrlimit(int resource, struct rlimit *rlim){
	int *preturn = (int *) malloc(sizeof(int));
	getrlimit_ocall(preturn,resource,rlim);
	return *preturn;
}

//setrlimit
int setrlimit(int resource, const struct rlimit *rlim){
	int *preturn = (int *) malloc(sizeof(int));
	setrlimit_ocall(preturn,resource,rlim);
	return *preturn;
}

//strcpy
char strcpy_tmp[10];
char *strcpy(char *dest, const char *src){
	strcpy_ocall(dest,src,strcpy_tmp);
	return strcp_tmp;
}

//exit
void exit(int status){
}

//time
time_t time(time_t *seconds){
	int *preturn = (int *)malloc(sizeof(int));
	time_ocall(preturn,seconds);
	return *preturn;
}


//localtime_r
struct tm localtime_r_tmp;
struct tm *localtime_r( const time_t *timer, struct tm *buf ){
	localtime_r_ocall(timer,buf,&localtime_r_tmp);
	return &localtime_r_tmp;
}

//getpid
pid_t getpid(void){
	int *preturn = (int *) malloc(sizeof(int));
	getpid_ocall(preturn);
	return *preturn;
}

//sigemptyset
int sigemptyset(sigset_t *set){
	int *preturn = (int *) malloc(sizeof(int));
	sigemptyset_ocall(preturn,set);
	return *preturn;
}

//sigaction
// not sure
int sigaction(int sig, const struct sigaction *restrict act,
       struct sigaction *restrict oact){
       	
       	return sigaction_ocall(sig,act,oact);
}
       
//sigaddset
int sigaddset(sigset_t *set, int signum){
	int *preturn = (int *) malloc(sizeof(int));
	sigaddset_ocall(preturn,set,signum);
	return *preturn;
}


//sigprocmask
int sigprocmask(ubt how,const sigset_t*set,sigset_t *oldset){
	int *preturn = (int *) malloc(sizeof(int));
	sigprocmask_ocall(preturn,how,set,oldset);
	return *preturn;
}

// raise
int raise(int sig){
	int *preturn = (int *)malloc(sizeof(int));
	raise_ocall(preturn,sig);
	return *preturn;
}
//__longjmp_chk
void __longjmp_chk (jmp_buf env, int val){
	
}

//_setjmp
int _setjmp(jmp_buf env){
	int *preturn = (int *)malloc(sizeof(int));
	_setjmp_ocall(preturn,env);
	return *preturn;
}

//gethostname
int gethostname(char *name, size_t len){
	int *preturn = (int *)malloc(sizeof(int));
	gethostname_ocall(preturn,name,len);
	return *preturn;
}

//getsid
pid_t getsid(pid_t pid){
	int *preturn = (int *)malloc(sizeof(int));
	getsid_ocall(preturn,pid);
	return *preturn;
}

//open
int open(const char * pathname, int flags){
	int *preturn = (int *)malloc(sizeof(int));
	open_ocall(preturn,pathname,flags);
	return *preturn;
}
// close
int close(int fildes){
	int *preturn = (int *)malloc(sizeof(int));
	close_ocall(preturn,fildes);
	return *preturn;
}

//isatty
int isatty(int fd){
	int *preturn = (int *)malloc(sizeof(int));
	isatty_ocall(preturn,fd);
	return *preturn;
}
//lseek
off_t lseek(int fd, off_t offset, int whence){
	int *preturn = (int *)malloc(sizeof(int));
	lseek_ocall(preturn,fd,offset,whence);
	return *preturn;
}

//__ctype_b_loc
// not sure
const unsigned short * * __ctype_b_loc (void){
	
}

//__ctype_tolower_loc
// not sure
int32_t * * __ctype_tolower_loc(void){
	
}

//__ctype_toupper_loc
//not sure
int32_t * * __ctype_toupper_loc(void){
	
}

//dlclose
int dlclose(void *handle){
	int *preturn = (int *)malloc(sizeof(int));
	dlclose_ocall(preturn,handle);
	return *preturn;
}

// dlopen
// not sure
void *dlopen(const char *filename, int flag){
	
}

//dlsym
// not sure
void *dlsym(void *restrict handle, const char *restrict name){
	
}

//uname
int uname(struct utsname *buf){
	int *preturn = (int *)malloc(sizeof(int));
	uname_ocall(preturn,buf);
	return *preturn;
}

//munmap
int munmap(void *start, size_t length){
	int *preturn = (int *)malloc(sizeof(int));
	munmap_ocall(preturn,start,length);
	return *preturn;
}

//mproteck
int mprotect(void *addr, size_t len, int prot){
	int *preturn = (int *)malloc(sizeof(int));
	mprotect_ocall(preturn,addr,len,prot);
	return *preturn;
}

//mmap
// not sure
void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset){
                  	
				  }

//readlink
// not sure
ssize_t readlink(const char *restrict path, char *restrict buf,
       size_t bufsize){
       		return readlink_ocall(path,buf,bufsize);
	   }
       
// __realpath_chk
char __realpath_chk_tmp[10];
char * __realpath_chk (const char *buf, char *resolved, size_t resolvedlen){
	__realpath_chk_ocall(buf,resolved,resolvedlen,__realpath_chk_tmp);
}

//access
int access(const char *path, int amode){
	int *preturn = (int *)malloc(sizeof(int));
	access_ocall(preturn,path,amode);
	return *preturn; 
}

//chdir
int chdir(const char * path){
	int *preturn = (int *)malloc(sizeof(int));
	chdir_ocall(preturn,path);
	return *preturn;
}

//mkdir
int mkdir(const char *path, mode_t mode){
	int *preturn = (int *)malloc(sizeof(int));
	mkdir_ocall(preturn,path,mode);
	return *preturn;
}

//symlink
int symlink(const char *path1, const char *path2){
	int *preturn = (int *)malloc(sizeof(int));
	symlink_ocall(preturn,path1,path2);
	return *preturn;
}
//link
int link (const char * oldpath, const char * newpath){
	int *preturn = (int *)malloc(sizeof(int));
	link_ocall(preturn,oldpath,newpath);
	return *preturn;
}

//_lxstat
int __lxstat (int vers, const char *name, struct stat *buf){
	int *preturn = (int *)malloc(sizeof(int));
	__lxstat_ocall(preturn,vers,name,buf);
	return *preturn;
}

int remove(const char *filename)
{
    return sgx_remove(filename);
}


// ocall cann't return int but it can 
//__fxstat
//statfs
// gettext
// _ITM_RU1
// _ZGTtnam
// _ITM_memcpyRtWn
// _ITM_RU8
// _ITM_addUserCommitAction
// _ITM_memcpyRnWt
// _ZGTtdlPv
// __wctype_l
// stdout
// stdin
// __freelocale
// __nl_langinfo_l
// __uselocale C++
// __duplocale
// stderr
// _GLOBAL_OFFSET_TABLE_
// __stack_chk_fail

// _exit in sgx sdk
// getpagesize in sgx sdk
// strtok_r in sgx sdk
// strpbrk in sgx sdk
// memmove in sgx sdk
// memset in sgx sdk
// pthread_key_delete in sgx sdk
// pthread_key_create in sgx sdk
// pthread_setspecific in sgx sdk
// pthread_getspecific in sgx sdk
// memchr in sgx sdk
// wmemchr in sgx sdk
// strchr in sgx sdk
// mbsrtowcs in sgx sdk
// wcscmp in sgx sdk
// wmemcpy in sgx sdk
// wcsnrtombs in sgx sdk
// wcrtomb in sgx sdk
// mbsnrtowcs in sgx sdk
// mbrtowcin in sgx sdk
// strtoul in sgx sdk
// strerror in sgx sdk
// wmemmove in sgx sdk
// wmemcmp in sgx sdk
// atexit in sgx sdk
// pthread_cond_destroy in sgx sdk
// pthread_cond_waiti in sgx sdk
// pthread_cond_signal in sgx sdk
// pthread_cond_broadcast in sgx sdk 
// isspace in sgx sdk
// pthread_join in sgx sdk
// wmemset in sgx sdk
// pthread_create in sgx sdk
// wctob in sgx sdk
// btowc in sgx sdk
// vsnprintf in sgx sdk
// memcmp in sgx sdk
// pthread_once in sgx sdk
// frexpl in sgx sdk
// wcslen in sgx sdk
// asctime in sgx sdk
// free in sgx sdk
// abort in sgx sdk
// strcmp in sgx sdk
// memcpy in sgx sdk
// realloc in sgx sdk
// strncmp in sgx sdk
// strlen in sgx sdk
// malloc in sgx sdk
// strrchr in sgx sdk
// isupper in sgx sdk
// isblank in sgx sdk
// isdigit in sgx sdk
// toupper in sgx sdk
// strnlen in sgx sdk
// __pthread_key_create !! pthread_key_create in sgx sdk
// pthread_mutex_unlock in sgx sdk
// pthread_mutex_lock in sgx sdk
// pthread_key_create in sgx sdk
// pthread_setspecific in sgx sdk
// pthread_getspecific in sgx sdk
// calloc in sgx sdk
// __popcountdi2 in sgx sdk
// tolower in sgx sdk
// __snprintf_chk in sgx sdk
// log in sgx sdk
// exp in sgx sdk
// pow in sgx sdk
// sin in sgx sdk
// __vsnprintf_chk in sgx sdk
// strtoull in sgx sdk
// __memcpy_chk in sgx sdk
// strtol in sgx sdk
// qsort in sgx sdk
// isalpha in sgx sdk
// isalnum in sgx sdk
// strncpy in sgx sdk
//strftime in sgx sdk
// strtold in sgx sdk
// islower in sgx sdk
// isxdigit in sgx sdk
// modf in sgx sdk
// strtoll in sgx sdk
// pthread_self in sgx sdk
// strtof in sgx sdk
// strerror_r in sgx sdk







// _Unwind_Backtrace in unwind.h
// _Unwind_Resume in unwind.h
// _Unwind_DeleteException in unwind.h
// _Unwind_RaiseException in unwind.h
// _Unwind_Resume_or_Rethrow in unwind.h
// _Unwind_GetDataRelBase in unwind.h
// _Unwind_GetRegionStart in unwind.h
// _Unwind_GetTextRelBase in unwind.h
// _Unwind_SetGR in unwind.h
// _Unwind_SetIP in unwind.h
// _Unwind_GetLanguageSpecif in unwind.h
// _Unwind_GetIPInfo in unwind.h



