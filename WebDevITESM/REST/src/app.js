// server/index.js
const express = require("express");
const PORT = process.env.PORT || 3001;
const app = express();
const fs =  require("fs");
const uuid = require('uuid');
const mysql = require('mysql')

var cors = require('cors')


var con = mysql.createConnection({
    host: "us-mm-dca-20c15ada95c7.g5.cleardb.net",
    user: "bcfd996f48d23c",
    password: "0619f632",
    database : 'heroku_d3911b3e85d510b',
    insecureAuth : true
  });
  
  con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");
  });
app.use(cors())
app.get("/datos", (req, res) =>{
    con.query('SELECT * FROM heroku_d3911b3e85d510b.dose_image WHERE series_id = 11121;', function (error, results, fields) {
        if (error) throw error;
        // connected!
        console.log(results);
        res.json({datos:results})
      });
    
})
app.get("/pets", (req, res) => {
    console.log(__dirname);
    fs.readFile( __dirname + "/pets.json", "utf8", (err, data) => {
  data= JSON.parse(data)
  data = Object.entries(data).map(([key, value]) => ({[key]: value}))
  console.log( data );
  res.json( data );
    });
  });
const newPet = {
    "pet4": {
 "name": "nala",
 "type": "dog",
 "owner": "eldelcesar",
 "color": "salt and peper",
 "id": 4
    }
 }


 app.post("/addPet", (req, res) => {
    fs.readFile( __dirname + "/"+ "pets.json", "utf8", (err, data) => {
    data = JSON.parse( data );
    data["pet4"+uuid.v4()] = newPet["pet4"];
    console.log( data );
    fs.writeFile( __dirname + "/"+ "pets.json", JSON.stringify(data), function (err) {
        if (err) throw err;
        console.log('Replaced!');
    }); 
    data = Object.entries(data).map(([key, value]) => ({[key]: value}))
    console.log( data );
    res.json( data );
    });
 });
 app.put("/updatePet", (req, res) => {
    fs.readFile( __dirname + "/"+ "pets.json", "utf8", (err, data) => {
        data = JSON.parse( data );
        data["pet2"] = newPet["pet4"];
        console.log( data );
        
    fs.writeFile( __dirname + "/"+ "pets.json", JSON.stringify(data), function (err) {
        if (err) throw err;
        console.log('Replaced!');
    }); 
    res.json( data );
    });
 });
 app.delete("/deletePet", (req, res) => {
    fs.readFile( __dirname + "/"+ "pets.json", "utf8", (err, data) => {
        data = JSON.parse( data );
        delete data["pet4"];
        console.log( data );
        
    fs.writeFile( __dirname + "/"+ "pets.json", JSON.stringify(data), function (err) {
        if (err) throw err;
        console.log('Replaced!');
    }); 
    res.json( data );
    });
})
app.get("/api", (req, res) => {
    res.json({ message: "Hello from server side!" });
  });
app.listen(PORT, () => {
 console.log(`Server listening on ${PORT}`);
});
// ¿Qué observas? ¿Qué está haciendo ese ${PORT}