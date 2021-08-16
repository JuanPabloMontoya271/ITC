package main

import (


	"fmt"
	"log"
	"net/http"
	"encoding/json"

)
type Article struct{
	Title string `json: "Title"`
	Description string `json:"description"`
	Content string `json:"Content"`

}

type Articles []Article

func allArticles(w http.ResponseWriter, req *http.Request){
	articles := Articles {
		Article{Title: "Test title", Description: "test description", Content: "Test content"},
	}
	fmt.Println("get All Articles")
	json.NewEncoder(w).Encode(articles)
}
func homePage(w http.ResponseWriter , req *http.Request){

	fmt.Fprintf(w, "HomePage Endpoint")

}
func handleRequests(){
	http.HandleFunc("/", homePage)
	http.HandleFunc("/articles", allArticles)
	log.Fatal(http.ListenAndServe(":8081", nil))

}
func main(){

	handleRequests()
}