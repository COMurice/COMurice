#include <stdio.h>
#include "Enclave_t.h"
// #include "sgx_tprotected_fs.h"
#include "sgx_trts.h"
#include "sgx_spinlock.h"
#include <stdarg.h>
#include <string.h>
#include <wchar.h>
// #include <sys/uio.h>
// #include <execinfo.h>    
// #include <pwd.h>
// #include<bits/stdc++.h>
// #include<sys/vfs.h>
// #include<sys/statfs.h>
// #include<fcntl.h>
// #include<unistd.h>
// #include <sys/resource.h>
// #include<signal.h>
// #include<sys/stat.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<sys/mman.h>
// #include<sys/utsname.h>
// #include<dlfcn.h>
// #include<sys/types.h>
// #include<dirent.h>
// #include <pthread.h> 
// #include<ctype.h>
// #include <sys/sysinfo.h>
// #include<malloc.h>
// #include<spawn.h>
// #include<sys/wait.h>
// #include<string.h>
// #include <link.h>
// #include<sys/time.h>
// #include <limits.h>
// #include <stdlib.h>
#define ubt int
#define _locale_t int
#define nfds_t int
#define wctype_t int
#define _RESTRICT restrict
#define bool int
#define true 1
#define false 0
#define off_t int
#define size_t int
#define mode_t int
#define uid_t int
#define pid_t int
#define _Unwind_Ptr void *
#define pthread_t unsigned long int 
#define time_t int
#define FILE void
#define ssize_t int
#define _locale_t int
#define locale_t int
#define off64_t int
#define nfds_t int
#define wint_t int
#define wctype_t int
#define clockid_t int
#define _RESTRICT restrict
#define ubt int
#define int32_t int
#define bool int
#define ubt int
#define uint int 
#define true 1
#define false 0
#define PATH_MAX 1024
typedef void pthread_key_t; 
typedef void DIR;
typedef void sigset_t;
typedef int (*PP)(pthread_key_t* key, void (*destructor)(void*));
typedef void stack_t;
typedef void cpu_set_t;
typedef void _Unwind_exception;
typedef void jmp_buf;
// typedef int (*Ppthread_once)(void *once_control, void (*init_routine)(void));
// typedef int (*Ppthread_mutex_lock)(void *mutex);
// typedef int (*Ppthread_mutex_unlock)(void *mutex); 
struct mallinfo {
    int arena;     /* Non-mmapped space allocated (bytes) */
    int ordblks;   /* Number of free chunks */
    int smblks;    /* Number of free fastbin blocks */
    int hblks;     /* Number of mmapped regions */
    int hblkhd;    /* Space allocated in mmapped regions (bytes) */
    int usmblks;   /* Maximum total allocated space (bytes) */
    int fsmblks;   /* Space in freed fastbin blocks (bytes) */
    int uordblks;  /* Total allocated space (bytes) */
    int fordblks;  /* Total free space (bytes) */
    int keepcost;  /* Top-most, releasable space (bytes) */
};

struct tm {
int tm_sec; /* 秒 – 取值区间为[0,59] */
int tm_min; /* 分 - 取值区间为[0,59] */
int tm_hour; /* 时 - 取值区间为[0,23] */
int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
int tm_year; /* 年份，其值等于实际年份减去1900 */
int tm_wday; /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
int tm_yday; /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
int tm_isdst; 
long int tm_gmtoff; 
const char *tm_zone; 
};

struct iovec {
               void  *iov_base;    /* Starting address */
               size_t iov_len;     /* Number of bytes to transfer */
           };

int printf(const char* fmt, ...)
{
    	#ifdef LLVM_DEBUG
	char buf[BUFSIZ] = { '\0' };
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(buf, BUFSIZ, fmt, ap);
	va_end(ap);
	ocall_print_string(buf);
	return (int)strnlen(buf, BUFSIZ - 1) + 1;
    	#endif
	return 0;
}
void Iago()
{
	printf("there may encounter some Iago attacks\n");
}	 
int in_errno;
long long mmap_occupied=0;
long long pread_occupied=0;
extern "C"
{

	int mmap_index = 0;
	void *mmap_addr[100];
	void *mmap_bufaddr[100];
	void *pread_addr[1000];
	int pread_idx=0;
	 int mmap_len[100];
	//pthread_mutex_t *mutex;
	// int main(int a,int b,int c);
	int main(int argc, char **argv, char **env);
        PP  __pthread_key_create;
	char **environ;
	void *__dso_handle;
	void* errno_addr;
	// Ppthread_once pthread_once;
	// Ppthread_mutex_lock pthread_mutex_lock;
	// Ppthread_mutex_unlock pthread_mutex_unlock;
        int pthread_key_create(void* key, void (*destructor)(void*));
	// int pthread_once(void *once_control, void (*init_routine)(void));
	// int pthread_mutex_lock(void *mutex);
	// int pthread_mutex_unlock(void *mutex); 

	
	// typedef struct _jmp_buf
	// {
	// 	int _jp[1];
	// } jmp_buf[1];
	// struct timespec
	// {
	// 	time_t tv_sec; /* seconds */
	// 	long tv_nsec;  /* nanoseconds */
	// };

	// struct pollfd
	// {
	// 	int fd;
	// 	short events;
	// 	short revents;
	// };
	// fstatfs
	
	// int fstatfs(int fd, struct statfs *buf)
	// {
        //         printf("log %s\n","fstatfs");
	// 	int preturn;
	// 	fstatfs_ocall(&preturn, fd, (void *)buf);
	// 	return preturn;
	// }

	// rename
	int rename(char *oldname, char *newname)
	{
                printf("log %s\n","rename");
		int preturn;
		rename_ocall(&preturn, oldname, newname);
		return preturn;
	}

	// posix_fallocate
	// int posix_fallocate(int fd, off_t offset, off_t len)
	// {
        //         printf("log %s\n","posix_fallocate");
	// 	int preturn;
	// 	posix_fallocate_ocall(&preturn, fd, (int)offset, (int)len);
	// 	return preturn;
	// }

	// ftruncate
	int ftruncate(int fd, off_t length)
	{
                printf("log %s\n","ftruncate");
		int preturn;
		ftruncate_ocall(&preturn, fd, (int)length);
		return preturn;
	}
	
	// __xstat
	int __xstat(int __ver, const char *__filename, struct stat *__stat_buf)
	{
                printf("log %s\n","__xstat");
		int preturn;
		__xstat_ocall(&preturn, __ver, __filename, (void *)__stat_buf);
		return preturn;
	}

	// realpath 
	char *realpath(const char *path, char *resolved_path)
	{
                printf("log %s\n","realpath");
		int preturn;
		if(resolved_path == nullptr)
		{
			resolved_path =(char *) malloc(PATH_MAX+1);
			realpath_ocall(&preturn, path, resolved_path);
			if(!preturn)
			{
				free(resolved_path);
				return nullptr;
			}
			else
			{
				return resolved_path;
			}
		}
		else
		{
			realpath_ocall(&preturn, path, resolved_path);
			if(!preturn)
			{
				return nullptr;
			}
			else
			{
				return resolved_path;
			}
		}
	}

	// getcwd 
	// char *getcwd(char *buf, size_t size)
	// {
	// 	printf("log %s\n","getcwd");	
	// 	int preturn;
	// 	if(buf == nullptr)
	// 	{
	// 		buf = (char *)malloc(PATH_MAX+1);
	// 		getcwd_ocall(&preturn, buf, size);
	// 		printf("getcwd %s\n",buf);
	// 		if(!preturn)
	// 		{
	// 			free(buf);
	// 			return nullptr;
	// 		}
	// 		else
	// 		{
	// 			return buf;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		getcwd_ocall(&preturn, buf, size);
	// 		printf("getcwd %s\n",buf);
	// 		if(!preturn)
	// 		{
	// 			return nullptr;
	// 		}
	// 		else
	// 		{
	// 			return buf;
	// 		}
	// 	}
	// }

	// lstat
	// int lstat(const char *path, struct stat *buf)
	// {
        //         printf("log %s\n","lstat");
	// 	int preturn;
	// 	lstat_ocall(&preturn, path, (void *)buf);
	// 	return preturn;
	// }

	// this is cyp's work
	// stat
	// int stat(const char *path, struct stat *buf)
	// {
        // 	printf("log %s\n","stat");
	// 	int preturn;
	// 	stat_ocall(&preturn, path, (void *)buf);
	// 	printf("stat arg %s return %d\n",path,preturn);
	// 	return preturn;
	// }

	// umask
	// int umask(mode_t mask)
	// {
        //         printf("log %s\n","umask");
	// 	int preturn;
	// 	umask_ocall(&preturn, (int)mask);
	// 	return preturn;
	// }

	// chmod
	// int chmod(const char *path, mode_t mode)
	// {
        //         printf("log %s\n","chmod");
	// 	int preturn;
	// 	chmod_ocall(&preturn, path, (int)mode);
	// 	return preturn;
	// }

	// fchmod
	// int fchmod(int fildes, mode_t mode)
	// {
        //         printf("log %s\n","fchmod");
	// 	int preturn;
	// 	fchmod_ocall(&preturn, fildes, (int)mode);
	// 	return preturn;
	// }

	// futimens
	int futimens(int fd, const struct timespec times[2])
	{
                printf("log %s\n","futimens");
		int preturn;
		futimens_ocall(&preturn, fd, (void *)times);
		return preturn;
	}



	// readdir 
	//void readdir_ocall(DIR*,struct dirent*); 

	// struct dirent *readdir(DIR *dir) 
	// {
        // 	printf("log %s\n","readdir");
	// 	static char readdir_tmp[584];
	// 	int preturn;
	// 	readdir_ocall(&preturn, (void **)&dir, (void *)readdir_tmp,&in_errno);
	// 	printf("readdir arg %p return %d\n",dir, preturn);
	// 	if (!preturn)
	// 		return (struct dirent *)readdir_tmp;
	// 	return nullptr;
	// }	

	// // opendir
	// //void opendir_ocall(char*,DIR*); 
	// //not sure
	
	// DIR *opendir(const char *name)
	// {
        // 	printf("log %s\n","opendir");
	// 	int preturn;
	// 	DIR * ret = 0;
	// 	opendir_ocall(&preturn,name,(void **)&ret,&in_errno); 
	// 	printf("opendir %s return %d pointer %p\n",name, preturn,ret);
	// 	return ret;
	// }

	// // pread
	// size_t pread(int fd, void *buf, size_t count, off_t offset)
	// {
        // 	printf("log %s\n","pread");
	// 	int preturn;
	// 	pread_ocall(&preturn, fd, buf, count, offset);
	// 	printf("pread fd:%d return %d\n",fd,preturn);
	// 	return preturn;
	// }

	// getuid
	uid_t getuid(void)
	{
                printf("log %s\n","getuid");
		int preturn;
		getuid_ocall(&preturn);
		return preturn;
	}

	// getpwuid
	// void getpwuid(uid_t,struct passwd *) 
	
	// struct passwd *getpwuid(uid_t uid)
	// {
        //         printf("log %s\n","getpwuid");
	// 	// static struct passwd getpwuid_tmp;
	// 	// getpwuid_ocall((int)uid, (void *)&getpwuid_tmp);
	// 	// return &getpwuid_tmp;
	// }
	// getpwnam
	// void getpwnam(char*,struct passwd*) 
	
	struct passwd *getpwnam(const char *name)
	{
                printf("log %s\n","getpwnam");
		// static struct passwd getpwnam_tmp;
		// getpwnam_ocall(name, (void *)&getpwnam_tmp);
		// return &getpwnam_tmp;
	}

	// mallinfo
	// void mallinfo(struct mallinfo *)
	
	// struct mallinfo *mallinfo(void)
	// {
        //         printf("log %s\n","mallinfo");
	// 	static struct mallinfo mallinfo_tmp;
	// 	memset(&mallinfo_tmp,0,sizeof(struct mallinfo));
	// 	return &mallinfo_tmp;
	// }

	// getrusage
	int getrusage(int who, struct rusage *usage)
	{
                printf("log %s\n","getrusage");
		int preturn;
		getrusage_ocall(&preturn, who, (void *)usage);
		return preturn;
	}

	// dup2
	int dup2(int odlfd, int newfd)
	{
                printf("log %s\n","dup2");
		int preturn;
		dup2_ocall(&preturn, odlfd, newfd);
		return preturn;
	}

	// sigfillset
	int sigfillset(sigset_t *set)
	{
                printf("log %s\n","sigfillset");
		int preturn;
		sigfillset_ocall(&preturn, (void*)set);
		return preturn;
	}
	// rand
	// int rand(void)
	// {
       	// 	printf("log %s\n","rand");
	// 	uint8_t tmp[4];
	// 	int *ret = (int *)tmp;
	// 	sgx_read_rand(tmp, 4);
	// 	return *ret;
	// }



	// // waitpid
	// pid_t waitpid(pid_t pid, int *status_pid, int options)
	// {
       	// 	printf("log %s\n","waitpid");
	// 	int preturn;
	// 	waitpid_ocall(&preturn, (int)pid, status_pid, options);
	// 	return preturn;
	// }

	// alarm
	unsigned int alarm(unsigned int seconds)
	{
                printf("log %s\n","alarm");
		int preturn;
		alarm_ocall(&preturn, seconds);
		return preturn;
	}

	// strsignal
	
	char *strsignal(int sig)
	{
		asm("int3");
        	printf("log %s\n","strsignal");
		static char strsignal_tmp[1000] = "fuck signal\n";
		// strsignal_ocall(sig, strsignal_tmp);
		return strsignal_tmp;
	}

	// kill
	int kill(pid_t pid, int sig)
	{
        	printf("log %s\n","kill");
		int preturn;
		kill_ocall(&preturn, (int)pid, sig);
		return preturn;
	}

	// wait
	pid_t wait(int *status_pid)
	{
                printf("log %s\n","wait");
		int preturn;
		wait_ocall(&preturn, status_pid);
		return preturn;
	}

	// sysconf
	long sysconf(int name)
	{
                printf("log %s\n","sysconf");
		int preturn;
		sysconf_ocall(&preturn, name);
		return preturn;
	}

	// fork
	pid_t fork(void)
	{
                printf("log %s\n","fork");
		int preturn;
		fork_ocall(&preturn);
		return preturn;
	}

	// execve   xxxxxxxxx
	// int execve(const char *filename, char *const argv[], char *const envp[])
	// {
	// 	int *preturn = (int *)malloc(sizeof(int));
	// 	execve_ocall(preturn, filename, argv, envp);
	// 	return *preturn;
	// }

	// environ
	

	// execv  xxxxxxxxxx
	// int execv(const char *path, char *const argv[])
	// {
	// 	int *preturn = (int *)malloc(sizeof(int));
	// 	execv_ocall(preturn, path, argv);
	// 	return *preturn;
	// }

	// _Unwind_GetIP
	// not sure
	_Unwind_Ptr _Unwind_GetIP(struct _Unwind_Context *context)
	{
                printf("log %s\n","_Unwind_GetIP");
		return nullptr;
	}

	// sigaltstack
	// not sure
	
	// int sigaltstack(const stack_t *ss, stack_t *old_ss)
	// {
        //         printf("log %s\n","sigaltstack");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// sigaltstack_ocall(preturn, ss, old_ss);
	// 	// return *preturn;
	// 	return -1;
	// }

	// unlink
	int unlink(const char *pathname)
	{
                printf("log %s\n","unlink");
		int preturn;
		unlink_ocall(&preturn, pathname);
		return preturn;
	}

	// dl_iterate_phdr
	// not sure
	// int dl_iterate_phdr(int (*callback)(struct dl_phdr_info *info, size_t size, void *data), void *data)
	// {
	// 	return dl_iterate_phdr_ocall(callback, data);
	// }

	// backtrace
	int backtrace(void **buffer, int size)
	{
                printf("log %s\n","backtrace");
		// int preturn;
		// backtrace_ocall(&preturn, buffer, size);
		// return preturn;
		return 0;
	}

	// backtrace_symbols_fd
	// void backtrace_symbols_fd(void *const *buffer, int size, int fd) 
	// {
        //         printf("log %s\n","backtrace_symbols_fd");

	// }

	// sched_getaffinity

	// int sched_getaffinity(pid_t pid, unsigned int cpusetsize, cpu_set_t *mask)
	// {
        //         printf("log %s\n","sched_getaffinity");
	// 	int preturn;
	// 	sched_getaffinity_ocall(&preturn, (int)pid, cpusetsize, (int *)mask);
	// 	return preturn;
	// }

	// __sched_cpucount
	// int __sched_cpucount(size_t setsize, const cpu_set_t *setp)
	// {
        //         printf("log %s\n","__sched_cpucount");
	// 	int preturn;
	// 	__sched_cpucount_ocall(&preturn, setsize, (void*)setp);
	// 	return preturn;
	// }

	// pthread_setschedparam
	// int pthread_setschedparam(pthread_t target_thread, int policy, const struct sched_param *param)
	// {
        //         printf("log %s\n","pthread_setschedparam");
	// 	// int preturn;
	// 	// pthread_setschedparam_ocall(&preturn, (int)target_thread, policy, (const void *)param);
	// 	// return preturn;
	// 	return 1;
	// }

	// pthread_attr_init
	// int pthread_attr_init(struct pthread_attr_t *attr)
	// {
        //         printf("log %s\n","pthread_attr_init");
	// 	// int preturn;
	// 	// pthread_attr_init_ocall(&preturn, (int *)attr);
	// 	// return preturn;
	// 	return 1;
	// }
	// // pthread_attr_destroy
	// int pthread_attr_destroy(struct pthread_attr_t *attr)
	// {
        //         printf("log %s\n","pthread_attr_destroy");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// pthread_attr_destroy_ocall(preturn, attr);
	// 	// return *preturn;
	// 	return 1;
	// }

	// __printf_chk
	int __printf_chk(int flag, const char *format,...)
	{
                printf("log %s\n","__printf_chk");
		// int *preturn = (int *)malloc(sizeof(int));
		// __printf_chk_ocall(preturn, flag, format);
		// return *preturn;
		return 0;
	}

	// localtime
	
	struct tm *localtime(const time_t *timer)
	{
                printf("log %s\n","localtime");
		static struct tm localtime_tmp;
		localtime_ocall((const void *)timer, (void *)&localtime_tmp);
		return &localtime_tmp;
	}

	// // gettimeofday
	// int gettimeofday(struct timeval *tv, struct timezone *tz)
	// {
        // 	printf("log %s\n","gettimeofday");
	// 	int preturn;
	// 	gettimeofday_ocall(&preturn, tv, tz);
	// 	printf("gettimeofday return %d\n",preturn);
	// 	return preturn;
	// }

	// aligned_alloc
	// void *aligned_alloc(size_t alignment, size_t size)
	// {
        //         printf("log %s\n","aligned_alloc");
	// 	return malloc((size/alignment)*alignment+size % alignment);
	// }

	// fwrite @
	
	size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
	{
                printf("log %s\n","fwrite");
		size = size * nmemb;
		if (stream == nullptr || ptr == nullptr) {
			return 0;
		}
		int preturn;
		fwrite_ocall(&preturn, ptr, size, 1, stream);
		return preturn;
	}

	// fputs @
	int fputs(const char *str, FILE *stream)
	{
                printf("log %s\n","fputs");
		if (stream == nullptr || str == nullptr) {
			return 0;
		}
		int preturn;
		fputs_ocall(&preturn, str, stream);
		return preturn;
	}
	
	// fputc @
	int fputc(int c, FILE *stream)
	{
                printf("log %s\n","fputc");
		if (stream == nullptr) {
			return 0;
		}
		int preturn;
		fputc_ocall(&preturn, c, stream);
		return preturn;
	}
	// write
	ssize_t write(int fd, const void *buf, size_t count)
	{
        	
		printf("log %s\n","write");
		int preturn;
		write_ocall(&preturn, fd, buf, count,&in_errno);
		printf("write return %d\n",preturn);
		return preturn;
	}

	// syscall
	// not sure
	int syscall(int number, ...)
	{
        	printf("log %s\n","syscall");
	}
	// __tls_get_addr
	// not sure
	// void *__tls_get_addr(size_t m, size_t offset)
	// {
	// 	void *preturn = (void *)malloc(10);
	// 	return preturn;
	// }
	// __cxa_thread_atexit_impl
	// not sure
	// typedef void (*dtor_func)(void *) {}
	// int __cxa_thread_atexit_impl(dtor_func func, void *obj, void *dso_symbol)
	// {
	// }

	// __strtof_l
	// float _strtof_l(const char *strSource,char **endptr,_locale_t locale)
	// {
        //         printf("log %s\n","_strtof_l");
	// 	return 0;
	// }

	// __strtod_l
	// double _strtod_l(const char *strSource,char **endptr,_locale_t locale)
	// {
        //         printf("log %s\n","_strtod_l");
	// 	return 0;
	// }

	// strtold_l
	// long double _strtold_l(const char *strSource,char **endptr,_locale_t locale)
	// {
        //         printf("log %s\n","_strtold_l");
	// 	return 0;
	// }
	// __newlocale
	locale_t __newlocale(int category_mask, const char *locale, locale_t base)
	{
                printf("log %s\n","__newlocale");
		// int *preturn = (int *)malloc(sizeof(int));
		// __newlocale_ocall(preturn, category_mask, locale, (int)base);
		// return *preturn;
		return 0;
	}
	// __dso_handle


	// __cxa_atexit
	// not sure
	// int __cxa_atexit(void (*func)(void *), void *arg, void *dso_handle)
	// {
	// }

	// strdup

	char *strdup(const char *s)
	{
                printf("log %s\n","strdup");
		// char strdup_tmp[10];
		// strdup_ocall(s, strdup_tmp);
		// return strdup_tmp;
		char *tmp = (char *)malloc(strlen(s)+1);
		if(tmp)
			strlcpy(tmp,s,strlen(s));
		return tmp;

	}
	// bind_textdomain_codeset
	char *bind_textdomain_codeset(const char *domainname, const char *codeset)
	{
                printf("log %s\n","bind_textdomain_codeset");
		static char bind_textdomain_codeset_tmp[1000];
		bind_textdomain_codeset_ocall(domainname, codeset, bind_textdomain_codeset_tmp);
		return bind_textdomain_codeset_tmp;
	}
	// dgettext
	char *gettext(const char *msgid)
	{
                printf("log %s\n","gettext");
		return "fuck gettext\n";
	}
	char *dgettext(const char *domainname, const char *msgid)
	{
                printf("log %s\n","dgettext");
		return "fuck dgettext\n";
	}
	// char *dcgettext(const char *domainname, const char *msgid, int category)
	// {
        //         printf("log %s\n","dcgettext");
	// 	return "fuck dcgettext\n";
	// }
	// getenv
	// char *getenv(const char *name)
	// {
        // 	printf("log %s\n","getenv");
	// 	int preturn;
	// 	// static char getenv_tmp[100] = {0};
	// 	char *ret;
	// 	getenv_ocall(&preturn,name, (void **)&ret);
	// 	printf("getenv %s = %s\n",name,ret);
	// 	return ret;
		
	// }
	// __strcoll_l
	// int _strcoll_l(const char *string1,const char *string2,_locale_t locale)
	// {
        //         printf("log %s\n","_strcoll_l");
	// 	return 0;
	// }

	// __strxfrm_l
	// size_t _strxfrm_l(char *strDest,const char *strSource,size_t count,_locale_t locale)
	// {
        //         printf("log %s\n","_strxfrm_l");
	// 	return 0;
	// }

	// __wcscoll_l
	int __wcscoll_l(const wchar_t *string1,const wchar_t *string2,_locale_t locale)
	{
                printf("log %s\n","__wcscoll_l");
		return 0;
	}

	// __wcsxfrm_l
	size_t __wcsxfrm_l(wchar_t *strDest,const wchar_t *strSource,size_t count,_locale_t locale)
	{
                printf("log %s\n","__wcsxfrm_l");
		return 0;
	}

	// __ctype_get_mb_cur_max
	size_t __ctype_get_mb_cur_max()
	{
                printf("log %s\n","__ctype_get_mb_cur_max");
		return 100;
	}

	// __errno_location
    
	// int *__errno_location(void)
	// {
        // 	printf("log %s\n","__errno_location");
	// 	// int __errno_location_tmp[10];
	// 	// __errno_location_ocall(__errno_location_tmp);
	// 	// return __errno_location_tmp;
	// 	printf("__errno_loacation %d\n",*(int *)errno_addr);
	// 	return (int *)errno_addr;
	// }
	// __errno_location
	
	// int *__errno_location(void)
	// {
	// 	// int preturn;
	// 	// __errno_location_ocall(&preturn);
        // 	// printf("log %s\n","__errno_location");
	// 	// printf("__errno_loacation %p\n",(int *)errno_addr);	
	// 	// return (int *)errno_addr;
	// 	return &in_errno;
	// }	
	
	// fflush
	// int fflush(FILE *stream)
	// {
        //         printf("log %s\n","fflush");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// fflush_ocall(preturn, (void *)stream);
	// 	// return *preturn;
	// }
	// fdopen

	// FILE *fdopen(int fildes, const char *mode)
	// {
        //         printf("log %s\n","fdopen");
	// 	// FILE **fdopen_tmp = (FILE **)malloc(sizeof(FILE *));
	// 	// fdopen_ocall(fildes, mode, (void *)fdopen_tmp);
	// 	// return *(FILE **)fdopen_tmp;
	// }

	// setvbuf
	// int setvbuf(FILE *stream, char *buffer, int mode, size_t size)
	// {
        //         printf("log %s\n","setvbuf");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// setvbuf_ocall(preturn, stream, buffer, mode, size);
	// 	// return *preturn;
	// }

	// fopen64
	FILE *fopen64(char *Path, char *Type)
	{
                printf("log %s\n","fopen64");
		// FILE **fopen64_tmp = (FILE **)malloc(sizeof(FILE *));
		// fopen64_ocall(Path, Type, (void *)fopen64_tmp);
		// return *(FILE **)fopen64_tmp;
	}

	// fileno
	int fileno(FILE *stream)
	{
                printf("log %s\n","fileno");
		// int *preturn = (int *)malloc(sizeof(int));
		// fileno_ocall(preturn, stream);
		// return *preturn;
	}

	// // fclose
	// int fclose(FILE *fp)
	// {
	// 	printf("log %s\n","fclose");
	// 	int preturn;
	// 	fclose_ocall(&preturn, (void **)&fp,&in_errno);
	// 	printf("fclose return %d\n",preturn);
	// 	return preturn;
	// }
	// read
	ssize_t read(int fd, void *buf, size_t count)
	{
                printf("log %s\n","read");
		int preturn;
		read_ocall(&preturn, fd, buf, count);
		return preturn;
	}
	// writev
	ssize_t writev(int filedes, const struct iovec *iov, int iovcnt)
	{
                printf("log %s\n","writev");
		int preturn = 0;
		for(int i =0;i<iovcnt;i++)
		{
			preturn += write(filedes,iov[i].iov_base,iov[i].iov_len);
		}
		return preturn;
	}
	// // lseek64
	// off64_t lseek64(int fd, off64_t offset, int whence)
	// {
	// 	printf("log %s\n","lseek64");
        //         printf("log %s fd:%d\n","lseek64",fd);
	// 	long long preturn;
	// 	lseek64_ocall(&preturn, fd, (long long)offset, whence);
	// 	return preturn;
	// }
	// // ioctl
	// int ioctl(int d, int request, ...)
	// {
	// 	printf("log %s\n","ioctl");
	// 	printf("log %s fd:%d\n","lseek64",d);
        //         printf("ioctl fd:%d %s\n",d,"ioctl");
	// 	return 0;
	// }
	// poll in poll.h
	int poll(struct pollfd *fd, nfds_t nfds, int timeout)
	{
                printf("log %s\n","poll");
		//int *preturn = (int *)malloc(sizeof(int));
		int preturn;
		poll_ocall(&preturn, fd, nfds*8, timeout);
		return preturn;
	}
	// __fxstat64
	int __fxstat64(int ver, int fildes, struct stat64 *stat_buf)
	{
                printf("log %s\n","__fxstat64");
		int preturn;
		__fxstat64_ocall(&preturn, ver, fildes, stat_buf);
		return preturn;
	}
	// setlocale
	// char *setlocale(int category, const char *locale)
	// {
        //         printf("log %s\n","setlocale");
	// 	return 0;
	// }
	// __strftime_l
	size_t __strftime_l(char *strDest,size_t maxsize,const char *format,const struct tm *timeptr,_locale_t locale)
	{
                printf("log %s\n","__strftime_l");
		return 0;
	}

	// __wcsftime_l
	size_t __wcsftime_l(wchar_t *strDest,size_t maxsize,const wchar_t *format,const struct tm *timeptr,_locale_t locale)
	{
                printf("log %s\n","__wcsftime_l");
		return 0;
	}

	// __towupper_l
	int __towupper_l(wint_t c,_locale_t locale)
	{
                printf("log %s\n","__towupper_l");
		return 0;
	}

	// __towlower_l
	int __towlower_l(wint_t c,_locale_t locale)
	{
                printf("log %s\n","__towlower_l");
		return 0;
	}

	// __iswctype_l
	int __iswctype_l(wint_t c,wctype_t desc,_locale_t locale)
	{
                printf("log %s\n","__iswctype_l");
		return 0;
	}

	// bindtextdomain
	char *bindtextdomain(const char *domainname, const char *dirname)
	{
                printf("log %s\n","bindtextdomain");
		return 0;
	}
	// get_nprocs
	// int get_nprocs(void)
	// {
        //         printf("log %s\n","get_nprocs");
	// 	int preturn;
	// 	get_nprocs_ocall(&preturn);
	// 	return preturn;
	// }
	// nanosleep
	int nanosleep(const struct timespec *req, struct timespec *rem)
	{
                printf("log %s\n","nanosleep");
		int preturn;
		nanosleep_ocall(&preturn, (void *)req, (void *)rem);
		return preturn;
	}
	// pthread_detach
	// int pthread_detach(pthread_t tid)
	// {
        //         printf("log %s\n","pthread_detach");
	// 	return 0;
	// }

	// clock_gettime
	int clock_gettime(clockid_t clk_id, struct timespec *tp)
	{
                printf("log %s\n","clock_gettime");
		int preturn;
		clock_gettime_ocall(&preturn, (int)clk_id, (void *)tp);
		return preturn;
	}

	// // fopen
	// FILE *fopen(const char *filename, const char *mode)
	// {
        //         printf("log %s\n","fopen");
	// 	FILE *ret;
	// 	fopen_ocall(filename, mode, (void **)&ret);
	// 	printf("fopen %s\n",filename);
	// 	return ret;
	// }
	// __fprintf_chk
	int __fprintf_chk(FILE *stream, int flag, const char *format)
	{
                printf("log %s\n","__fprintf_chk");
		// int *preturn = (int *)malloc(sizeof(int));
		// __fprintf_chk_ocall(preturn, stream, flag, format);
		// return *preturn;
		return 0;
	}

	// sprintf
	//not sure
	// int sprintf(char *str, const char *format, ...)
	// {
        //         printf("log %s\n","sprintf");
	// 	int ret;
	// 	va_list arglist;
	// 	va_start(arglist, format);
	// 	ret = vsnprintf(str, 10000, format, arglist);
	// 	va_end(arglist);
	// 	return ret;
	// }

	// __assert_fail
	// void __assert_fail(const char *assertion, const char *file, unsigned int line, const char *function)
	// {
        //         printf("log %s\n","__assert_fail");

	// }

	// getc
	// int getc(FILE *stream)
	// {
        //         printf("log %s\n","getc");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// getc_ocall(preturn, (void *)stream);
	// 	// return *preturn;
	// 	return 0;
	// }

	// ungetc
	// int ungetc(int chr, FILE *stream)
	// {
        //         printf("log %s\n","ungetc");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// ungetc_ocall(preturn, chr, stream);
	// 	// return *preturn;
	// 	return 0;
	// }

	// // putc
	// int putc(int chr, FILE *stream)
	// {
        //         printf("log %s\n","putc");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// putc_ocall(preturn, chr, (void *)stream);
	// 	// return *preturn;
	// 	return 0;
	// }

	// // fseeko64
	// int fseeko64(FILE *stream, off64_t offset, int fromwhere)
	// {
        //         printf("log %s\n","fseeko64");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// fseeko64_ocall(preturn, stream, offset, fromwhere);
	// 	// return *preturn;
	// 	return 0;
	// }

	// ftello64
	// off64_t ftello64(FILE *stream)
	// {
        //         printf("log %s\n","ftello64");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// ftello64_ocall(preturn, stream);
	// 	// return *preturn;
	// 	return 0;
	// }

	// // getwc
	// wint_t getwc(FILE *stream)
	// {
        //         printf("log %s\n","getwc");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// getwc_ocall(preturn, stream);
	// 	// return *preturn;
	// 	return 0;
	// }

	// // ungetwc
	// wint_t ungetwc(wint_t ch, FILE *stream)
	// {
        //         printf("log %s\n","ungetwc");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// ungetwc_ocall(preturn, ch, stream);
	// 	// return *preturn;
	// 	return 0;
	// }

	// putwc
	// wint_t putwc(wchar_t ch, FILE *stream)
	// {
        //         printf("log %s\n","putwc");
	// 	// int *preturn = (int *)malloc(sizeof(int));
	// 	// putwc_ocall(preturn, ch, stream);
	// 	// return *preturn;
	// 	return 0;
	// }

	// // fread
	// size_t fread(void *buffer, size_t size, size_t count, FILE *stream)
	// {
	// 	printf("log %s\n","fread");	
	// 	int preturn;
	// 	fread_ocall(&preturn, buffer, 1, count * size, (void **)&stream);
	// 	printf("fread return %d\n",preturn);
	// 	return preturn;
	// }

	// getrlimit
	int getrlimit(int resource, struct rlimit *rlim)
	{
                printf("log %s\n","getrlimit");
		int preturn;
		getrlimit_ocall(&preturn, resource, rlim);
		return preturn;
	}

	//setrlimit
	int setrlimit(int resource, const struct rlimit *rlim)
	{
                printf("log %s\n","setrlimit");
		int preturn;
		setrlimit_ocall(&preturn, resource, rlim);
		return preturn;
	}

	// //strcpy
	// char *strcpy(char *dest, const char *src)
	// {
        //         printf("log %s\n","strcpy");
	// 	strlcpy(dest,src,100000);
	// }

	// exit
	void exit(int status_pid)
	{
                printf("log %s\n","exit");
		exit_ocall(status_pid);
	}
	//time
	time_t time(time_t *seconds)
	{
                printf("log %s\n","time");
		int preturn;
		time_ocall(&preturn, (void *)seconds);
		return preturn;
	}

	//localtime_r
	struct tm *localtime_r(const time_t *timer, struct tm *buf)
	{
                printf("log %s\n","localtime_r");
		static struct tm localtime_r_tmp;
		localtime_r_ocall((void *)timer, (void *)buf, (void *)&localtime_r_tmp);
		return &localtime_r_tmp;
	}

	// //getpid
	// pid_t getpid(void)
	// {
        //         printf("log %s\n","getpid");
	// 	int preturn;
	// 	getpid_ocall(&preturn);
	// 	return preturn;
	// }

	// //sigemptyset
	// int sigemptyset(sigset_t *set)
	// {
        // 	printf("log %s\n","sigemptyset");
	// 	//int preturn;
	// 	//sigemptyset_ocall(&preturn, (void *)set);
	// 	memset(set,0,128);
	// 	return 0;
	// }


	//sigaddset
	int sigaddset(sigset_t *set, int signo)
	{
                printf("log %s\n","sigaddset");
		int preturn;
		sigaddset_ocall(&preturn, (void *)set, signo);
		return preturn;
	}

	//sigprocmask
	int sigprocmask(ubt how, const sigset_t *set, sigset_t *oldset)
	{
                printf("log %s\n","sigprocmask");
		int preturn;
		sigprocmask_ocall(&preturn, (int)how, (const void *)set, (void *)oldset);
		return preturn;
	}

	// raise
	int raise(int sig)
	{
                printf("log %s\n","raise");
		int preturn;
		raise_ocall(&preturn, sig);
		return preturn;
	}
	//__longjmp_chk
	void __longjmp_chk(jmp_buf *env, int val)
	{
                printf("log %s\n","__longjmp_chk");

	}

	//_setjmp
	// int _setjmp(jmp_buf env)
	// {
	// 	int *preturn = (int *)malloc(sizeof(int));
	// 	_setjmp_ocall(preturn, (int) env);
	// 	return *preturn;
	// }

	//gethostname
	int gethostname(char *name, size_t len)
	{
                printf("log %s\n","gethostname");
		int preturn;
		gethostname_ocall(&preturn, name, len);
		return preturn;
	}

	//getsid
	pid_t getsid(pid_t pid)
	{
                printf("log %s\n","getsid");
		int preturn;
		getsid_ocall(&preturn, (int)pid);
		return preturn;
	}

	// //open
	// int open(const char *pathname, int flags, mode_t mode)
	// {
        // 	printf("log %s\n","open");
	// 	int preturn;
	// 	open_ocall(&preturn, pathname, flags, (int)mode);
	// 	printf("open %s return %d\n",pathname,preturn);
	// 	return preturn;
	// }
	// close
	// int close(int fildes)
	// {
        // 	printf("log %s\n","close");
	// 	int preturn;
	// 	close_ocall(&preturn, fildes);
	// 	printf("close fd:%d return %d\n",fildes,preturn);
	// 	return preturn;
	// }


	// //lseek
	// off_t lseek(int fd, off_t offset, int whence)
	// {
        // 	printf("log %s\n","lseek");
	// 	int preturn;
	// 	lseek_ocall(&preturn, fd, (int)offset, whence);
	// 	printf("lseek fd:%d return %d\n",fd,preturn);
	// 	return preturn;
	// }

	//__ctype_b_loc
	// not sure
	const unsigned short **__ctype_b_loc(void)
	{
                printf("log %s\n","__ctype_b_loc");

	}

	//__ctype_tolower_loc
	// not sure
	// int32_t **__ctype_tolower_loc(void)
	// {
        //         printf("log %s\n","__ctype_tolower_loc");

	// }

	//__ctype_toupper_loc
	//not sure
	int32_t **__ctype_toupper_loc(void)
	{
                printf("log %s\n","__ctype_toupper_loc");
	}

	//dlclose
	int dlclose(void *handle)
	{
                printf("log %s\n","dlclose");
		// int *preturn = (int *)malloc(sizeof(int));
		// dlclose_ocall(preturn, handle);
		// return *preturn;
		return 0;
	}

	// dlopen
	void *dlopen(const char *filename, int flag)
	{
                printf("log %s\n","dlopen");
		return nullptr;
	}

	//dlsym
	void *dlsym(void *handle, const char *name)
	{
                printf("log %s\n","dlsym");
		return nullptr;
	}

	//uname
	int uname(struct utsname *buf)
	{
                printf("log %s\n","uname");
		return -1;
	}

	//munmap
	// int munmap(void *start, size_t length)
	// {
        //         printf("log %s\n","munmap");
	// 	return 0;
	// }

	//mproteck
	int mprotect(void *addr, size_t len, int prot)
	{
                printf("log %s\n","mprotect");
		return 0;
	}



	//readlink
	ssize_t readlink(char *path, char *buf, size_t bufsize)
	{
        	printf("log %s\n","readlink");
		int preturn;
		readlink_ocall(&preturn, path, buf, bufsize,&in_errno);
		printf("readlink %s return %d buf_content:%s\n",path,preturn,buf);
		return preturn;
	}

	//__realpath_chk
	char *__realpath_chk(const char *buf, char *resolved, size_t resolvedlen)
	{
                printf("log %s\n","__realpath_chk");
		return realpath(buf,resolved);
	}

	//access
	// int access(const char *path, int amode)
	// {
        // 	printf("log %s\n","access");
	// 	int preturn;
	// 	access_ocall(&preturn, path, amode);
	// 	printf("access %s return %d\n",path,preturn);
	// 	return preturn;
	// }

	//chdir
	int chdir(const char *path)
	{
                printf("log %s\n","chdir");
		int preturn;
		chdir_ocall(&preturn, path);
		return preturn;
	}

	//mkdir
	int mkdir(const char *path, mode_t mode)
	{
                printf("log %s\n","mkdir");
		int preturn;
		mkdir_ocall(&preturn, path, (int)mode);
		return preturn;
	}

	//symlink
	int symlink(const char *path1, const char *path2)
	{
                printf("log %s\n","symlink");
		int preturn;
		symlink_ocall(&preturn, path1, path2);
		return preturn;
	}
	//link
	int link(const char *oldpath, const char *newpath)
	{
                printf("log %s\n","link");
		int preturn;
		link_ocall(&preturn, oldpath, newpath);
		return preturn;
	}

	//_lxstat

	int __lxstat(int vers, const char *name, struct stat *buf)
	{
                printf("log %s\n","__lxstat");
		int preturn;
		__lxstat_ocall(&preturn, vers, name, buf);
		return preturn;
	}

	
	// int remove(const char *filename)
	// {
        //         printf("log %s\n","remove");
	// 	int preturn;
	// 	remove_ocall(&preturn,filename);
	// 	return preturn;
	// }

	
	void _Unwind_Resume(_Unwind_exception *exception_object)
	{
                printf("log %s\n","_Unwind_Resume");
		
	}

	// locale_t uselocale(locale_t newloc) 
	// {
	// 	printf("log %s\n","uselocale");
	// 	return 0;
	// }
	typedef void posix_spawn_file_actions_t;
	int posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *file_actions, int fildes, int newfildes)
	{
                printf("log %s\n","posix_spawn_file_actions_adddup2");
		return 0;
	}

	void _Unwind_DeleteException(struct _Unwind_Exception * a)
	{
                printf("log %s\n","_Unwind_DeleteException");

	}
	int execve(const char *pathname, char *const argv[],char *const envp[])
	{
                printf("log %s\n","execve");

	}
	locale_t __uselocale (locale_t newloc)
	{
                printf("log %s\n","__uselocale ");
		return 0;
	}
	void _Unwind_SetGR(struct _Unwind_Context * context, int index, uint value)
	{
                printf("log %s\n","_Unwind_SetGR");

	}
	size_t __strxfrm_l(char *dest, const char *src, size_t n, locale_t l)
	{
                printf("log %s\n","__strxfrm_l");

	}
	int __strcoll_l (const char *s1, const char *s2, locale_t l)
	{
                printf("log %s\n","__strcoll_l ");

	}
	int posix_spawn(pid_t *pid, const char *path,const void *file_actions,const void *attrp,char *const argv[], char *const envp[])
	{
		 printf("log %s\n","posix_spawn");	
		printf("******posix_spawn %s\n", path);
		
		for(char ** tmp = (char **) argv;*tmp ; tmp++)
		{
			printf("real %s\n",*tmp);

		}
		printf("the point %p\n",(char **)envp);  // the point of envp is 0x0
		char *argv_all = (char *)calloc(100000,1); //char *argv_all = (char *)calloc(10000,1); the previous code snipet
		char *env_all = (char *)calloc(100000,1);
		int argv_len=0,env_len = 0,argv_idx =0,env_idx =0;
		for(;argv && argv[argv_idx];argv_idx++)
		{

			strncat(argv_all + argv_len,argv[argv_idx],strlen(argv[argv_idx]));
			printf("ssss %s\n",argv_all + argv_len);
			argv_len += strlen(argv[argv_idx]) + 1;
			
		}

		for(;envp && envp[env_idx];env_idx++)
		{
			strncat(env_all + env_len,envp[env_idx],strlen(envp[env_idx]));
			env_len += strlen(envp[env_idx]) + 1 ;
			//env_all += strlen(envp[env_idx]) + 1;

		}
		int preturn;
		printf("the return value of posix_pawn %d\n",preturn);


		



		posix_spawn_ocall(&preturn,pid,path,file_actions,attrp,argv_all,env_all,argv_len,env_len);
		//main(argv_idx,(char **)argv,(char **)envp);
		printf("the return value of posix_pawn %d\n",preturn);
		return 0;

	}
	_Unwind_Ptr _Unwind_GetLanguageSpecificData(struct _Unwind_Context * context, uint value)
	{
                printf("log %s\n","_Unwind_GetLanguageSpecificData");

	}
	_Unwind_Ptr _Unwind_GetDataRelBase(struct _Unwind_Context * context)
	{
                printf("log %s\n","_Unwind_GetDataRelBase");

	}
	wctype_t __wctype_l (const char *property, locale_t locale)
	{
                printf("log %s\n","__wctype_l ");

	}
	// int posix_spawn_file_actions_init(posix_spawn_file_actions_t *file_actions)
	// {
	// 	//memset(file_actions, 0, 80);
		
        // 	printf("log %s\n","posix_spawn_file_actions_init");
	// 	return 0;

	// }
	int posix_spawn_file_actions_init(posix_spawn_file_actions_t *file_actions)
	{
		memset(file_actions, 0, 80);
        	printf("log %s\n","posix_spawn_file_actions_init");
		return 0;

	}
	locale_t __duplocale (locale_t dataset)
	{
                printf("log %s\n","__duplocale ");
		return 0;
	}
	float __strtod_l (const char *nptr, char **endptr, int group,locale_t loc)
	{
                printf("log %s\n","__strtod_l ");
		return 0;
	}
	int posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *file_actions)
	{
                printf("log %s\n","posix_spawn_file_actions_destroy");
		return 0;
		//memory leak

	}
	_Unwind_Ptr _Unwind_GetRegionStart(struct _Unwind_Context * context)
	{
                printf("log %s\n","_Unwind_GetRegionStart");
		
	}
	typedef int nl_item;
	char *__nl_langinfo_l (nl_item item, locale_t l)
	{
                printf("log %s\n","__nl_langinfo_l ");

	}
	void _exit(int status)
	{
                printf("log %s\n","_exit");
		return exit(status);
	}
	_Unwind_Ptr _Unwind_GetTextRelBase(struct _Unwind_Context * context)
	{
                printf("log %s\n","_Unwind_GetTextRelBase");
	}
	float __strtof_l(const char *nptr, char **endptr, locale_t loc){
		printf("log %s\n","__strtof_l");	
	}
	void __freelocale (locale_t dataset)
	{
                printf("log %s\n","__freelocale ");

	}
	FILE * stderr;
	_Unwind_Ptr _Unwind_GetIPInfo(struct _Unwind_Context * context, int * ip_before_insn)
	{
                printf("log %s\n","_Unwind_GetIPInfo");

	}
	void _Unwind_SetIP(struct _Unwind_Context * context, _Unwind_Ptr value)
	{
                printf("log %s\n","_Unwind_SetIP");

	}
	typedef void _Unwind_Reason_Code;
	_Unwind_Reason_Code _Unwind_RaiseException(struct _Unwind_Exception *object)
	{
                printf("log %s\n","_Unwind_RaiseException");

	}
	_Unwind_Reason_Code _Unwind_Resume_or_Rethrow(struct _Unwind_Exception * exception_object)
	{
                printf("log %s\n","_Unwind_Resume_or_Rethrow");

	}
	long double strtold_l(const char *nptr, char **endptr, locale_t locale)
	{
                printf("log %s\n","strtold_l");

	}
	int __fxstat (int vers, int fd, struct stat *buf)
	{
                printf("log %s\n","__fxstat ");

	}
	int execv(const char *path, char *const argv[])
	{
                printf("log %s\n","execv");

	}
	int posix_spawn_file_actions_addopen(posix_spawn_file_actions_t * file_actions, int fildes,const char * path, int oflag, mode_t mode)
	{
		
                printf("log %s\n","posix_spawn_file_actions_addopen");
		printf("the return value of posix_spawn_file_actions_addopen  fd=%d\n",fildes);
		return 0;
	}
	// int sigaction(int signum, const struct sigaction *act,struct sigaction *oldact)
	// {
        //         printf("log %s\n","sigaction");
	// 	return 0;
	// }
	// int pthread_sigmask (int how,const sigset_t *set,sigset_t *oset)
	// {
	// 	printf("log %s\n","pthread_sigmask");
	// 	return 1;
	// }
	int setupterm(char *term, int fd, int *errret)
	{
			*errret = 1;
		printf("log %s\n","setupterm");
			return 0;
	}
	
	// typedef void TERMINAL;
	// TERMINAL *set_curterm(TERMINAL *nterm)
	// {
        // 	printf("log %s\n","set_curterm");
	// 	return nterm;
	// }
	// int del_curterm(TERMINAL *oterm)
	// {
        //         printf("log %s\n","del_curterm");
	// 	return 0;
	// }
	// int tigetnum(char *capname)
	// {
        //         printf("log %s\n","tigetnum");
	// 	int preturn;
	// 	tigetnum_ocall(&preturn,capname,&in_errno)
	// 	return preturn;
	// }
	/*
	int sgx_thread_set_untrusted_event_ocall(const void *waiter)
	{
                printf("log %s\n","sgx_thread_set_untrusted_event_ocall");
		return 1;
	}
	*/
	// void pthread_wakeup_ocall()
	// {
        //         printf("log %s\n","pthread_wakeup_ocall");
		
	// }
	// int dl_iterate_phdr( int (*callback) (struct dl_phdr_info *info,   size_t size, void *data),void *data)
	// {
        //         printf("log %s\n","dl_iterate_phdr");
	// 	return 1;
	// }
	// typedef void* _Unwind_Trace_Fn;
	// _Unwind_Reason_Code _Unwind_Backtrace(_Unwind_Trace_Fn trace, void* trace_argument)
	// {
        //         printf("log %s\n","_Unwind_Backtrace");

	// }
        FILE *stdin;
     	FILE *stdout;
	// int statfs(const char *path, struct statfs *buf)
	// {
        //         printf("log %s\n","statfs");

	// }
	// int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize)
	// {
        //         printf("log %s\n","pthread_attr_setstacksize");

	// }
	// void pthread_wait_timeout_ocall()
	// {
        //         printf("log %s\n","pthread_wait_timeout_ocall");

	// }
	char *dlerror(void)
	{
                printf("log %s\n","dlerror");

	}
	// void pthread_create_ocall()
	// {

	// }
	// int fstat(int fd, struct stat *buf) 
	// {
        // 	printf("log %s\n","fstat");
	// 	int preturn;
	// 	fstat_ocall(&preturn,fd,(void *)buf);
	// 	printf("fstat fd:%d return %d\n",fd,preturn);
	// 	return preturn;

	// }
	int sscanf(const char *str, const char *format, ...) 
	{
                printf("log %s\n","sscanf");

	}
	typedef struct Dl_info Dl_info;
	int dladdr(void *addr, Dl_info *info) 
	{
                printf("log %s\n","dladdr");

	}
	int truncate(const char * path, off_t length) 
	{
                printf("log %s\n","truncate");

	}
	char *strsep(char **s, const char *delim)
        {
		printf("log %s\n","strsep");
	}
	int ferror(FILE *stream) 
	{
                printf("log %s\n","ferror");

	}
	int feof(FILE *stream) 
	{
                printf("log %s\n","feof");

	}
	int putchar(int ch) 
	{
                printf("log %s\n","putchar");

	}
	int __open_2 (const char *file, int oflag) 
	{
                printf("log %s\n","__open_2 ");

	}
	// void puts(const char *str)
	// {
	// 	printf("log %s\n","puts ");	
	// }

        void ecall_compile(int cnt_argv,int cnt_env,int *length_argv,int *length_env,char *all_argv,char *all_env)
	{
		//errno_addr = *e_addr;
		__pthread_key_create = nullptr; 
		// pthread_once = nullptr;
		// pthread_mutex_lock = nullptr;
		// pthread_mutex_unlock = nullptr;
		// printf_ocall();
		// // volatile uint32_t sgx_spinlock_t_tmp = 0xc164d97a00007fff;
		// // volatile uint32_t sgx_spinlock_t_tmp = 1;
		// // sgx_spin_lock(&sgx_spinlock_t_tmp);
		// char *s = "/home/go/SGX_LLVM_0125/app";
		// char *s1 = "test.c";
		// char *s2 = "a=b";
		// char *s3 = "-c";
		// char *tmp_argv[4];
		// tmp_argv[0] = s;
		// tmp_argv[1] = s1;
		// tmp_argv[2] = s3;
		// tmp_argv[3] = nullptr;
		// char *tmp_env[2];
		// tmp_env[0] = s2;
		// tmp_env[1] = nullptr;
		//inner();


		// sgx_key_128bit_t temp="010";
		// printf("%s\n",temp);
		// printf("*****************************************");
		// printf("*****************************************\n");
		// printf("*****************************************\n");
		// memset(length_argv,0,sizeof(length_argv));
		// int l=strlen(all_argv);
		// cnt_argv=0;
		// for(int i=0;i<l;i++)
		// {
		// 	if(all_argv[i]=='0') 
		// 	{
		// 		cnt_argv++;
		// 	}
		// 	else
		// 	{
		// 		length_argv[cnt_argv]++;
		// 	}
		// }
		// printf("%d\n",cnt_argv);
		// for(int i=0;i<cnt_argv;i++)
		// {
		// 	printf("%d\n",length_argv[i]);
		// }
		char *env_use[100000];
		char *argv_use[100000];
		int length=0;
		printf("cnt_argv=%d\n",cnt_argv);
		printf("cnt_env %d \n",cnt_env);
		// printf("%s\n",(char *)all_argv);
		// for(int i=0;i<cnt_argv;i++)
		// {
		// 	argv_use[i]=all_argv+length;
		// 	argv_use[i][length_argv[i]]='\0';
		// 	length+=length_argv[i]+1;
		// 	printf("argv_used[%d] %s\n",i,argv_use[i]);
		// }
		printf("*******************\n");
		char *pargv = all_argv;
		char *penv=all_env;
		printf("*******************\n");
		
		int argv_idx = 0,env_idx=0;
		for (int i=0;i<100000;i++)
		{
			if (all_argv[i] && !pargv)
			pargv = all_argv + i;
			else if(all_argv[i] && pargv)
				continue;
			else if(!all_argv[i] && !pargv)
				argv_use[argv_idx++] = pargv;
			else if(!all_argv[i] && pargv)
			{
				//printf("ffff  %s\n",pargv);
				argv_use[argv_idx ++] = pargv;
				pargv = nullptr;
			}
		}
		for (int i=0;i<100000;i++)
		{
			if (all_env[i] && !penv)
				penv = all_env + i;
			else if(all_env[i] && penv)
				continue;
			else if(!all_env[i] && !penv)
				env_use[env_idx ++] = penv;
			else if(!all_env[i] && penv)
			{
				env_use[env_idx ++] = penv;
				penv = nullptr;
			}
		}
		for(int i=0;i<argv_idx;i++)
		{
			if(!argv_use[i])
			{
				argv_idx=i;
				break;
			}
			printf("argv_used[%d] %s\n",i, argv_use[i]);
		}
		for(int i=0;i<env_idx;i++)
		{
			if(!env_use[i])
			{
				env_idx=i;
				break;
			}
			printf("env_used[%d] %s\n",i, env_use[i]);
		}
		printf("****************************\n");
		printf("argv_idx = %d\n",argv_idx);
		main(argv_idx,argv_use,env_use);
		void *point=malloc(10);
		free(point);
		mmap_index=0;
	}
	// void get_launch_token()
	// {

	// }
	// int pthread_mutex_destroy(struct pthread_mutex_t *mutex)  //40 bytes
	// {
	// 	int preturn;
	// 	pthread_mutex_destroy_ocall(&preturn,(void *)mutex);
	// 	return preturn;	
	// }
	// int pthread_mutexattr_init(struct pthread_mutexattr_t *attr)
	// {int new_socket = accept(recive, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	// 	printf("log %s\n","pthread_mutexattr_init");		
	// 	int preturn;
	// 	pthread_mutexattr_init_ocall(&preturn,(void *)attr);
	// 	return preturn;	
	// }
	// int pthread_mutexattr_destroy(struct pthread_mutexattr_t *attr)
	// {
	// 	printf("log %s\n","pthread_mutexattr_destroy");	
	// 	int preturn;
	// 	pthread_mutexattr_destroy_ocall(&preturn,(void*)attr);
	// 	return preturn;	
	// }
	// int pthread_mutexattr_settype(struct pthread_mutexattr_t *attr,int type)
	// {
	// 	printf("log %s\n","pthread_mutexattr_settype");
	// 	int preturn;
	// 	pthread_mutexattr_settype_ocall(&preturn,(void *)attr,type);
	// 	return preturn;	
	// }	
	// int pthread_mutexattr_setpshared(struct pthread_mutexattr_t *attr,int pshared )
	// {
	// 	printf("log %s\n","pthread_mutexattr_setpshared");
	// 	int preturn;
	// 	pthread_mutexattr_setpshared_ocall(&preturn,(void *)attr,pshared);
	// 	return preturn;	
	// }
	// int pthread_create(unsigned long int  *threadp,struct pthread_attr_t *attr,void *(*start_routine)(void *), void *arg)
	// {
	// 	printf("log %s\n","pthread_create");	
	// 	printf("pthread_create\n");
	// 	//preturn = pthread_create_ocall(threadp,attr);

	// }
	
	// int pthread_once(pthread_once_t *once_control, void (*init_routine) (void))
	// {
	// 	printf("pthread_once\n");
	// 	return 0;
	// }




		
	int *__errno_location(void)
	{
		// int preturn;
		// __errno_location_ocall(&preturn);
        	// printf("log %s\n","__errno_location");
		// printf("__errno_loacation %p\n",(int *)errno_addr);	
		//return (int *)errno_addr;
		return &in_errno;
	}	
	struct dirent *readdir(DIR *dir) 
	{
		//printf("log %s\n","readdir");
		static char readdir_tmp[584];
		int preturn;
		//printf("readdir in %p",&dir);
		//printf("readdir in%p\n",dir);
		readdir_ocall(&preturn, (void **)&dir, (void *)readdir_tmp,&in_errno);
		//printf("readdir arg %p return %d\n",dir, preturn);
		if(preturn!=0&&preturn!=1)
		{
			Iago();
		}
		if (!preturn)
			return (struct dirent *)readdir_tmp;
		return nullptr;
	}
	// opendir
	DIR *opendir(const char *name)
	{
		printf("log %s\n","opendir");
		int preturn;
		DIR * ret = 0;
		opendir_ocall(&preturn,name,(void **)&ret,&in_errno); 
		printf("opendir %s return %d pointer %p\n",name, preturn,ret);
		return ret;
	}
	// access
	int access(const char *path, int amode)
	{
		printf("log %s\n","access");
		int preturn;
		access_ocall(&preturn, path, amode,&in_errno);
		printf("access %s return %d\n",path,preturn);
		if(preturn!=-1&&preturn!=0)
		{
			Iago();
		}
		return preturn;
	}
	// stat
	int stat(const char *path, struct stat *buf)
	{
		printf("log %s\n","stat");
		int preturn;
		stat_ocall(&preturn, path, (void *)buf,&in_errno);
		printf("stat arg %s return %d\n",path,preturn);
		if(preturn !=-1&&preturn !=0)
		{
			Iago();
		}
		return preturn;
	}
	//open
	int open(const char *pathname, int flags, mode_t mode)
	{
		printf("log %s\n","open");
		int preturn;
		open_ocall(&preturn, pathname, flags, (int)mode,&in_errno);
		if(preturn <-1)
		{
			Iago();
		}
		printf("open %s return %d\n",pathname,preturn);
		return preturn;
	}
	// sigactin
	int sigaction(int signum, const struct sigaction *act,struct sigaction *oldact) // because it has point in struct 
	{
                printf("log %s\n","sigaction");
		return 0;
	}
	//sigemptyset
	int sigemptyset(sigset_t *set)
	{
        	printf("log %s\n","sigemptyset");
		if(set == NULL)
		{
			in_errno=-1;
			return -1;
		}
		memset(set,0,128);
		return 0;
	}
	// getenv
	char *getenv(const char *name)
	{
		//int *p;
		//printf("%d\n",*p);
        	printf("log %s\n","getenv");
		int preturn;
		// static char getenv_tmp[100] = {0};
		char *ret;
		getenv_ocall(&preturn,name, (void **)&ret);
		printf("getenv %s = %s\n",name,ret);
		return ret;
	}
	//fstat	
	int fstat(int fd, struct stat *buf) 
	{
        	printf("log %s\n","fstat");
		int preturn;
		fstat_ocall(&preturn,fd,(void *)buf,&in_errno);
		printf("fstat fd:%d return %d\n",fd,preturn);
		if(preturn!=-1&&preturn!=0)
		{
			Iago();
		}
		return preturn;
	}
	// close
	int close(int fildes)
	{
        	printf("log %s\n","close");
		int preturn;
		close_ocall(&preturn, fildes,&in_errno);
		printf("close fd:%d return %d\n",fildes,preturn);
		if(preturn!=-1&&preturn!=0)
		{
			Iago();
		}
		return preturn;
	}
	// pread
	// size_t pread(int fd, void *buf, size_t count, off_t offset)
	// {
        // 	printf("log %s\n","pread");
	// 	int preturn;
	// 	pread_ocall(&preturn, fd, buf, count, offset,&in_errno);
	// 	printf("pread fd:%d return %d\n",fd,preturn);
	// 	if(preturn > count && preturn !=-1)
	// 	{
	// 		Iago();
	// 	}
	// 	return preturn;
	// }

	__attribute__ ((naked)) void * getesp()
	{
		asm("mov %rsp,%rax");
	}
	size_t pread(int fd, void *buf, size_t count, off_t offset)
	{
		// void *buf1 = malloc(1);
		// printf("stack:%p   heap:%p\n",getesp(),buf1);
		// free(buf1);
        	// printf("log %s\n","pread");
		// for(int i=0;i<count;i++)
		// {
		// 	//printf("log %s\n","pread");
		// 	asm("nop");
		// 	*(char *)(buf+i)='\0';
		// }
		int preturn;
		pread_ocall(&preturn, fd, buf, count, offset,&in_errno);
		printf ("pread********************************\n");
		printf ("pread********************************\n");
		printf ("pread********************************\n");
		printf ("pread********************************\n");
		printf ("pread********************************\n");
		printf ("pread********************************\n");
		printf("pread fd:%d  count:%d   offset:%d  return %d\n",fd,count,offset,preturn);
		// printf("pread fd:%d return %d++++++++++++++++++++++\n",fd,preturn);
		// pread_occupied+=count;
		// printf("the content of buf  %s\n",(char *)buf);
		if(preturn > count && preturn !=-1)
		{
			Iago();
		}
		pread_addr[pread_idx++]=buf;
		// printf("the content of total pread %lld\n",pread_occupied);
		return preturn;
	}
	// rand
	int rand(void)
	{
		printf("log %s\n","rand");
		uint8_t tmp[4];
		int *ret = (int *)tmp;
		sgx_read_rand(tmp, 4);
		return *ret;
	}
	// gettimeofday
	int gettimeofday(struct timeval *tv, struct timezone *tz)
	{
        	printf("log %s\n","gettimeofday");
		int preturn;
		gettimeofday_ocall(&preturn, tv, tz,&in_errno);
		printf("gettimeofday return %d\n",preturn);
		if(preturn !=-1&&preturn!=0)
		{
			Iago();
		}
		return preturn;
	}
	// closedirgettimeofday
	int closedir(DIR *dir)
	{
        	printf("log %s\n","closedir");
		int preturn;
		closedir_ocall(&preturn, (void **)&dir,&in_errno);
		printf("close dir return %d\n",preturn);
		if(preturn !=-1&&preturn !=0)
		{
			Iago();
		}
		return preturn;
	}
	//lseek
	off_t lseek(int fd, off_t offset, int whence)
	{
        	printf("log %s\n","lseek");
		int preturn;
		lseek_ocall(&preturn, fd, (int)offset, whence,&in_errno);
		printf("lseek fd:%d return %d\n",fd,preturn);
		if(preturn < -1)
		{
			Iago();
		}
		return preturn;
	}
	// getcwd 
	char *getcwd(char *buf, size_t size)
	{
		printf("log %s\n","getcwd");	
		int preturn;
		if(buf == nullptr)
		{
			buf = (char *)malloc(PATH_MAX+1);
			getcwd_ocall(&preturn, buf, size,&in_errno);
			printf("getcwd %s\n",buf);
			if(!preturn)
			{
				free(buf);
				return nullptr;
			}
			else
			{
				return buf;
			}
		}
		else
		{
			getcwd_ocall(&preturn, buf, size,&in_errno);
			printf("getcwd %s\n",buf);
			if(!preturn)
			{
				return nullptr;
			}
			else
			{
				return buf;
			}
		}
	}
	//mmap
	// void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
	// {
	// 	printf("the size of mmap %d\n",length);
	// 	mmap_occupied+=length;
	// 	printf("log %s\n","mmap");
	// 	void *preturn;
	// 	mmap_ocall(&preturn,addr, length, prot, flags, fd, (int)offset,&in_errno);
	// 	printf("log %s\n","mmap");
	// 	printf("the totoal need memory of mmap%lld\n",mmap_occupied);
	// 	return preturn;
	// }
	// void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
	// {
	// 	printf("log mmap\n");
	// 	void *preturn;
	// 	void *start_addr = malloc(length);
	// 	mmap_ocall(&preturn, &addr, length, prot, flags, fd, (int)offset,&in_errno);
        // 	memcpy(start_addr,preturn,length);

	// 	return start_addr;
	// }

	void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
	{
		printf("mmap fd:%d prot:%d\n",fd,prot);
		void *preturn;
		void *start_addr = malloc(length+1);
		memset(start_addr,0,length+1);
		
		mmap_ocall(&preturn, &addr, length, prot, flags, fd, (int)offset,&in_errno);
		memcpy(start_addr,preturn,length);
		
		// mmap_addr[mmap_index] = preturn;
		// mmap_bufaddr[mmap_index] = start_addr;
		// mmap_len[mmap_index] = length;
		// mmap_index++;
		return preturn;	
	}
	//munmap
	int munmap(void *start, size_t length)
	{
		return 0;
		printf("log %s\n","munmap");
		//asm("int3");
		if(start == 0)
			return 0;
		void *mmap_orgaddr = 0;
		for(int i=0;i<100;i++)
		{
			if(mmap_bufaddr[i] == start)
			{
				mmap_orgaddr = mmap_addr[i];
			}
		}
		if(mmap_orgaddr == 0)
		{
			return 0;
		}
		int preturn;
		memcpy(mmap_orgaddr,start,length);
		munmap_ocall(&preturn,&mmap_orgaddr,length,&in_errno);
		//free(mmap_bufaddr[mmap_index]);
        	printf("log %s\n","munmap");
		return 0;
	}
	// fopen
	FILE *fopen(const char *filename, const char *mode)
	{
                printf("log %s\n","fopen");
		FILE *ret;
		fopen_ocall(filename, mode, (void **)&ret,&in_errno);
		printf("fopen %s\n",filename);
		return ret;
	}
	// fread
	size_t fread(void *buffer, size_t size, size_t count, FILE *stream)
	{
		printf("log %s\n","fread");	
		int preturn;
		fread_ocall(&preturn, buffer, 1, count * size, (void **)&stream,&in_errno);
		printf("fread return %d\n",preturn);
		if(preturn > size*count)
		{
			Iago();
		}
		return preturn;
	}
	// fclose
	int fclose(FILE *fp)
	{
		printf("log %s\n","fclose");
		int preturn;
		fclose_ocall(&preturn, (void **)&fp,&in_errno);
		printf("fclose return %d\n",preturn);
		if(preturn !=-1 &&preturn !=0)
		{
			Iago();
		}
		return preturn;
	}
	//getpid
	pid_t getpid(void)
	{
                printf("log %s\n","getpid");
		int preturn;
		getpid_ocall(&preturn);
		return preturn;
	}
	// srand
	void srand(unsigned int seed)
	{
                printf("log %s\n","srand");

	}
	//isatty
	int isatty(int fd)
	{
		printf("log %s\n","isatty");
		int preturn;
		isatty_ocall(&preturn, fd,&in_errno);
		if(preturn != 1&&preturn !=0) 
		{
			Iago();
		}
		printf("isatty fd:%d return:%d",fd,preturn);
		return preturn;
	}
	//fstat	
	// int fstat(int fd, struct stat *buf) 
	// {
        // 	printf("log %s\n","fstat");
	// 	int preturn;
	// 	fstat_ocall(&preturn,fd,(void *)buf,&in_errno);
	// 	printf("fstat fd:%d return %d\n",fd,preturn);
	// 	return preturn;
	// }

	// waitpid
	pid_t waitpid(pid_t pid, int *status_pid, int options)
	{
		printf("log %s\n","waitpid");
		int preturn;
		waitpid_ocall(&preturn, (int)pid, status_pid, options,&in_errno);
		if(preturn < -1) 
		{
			Iago();
		}
		return 0;
	}
	// ioctl
	int ioctl(int d, int request, void *arguments)
	{
		int preturn;
		ioctl_ocall(&preturn,d,request,arguments,&in_errno);
		if(preturn<-1)
		{
			Iago();
		}
		return preturn;
	}

	
	// lseek64
	off64_t lseek64(int fd, off64_t offset, int whence)
	{
		printf("log %s\n","lseek64");
                printf("log %s fd:%d\n","lseek64",fd);
		long long preturn;
		lseek64_ocall(&preturn, fd, (long long)offset, whence,&in_errno);
		if(preturn < -1)
		{
			Iago();
		}
		return preturn;
	}

	typedef void TERMINAL;
	TERMINAL *set_curterm(TERMINAL *nterm)
	{
		printf("log %s\n","set_curterm");
		return nterm;
	}
	int del_curterm(TERMINAL *oterm)
	{
                printf("log %s\n","del_curterm");
		return 0;
	}
	int tigetnum(char *capname)
	{
                printf("log %s\n","tigetnum");
		int preturn;
		tigetnum_ocall(&preturn,capname,&in_errno);
		if(preturn!=-1&&preturn!=-2)
		{
			Iago();
		}
		return preturn;
	}
	// remove
	int remove(const char *filename)
	{
                printf("log %s\n","remove");
		int preturn;
		remove_ocall(&preturn,filename,&in_errno);
		if(preturn!=0&&preturn!=1)
		{
			Iago();
		}
		return preturn;
	}
}
	
