list=[]
with open('undefined_symbol.txt','r') as f:
        list=f.readlines()

dic={}
for content in list:
        str = content.split(" ")
        if(str[-2]=="to"):
                if(str[-1] in dic):
                        pass
                else:
                        dic[str[-1]]=1
                        print(str[-1])