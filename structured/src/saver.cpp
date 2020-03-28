#include "../saver.hpp"


const char *Saver::getName() {
  return "Saver";
}


void Saver::save(RectGrid& grid, int number)
{
    if(number % period != 0){
        return;
    }

    ofstream out;
    cout << "Saving results ..." << endl;
    string fileName = grid.getName() + numberToString(number) + ".vtk";
    out.open(fileName.c_str());
    out << "# vtk DataFile Version 3.0" << endl;
    out << "Created by Saver::save()" << endl;
    out << "ASCII" << endl;
    out << "DATASET STRUCTURED_POINTS" << endl;
    out << "DIMENSIONS " << grid.getNx() << " " << grid.getNy() << ' ' << "1" << endl;
    out << "SPACING " << grid.getDx() << " " << grid.getDy() << ' ' << "0" << endl;
    out << "ORIGIN " << grid.getOx() << " " << grid.getOy() << ' ' << "0" << endl;
    out << "POINT_DATA " << grid.getNx() * grid.getNy() << endl;
    out << "SCALARS p float" << endl;
    out << "LOOKUP_TABLE p_table" << endl;
    for (int j = 0; j < grid.getNy(); j++)
    {
        for (int i = 0; i < grid.getNx(); i++)
        {
            out << grid.getAcousticNode(i, j).pressure() << ' ';
        }
        out << endl;
    }
    out << "METADATA" << endl;
    out << "INFORMATION 0" << endl;
    out.close();
    cout << "Successfully" << endl;
}

string Saver::numberToString(int x){
    string str = "";
    for(int i = 0; i < 6; i++){
        str = char((x % 10) + '0') + str;
        x /= 10;
    }
    return str;
}
