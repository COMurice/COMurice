def check(str):
        id = 0
        count = 0
        print(str)
        for s in str:
                count= count+1
                if(s[0]!=" "and s[0]!="{"and s[0]!="\t" and s[0]!='\n'):
                        return False
                if(s[0]=="{"):
                        id = 1
        if(count>3):
                return False
        if(id==1):
                return True
        else :
                return False
def extract(str):
        right = 0
        left = 0
        for id in range(0,len(str)):
                if(str[id]=='('): 
                        right = id
                        break
        cnt = 0
        for i in range(right,0,-1):
                cnt = cnt+1
                if(str[i]=='*' or str[i]==' '):
                        if(cnt>3):
                                left = i
                                break
        return str[left+1:right]

list=[]
with open("temp",'r') as f:
    content = f.readlines()
for c in content:
        list.append(c)

with open('test.cpp','w') as file:
        pre_id=-1
        for i in list:
                file.write(i)
                if(check(i)):
                        s=extract(list[pre_id])
                        temp = "                printf(\"log %s\\n\","
                        file.write(temp)
                        file.write("\"")
                        file.write(s)
                        file.write("\"")
                        file.write(");")
                        file.write('\n')
                pre_id=pre_id+1

