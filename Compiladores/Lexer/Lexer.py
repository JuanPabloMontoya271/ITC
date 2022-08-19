import json
import os
import glob 
import threading
from time import time
from tracemalloc import start
from Generator import Generator

class Lexer:
    def __init__(self, file_path: str):

        self.file_path_ = file_path
        self.rows = [f"q{i}" for i in range(13)] + ["D"]
        with open("dfa_table.json") as file:
            self.table = json.load(file)
        self.dfa_table = {row: elem for row, elem in zip(self.rows, self.table)}

        self.special     = {"{" : "Opening Bracket", 
                            "}" : "Closing Bracket", 
                            "(" : "Opening Parenthesis", 
                            ")" : "Closing Parenthesis", 
                            "*" : "Multiplication operator", 
                            "^" : "Exponent Operator", 
                            "=" : "Equal Sign", 
                            "+" : "Plus sign",
                            "-" : "Substraction Sign"
                            }
                            
        self.types       = {"q0"  :  "Space", 
                            "q12" :  "variable", 
                            "q7"  :  "Real", 
                            "q3"  :  "Float", 
                            "q4"  :  "Float", 
                            "q2"  :  "Integer", 
                            "q1"  :  self.special, 
                            "q10" :  "Slash", 
                            "q11" :  "Comentario",
                            "q8"  :  "String", 
                            "q9"  :  "String"
                            }
        self.result = []
        return 
    def run(self):

        with open(self.file_path_) as file:
            lines = file.readlines()

        for line in lines:
            self.dfa(line)

    def classify(self, c: str):

        isKnown = (c in set({"{", "}", "(", ")", "*", "^", "="}))
        isnum= (c.isnumeric())
        ispoint = (c == ".")
        isE = (c in set({"E", "e"}))
        issign = (c == "-" or c == "+")
        isquotes = (c in set({'"', "'"}))
        isslash = (c == "/")
        isspace = (c == " ")
        isalpha = (ord(c)>=ord("a") and ord(c)<=ord("z") or ord(c)>=ord("A") and ord(c)<=ord("Z"))
        isVariableAccepted = (isalpha or isnum or c == "_")
    
        if isE:
            return "3"
        elif isKnown:
            return "0"
        elif isnum:
            return "1"
        elif ispoint:
            return "2"
        elif issign:
            return "4"
        elif isquotes:
            return "5"
        elif isslash:
            return "6"
        elif isspace:
            return "7"
        elif isalpha:
            return "8"
        elif isVariableAccepted:
            return "9"
        else:
            return "10"

    def dfa(self, word: str):
        states = self.rows
        connections = self.dfa_table
        queue = ["q0"]
        curr_lex = []
        for c in word:
            curr = queue.pop(0)
            next = connections[curr][self.classify(c)]
            if self.classify(c) == "7" and curr != "q11" and curr != "q8":
                self.postprocess(curr, curr_lex)
                curr_lex = []
            else:
                curr_lex.append(c)

            queue.append(next)
        self.postprocess(curr, curr_lex)
        
    def postprocess(self, curr, curr_lex):
        type_ = self.types.get(curr, "Unknown") 
        type_ = type_ if curr !="q1" else type_[curr_lex[0]]
        self.result.append({"".join(curr_lex): type_ })
        return 
def main(file):
    lexer = Lexer(file)
    lexer.run()
    generator = Generator()
    html, css = generator(lexer.result)
    result_name = os.path.join(file.split(".")[0]+".html")
    css_name = os.path.join("inputs", "styles.css")
    with open(result_name, "w") as file:
        file.write(html)
    with open(css_name, "w") as file:
        file.write(css)
if __name__ == "__main__":
    files = (glob.glob("inputs/*"))
    start_time = time()
    for file in files:
        main(file)
    first_time = time()-start_time

    start_time = time()
    threads = []
    for file in files:
        x = threading.Thread(target = main, args = (file,))
        x.start()
        threads.append(x)
    for thread in threads:
        thread.join()
    
    second_time = time() - start_time
    print(f"Boost up : {first_time/second_time}, first : {first_time}, second: {second_time}")
