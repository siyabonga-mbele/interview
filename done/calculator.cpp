#include <iostream>



int main(){
    
    double score[4];
    std::string name;
    //std::string name[2];
    int count;

    std::cout << "Welcome to Maths Lit Marks sheet" << "\n ---------------------------------------\n\n"<< std::endl;

    std::cout << "Enter the name of the student : ";
    std::cin >> name;

    //creates a loop for score entries to score and name array
    for (int i = 0; i <= 3; i++)
    {
        //std::cout << "Enter the name of the student " << i << " : ";
        //std::cin >> name[i];

        if (i <= 2)
        {
            std::cout << "Enter the marks of T" << i + 1 << " : ";
            std::cin >> score[i];
            count += score[i];
        }
        else
        {
            score[i] = count / 3;
        }
        //avg += score[i];

    }  
    
    std::cout << "Name\t\t\t:\t T1\t T2\t T3\t Average" << std::endl;
    std::cout << name << "\t\t\t:\t ";

    
    for (int i = 0; i <= 3; i++)
    {
        std::cout << score[i]  << " \t";
        
        
        
    }
}