import React, {Component} from "react"
import './index.css'

class Visualizers extends Component {

    constructor(props){

        super(props)
        this.state = {
            numValues: 100,
            values: [ ],
            width: 99,
            maxHeight: 40,
            maxValue: 10,
            minValue: 0,
            speed: 500,
            valueToLook: 10, 
            timeToLook: 20000,
            maxTime:500, 
            waitTime: 10,
            
        }
    }
    
    componentDidMount(){
        
        let array =this.resetArray();
        //this.run("BinarySearch", array )
        
        this.mergeSortAlgorithm(array)

        
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
                //res);
                break;
            case "LinearSearch":
                res = this.linearSearchSorted(array, valueToLook);
                break;
            default:
                break;
        }
        

        
      }
     
       async mergeSortAlgorithm(array){
            let values = array.values
            await sleep(2000)
            values = await this.mergeSort(values, values, 0 , values.length-1)

            //values);
            
            this.setState({values:values})
            await sleep (2000)
            //"values before run", values);
            await this.run("BinarySearch", {values: values})
            await this.run("LinearSearch", {values: values})
      }
      async mergeSort(array, values, i , j){
          if (array.length <=1){
              return array

            }
        let mid = Math.floor((i+j)/2)
        //"mid", mid, "i", i, "j");
        
        let left = await this.mergeSort(array.slice(0, Math.floor(array.length/2)), values, i, mid)
        let right = await this.mergeSort(array.slice(array.length/2, array.length), values, mid, j)
        
        return await this.merge(left, right,values, i, j)

      }
  
       async merge(l1, l2, array, y, k){
          let i = 0;
          let j = 0;
          let res = []
          let prev;
          //"Merge i", y, "Merge j", k);
          while (i <l1.length && j<l2.length){
            
            if (l1[i].val<=l2[j].val){
                res.push (l1[i])
                array[y+i+j] = l1[i]
                prev = y+i+j
                array[y+i+j].color = "red"
                i++;
                
            }

            else{

                res.push (l2[j])
                array[y+i+j] = l2[j]
                array[y+i+j].color = "red"
                prev = y+i+j    
                j++;

            }
            
            await sleep(this.state.timeToLook/(array.length*Math.log2(array.length)))
            this.setState({values: array})
           array[prev].color = "royalblue"
            
          }
          while (i<l1.length){
              res.push(l1[i])
              array[y+i+j] = l1[i]
              i++;
            
             
          }
          while (j<l2.length){

            res.push (l2[j])
            array[y+i+j] = l2[j]
            j++;
            
          }
          this.setState({values: array})
          await sleep ((res.length*this.state.waitTime)%this.state.maxTime)
          return res

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
            
            await sleep(this.state.timeToLook/(array.length*2))
        }
      }
      async BinarySearch(array, value){
        //array, "value",value);
        
        
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
                //"mid", mid, value);
                array[midIdx].color = "green"
                return mid

            }
            if (mid<value){
                array[i].color = "royalblue"
                
                i = midIdx+1;
                array[i].color = "red"
                //"i", mid);
                
            }
            else{
                array[j].color = "royalblue"
                j= midIdx-1;
                array[j].color = "red"
                //"j",mid);
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
        this.setState({values:array})
        // this.setState({values: array.sort((a,b)=>{
        //     let x = a.val;
        //     let y = b.val;
        //     return ((x < y) ? -1 : ((x > y) ? 1 : 0));}), maxValue : max_val})
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