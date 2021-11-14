#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.cpp"



using namespace std;
int toInt(char str)
{
    return (int)str - 48;
}
void loadGraph()
{
    string line;
    ifstream myfile("casos_prueba.txt");
    
    if (myfile.is_open())
    {
        
        getline(myfile, line);
        std::cout << "Casos : "  << line << std::endl;
        
        int casos = toInt(line[0]);
        cout << casos <<endl;
        for (int i =0; i< casos; i+=1)
        {
            getline(myfile, line);
            
            auto V = toInt(line[0]);
            cout << V << endl;
            auto g = Graph(V);
            getline(myfile, line);
            
           
            
            auto ejes = toInt(line[0]);
            cout << ejes << endl;
            for (int j =0; j<ejes; j+=1)
            {
                getline(myfile, line);
                cout << line[0] << line[2] << endl;
                g.addEdge(toInt(line[0]), toInt(line[2]) );
                

            }
            cout<<i<<endl;
            if (g.isCyclic())

                    cout << "Graph contains cycle" << endl;

                else

                    cout << "Graph doesn't contain cycle" << endl;

        }
        
        myfile.close();
        
    }

    else 
    {
        std::cout << "Unable to open file";
        

}
}
int main()

{

    // Create a graph given in the above diagram 
    loadGraph();



    
    return 0;

}


