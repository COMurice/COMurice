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

//void fstatfs_ocall(int fd, struct statfs *buf)
void fstatfs_ocall(int *preturn, int fd, void *buf)
{
   *preturn = fstatfs(fd, (struct statfs *)buf);
}

void rename_ocall(int *preturn, char *oldname, char *newname)
{
   *preturn = rename(oldname, newname);
}

// posix_fallocate
//void posix_fallocate_ocall(int *preturn, int fd, off_t offset, off_t len)
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
void getcwd_ocall(int *preturn, char *buf, size_t size)
{
   *preturn = getcwd(buf, size) ? 1 : 0;
}


// lstat
// void lstat_ocall(int *preturn, const char *path, struct stat *buf)
void lstat_ocall(int *preturn, const char *path, void *buf)
{
   *preturn = lstat(path, (struct stat *)buf);
}




// stat
void stat_ocall(int *preturn,const char *path, void *buf)
{
	*preturn = stat(path,(struct stat *)buf);
}

// umask
void umask_ocall(int *preturn,mode_t mask)
{
	*preturn = umask(mask);
}

// chmod
void chmod_ocall(int *preturn,const char * path, mode_t mode)
{
	*preturn = chmod(path,mode);
}

//fchmod
void fchmod_ocall(int *preturn,int fildes, mode_t mode)
{
   *preturn = fchmod(fildes, mode);
}



// futimens
void futimens_ocall(int *preturn,int fd, void *times)
{
   *preturn = futimens(fd,times);
}


// closedir
void closedir_ocall(int *preturn,void *dir)
{
   *preturn = closedir((DIR *)dir);
}


// readdir
//void readdir_ocall(DIR*,struct dirent*);

void readdir_ocall(void *dir,struct dirent* readdir_tmp)
{
	*readdir_tmp = *readdir((DIR *)dir);
}

/*
struct dirent* readdir_ocall(DIR * dir)
{
	return readdir(dir);
}
*/

//opendir_ocall
void opendir_ocall(const char *name,DIR *opendir_tmp)
{
	*opendir_tmp=*opendir(name)
}

void pread_ocall(int *preturn,int fd, void *buf, size_t count, off_t offset)
{
   *preturn = pread(fd, buf, count, offset);
   return *preturn;
}

// getuid
void getuid_ocall(int *preturn)
{
   *preturn =  getuid();
}

// getpwuid
// void getpwuid(uid_t,struct passwd *)

void getpwuid_ocall(uid_t uid,struct passwd * getpwuid_tmp)
{
	*getpwuid_tmp=*getpwuid(uid);
}

//getpwnam
void getpwnam_ocall(const char *name,struct passwd *getpwnam_tmp)
{
	*getpwnam_tmp=*getpwnam(name);
}

// mallinfo
void mallinfo_ocall(struct mallinfo *mallinfo_tmp)
{
	*mallinfo_tmp=*mallinfo();
}

// getrusage

void getrusage_ocall(int *preturn,int who,struct rusage *usage)
{
	*preturn = getrusage(who,usage);
}

// dup2
void dup2_ocall(int *preturn,int odlfd, int newfd)
{
   *preturn = dup2(odlfd,newfd);
}

// sigfillset
void sigfillset_ocall(int *preturn,sigset_t * set)
{
   *preturn = sigfillset(set);
}

// srand

// posix_spawn
// posix_spawn_file_actions_t
// not sure
void posix_fallocate_ocall(void *restrict pid, const char *restrict path, const void *file_actions, const void *restrict attrp, char *const argv[restrict], char *const envp[restrict])
{
   // return posix_spawn(pid,path,file_actions,attrp,argv,envp);
}

// waitpid
void waitpid_ocall(int *preturn,pid_t pid, int *status, int options)
{
   *preturn = waitpid(pid, status, options);
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
void kill_ocall(int *preturn,pid_t pid, int sig)
{
   *preturn = kill(pid, sig);
}

// wait
void wait_ocall (int *preturn,int * status)
{
    *preturn = wait(status);
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
	*preturn = sigaltstack(ss,old_ss);
}

// unlink
void unlink_ocall(int *preturn ,const char * pathname)
{
   *preturn = unlink(pathname);
}

// dl_iterate_phdr
// not sure
int dl_iterate_phdr_ocall(int (*callback) (struct dl_phdr_info *info, size_t size, void *data), void *data)
{
   return dl_iterate_phdr(callback, data);
}

// backtrace
void backtrace_ocall(int *preturn,void **buffer, int size)
{
   *preturn = backtrace(buffer,size);
}

// sched_getaffinity
void sched_getaffinity_ocall(int *preturn ,pid_t pid, unsigned int cpusetsize, cpu_set_t *mask){
	*preturn = sched_getaffinity(pid,cpusetsize,mask);
}

// __sched_cpucount
void __sched_cpucount_ocall(int *preturn ,size_t setsize, const cpu_set_t *setp){
	*preturn = __sched_cpucount(setsize,setp);
}

// pthread_setschedparam
void pthread_setschedparam_ocall(int *preturn , pthread_t target_thread, int policy, const struct sched_param *param){
	*preturn = pthread_setschedparam(target_thread,policy,param);
}

// pthread_attr_init
void pthread_attr_init_ocall(int *preturn,pthread_attr_t *attr){
	*preturn = pthread_attr_init(attr);
}

// pthread_attr_destroy
void pthread_attr_destroy_ocall(int *preturn,pthread_attr_t *attr){
	*preturn = pthread_attr_destroy(attr);
}

// __printf_chk
void __printf_chk_ocall(int *preturn,int flag, const char * format){
    *preturn = __printf_chk(flag,format);
}

//localtime
void localtime_ocall(const time_t *timer,struct tm* localtime_tmp){
	*localtime_tmp=*localtime(timer);
}

// gettimeofday
void gettimeofday_ocall(int *preturn,struct timeval * tv, struct timezone * tz){
	*preturn = gettimeofday(tv,tz);
}

//don't know how to write
// aligned_alloc
void aligned_alloc_ocall(void *preturn,size_t alignment, size_t size){
	preturn = (void *) aligned_alloc(32,10);
}


// fwrite
void fwrite_ocall(int *preturn,const void *ptr, size_t size, size_t nmemb, FILE *stream){
	*preturn = write(ptr,size,nmemb,stream);
}

// fputs
void fputs_ocall(int *preturn,const char *str, FILE *stream){
	*preturn =  fputs(str,stream);
}

// fputc
void fputc_ocall(int *preturn,int c, FILE * stream){
	*preturn =  fputc(c,stream);
}

// write
void write_ocall (int *preturn ,int fd, const void * buf, size_t count){
	*preturn = write(fd,buf,count);
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
	*preturn = _strtof_l(strSource,endptr,locale);
}

// __strtod_l
void _strtod_l_ocall(
   double *preturn,
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	*preturn = _strtod_l(strSource,endptr,locale);
}

// strtold_l
void _strtold_l_ocall(
    long double *preturn,
   const char *strSource,
   char **endptr,
   _locale_t locale
){
	*preturn = _strtold_l(strSource,endptr,locale);
}

// __newlocale
void __newlocale_ocall (int *preturn,int category_mask, const char *locale, locale_t base){
	*preturn = __newlocale(category_mask,locale,base);
}


//don't know how to wirte
// __dso_handle
void *__dso_handle;

// __cxa_atexit
int __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle){

}

// strdup
void strdup_ocall(const char *s,char * strdup_tmp){
	char *p=strdup(s);
	int n=strlen(p);
	for(int i=0;i<n;i++) strdup_tmp[i]=p[i];
}

// bind_textdomain_codeset
void bind_textdomain_codeset_ocall (const char * domainname, const char * codeset,char *bind_textdomain_codeset_tmp){
	char *p=bind_textdomain_codeset(domainname,codeset);
	int n=strlen(p);
	for(int i=0;i<n;i++) bind_textdomain_codeset_tmp[i]=p[i];
}

//don't know how to wirte
// dgettext
char * gettext (const char * msgid);char * dgettext (const char * domainname, const char * msgid);char * dcgettext (const char * domainname, const char *msgid, int category){

}

// getenv
void getenv_ocall(const char* name,char *getenv_tmp){
	char *p=getenv(name);
	int n=strlen(p);
	for(int i=0;i<n;i++) getenv_tmp[i]=p[i];
}

// __strcoll_l
void _strcoll_l_ocall(
   int *preturn,
   const char *string1,
   const char *string2,
   _locale_t locale
){
	*preturn = _strcoll_l(string1,string2,locale);
}

// __strxfrm_l
void _strxfrm_l_ocall(
   int *preturn,
   char *strDest,
   const char *strSource,
   size_t count,
   _locale_t locale
){
	*preturn = _strxfrm_l(strDest,strSource,count,locale);
}

// __wcscoll_l
void __wcscoll_l_ocall(
   int *preturn,
   const wchar_t *string1,
   const wchar_t *string2,
   _locale_t locale
){
	*preturn = __wcscoll_l(string1,string2,locale);
}

// __wcsxfrm_l
void __wcsxfrm_l_ocall(
   int *preturn,
   wchar_t *strDest,
   const wchar_t *strSource,
   size_t count,
   _locale_t locale
){
	*preturn = __wcsxfrm_l(strDest,strSource,count,locale);
}

// __ctype_get_mb_cur_max
void __ctype_get_mb_cur_max_ocall(int *preturn){
	*preturn = __ctype_get_mb_cur_max();
}

// __errno_location
void __errno_location_ocall(int *__errno_location_tmp){
	__errno_location_tmp=__errno_location_ocall();
}

// fflush
void fflush_ocall(int *preturn,FILE *stream){
	*preturn = fflush(preturn,stream);
}

// fdopen
void fdopen_ocall(int fildes,const char * mode,FILE *fdopen_tmp){
	fdopen_tmp=fdopen(fildes,mode);
}


// setvbuf
void setvbuf_ocall(int *preturn,FILE *stream, char *buffer, int mode, size_t size){
	*preturn = setvbuf(stream,buffer,mode,size);
}


// fopen64
void fopen64_ocall(char *Path, char *Type,FILE *fopen64_tmp){
	fopen64_tmp = fopen64(Path,Type);
}

// fileno
void fileno_ocall(int *preturn,FILE * stream){
	*preturn = fileno(stream);
}

// fclose
void fclose_ocall(int *preturn,FILE *fp ){
	*preturn = fclose(fp);
}

// read
void read_ocall(int *preturn,int fd, void * buf, size_t count){
	*preturn = read(preturn,fd,buf,count);
}

// writev
void writev_ocall(int *preturn,int filedes, const struct iovec *iov, int iovcnt){
	*preturn = writev(preturn,filedes,iov,iovcnt);
}

// lseek64
void lseek64_ocall(int *preturn,int fd, off64_t offset, int whence){
	*preturn = lseek64(fd,offset,whence);
}

// poll in poll.h
void poll_ocall(int *preturn,struct pollfd fd[], nfds_t nfds, int timeout){
	*preturn = poll(fd,nfds,timeout);
}

// __fxstat64
void __fxstat64_ocall(int *preturn,int ver, int fildes, struct stat64 * stat_buf){
	*preturn = __fxstat64(ver,fildes,stat_buf);
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
   const struct tm *timeptr,
   _locale_t locale
){
	*preturn = __strftime_l(strDest,maxsize,format,timeptr,locale);
}

// __wcsftime_l
void __wcsftime_l_ocall(
   int *preturn,
   wchar_t *strDest,
   size_t maxsize,
   const wchar_t *format,
   const struct tm *timeptr,
   _locale_t locale
){
	*preturn = __wcsftime_l(strDest, maxsize,format,timeptr,locale);
}


// __towupper_l
void __towupper_l_ocall(
   int *preturn,
   wint_t c ,
   _locale_t locale
){
	*preturn = __towupper_l(c,locale);
}

// __towlower_l
void __towlower_l_ocall(
   int *preturn,
   wint_t c,
   _locale_t locale
){
	*preturn = __towlower_l(c,locale);
}

// __iswctype_l
void __iswctype_l_ocall(
   int *preturn,
   wint_t c,
   wctype_t desc,
   _locale_t locale
){
	*preturn = __iswctype_l(c,desc,locale);
}

// bindtextdomain
void bindtextdomain_ocall (const char * domainname, const char * dirname,char *bindtextdomain_tmp){
	bindtextdomain_tmp = bindtextdomain(domainname,dirname);
}

// get_nprocs
void get_nprocs_ocall(int *preturn){
	*preturn = get_nprocs();
}

// nanosleep
void nanosleep_ocall(int *preturn,const struct timespec *req, struct timespec *rem){
	*preturn = nanosleep(req,rem);
}

// pthread_detach
void pthread_detach_ocall(int *preturn,pthread_t tid){
	*preturn = pthread_detach(tid);
}

// clock_gettime
void clock_gettime_ocall(int *preturn,clockid_t clk_id,struct timespec *tp){
	*preturn = clock_gettime(clk_id,tp);
}


// fopen
void fopen_ocall(const char *filename, const char *mode,FILE *fopen_tmp){
	fopen_tmp=fopen(filename,mode);
}

// __fprintf_chk
void __fprintf_chk_ocall(int *preturn,FILE * stream, int flag, const char * format){
	*preturn = __fprintf_chk(stream,flag,format);
}

// sprintf
// not sure
int sprintf(char *str, const char *format, ...){
}


// getc
void getc_ocall(int *preturn,FILE *stream){
	*preturn = getc(stream);
}

// ungetc
void ungetc_ocall(int *preturn,int chr, FILE *stream){
	*preturn = ungetc(chr,stream);
}

// putc
void putc_ocall(int *preturn,int chr, FILE *stream){
	*preturn = putc(preturn,chr,stream);
}

// fseeko64
void fseeko64_ocall(int *preturn,FILE *stream, off64_t offset, int fromwhere){
	*preturn = fseeko64(stream,offset,fromwhere);
}

// ftello64
void ftello64_ocall(int *preturn,FILE *stream){
	*preturn = ftello64(stream);
}

// getwc
void getwc_ocall(int *preturn,FILE* stream){
	*preturn = getwc(stream);
}

// ungetwc
void ungetwc_ocall(int *preturn,wint_t ch, FILE * stream){
	*preturn = ungetwc(ch,stream);
}

// putwc
void putwc_ocall(int *preturn,wchar_t ch, FILE * stream){
	*preturn = putwc(ch,stream);
}

// fread
void fread_ocall(int *preturn,void *buffer, size_t size, size_t count, FILE *stream ){

	*preturn = fread(buffer,size,count,stream);
}

// getrlimit
void getrlimit_ocall(int *preturn,int resource, struct rlimit *rlim){
	*preturn = getrlimit(resource,rlim);
}

//setrlimit
void setrlimit_ocall(int *preturn,int resource, const struct rlimit *rlim){
	*preturn = setrlimit(resource,rlim);
	return *preturn;
}

//strcpy
void strcpy_ocall(char *dest, const char *src,char *strcpy_tmp){
	strcpy_tmp = strcpy(dest,src);
}



//time
void time_ocall(int *preturn,time_t *seconds){
	*preturn = time(preturn,seconds);
}

//localtime_r
void localtime_r_ocall( const time_t *timer, struct tm *buf ,struct tm *localtime_r_tmp){
	localtime_r_tmp=localtime_r(timer,buf);
}

//getpid
void getpid_ocall(int *preturn){
	*preturn = getpid();
}

//sigemptyset
void sigemptyset_ocall(int *preturn,sigset_t *set);
	*preturn = sigemptyset(set);
}

//sigaddset
void sigaddset_ocall(int *preturn,sigset_t *set, int signum){
	*preturn = sigaddset(set,signum);
}

//sigprocmask
void sigprocmask_ocall(int *preturn,ubt how,const sigset_t*set,sigset_t *oldset){
	*preturn = sigprocmask(how,set,oldset);
}

// raise
void raise_ocall(int *preturn,int sig){
	*preturn = raise(sig);
}

//_setjmp
void _setjmp_ocall(int *preturn,jmp_buf env){
	*preturn = _setjmp(env);
}

//gethostname
void gethostname_ocall(int *preturn,char *name, size_t len){
	*preturn = gethostname(name,len);
}

//getsid
void getsid_ocall(int *preturn,pid_t pid){
	*preturn = getsid(pid);
}

//open
void open_ocall(int *preturn,const char * pathname, int flags){
	*preturn = open(pathname,flags);
}

// close
void close_ocall(int *preturn,int fildes){
	*preturn = close(fildes);
}

//isatty
void isatty_ocall(int *preturn,int fd){
	*preturn = isatty(fd);
}

//lseek
void lseek_ocall(int *preturn,int fd, off_t offset, int whence){
	*preturn = seek(fd,offset,whence);
}

//dlclose
void dlclose_ocall(int *preturn,void *handle){
	*preturn = dlclose(handle);
}

//uname
void uname_ocall(int *preturn,struct utsname *buf){
	*preturn = uname(buf);
}

//munmap
void munmap_ocall(int *preturn,void *start, size_t length){
	*preturn = munmap(start,length);
}

//mproteck
void mprotect_ocall(int *preturn,void *addr, size_t len, int prot){
	*preturn = mprotect(addr,len,prot);
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
void __realpath_chk_ocall(const char *buf, char *resolved, size_t resolvedlen,char *__realpath_chk_tmp){
	__realpath_chk_tmp=__realpath_chk(buf,resolved,resolvedlen);
}

//access
void access_ocall(int *preturn,const char *path, int amode){
	*preturn = access(path,amode);

}

//chdir
void chdir_ocall(int *preturn,const char * path){
	*preturn = chdir(path);
}

//mkdir
void mkdir_ocall(int *preturn,const char *path, mode_t mode){
	*preturn = mkdir(path,mode);
}

 //symlink
void symlink(int *preturn,const char *path1, const char *path2){
	*preturn = symlink(path1,path2);
}

//link
void link_ocall (int *preturn,const char * oldpath, const char * newpath){
	*preturn=link(oldpath,newpath);
	return *preturn;
}

//_lxstat
void __lxstat_ocall (int *preturn,int vers, const char *name, struct stat *buf){
	*preturn = __lxstat(vers,name,buf);
}










