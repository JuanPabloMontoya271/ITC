#Caesar cipher encryptor

string = "xyza"
def encryptor(string, key):
    newString = ""
    for i in range(len(string)):
        newString+= (chr((ord(string[i])-ord("a")+key)%26+ord("a")))
    return newString

print(encryptor(string,3))