#Palindrome Check

def PalindromeCheck(string):
    i = 0
    j = len(string)-1
    while i<j:
        if string[i]!=string[j]:
            return False
    return True
print(PalindromeCheck("hola"))