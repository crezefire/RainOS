#ifndef USER_H
#define USER_H

struct stat;
struct rtcdate;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);

// ulib.c
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

//EXOKERNEL DEFS

#define nullptr 0

//Memory
char* ExGetVA(void);
char* ExGetFrame(int);
char* ExGetPDE(uint);
char* ExGetPTE(uint);
int   ExAddPage(char *va, char *frame);
int	  ExRegister();

typedef void (*function_ptr)(void);

//FS
char* ExFileRead(char*, char*);
//void  ExReadSector(uint sector, uint device, char* location);
void  ExReadSector(void);

void ExResetTransferCount();
uint ExGetTransferCount();

#endif
