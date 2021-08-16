class tabla_de_verdad:
    def __init__(self, logic=None, params = 1):
        default_logic = lambda res: bool(res[0]) or bool(res[1])
        self.logic = logic if logic is not None else default_logic
        self.params = params
        self.resultados = []
        self.placeHolder = [None]*self.params
        
    def create_table(self):
        self.tabla(self.params, self.placeHolder, i=0 )
        
    
    def tabla(self, n, res, i):
        if i ==n:
            logica = self.logic(res)
            # print(res,": ", logica)
            temp = res.copy()
            temp.append(logica)
            self.resultados.append(temp)
            return 
        res [i]= 0
        self.tabla(n, res, i+1)
        
        res[i] = 1
        self.tabla(n, res, i+1)
        
tabla = tabla_de_verdad(params = 3, logic = lambda res: bool(res[0]) and bool(res[1]) or not(res[2]))
tabla.create_table()
print(tabla.resultados)
