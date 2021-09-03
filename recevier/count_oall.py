line=[]
with open("log.log",'r',encoding='gbk',errors='ignore') as f:
    content = f.readlines()
for c in content:
        line.append(c)
list=[]
dict={}
for str in line:
        list = str.split()
        if(list[0]=="log"):
                if(list[1] in dict):
                        dict[list[1]]=dict.get(list[1])+1
                else :
                        dict[list[1]]=1
                        
list1=[]
list1=sorted(dict.items(), key=lambda item:item[1], reverse=True)
for i in list1:
        print(i)
        #print(dict[i]) 
        

# ('readdir', 3240)
# ('opendir', 136)
# ('access', 68)
# ('stat', 65)
# ('open', 36)
# ('sigaction', 32)
# ('sigemptyset', 30)
# ('getenv', 26)
# ('fstat', 26)
# ('close', 24)
# ('pread', 20)
# ('rand', 14)
# ('gettimeofday', 6)
# ('closedir', 4)
# ('lseek', 3)
# ('getcwd', 3)
# ('mmap', 3)
# ('fopen', 2)
# ('fread', 2)
# ('fclose', 2)
# ('getpid', 2)
# ('srand', 2)
# ('isatty', 2)
# ('posix_spawn', 2)
# ('waitpid', 2)
# ('readlink', 1)
# ('ioctl', 1)
# ('lseek64', 1)
# ('tigetnum', 1)
# ('set_curterm', 1)
# ('del_curterm', 1)
# ('write', 1)
# ('rename', 1)
# ('remove', 1)
