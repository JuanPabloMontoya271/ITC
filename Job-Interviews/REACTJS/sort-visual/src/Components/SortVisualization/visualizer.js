import React, {Component} from "react"
import './index.css'

class Visualizers extends Component {

    constructor(props){

        super(props)
        this.state = {
            numValues: 75,
            values: [ ],
            width: 99,
            maxHeight: 40,
            maxValue: 10,
            minValue: 0,
            speed: 500,
            valueToLook: 10
            
        }
    }
    
    componentDidMount(){
        
        let array =this.resetArray();
        this.run("BinarySearch", array )
        
    }
    componentWillUnmount() {
        
      }
      run(algorithm, values){
       let array = values.values;
       let max = values.max;
        let res;
        let valueToLook = this.state.valueToLook
        switch (algorithm) {
            case "MergeSort":
                this.mergeSortAlgorithm(array, max);
                break;
            case "BinarySearch":
                res=this.BinarySearch(array,valueToLook);
                console.log(res);
                break;
            case "LinearSearch":
                res = this.linearSearchSorted(array, valueToLook);
                break;
            default:
                break;
        }
        

        
      }
     
      mergeSortAlgorithm(){


      }
      async linearSearchSorted(array, value){
        let left_dif, right_dif;
         
        for (let i=0; i< array.length-1; i++){
            left_dif = Math.abs(array[i].val -value)
            right_dif = Math.abs(array[i+1].val-value)


            if (right_dif>left_dif){
                array[i].color = "green"
                return array[i].val



            }
            array[i].color = "red"
            this.setState({values:array})
            
            await sleep(this.state.speed)
        }
      }
      async BinarySearch(array, value){
        console.log(array, "value",value);
        
        
        let i = 0;
        let j = array.length-1;
        let mid = Math.floor((i+j)/2);
        let arr;
        array[i].color = "red"
        array[j].color = "red"
        this.setState({values: array})
        await sleep(1000)
        while(i<j){
            arr = this.helper(i, j, array, value);
            i = arr.i
            j = arr.j
            mid = arr.mid
            array = arr.array
            
            await sleep(this.state.speed)
            
        }
        array[i].color = "green"
        array[j].color ="green"
        this.setState({values: array})
        return mid
      }
    helper(i, j, array, value){
        let midIdx =Math.floor((i+j)/2)
            let mid =  array[(midIdx)].val
           
            if ((mid) === value){
                console.log("mid", mid, value);
                array[midIdx].color = "green"
                return mid

            }
            if (mid<value){
                array[i].color = "royalblue"
                
                i = midIdx+1;
                array[i].color = "red"
                console.log("i", mid);
                
            }
            else{
                array[j].color = "royalblue"
                j= midIdx-1;
                array[j].color = "red"
                console.log("j",mid);
            }
            this.setState({values: array})
            return {i: i, j: j, mid: mid, array:array}

    }
    resetArray(){

        let array = []
        var max_val = 0
        for (let i = 0; i< this.state.numValues; i++){
            let value = randomIntFromInterval(this.state.minValue,this.state.maxValue)
            array.push({val: value, color: "royalblue"})
            max_val = Math.max(value, max_val)
            
            

        }
        this.setState({values: array.sort((a,b)=>{
            let x = a.val;
            let y = b.val;
            return ((x < y) ? -1 : ((x > y) ? 1 : 0));}), maxValue : max_val})
        return {values: array, maxValue : max_val}
    }
    render() {
      const {values} = this.state;
      const res = values.map((val, key)=> <div className = "bar" key = {key} style = {{height: val.val/this.state.maxValue*this.state.maxHeight+"vh", background: val.color}}></div>)

        return (
            <div className ="wrapper" style = {{width: this.state.width +"%",columnGap:this.state.width/this.state.numValues/4+"%", gridTemplateColumns: "repeat("+this.state.numValues+","+ this.state.width/this.state.numValues/4*3+"%)"} }>
                {res}
            </div>
            
      );
    }
  }
  function randomIntFromInterval (a,b){
    return Math.random()*(b-a+1)+a
}
function sleep(ms){

    return new Promise (resolve =>setTimeout(resolve, ms))
}
export default Visualizers;