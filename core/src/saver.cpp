#include "../saver.hpp"


const char *Saver::getName() {
  return "Saver";
}

void Saver::save(RectGrid& grid)
{
    ofstream out;
    cout << "Saving results ..." << endl;
    out.open("output.vtk");
    out << "# vtk DataFile Version 3.0" << endl;
    out << "Created by Saver::save()" << endl;
    out << "ASCII" << endl;
    out << "DATASET STRUCTURED_POINTS" << endl;
    out << "DIMENSIONS " << grid.getNx() << " " << grid.getNy() << "1" << endl;
    out << "SPACING " << grid.getDx() << " " << grid.getDy() << "0" << endl;
    out << "ORIGIN " << grid.getOx() << " " << grid.getOy() << "0" << endl;
    out << "POINT_DATA " << grid.getNx() * grid.getNy() << endl;
    out << "SCALARS p float" << endl;
    out << "LOOKUP_TABLE p_table" << endl;
    for (int i = 0; i < grid.getNx(); i++)
    {
        for (int j = 0; j < grid.getNy(); j++)
        {
            out << grid.getPressure(i, j) << ' ';
        }
        out << endl;
    }
    out << "METADATA" << endl;
    out << "INFORMATION 0" << endl;
}
