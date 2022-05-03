import React from 'react';
import {Component} from 'react'
class Car extends Component {
    constructor(props) {
        super(props);
   
        this.state = {
            items: [],
            DataisLoaded: false
        };
    }
   
    // ComponentDidMount is used to
    // execute the code 
    postEndpoint(){
        fetch(
            "http://localhost:3001/AddPet", {method:"POST"})
                        .then((res) => res.json())
                        .then((json) => {
                          console.log(json);
                          this.setState({
                            items: json,
                            DataisLoaded: true
                        });
                        })
    }
    componentDidMount() {
        fetch(
"http://localhost:3001/pets")
            .then((res) => res.json())
            .then((json) => {
                this.setState({
                    items: json,
                    DataisLoaded: true
                });
            })
    }
    render() {
        const { DataisLoaded, items } = this.state;
        if (!DataisLoaded) return <div>
            <h1> Pleses wait some time.... </h1> </div> ;
   
        return (
        <div className = "App">
            <h1> Fetch data from an api in react </h1>  {
                items.map((item) => ( 
                
                <ol key = { Object.keys(item)[0] } >
                    name: { item[Object.keys(item)[0]].name }, 
                    type: { item[Object.keys(item)[0]].type }, 
                    owner: { item[Object.keys(item)[0]].owner },
                    color: {item[Object.keys(item)[0]].color}
                    </ol>
                ))
            }
            <button onClick = {()=>{this.postEndpoint()}}>Add</button>
        </div>
    );
}
  }
export default Car;
  