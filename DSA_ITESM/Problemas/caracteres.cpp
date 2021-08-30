#include <iostream>
#include <vector>
int binario(std::string);
int lineal(std::string);
int main()
{
    int n;
    std::cin >> n;
    std::string in;
    for (int i = 0; i < n; i++)
    {
        std::cin >> in;
        lineal(in);
        binario(in);
    }

}
int binario(std::string in)
{
    int i = 0;
    int j = in.size() - 1;
    int comparaciones = 1;
    if (in[i] != in[i + 1])
    {
        std::cout << "FOUND: " << in[i] << " in " << comparaciones << " iterations" << std::endl;
        return i;
    }
    comparaciones += 1;
    if (in[j] != in[j - 1])
    {
        std::cout << "FOUND: " << in[j] << " in " << comparaciones << " iterations" << std::endl;
        return j;
    }
    while (i < j)
    {

        int mid = (i + j) / 2;

        if (in[mid + 1] != in[mid] && in[mid - 1] != in[mid])
        {
            std::cout << "FOUND: " << in[mid] << " in " << comparaciones << " iterations" << std::endl;
            return mid;
        }
        if (in[mid + 1] == in[mid])
        {
            j = mid - 1;
        }
        else if (in[mid - 1] == in[mid])
        {
            i = mid + 1;
        }
        comparaciones += 1;
    }
    std::cout << "FOUND: " << in[in.size() - 1] << " in " << comparaciones << " iterations" << std::endl;
    return in.size() - 1;
}
int lineal(std::string in)
{
    int i = 0;
    int comparaciones = 0;
    while (i < in.size() - 1)
    {
        comparaciones += 1;
        if (in[i] != in[i + 1])
        {
            std::cout << "FOUND: " << in[i] << " in " << comparaciones << " iterations" << std::endl;
            return i;

        }
        i += 2;


    }
    std::cout << "FOUND: " << in[in.size() - 1] << " in " << comparaciones << " iterations" << std::endl;
    return in.size() - 1;
}