from dotenv import load_dotenv
import os
import requests
def main():
    load_dotenv() 
    key = os.environ.get("gcloud_key")
    print(key)
    url = f"https://maps.googleapis.com/maps/api/place/findplacefromtext/json?input=Museum%20of%20Contemporary%20Art%20Australia&inputtype=textquery&fields=formatted_address%2Cname%2Crating%2Copening_hours%2Cgeometry&key={key}"

    payload={}
    headers = {}

    response = requests.request("GET", url, headers=headers, data=payload)

    print(response.text)

if __name__ == "__main__":
    main()




    