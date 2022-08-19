// server/index.js
const express = require("express");
const PORT = process.env.PORT || 3002;
const app = express();
const fs =  require("fs");
const uuid = require('uuid');
const mysql = require('mysql')
const moment = require("moment")
var cors = require('cors')


var con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "password2",
    database : "vetusDB",
    insecureAuth : true
  });
  
  con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");
  });
app.use(cors())
app.use(express.json());
const generate_time_and_date = ()=>{
  let ts = Date.now();

  let date_ob = new Date(ts);
  let date = date_ob.getDate();
  let month = date_ob.getMonth() + 1;
  let year = date_ob.getFullYear();
  let hours = date_ob.getHours();
  let minutes = date_ob.getMinutes();
  let seconds = date_ob.getSeconds();
  // prints date & time in YYYY-MM-DD format
  console.log(year + "-" + month + "-" + date + " " + hours + ":" + minutes + ":" + seconds);
  return [`'${year}-${month}-${date}'`,`'${hours}:${minutes}:${seconds}'`]
}
// const addTime = async ()=>{
//   let ts = Date.now();

//   let date_ob = new Date(ts);
//   let date = date_ob.getDate();
//   let month = date_ob.getMonth() + 1;
//   let year = date_ob.getFullYear();
//   let hours = date_ob.getHours();
//   let minutes = date_ob.getMinutes();
//   let seconds = date_ob.getSeconds();
//   // prints date & time in YYYY-MM-DD format
//   console.log(year + "-" + month + "-" + date + " " + hours + ":" + minutes + ":" + seconds);
//   return new Promise(function(resolve, reject){
//     con.query(
//       `INSERT INTO Tiempo(fecha, tiempo) VALUES('${year}-${month}-${date}','${hours}:${minutes}:${seconds}')`, 
//         function(err, results){  
//           if (err) reject(err);                                              
//           resolve(results)
//         }
//     )})
// }

const getPrueba =(tipo, id)=>{
  return new Promise(function(resolve, reject){
    con.query(
      `SELECT Prueba.PruebaID, Prueba.Fecha, Prueba.Tiempo, DesempenioTest.resBalance, DesempenioTest.resTotal, DesempenioTest.resVelMarcha, DesempenioTest.resSilla FROM vetusDB.DesempenioTest INNER JOIN vetusDB.Prueba ON Prueba.PruebaID = DesempenioTest.PruebaID; 
      `, 
        function(err, results){                                                
            if (err) reject(err);
            resolve(results)
            
        }
    )})
}
const getPlots = (response)=>{
  return new Promise(function(resolve, reject){
  console.log("Plots");
  res = [
    { x:[], 
      y:[], 
      name: "Balance",
      type: 'scatter',
      mode: 'lines+markers',
      marker: {color: 'red'},
    }, 
    {
      x:[], 
      y:[],
      name: "Velocidad Marcha",
      type: 'scatter',
      mode: 'lines+markers',
      marker: {color: 'green'},
    },
    { x:[], 
      y:[],
      name: "Silla", 
      type: 'scatter',
      mode: 'lines+markers',
      marker: {color: 'yellow'},
    },
    { x:[], 
      y:[],
      name: "Total",
      type: 'scatter',
      mode: 'lines+markers',

      marker: {color: 'blue'},}]
  for(var i =0; i<response.length; i+=1)
  {
    console.log("Date : ", response[i].Fecha.toISOString(), "Tiempo: ", response[i].Tiempo)
    let date = response[i].Fecha.toISOString()
    let time = response[i].Tiempo;
    let resBalance = response[i].resBalance;
    let resVelMarcha = response[i].resVelMarcha;
    let resSilla = response[i].resSilla;
    let resTotal = response[i].resTotal;
    const dateTime = moment(`${date} ${time}`, 'YYYY-MM-DD HH:mm:ss').format();
    res[0].x.push(dateTime);
    res[0].y.push(resBalance);
    res[1].x.push(dateTime);
    res[1].y.push(resVelMarcha);
    res[2].x.push(dateTime);
    res[2].y.push(resSilla);
    res[3].x.push(dateTime);
    res[3].y.push(resTotal);
  }
  console.log(res);
  resolve(res);
})
}
const getPacientes = ()=>{
  return new Promise(function(resolve, reject){
    con.query(
      `SELECT PersonaID, nombre, primerApellido FROM vetusDB.Persona WHERE rolID=1;
      `, 
        function(err, results){                                                
            if (err) reject(err);
            resolve(results)
            
        }
    )})
}
const getPruebas = ()=>{
  return new Promise(function(resolve, reject){
    con.query(
      `SELECT A.PruebaID , A.Fecha , A.Tiempo, A.NombrePaciente, A.ApellidoPaciente, A.CorreoPaciente,Persona.nombre as NombreAplicador, Persona.primerApellido as ApellidoAplicador, Persona.correoElectronico as CorreoAplicador 
       FROM (SELECT Prueba.AplicadorID, Prueba.PruebaID as PruebaID, Prueba.Fecha as Fecha, Prueba.Tiempo  as Tiempo, Persona.nombre as NombrePaciente, Persona.primerApellido as ApellidoPaciente, Persona.correoElectronico as CorreoPaciente 
       FROM vetusDB.Prueba INNER JOIN vetusDB.Persona ON Persona.PersonaID = Prueba.PacienteID) 
       as A INNER JOIN vetusDB.Persona 
       ON Persona.PersonaID = A.AplicadorID;
      `, 
        function(err, results){                                                
            if (err) reject(err);
            resolve(results)
            
        }
    )})
}
const addPrueba = (PacienteID, AplicadorID)=>{
  let date_and_time = generate_time_and_date();
  let date = date_and_time[0];
  let time = date_and_time[1];
  console.log(date, time)
  return new Promise(function(resolve, reject){
    con.query(
      `INSERT INTO Prueba(PacienteID, AplicadorID, Fecha, Tiempo) VALUES(${PacienteID}, ${AplicadorID}, ${date}, ${time})`, 
        function(err, results){                                                
            if (err) reject(err);
            resolve(results)
            
        }
    )})
};
const addDesempeno= (PruebaID, DesempenoTest)=>{
  let resBalance = DesempenoTest["resBalance"];
  let resVelMarcha = DesempenoTest["resVelMarcha"];
  let resSilla = DesempenoTest["resSilla"];
  let resTotal = DesempenoTest["resTotal"];

  return new Promise(function(resolve, reject){
    con.query(
      `INSERT INTO DesempenioTest(PruebaID, resBalance, resVelMarcha, resSilla, resTotal) VALUES(${PruebaID}, ${resBalance}, ${resVelMarcha}, ${resSilla}, ${resTotal})`, 
        function(err, results){                                                
            if (err) reject(err);
            resolve(results)
            
        }
    )})
};
const addSarcopenia = (PruebaID, SarcopeniaTest)=>{
  let resFuerza = SarcopeniaTest["resFuerza"];
  let resCaminar = SarcopeniaTest["resCaminar"];
  let resSilla = SarcopeniaTest["resSilla"];
  let resEscaleras = SarcopeniaTest["resEscaleras"];
  let resCaidas = SarcopeniaTest["resCaidas"];

  return new Promise(function(resolve, reject){
    con.query(
      `INSERT INTO SarcopeniaTest(PruebaID, resFuerza, resCaminar, resSilla, resEscaleras, resCaidas) VALUES(${PruebaID},${resFuerza}, ${resCaminar},${resSilla},${resEscaleras}, ${resCaidas})`, 
        function(err, results){                                                
            if (err) reject(err);
            resolve(results)
            
        }
    )})
};
const addFragilidad = (PruebaID, FragilidadTest)=>{
  let resFatiga = FragilidadTest["resFatiga"];
  let resResistencia = FragilidadTest["resResistencia"];
  let resDeambulacion = FragilidadTest["resDeambulacion"];
  let resEnfermedades = FragilidadTest["resEnfermedades"];
  let resPeso = FragilidadTest["resPeso"];
  
  return new Promise(function(resolve, reject){
    con.query(
      `INSERT INTO FragilidadTest(PruebaID,resFatiga, resResistencia, resDeambulacion, resEnfermedades, resPeso) VALUES(${PruebaID}, ${resFatiga}, ${resResistencia}, ${resDeambulacion}, ${resEnfermedades}, ${resPeso})`, 
        function(err, results){                                                
            if (err) reject(err);
            resolve(results)
            
        }
    )})
};
const addResultado = async (req)=>{
  let PacienteID = req.body.PacienteID;
  let AplicadorID = req.body.AplicadorID;
  let FragilidadTest = req.body.FragilidadTest;
  let SarcopeniaTest = req.body.SarcopeniaTest;
  let DesempenioTest = req.body.DesempenioTest;

  // current timestamp in milliseconds
  // addTime()
  // .then((response)=>{
  //   console.log(`Tiempo: ${response}`);
  //   let TiempoID = response["insertId"];
     addPrueba(PacienteID, AplicadorID)
     .then((response)=>{
       console.log(`Prueba: ${response}`);
       let PruebaID = response["insertId"]
        addDesempeno(PruebaID, DesempenioTest).then((response)=>{
          console.log(`Desempeno : ${response}`);
          addSarcopenia(PruebaID, SarcopeniaTest).then((response)=>{
            console.log(`Sarcopenia : ${response}`);
            addFragilidad(PruebaID, FragilidadTest).then((response)=>{
              console.log(`Fragilidad : ${response}`);
            })
          })
        })
     })

  // console.log(TiempoID)
  
 
  // console.log('Add resultado');
}
app.get("/plots", (req, res)=>{
  getPrueba().then((response)=>{
    console.log(response)
    getPlots(response).then((response)=>{
      res.json(response)
    })
    
  })
});
app.get("/desempeno", (req, res)=>{
  getPrueba("DesempenioTest", 26).then((response)=>{
    res.json(response)
  });
});
app.get("/fragilidad", (req, res)=>{
  getPrueba("FragilidadTest", 26).then((response)=>{
    res.json(response)
  });
});
app.get("/sarcopenia", (req, res)=>{
  getPrueba("SarcopeniaTest", 26).then((response)=>{
    res.json(response)
  });
});
app.get("/pruebas", (req, res)=>{
  getPruebas()
  .then((response)=>{
    res.json(response)
  });
});
app.get("/pacientes", (req, res)=>{
  getPacientes()
  .then((response)=>{
    res.json(response)
  });
});
app.post("/resultados", (req, res) =>{
  addResultado(req);
  res.json(req.body)
});
app.listen(PORT, () => {
 console.log(`Server listening on ${PORT}`);
});
