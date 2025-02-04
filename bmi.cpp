#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ounces2pounds(int x)
{
    return(x/16);
}

int stones2pounds(int x)
{
    return(x*14);
}

double weight2kg(int stones, int pounds, int ounces)
{
    return ((stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2);
}

double height2metres(int feet, double inches)
{
    return((feet+(inches/12))/3.28);
}

char categorise(double kg, double metre)
{
    double bmi = ((kg)/(metre*metre));
	cout <<"here "<< bmi<< "m"<<metre*metre <<"k"<<kg;
bmi = ((kg)/(metre*metre));
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi<25)
        cat='B';
    else if (bmi<=30)
        cat='C';
    else if(bmi > 30)
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet;
    double kg, m, inches;
    char cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (!f_in.eof())
    {
    	f_in >> person_id >> stones >> pounds >> ounces >> feet >> inches;
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),double(inches));
        cat=categorise(kg,m);
	if(f_in.eof()) break;
	f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    process_data(argv[1], argv[2]);
}
