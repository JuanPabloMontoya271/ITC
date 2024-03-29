import json

class Generator:
    def __init__(self) -> None :
        self.result = []
        with open("rules.json") as file:
            self.rules = json.load(file)
        
        self.rules = json.loads(self.rules)
        return 
    
    def __call__(self, stream: list[dict]) -> list[str]:
        for element in stream:
            for key, value in (element.items()):
                if key in self.rules:
                    self.result.append(self.span(key, self.rules[key]["Color"]))
                else:
                    self.result.append(self.span(key, "normal"))
        response = [self.html_wrapper("".join(self.result)), self.generate_css()]
        return response
    
    def span(self, text: str, color: int):
        return f"<span class='family-{color}' > {text} </span>"
    
    def html_wrapper(self, content):
        html = """<html> <head>
                            <link rel="stylesheet" href="styles.css">
                            </head> <body>""" 
        footer = """</body></html>"""
        return html + content + footer 
    def generate_css(self):
        css = """.family-0{
                    color: rgb(28, 140, 238);
                }
                .family-1{
                    color: rgb(5, 64, 115);
                }
                .family-2{
                    color: rgb(126, 255, 79);
                }
                .family-3{
                    color: rgb(65, 229, 254);
                }
                .family-4{
                    color: rgb(57, 30, 255);
                }
                .family-5{
                    color: rgb(33, 71, 105);
                }
                .family-6{
                    color: rgb(48, 158, 255);
                }
                .family-7{
                    color: rgb(255, 114, 114);
                }
                .family-8{
                    color: rgb(89, 192, 233);
                }
                .family-9{
                    color: rgb(255, 240, 242);
                }
                .family-10{
                    color: #2194f8;
                }
                .family-11{
                    color: rgb(79, 173, 255);
                }
                .family-12{
                    color: rgb(144, 255, 40);
                }
                .family-13{
                    color: rgb(84, 175, 255);
                }
                .family-normal{
                    color: rgb(92, 179, 255);
                }"""
        return css