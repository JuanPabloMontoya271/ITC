const button = document.getElementById("submit");
const inputs = [... document.getElementsByTagName("input")] 

button.addEventListener("click", (e) => {
    
    inputs.map((element, key) =>{
        console.log("Elemento ", key, "(", element.name,") : ", element.value);
    });
    console.log("Información extra :)")
});

