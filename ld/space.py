with open("link.txt","r") as f:
        content = f.readlines()

for i in content:
        list = i.split(" ")

with open("order","w") as f:
        for i in list:
                f.write(i)
                f.write("\n")